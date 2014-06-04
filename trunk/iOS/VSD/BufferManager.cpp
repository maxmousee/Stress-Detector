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
        for(int i = 0; i < kBufferLength; i++){
            //printf("%f", inputBuffer[i]);
        }
        inputBufferFrameIndex = 0;
        inputBuffer = (Float32*) calloc(inputMaxFramesPerSlice, sizeof(Float32));
    }
}