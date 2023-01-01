#include <jni.h>
#include <string>
#include <android/log.h>
#define  TAG "YJH"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
//先声明int get（）。运行后库自己去找 实现libhello.a库里的实现 如果找不到报错
// 用 C 编译的 getNum 所以需要执行需要 C 环境
extern "C" {
//  自己定义的方法 会返回 12345
int getNum();
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmake_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    LOGE("get%d\n",getNum());
    return env->NewStringUTF(hello.c_str());
}