//
// Created by akokoshn on 14/12/2022.
//

#include "java_helper.h"
#include "android.h"

jclass JavaHelper::jniHelperClz = NULL;
jmethodID JavaHelper::Func = NULL;

bool JavaHelper::init()
{
    LOGI("JavaHelper::init env = %p", env);
    if (!env) {
        LOGE("Java environment not initialized");
        return false;
    }
    if (Func) {
        return true;
    }

    jniHelperClz =
        env->FindClass("bluetoothhelper/BluethoothHelper");

    Func = env->GetStaticMethodID(jniHelperClz, "getDevices", "()Ljava/lang/String;");
    if (!Func) {
        LOGE("Failed to retrieve getDevices() methodID @ line %d", __LINE__);
        return false;
    }

    return true;
}

std::vector<DeviceDescriptor> JavaHelper::findDevices()
{   
	std::vector<DeviceDescriptor> descriptors;
    if (!init()) {
        return descriptors;
    }
    
    jobject res = env->CallStaticObjectMethod(jniHelperClz, Func);

    const char* val = env->GetStringUTFChars((jstring)res, NULL);
    if (!val) {
        LOGE("Unable to get devices");
        return descriptors;
    }

    LOGI("RES - %s", val);

    env->ReleaseStringUTFChars((jstring)res, val);

    env->DeleteLocalRef(res);

    return descriptors;
}

void JavaHelper::setEnv(JNIEnv* _env)
{
    env = _env;
}