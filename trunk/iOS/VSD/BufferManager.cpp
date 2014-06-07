//
//  BufferManager.cpp
//  VSD
//
//  Created by Natan Facchin on 6/3/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#include "BufferManager.h"

#define min(x,y) (x < y) ? x : y


BufferManager::BufferManager( UInt32 inMaxFramesPerSlice ) :
inputBuffer(NULL),
inputBufferFrameIndex(0),
inputBufferLen(inMaxFramesPerSlice)
{
    inputBuffer = (Float32*) calloc(inMaxFramesPerSlice, sizeof(Float32));
    inputBufferFrameIndex = inMaxFramesPerSlice;
}

BufferManager::~BufferManager()
{
    free(inputBuffer);
}

void BufferManager::CopyAudioDataToInputBuffer( Float32* inData, UInt32 numFrames )
{
    UInt32 framesToCopy = min(numFrames, kBufferLength - inputBufferFrameIndex);
    memcpy(inputBuffer + inputBufferFrameIndex, inData, framesToCopy * sizeof(Float32));
    inputBufferFrameIndex += framesToCopy * sizeof(Float32);
    if (inputBufferFrameIndex >= kBufferLength) {
        //OSAtomicIncrement32(&mHasNewFFTData);
        //OSAtomicDecrement32(&mNeedsNewFFTData);
        //printf("BUFFER FULL, DISPATCH NOTIFICATION %zu frameindex %f\n", inputBufferFrameIndex, inputBuffer[0]);
        //emxArray_real_T *inputDataReal;
        //inputDataReal = emxCreateWrapper_real_T(inputBufferDouble, 1, kBufferLength);
        
        
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
            int stopProcess = 0;
            while (stopProcess == 0){
                
                int nComponent = finalIMF;
                
                double stressCoefficient = 0.0;
                double inputBufferDouble[kBufferLength];
                int lowPassFreq = 30;
                Filter *my_filter;
                my_filter = new Filter(LPF, lowPassFreq, 8, 3.0);
                
                for(int i = 0; i < kBufferLength; i++){
                    inputBufferDouble[i] = my_filter->do_sample((double)inputBuffer[i]);
                }
                
                stressCoefficient = processAudio(inputBufferDouble, nComponent);
                nComponent++;
                printf("%.2f \n", stressCoefficient);
                //printf("nComponent %d\n", nComponent);
                if(stressCoefficient >= 3 && stressCoefficient <= 50) {
                    stopProcess = 1;
                    printf("FOUND STRESS COEFICIENT, STOP\n");
                }
                //if (stressCoefficient <= 3 && nComponent >= finalIMF) {
                if (nComponent >= finalIMF) {
                    stopProcess = 1;
                    printf("REACHED FINAL, STOP\n");
                }
                
                dispatch_async(dispatch_get_main_queue(), ^{
                    // Update the UI
                    
                });
            }
        });
        
        inputBufferFrameIndex -= kBufferLength;
        //printf("stressCoefficient %d ", stressCoefficient);
        //free(inputBuffer);
        //inputBuffer = (Float32*) calloc(inputMaxFramesPerSlice, sizeof(Float32));
    }
}