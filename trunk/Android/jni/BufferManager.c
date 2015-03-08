//
//  BufferManager.c
//  VSD
//
//  Created by Natan Facchin on 6/3/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#include <jni.h>
#include "processAudio.h"

#define kBufferLength 8192
#define finalIMF 2
#define min(x,y) (x < y) ? x : y


jdouble JNICALL Java_com_nfsindustries_vsd_LiveStressActivity_CopyAudioDataToInputBuffer
( JNIEnv* env, jobject thiz, jdoubleArray arr )
{
    double stressCoefficient = 0.0;
    int i = 0;
    int j = 0;
    int stopProcess = 0;
    double inputBuffer[kBufferLength];
    jdouble *body = (*env)->GetDoubleArrayElements(env, arr, 0);
    for (j=0; j< (*env)->GetArrayLength(env, arr); j++) {
       inputBuffer[j] = body[j];
    }
    (*env)->ReleaseDoubleArrayElements(env, arr, body, 0);
    while (stopProcess == 0){
       int nComponent = finalIMF;
       stressCoefficient = processAudio(inputBuffer, nComponent);
       nComponent++;
       //printf("nComponent %d\n", nComponent);
       if(stressCoefficient >= 3 && stressCoefficient <= 40) {
          stopProcess = 1;
          //printf("FOUND STRESS COEFICIENT, STOP\n");
          //printf("%.2f \n", stressCoefficient);
          return stressCoefficient;
       }
       if (nComponent >= finalIMF) {
          stopProcess = 1;
          //printf("REACHED FINAL, STOP -- HAMMERTIME\n");
       }
    }
    return -1.0; //SHOULD NOT REACH THIS SH*T
}
