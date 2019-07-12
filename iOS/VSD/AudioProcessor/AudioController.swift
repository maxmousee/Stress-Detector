//
//  AudioController.swift
//
//  This is a Swift class
//    that uses the iOS RemoteIO Audio Unit
//    to record audio input samples,
//  (should be instantiated as a singleton object.)

import Foundation
import AVFoundation
import AudioUnit

final class AudioController: NSObject {
    
    var audioUnit:   AudioUnit?     = nil
    
    var micPermission   =  false
    var sessionActive   =  false
    var isRecording     =  false
    
    let sampleRate : Double = 8000.0    // default audio sample rate
    let nc = 2  // 2 channel stereo
    
    let circBuffSize = 32768        // lock-free circular fifo/buffer size
    var one_ui32: UInt32 = 1
    var circBuffer   = [Float](repeating: 0, count: 32768)  // for incoming samples
    var circInIdx  : Int =  0
    var inputAudioBuffer: Array<Double> = []
    var numberOfChannels: Int       =  2
    private let outputBus: UInt32   =  0
    private let inputBus: UInt32    =  1
    private var micPermissionDispatchToken = 0
    private var interrupted = false     // for restart from audio interruption notification
    
    func startRecording() {
        if isRecording { return }
        
        startAudioSession()
        if sessionActive {
            startAudioUnit()
        }
    }
    
    private func startAudioUnit() {
        var err: OSStatus = noErr
        
        if self.audioUnit == nil {
            setupAudioUnit()         // setup once
        }
        guard let au = self.audioUnit
            else { return }
        
        err = AudioUnitInitialize(au)
        if err != noErr { return }
        err = AudioOutputUnitStart(au)  // start
        
        if err == noErr {
            isRecording = true
        }
    }
    
    fileprivate func checkRecordPermission(_ audioSession: AVAudioSession) {
        if (micPermission == false) {
            if (micPermissionDispatchToken == 0) {
                micPermissionDispatchToken = 1
                audioSession.requestRecordPermission({(granted: Bool)-> Void in
                    if granted {
                        self.micPermission = true
                        return
                        // check for this flag and call from UI loop if needed
                    } else {
                        // dispatch in main/UI thread an alert informing that mic permission is not switched on
                    }
                })
            }
        }
    }
    
    private func startAudioSession() {
        if (sessionActive == false) {
            // set and activate Audio Session
            do {
                
                let audioSession = AVAudioSession.sharedInstance()
                
                checkRecordPermission(audioSession)
                if micPermission == false { return }
                
                try audioSession.setCategory(AVAudioSession.Category.record)
                // sampleRate = 8000.0
                let preferredIOBufferDuration = 1.0         // 1 second = 8000 samples
                let desiredSampleRate = sampleRate
                try audioSession.setPreferredSampleRate(desiredSampleRate)
                try audioSession.setPreferredIOBufferDuration(preferredIOBufferDuration)
                
                NotificationCenter.default.addObserver(forName: AVAudioSession.interruptionNotification, object: nil, queue: nil, using: myAudioSessionInterruptionHandler)
                
                try audioSession.setActive(true)
                sessionActive = true
            } catch /* let error as NSError */ {
                // handle error here
            }
        }
    }
    
    fileprivate func setupAudioUnitProperties(_ osErr: inout Int32, _ au: AudioUnit) {
        // Enable I/O for input.
        
        osErr = AudioUnitSetProperty(au, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, inputBus, &one_ui32, UInt32(MemoryLayout<UInt32>.size))
        
        // Set format to 32-bit Floats, linear PCM
        var streamFormatDesc:AudioStreamBasicDescription = AudioStreamBasicDescription(
            mSampleRate:        Double(sampleRate),
            mFormatID:          kAudioFormatLinearPCM,
            mFormatFlags:       ( kAudioFormatFlagsNativeFloatPacked ),
            mBytesPerPacket:    UInt32(nc * MemoryLayout<UInt32>.size),
            mFramesPerPacket:   1,
            mBytesPerFrame:     UInt32(nc * MemoryLayout<UInt32>.size),
            mChannelsPerFrame:  UInt32(nc),
            mBitsPerChannel:    UInt32(8 * (MemoryLayout<UInt32>.size)),
            mReserved:          UInt32(0)
        )
        
        osErr = AudioUnitSetProperty(au, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, outputBus, &streamFormatDesc, UInt32(MemoryLayout<AudioStreamBasicDescription>.size))
        
        osErr = AudioUnitSetProperty(au, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, inputBus, &streamFormatDesc, UInt32(MemoryLayout<AudioStreamBasicDescription>.size))
        
        var inputCallbackStruct = AURenderCallbackStruct(inputProc: captureCallback, inputProcRefCon: UnsafeMutableRawPointer(Unmanaged.passUnretained(self).toOpaque()))
        
        osErr = AudioUnitSetProperty(au, AudioUnitPropertyID(kAudioOutputUnitProperty_SetInputCallback), AudioUnitScope(kAudioUnitScope_Global), inputBus, &inputCallbackStruct, UInt32(MemoryLayout<AURenderCallbackStruct>.size))
        
        // Ask CoreAudio to allocate buffers on render.
        osErr = AudioUnitSetProperty(au, AudioUnitPropertyID(kAudioUnitProperty_ShouldAllocateBuffer), AudioUnitScope(kAudioUnitScope_Output), inputBus, &one_ui32, UInt32(MemoryLayout<UInt32>.size))
    }
    
    private func setupAudioUnit() {
        
        var componentDesc:  AudioComponentDescription = AudioComponentDescription(
                componentType:          OSType(kAudioUnitType_Output),
                componentSubType:       OSType(kAudioUnitSubType_RemoteIO),
                componentManufacturer:  OSType(kAudioUnitManufacturer_Apple),
                componentFlags:         UInt32(0),
                componentFlagsMask:     UInt32(0) )
        
        var osErr: OSStatus = noErr
        
        let component: AudioComponent! = AudioComponentFindNext(nil, &componentDesc)
        
        osErr = AudioComponentInstanceNew(component, &self.audioUnit)
        
        guard let au = self.audioUnit
            else { return }
        
        setupAudioUnitProperties(&osErr, au)
    }
    
    let captureCallback: AURenderCallback = { (inRefCon, ioActionFlags, inTimeStamp, inBusNumber, frameCount, ioData ) -> OSStatus in
        
        let audioObject = unsafeBitCast(inRefCon, to: AudioController.self)
        var err: OSStatus = noErr
        
        // set mData to nil, AudioUnitRender() should be allocating buffers
        var bufferList = AudioBufferList(mNumberBuffers: 1, mBuffers: AudioBuffer(mNumberChannels: UInt32(2), mDataByteSize: 2048, mData: nil))
        
        if let au = audioObject.audioUnit {
            err = AudioUnitRender(au, ioActionFlags, inTimeStamp, inBusNumber, frameCount, &bufferList)
        }
        
        audioObject.processMicrophoneBuffer( inputDataList: &bufferList, frameCount: UInt32(frameCount) )
        return 0
    }
    
    // process RemoteIO Buffer from mic input
    private func processMicrophoneBuffer(inputDataList : UnsafeMutablePointer<AudioBufferList>,frameCount : UInt32)
    {
        let inputDataPtr = UnsafeMutableAudioBufferListPointer(inputDataList)
        let mBuffers : AudioBuffer = inputDataPtr[0]
        
        let bufferPointer = UnsafeMutableRawPointer(mBuffers.mData)
        if let bptr = bufferPointer {
            let dataArray = bptr.assumingMemoryBound(to: Float.self)
            var j = self.circInIdx
            let m = self.circBuffSize
            for i in 0..<(Int(frameCount)/2) {
                let x = Float(dataArray[i+i])   // copy left  channel sample
                if (inputAudioBuffer.count == Int(sampleRate)) {
                    //calculate VSD and clear buffer
                    let inputAudioUMP = UnsafeMutablePointer<Double>.allocate(capacity: Int(sampleRate))
                    inputAudioUMP.initialize(from: &inputAudioBuffer, count: Int(sampleRate))
                    let stressFreq = vsd(inputAudioUMP, Int32(sampleRate))
                    inputAudioBuffer.removeAll()
                    let stress = Stress(stressCoeficient: stressFreq)
                    NotificationCenter.default.post(name: NSNotification.Name(rawValue: NOTIFICATION_NAME), object: stress)
                }
                inputAudioBuffer.append(Double(x)) //Using left channel because reasons
                //we do not expect left channel to be significantly different from the right channel
                self.circBuffer[j] = x
                j += 2 ; if j >= m { j = 0 }                // into circular buffer
            }
            self.circInIdx = j              // circular index will always be less than size
        }
    }
    
    func stopRecording() {
        AudioUnitUninitialize(self.audioUnit!)
        isRecording = false
    }
    
    private func myAudioSessionInterruptionHandler(notification: Notification) -> Void {
        let interuptionDict = notification.userInfo
        if let interuptionType = interuptionDict?[AVAudioSessionInterruptionTypeKey] {
            let interuptionVal = AVAudioSession.InterruptionType(
                rawValue: (interuptionType as AnyObject).uintValue )
            if (interuptionVal == AVAudioSession.InterruptionType.began) {
                if (isRecording) {
                    stopRecording()
                    isRecording = false
                    let audioSession = AVAudioSession.sharedInstance()
                    do {
                        try audioSession.setActive(false)
                        sessionActive = false
                    } catch { }
                    interrupted = true
                }
            }
        }
    }
}
