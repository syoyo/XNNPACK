#!/bin/sh
# Copyright 2020 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

#################################### Scalar ###################################
tools/xngen src/f32-vlrelu/scalar.c.in -D BATCH_TILE=1 -D WASM=0 -o src/f32-vlrelu/gen/scalar-x1.c
tools/xngen src/f32-vlrelu/scalar.c.in -D BATCH_TILE=2 -D WASM=0 -o src/f32-vlrelu/gen/scalar-x2.c
tools/xngen src/f32-vlrelu/scalar.c.in -D BATCH_TILE=4 -D WASM=0 -o src/f32-vlrelu/gen/scalar-x4.c

##################################### WAsm ####################################
tools/xngen src/f32-vlrelu/wasm.c.in -D BATCH_TILE=1 -D WASM=1 -o src/f32-vlrelu/gen/wasm-x1.c
tools/xngen src/f32-vlrelu/wasm.c.in -D BATCH_TILE=2 -D WASM=1 -o src/f32-vlrelu/gen/wasm-x2.c
tools/xngen src/f32-vlrelu/wasm.c.in -D BATCH_TILE=4 -D WASM=1 -o src/f32-vlrelu/gen/wasm-x4.c

################################### ARM NEON ##################################
tools/xngen src/f32-vlrelu/neon.c.in -D BATCH_TILE=4 -o src/f32-vlrelu/gen/neon-x4.c
tools/xngen src/f32-vlrelu/neon.c.in -D BATCH_TILE=8 -o src/f32-vlrelu/gen/neon-x8.c

#################################### PSIMD ####################################
tools/xngen src/f32-vlrelu/psimd.c.in -D BATCH_TILE=4 -o src/f32-vlrelu/gen/psimd-x4.c
tools/xngen src/f32-vlrelu/psimd.c.in -D BATCH_TILE=8 -o src/f32-vlrelu/gen/psimd-x8.c

################################# x86 128-bit #################################
tools/xngen src/f32-vlrelu/sse.c.in -D BATCH_TILE=4 -o src/f32-vlrelu/gen/sse-x4.c
tools/xngen src/f32-vlrelu/sse.c.in -D BATCH_TILE=8 -o src/f32-vlrelu/gen/sse-x8.c

################################# x86 256-bit #################################
tools/xngen src/f32-vlrelu/avx.c.in -D BATCH_TILE=8  -o src/f32-vlrelu/gen/avx-x8.c
tools/xngen src/f32-vlrelu/avx.c.in -D BATCH_TILE=16 -o src/f32-vlrelu/gen/avx-x16.c

################################# x86 512-bit #################################
tools/xngen src/f32-vlrelu/avx512f.c.in -D BATCH_TILE=16 -o src/f32-vlrelu/gen/avx512f-x16.c
tools/xngen src/f32-vlrelu/avx512f.c.in -D BATCH_TILE=32 -o src/f32-vlrelu/gen/avx512f-x32.c

################################## Unit tests #################################
tools/generate-vunary-test.py --spec test/f32-vlrelu.yaml --output test/f32-vlrelu.cc
