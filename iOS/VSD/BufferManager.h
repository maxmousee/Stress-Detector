//
//  BufferManager.h
//  VSD
//
//  Created by Natan Facchin on 6/3/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#ifndef __VSD__BufferManager__
#define __VSD__BufferManager__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include <AudioToolbox/AudioToolbox.h>
#include <libkern/OSAtomic.h>

#include "vsd.h"

#define kBufferLength 8000

#define kStressProcessedNotification @"stressProcessed"
#define kStressCoefVarName @"stressCoef"

class BufferManager
{
public:
    BufferManager( UInt32 inMaxFramesPerSlice );
    ~BufferManager();
    Float32*        inputBuffer;
    UInt32          inputBufferFrameIndex;
    UInt32          inputBufferLen;
    UInt32          inputMaxFramesPerSlice;
    void            CopyAudioDataToInputBuffer( Float32* inData, UInt32 numFrames );
};

#endif /* defined(__VSD__BufferManager__) */
