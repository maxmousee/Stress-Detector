#include "VSDJNI.h"
#include "vsd.h"

JNIEXPORT jdouble JNICALL Java_VSDJNI_processAudio(JNIEnv* env, jobject obj, jdoubleArray array)
{
      jdouble* body = env->GetDoubleArrayElements(array, 0);
      jsize len = env->GetArrayLength(array);
      jdouble* inputAudioBuffer = env->GetDoubleArrayElements(array, 0);
      double stressFrequency = vsd(inputAudioBuffer, 8000);
      env->ReleaseDoubleArrayElements(array, body, 0);
      return stressFrequency;
}
