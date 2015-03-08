//
//  BufferManager.h
//  VSD
//
//  Created by Natan Facchin on 6/3/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#ifndef __VSD__BufferManager__
#define __VSD__BufferManager__

#include "processAudio.h"

#define kBufferLength 8192
#define finalIMF 2

#define kStressProcessedNotification @"stressProcessed"
#define kStressCoefVarName @"stressCoef"

class BufferManager
{
private:
	/*
    int          inputBufferFrameIndex = 0;
    int          inputBufferLen;
*/
public:
#ifdef __cplusplus
        extern "C" {
#endif
        double CopyAudioDataToInputBuffer( double inputBuffer[8192] )
#ifdef __cplusplus
        }
#endif
};

#endif /* defined(__VSD__BufferManager__) */
