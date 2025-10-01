
1.
mkdir build

2.
conan install . --output-folder=build --build=missing

3. 
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake"

4.
cd build

cmake --build .