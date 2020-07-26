// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <xnnpack/params.h>
#include <xnnpack/common.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DECLARE_F16_VBINOP_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                         \
        size_t n,                                    \
        const void* a,                               \
        const void* b,                               \
        void* y,                                     \
        const struct xnn_f16_default_params* params);

#define DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                \
      size_t n,                                             \
      const void* a,                                        \
      const void* b,                                        \
      void* y,                                              \
      const struct xnn_f16_minmax_params* params);

DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vmin_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vmin_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vsqrdiff_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vsqrdiff_ukernel__neonfp16arith_x8)

DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vadd_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vadd_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vdiv_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vdiv_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vmul_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vmul_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vsub_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vsub_minmax_ukernel__neonfp16arith_x16)

DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vmaxc_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vmaxc_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vminc_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vminc_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vsqrdiffc_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_UKERNEL_FUNCTION(xnn_f16_vsqrdiffc_ukernel__neonfp16arith_x16)

DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vaddc_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vaddc_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vdivc_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vdivc_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vrdivc_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vrdivc_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vmulc_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vmulc_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vsubc_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vsubc_minmax_ukernel__neonfp16arith_x16)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vrsubc_minmax_ukernel__neonfp16arith_x8)
DECLARE_F16_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f16_vrsubc_minmax_ukernel__neonfp16arith_x16)

#define DECLARE_F32_VBINOP_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                         \
      size_t n,                                      \
      const float* a,                                \
      const float* b,                                \
      float* y,                                      \
      const union xnn_f32_default_params* params);

#define DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                \
      size_t n,                                             \
      const float* a,                                       \
      const float* b,                                       \
      float* y,                                             \
      const union xnn_f32_minmax_params* params);

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__neon_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__neon_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__sse_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__sse_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__avx_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__avx_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasm_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasm_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__wasm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmin_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__neon_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__neon_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__sse_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__sse_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__avx_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__avx_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiff_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vadd_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vadd_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vadd_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vadd_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vadd_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdiv_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdiv_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdiv_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdiv_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdiv_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmul_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmul_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmul_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmul_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmul_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsub_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsub_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsub_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsub_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsub_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vaddc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vaddc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vaddc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vaddc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vaddc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdivc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdivc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdivc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdivc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vdivc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmulc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmulc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmulc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmulc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmulc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrdivc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrdivc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrdivc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrdivc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrdivc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrsubc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrsubc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrsubc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrsubc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vrsubc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsubc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsubc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsubc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsubc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsubc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vadd_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdiv_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmul_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsub_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__neon_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__neon_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__sse_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__sse_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__avx_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__avx_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasm_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasm_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__wasm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vmaxc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__neon_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__neon_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__sse_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__sse_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__avx_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__avx_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasm_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasm_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__wasm_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vminc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__neon_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__neon_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__sse_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__sse_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__avx_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__avx_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__wasmsimd_x4)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__wasmsimd_x8)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__scalar_x1)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__scalar_x2)
DECLARE_F32_VBINOP_UKERNEL_FUNCTION(xnn_f32_vsqrdiffc_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vaddc_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vdivc_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrdivc_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vmulc_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vsubc_minmax_ukernel__scalar_x4)

DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__neon_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__neon_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__sse_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__sse_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__avx_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__avx_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__avx512f_x16)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__avx512f_x32)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasmsimd_arm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasmsimd_arm_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasmsimd_x86_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasmsimd_x86_x8)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasm_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasm_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__wasm_x4)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__scalar_x1)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__scalar_x2)
DECLARE_F32_VBINOP_MINMAX_UKERNEL_FUNCTION(xnn_f32_vrsubc_minmax_ukernel__scalar_x4)


#ifdef __cplusplus
}  // extern "C"
#endif
