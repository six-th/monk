#!/bin/bash

SRC_PATH=${MK_PATH}/3rd_Party/benchmark/benchmark
BUILD_PATH=${MK_DEPS_PKGS}/__build/benchmark
PREFIX_PATH=${MK_DEPS_PKGS}/benchmark

mkdir ${BUILD_PATH}
cd ${BUILD_PATH}
cmake ${SRC_PATH}   -DCMAKE_INSTALL_PREFIX=${PREFIX_PATH} \
                    -DCMAKE_BUILD_TYPE=Release  \
                    -DBUILD_SHARED_LIBS=ON \
                    -DBENCHMARK_ENABLE_TESTING=OFF \
                    -DBENCHMARK_ENABLE_GTEST_TESTS=OFF

make -j4
make install
cd  ${MK_PATH}/3rd_Party

#备注:
#如果不加-DCMAKE_BUILD_TYPE=Release定义的话,
#运行程序时候,benchmark会有警告:***WARNING*** Library was built as DEBUG. Timings may be affected.
