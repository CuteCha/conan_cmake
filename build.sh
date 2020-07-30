set -e -x
build_dir="cmake-build-debug-mac"
mkdir -p ${build_dir} && cd ${build_dir}
~/anaconda3/bin/conan install .. --build=missing
cmake .. && make
cd ..