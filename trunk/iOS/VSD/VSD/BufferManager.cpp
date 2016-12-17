/*
 
 Copyright (C) 2016 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 This class handles buffering of audio data that is shared between the view and audio controller
 
 */

#include "BufferManager.h"


#define min(x,y) (x < y) ? x : y


BufferManager::BufferManager( UInt32 inMaxFramesPerSlice ) :
mDisplayMode(0 /*aurioTouchDisplayModeOscilloscopeWaveform*/),
mDrawBuffers(),
mDrawBufferIndex(0),
mCurrentDrawBufferLen(kDefaultDrawSamples)
{
    for(UInt32 i=0; i<kNumDrawBuffers; ++i) {
        mDrawBuffers[i] = (Float32*) calloc(inMaxFramesPerSlice, sizeof(Float32));
    }
}


BufferManager::~BufferManager()
{
    for(UInt32 i=0; i<kNumDrawBuffers; ++i) {
        free(mDrawBuffers[i]);
        mDrawBuffers[i] = NULL;
    }
    
}


void BufferManager::CopyAudioDataToDrawBuffer( Float32* inData, UInt32 inNumFrames )
{
    if (inData == NULL) return;
    
    for (UInt32 i=0; i<inNumFrames; i++)
    {
        if ((i+mDrawBufferIndex) >= mCurrentDrawBufferLen)
        {
            CycleDrawBuffers();
            mDrawBufferIndex = -i;
        }
        mDrawBuffers[0][i + mDrawBufferIndex] = inData[i];
    }
    mDrawBufferIndex += inNumFrames;
}


void BufferManager::CycleDrawBuffers()
{
    // Cycle the lines in our draw buffer so that they age and fade. The oldest line is discarded.
	for (int drawBuffer_i=(kNumDrawBuffers - 2); drawBuffer_i>=0; drawBuffer_i--)
		memmove(mDrawBuffers[drawBuffer_i + 1], mDrawBuffers[drawBuffer_i], mCurrentDrawBufferLen);
}

