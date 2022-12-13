//
// Created by akokoshn on 14/12/2022.
//

#ifndef JAVA_HELPER_H
#define JAVA_HELPER_H

#include "jni.h"
#include "internal_types.h"
#include "internal_types.h"

class JavaHelper
{
	static JNIEnv* env;
	static jclass jniHelperClz;
	static jmethodID Func;

	static bool init();
public:
	static std::vector<DeviceDescriptor> findDevices();
	static void setEnv(JNIEnv* _env);
};

#endif //JAVA_HELPER_H
