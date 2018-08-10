#include "VSDJNI.h"
#include "vsd.h"

JNIEXPORT jdouble JNICALL Java_VSDJNI_processAudio(JNIEnv* env, jobject obj, jdoubleArray array)
{
      jdouble* body = env->GetIntArrayElements(array, 0);
      jsize len = env->GetArrayLength(array);
      printf("1\n");
      jdouble* inputAudioBuffer = env->GetDoubleArrayElements(array, 0);
      printf("3\n");
      double stressFrequency = vsd(inputAudioBuffer, 8000);
      printf("4\n");
      //env->ReleaseDoubleArrayElements(array, body, 0);
      return stressFrequency;
}
