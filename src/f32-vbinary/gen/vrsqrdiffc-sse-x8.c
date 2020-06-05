// Auto-generated file. Do not edit!
//   Template: src/f32-vbinary/vopc-sse.c.in
//   Generator: tools/xngen
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xmmintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/intrinsics-polyfill.h>
#include <xnnpack/vbinary.h>


void xnn_f32_vrsqrdiffc_ukernel__sse_x8(
    size_t n,
    const float* a,
    const float* b,
    float* y,
    const union xnn_f32_default_params params[restrict XNN_MIN_ELEMENTS(1)]) XNN_DISABLE_TSAN
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);


  const __m128 vb = _mm_load1_ps(b);
  for (; n >= 8 * sizeof(float); n -= 8 * sizeof(float)) {
    const __m128 va0123 = _mm_loadu_ps(a);
    const __m128 va4567 = _mm_loadu_ps(a + 4);
    a += 8;

    __m128 vy0123 = _mm_sub_ps(vb, va0123);
    __m128 vy4567 = _mm_sub_ps(vb, va4567);

    vy0123 = _mm_mul_ps(vy0123, vy0123);
    vy4567 = _mm_mul_ps(vy4567, vy4567);


    _mm_storeu_ps(y, vy0123);
    _mm_storeu_ps(y + 4, vy4567);
    y += 8;
  }
  for (; n >= 4 * sizeof(float); n -= 4 * sizeof(float)) {
    const __m128 va0123 = _mm_loadu_ps(a);
    a += 4;

    __m128 vy0123 = _mm_sub_ps(vb, va0123);
    vy0123 = _mm_mul_ps(vy0123, vy0123);
    _mm_storeu_ps(y, vy0123);
    y += 4;
  }
  if XNN_UNLIKELY(n != 0) {
    const __m128 va0123 = _mm_loadu_ps(a);

    __m128 vy0123 = _mm_sub_ps(vb, va0123);
    vy0123 = _mm_mul_ps(vy0123, vy0123);
    if (n & (2 * sizeof(float))) {
      _mm_storel_pi((__m64*) y, vy0123);
      vy0123 = _mm_movehl_ps(vy0123, vy0123);
      y += 2;
    }
    if (n & (1 * sizeof(float))) {
      _mm_store_ss(y, vy0123);
    }
  }
}
