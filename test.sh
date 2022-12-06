ADB=$1/adb

$ADB push bin/test /data/local/tmp
$ADB push lib/libdevice_driver.so /data/local/tmp
$ADB shell chmod 777 /data/local/tmp/test
$ADB shell LD_LIBRARY_PATH=/data/local/tmp /data/local/tmp/test
read -n1 -r -p "Press any key to continue..." key