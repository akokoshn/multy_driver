TOOLCHAIN=C:\\Users\\k00535555\\Downloads\\android-ndk-r21d-windows-x86_64\\android-ndk-r21d
NINJA=C:\\Users\\k00535555\\Downloads\\ninja-win\\ninja
cmake -GNinja -DCMAKE_MAKE_PROGRAM=$NINJA --DCMAKE_INSTALL_PREFIX:PATH=C:\\Repositories\\CrossFitTimer -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-24 -DANDROID_STL=c++_static .
cmake --build . --target install
cmake --build . --target clean
read -n1 -r -p "Press any key to continue..." key
rm CMakeCache.txt
rm -r CMakeFiles