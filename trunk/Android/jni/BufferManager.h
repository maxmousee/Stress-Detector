//
//  BufferManager.h
//  VSD
//
//  Created by Natan Facchin on 6/3/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#ifndef __VSD__BufferManager__
#define __VSD__BufferManager__

#include <jni.h>
#include "processAudio.h"
#include "filt.h"

#define kBufferLength 8192
#define finalIMF 2

#define kStressProcessedNotification @"stressProcessed"
#define kStressCoefVarName @"stressCoef"

class BufferManager
{
private:
    Filter *my_filter;
public:
    BufferManager( UInt32 inMaxFramesPerSlice );
    ~BufferManager();
    Float32*        inputBuffer;
    UInt32          inputBufferFrameIndex;
    UInt32          inputBufferLen;
    UInt32          inputMaxFramesPerSlice;
    double            CopyAudioDataToInputBuffer( Float32* inData, UInt32 numFrames );
};

#endif /* defined(__VSD__BufferManager__) */
