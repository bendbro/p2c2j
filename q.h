#ifndef _Q_H_
#define _Q_H_
#include <jni.h>

extern "C" {
  void coutTest(char* options);
  int globalTest();
  void toEuler();
  void init();
  void doJavaPrintLine();
}

extern JNIEnv *jniEnv;
#endif

