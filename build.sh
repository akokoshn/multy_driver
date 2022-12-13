TOOLCHAIN=$1
NINJA=$2/ninja
PATH_TO_ANDROID_TREE=$3
cmake -GNinja -DCMAKE_MAKE_PROGRAM=$NINJA -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN/build/cmake/android.toolchain.cmake -DANDROID_ABI=x86_64 -DANDROID_PLATFORM=android-33 -DANDROID_STL=c++_static -DANDROID_TREE=$PATH_TO_ANDROID_TREE
cmake --build . --target install
cmake --build . --target clean
read -n1 -r -p "Press any key to continue..." key
rm CMakeCache.txt
rm -r CMakeFiles
