//
// Created by zhangshunwei on 10/21/21.
//

#include <jni.h>
#include <string>

int myFree(int *p){
    free(p);
    p=NULL;
    return 0;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_getStr1(JNIEnv *env, jclass clazz) {
    std::string hello = "Hello from C++";

    int *ptr = (int*)malloc(sizeof(int) * 3);

    myFree(ptr);
    myFree(ptr);

    return env->NewStringUTF(hello.c_str());
}