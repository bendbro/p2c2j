#include "q.h"
#include <iostream>

void coutTest(char* options) {
  std::cout<<options<<std::endl;
}

int aGlobal = 0;
int globalTest() {
    aGlobal = aGlobal+1;
    return aGlobal;
}

JavaVMOption jvmopt[1];
JavaVMInitArgs vmArgs;
JavaVM *javaVM;
JNIEnv *jniEnv; //is extern
void init() {
  jvmopt[0].optionString = "-Djava.class.path=.";
  vmArgs.version = JNI_VERSION_1_2;
  vmArgs.nOptions = 1;
  vmArgs.options = jvmopt;
  vmArgs.ignoreUnrecognized = JNI_TRUE;
  long flag = JNI_CreateJavaVM(&javaVM, (void**)&jniEnv, &vmArgs);
  if(flag == JNI_ERR) {
    std::cout<<"Error creating Java VM";
  }
}

void doJavaPrintLine() {
  // Get system class
  jclass syscls = jniEnv->FindClass("java/lang/System");
  // Lookup the "out" field
  jfieldID fid = jniEnv->GetStaticFieldID(syscls, "out","Ljava/io/PrintStream;");
  jobject out = jniEnv->GetStaticObjectField(syscls, fid);
  // Get PrintStream class
  jclass pscls = jniEnv->FindClass("java/io/PrintStream");
  // Lookup printLn(String)
  jmethodID mid = jniEnv->GetMethodID(pscls, "println","(Ljava/lang/String;)V");
  // Invoke the method
  jstring str = jniEnv->NewStringUTF("hello world from java!");
  jniEnv->CallVoidMethod(out, mid, str);
}

void toEuler(float* qSrc, float* eDst) {
 
}
