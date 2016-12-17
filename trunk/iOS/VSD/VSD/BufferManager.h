/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 This class handles buffering of audio data that is shared between the view and audio controller
 
 */

#ifndef __aurioTouch3__BufferManager__
#define __aurioTouch3__BufferManager__

#include <AudioToolbox/AudioToolbox.h>
#include <libkern/OSAtomic.h>


const UInt32 kNumDrawBuffers = 12;
const UInt32 kDefaultDrawSamples = 1024;


class BufferManager
{
public:
    BufferManager( UInt32 inMaxFramesPerSlice );
    ~BufferManager();
    
    void            SetDisplayMode ( UInt32 inDisplayMode ) { mDisplayMode = inDisplayMode; }
    UInt32          GetDisplayMode () { return mDisplayMode; }
    
    Float32**       GetDrawBuffers ()  { return mDrawBuffers; }
    void            CopyAudioDataToDrawBuffer( Float32* inData, UInt32 numFrames );
    void            CycleDrawBuffers();
    
    void            SetCurrentDrawBufferLength ( UInt32 inDrawBufferLen ) { mCurrentDrawBufferLen = inDrawBufferLen; }
    UInt32          GetCurrentDrawBufferLength ()   { return mCurrentDrawBufferLen; }
    
    
private:
    UInt32          mDisplayMode;
    
    Float32*        mDrawBuffers[kNumDrawBuffers];
    UInt32          mDrawBufferIndex;
    UInt32          mCurrentDrawBufferLen;
    
};

#endif /* defined(__aurioTouch3__BufferManager__) */
