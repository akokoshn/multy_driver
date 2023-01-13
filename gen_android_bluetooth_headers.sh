$OASP_PATH = $1
hidl-gen -o include -r android.hardware:$OASP_PATH/hardware/interfaces -r android.hidl:$OASP_PATH/platform/system/libhidl/transport  -L c++ android.hardware.bluetooth@1.0
hidl-gen -o include -r android.hardware:$OASP_PATH/hardware/interfaces -r android.hidl:$OASP_PATH/platform/system/libhidl/transport  -L c++ android.hardware.bluetooth@1.1
hidl-gen -o include  -r android.hidl:$AOSP/platform/system/libhidl/transport  -L c++ android.hidl.base@1.0
hidl-gen -o include  -r android.hidl:$AOSP/platform/system/libhidl/transport  -L c++ android.hidl.manager@1.0