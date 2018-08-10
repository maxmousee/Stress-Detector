#include "VSD_JNI.h"
#include "vsd.h"
#include <ctype.h>

JNIEXPORT jdouble JNICALL Java_VSD_1JNI_processAudio(JNIEnv* env, jobject obj, 
jdoubleArray inputArray, jint sampleRate) {
      jdouble* inputAudioBuffer = env->GetDoubleArrayElements(inputArray, 0);
      double inputAudioDoubleBuffer[8000] = { 0 };
      double stressFrequency = vsd(inputAudioDoubleBuffer, sampleRate);
      return stressFrequency;
  }
