#include "VSDJNI.h"
#include "vsd.h"

JNIEXPORT jdouble JNICALL Java_VSDJNI_processAudio(JNIEnv *, jobject, jdoubleArray, jint) {
      jdouble* inputAudioBuffer = env->GetDoubleArrayElements(jdoubleArray, 0);
      double inputAudioDoubleBuffer[8000] = {};
      double stressFrequency = vsd(inputAudioDoubleBuffer, 8000);
      return stressFrequency;
  }
