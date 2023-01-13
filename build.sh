NINJA=$1/ninja
cmake -GNinja -DCMAKE_MAKE_PROGRAM=$NINJA .
cmake --build . --target install
cmake --build . --target clean
read -n1 -r -p "Press any key to continue..." key
rm CMakeCache.txt
rm -r CMakeFiles
