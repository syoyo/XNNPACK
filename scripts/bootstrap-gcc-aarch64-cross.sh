#!/bin/bash

rm -rf build-cross

mkdir build-cross
cd build-cross && cmake \
  -DCMAKE_TOOLCHAIN_FILE=cmake/aarch64-linux-gnu.toolchain \
  -DXNNPACK_BUILD_TESTS=Off \
  -DXNNPACK_BUILD_BENCHMARKS=Off \
  ..
