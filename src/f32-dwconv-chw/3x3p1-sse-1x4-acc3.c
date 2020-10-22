// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xmmintrin.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>


void xnn_f32_dwconv_chw_ukernel_3x3p1__sse_1x4_acc3(
    size_t input_height,
    size_t input_width,
    const float* input,
    const float* weights,
    const float* zero,
    float* output,
    uint32_t padding_top,
    const union xnn_f32_chw_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(input_height != 0);
  assert(input_width != 0);
  assert(input_width % sizeof(float) == 0);
  assert(padding_top == 1);

  const __m128 vmask = _mm_load_ps((const float*) params->sse.mask);
  const __m128 vmax = _mm_load_ps(params->sse.max);
  const __m128 vmin = _mm_load_ps(params->sse.min);

  const __m128 vbias = _mm_load1_ps(weights);
  const __m128 vk00 = _mm_load1_ps(weights + 1);
  const __m128 vk01 = _mm_load1_ps(weights + 2);
  const __m128 vk02 = _mm_load1_ps(weights + 3);
  const __m128 vk10 = _mm_load1_ps(weights + 4);
  const __m128 vk11 = _mm_load1_ps(weights + 5);
  const __m128 vk12 = _mm_load1_ps(weights + 6);
  const __m128 vk20 = _mm_load1_ps(weights + 7);
  const __m128 vk21 = _mm_load1_ps(weights + 8);
  const __m128 vk22 = _mm_load1_ps(weights + 9);

  const size_t input_decrement = round_up_po2(input_width, 4 * sizeof(float));

  const float* i0 = zero;
  const float* i1 = input;
  const float* i2 = (const float*) ((uintptr_t) i1 + input_width);

  size_t output_height = input_height;
  do {
    if XNN_UNPREDICTABLE(output_height == 1) {
      i2 = zero;
    }

    // vi0x3012 = ( vi02, vi01, vi00, vi03 )
    __m128 vi0x3012 = _mm_setzero_ps();
    // vi1x3012 = ( vi12, vi11, vi10, vi13 )
    __m128 vi1x3012 = _mm_setzero_ps();
    // vi2x3012 = ( vi22, vi21, vi20, vi13 )
    __m128 vi2x3012 = _mm_setzero_ps();
    // vi0x4567 = ( vi07, vi06, vi05, vi04 )
    __m128 vi0x4567 = _mm_loadu_ps(i0);
    i0 += 4;
    // vi1x4567 = ( vi17, vi16, vi15, vi14 )
    __m128 vi1x4567 = _mm_loadu_ps(i1);
    i1 += 4;
    // vi2x4567 = ( vi27, vi26, vi25, vi24 )
    __m128 vi2x4567 = _mm_loadu_ps(i2);
    i2 += 4;

    size_t w = input_width;
    for (; w > 4 * sizeof(float); w -= 4 * sizeof(float)) {
      __m128 vo4567p0 = vbias;

      // vi0x89AB = ( vi0B, vi0A, vi09, vi08 )
      const __m128 vi0x89AB = _mm_loadu_ps(i0);
      i0 += 4;
      // vi1x89AB = ( vi1B, vi0A, vi09, vi08 )
      const __m128 vi1x89AB = _mm_loadu_ps(i1);
      i1 += 4;
      // vi2x89AB = ( vi2B, vi0A, vi09, vi08 )
      const __m128 vi2x89AB = _mm_loadu_ps(i2);
      i2 += 4;

      // vi0x7456 = ( vi06, vi05, vi04, vi07 )
      const __m128 vi0x7456 = _mm_shuffle_ps(vi0x4567, vi0x4567, _MM_SHUFFLE(2, 1, 0, 3));
      // vi1x7456 = ( vi16, vi15, vi14, vi17 )
      const __m128 vi1x7456 = _mm_shuffle_ps(vi1x4567, vi1x4567, _MM_SHUFFLE(2, 1, 0, 3));
      // vi2x7456 = ( vi26, vi25, vi24, vi27 )
      const __m128 vi2x7456 = _mm_shuffle_ps(vi2x4567, vi2x4567, _MM_SHUFFLE(2, 1, 0, 3));

      vo4567p0 = _mm_add_ps(vo4567p0, _mm_mul_ps(vi0x4567, vk01));
      __m128 vo4567p1 = _mm_mul_ps(vi1x4567, vk11);
      __m128 vo4567p2 = _mm_mul_ps(vi2x4567, vk21);

      // vi0x3456 = ( vi06, vi05, vi04, vi03 )
      const __m128 vi0x3456 = _mm_move_ss(vi0x7456, vi0x3012);
      // vi1x3456 = ( vi16, vi15, vi14, vi13 )
      const __m128 vi1x3456 = _mm_move_ss(vi1x7456, vi1x3012);
      // vi2x3456 = ( vi26, vi25, vi24, vi23 )
      const __m128 vi2x3456 = _mm_move_ss(vi2x7456, vi2x3012);

      vo4567p0 = _mm_add_ps(vo4567p0, _mm_mul_ps(vi0x3456, vk00));
      vo4567p1 = _mm_add_ps(vo4567p1, _mm_mul_ps(vi1x3456, vk10));
      vo4567p2 = _mm_add_ps(vo4567p2, _mm_mul_ps(vi2x3456, vk20));

      vi0x3012 = vi0x7456;
      vi1x3012 = vi1x7456;
      vi2x3012 = vi2x7456;

      // vi0x8567 = ( vi07, vi06, vi05, vi08 )
      const __m128 vi0x8567 = _mm_move_ss(vi0x4567, vi0x89AB);
      // vi1x8567 = ( vi17, vi16, vi15, vi18 )
      const __m128 vi1x8567 = _mm_move_ss(vi1x4567, vi1x89AB);
      // vi2x8567 = ( vi27, vi26, vi25, vi28 )
      const __m128 vi2x8567 = _mm_move_ss(vi2x4567, vi2x89AB);

      // vi0x5678 = ( vi08, vi07, vi06, vi05 )
      const __m128 vi0x5678 = _mm_shuffle_ps(vi0x8567, vi0x8567, _MM_SHUFFLE(0, 3, 2, 1));
      // vi1x5678 = ( vi18, vi17, vi16, vi15 )
      const __m128 vi1x5678 = _mm_shuffle_ps(vi1x8567, vi1x8567, _MM_SHUFFLE(0, 3, 2, 1));
      // vi2x5678 = ( vi28, vi27, vi26, vi25 )
      const __m128 vi2x5678 = _mm_shuffle_ps(vi2x8567, vi2x8567, _MM_SHUFFLE(0, 3, 2, 1));

      vo4567p0 = _mm_add_ps(vo4567p0, _mm_mul_ps(vi0x5678, vk02));
      vo4567p1 = _mm_add_ps(vo4567p1, _mm_mul_ps(vi1x5678, vk12));
      vo4567p2 = _mm_add_ps(vo4567p2, _mm_mul_ps(vi2x5678, vk22));

      vi0x4567 = vi0x89AB;
      vi1x4567 = vi1x89AB;
      vi2x4567 = vi2x89AB;

      __m128 vo = _mm_add_ps(vo4567p0, vo4567p1);
      vo = _mm_add_ps(vo, vo4567p2);

      vo = _mm_max_ps(vo, vmin);
      vo = _mm_min_ps(vo, vmax);

      _mm_storeu_ps(output, vo);
      output += 4;
    }
    // Always process the last block of 1..4 pixels.
    assert(w >= 1 * sizeof(float));
    assert(w <= 4 * sizeof(float));
    {
      __m128 vo4567p0 = vbias;

      vi0x4567 = _mm_and_ps(vmask, vi0x4567);
      vi1x4567 = _mm_and_ps(vmask, vi1x4567);
      vi2x4567 = _mm_and_ps(vmask, vi2x4567);

      // vi0x7456 = ( vi06, vi05, vi04, vi07 )
      const __m128 vi0x7456 = _mm_shuffle_ps(vi0x4567, vi0x4567, _MM_SHUFFLE(2, 1, 0, 3));
      // vi1x7456 = ( vi16, vi15, vi14, vi17 )
      const __m128 vi1x7456 = _mm_shuffle_ps(vi1x4567, vi1x4567, _MM_SHUFFLE(2, 1, 0, 3));
      // vi2x7456 = ( vi26, vi25, vi24, vi27 )
      const __m128 vi2x7456 = _mm_shuffle_ps(vi2x4567, vi2x4567, _MM_SHUFFLE(2, 1, 0, 3));

      vo4567p0 = _mm_add_ps(vo4567p0, _mm_mul_ps(vi0x4567, vk01));
      __m128 vo4567p1 = _mm_mul_ps(vi1x4567, vk11);
      __m128 vo4567p2 = _mm_mul_ps(vi2x4567, vk21);

      // vi0x3456 = ( vi06, vi05, vi04, vi03 )
      const __m128 vi0x3456 = _mm_move_ss(vi0x7456, vi0x3012);
      // vi1x3456 = ( vi16, vi15, vi14, vi13 )
      const __m128 vi1x3456 = _mm_move_ss(vi1x7456, vi1x3012);
      // vi2x3456 = ( vi26, vi25, vi24, vi23 )
      const __m128 vi2x3456 = _mm_move_ss(vi2x7456, vi2x3012);

      vo4567p0 = _mm_add_ps(vo4567p0, _mm_mul_ps(vi0x3456, vk00));
      vo4567p1 = _mm_add_ps(vo4567p1, _mm_mul_ps(vi1x3456, vk10));
      vo4567p2 = _mm_add_ps(vo4567p2, _mm_mul_ps(vi2x3456, vk20));

      const __m128 vzero = _mm_setzero_ps();
      // vi0x8567 = ( vi07, vi06, vi05, 0.0 )
      const __m128 vi0x8567 = _mm_move_ss(vi0x4567, vzero);
      // vi1x8567 = ( vi17, vi16, vi15, 0.0 )
      const __m128 vi1x8567 = _mm_move_ss(vi1x4567, vzero);
      // vi2x8567 = ( vi27, vi26, vi25, 0.0 )
      const __m128 vi2x8567 = _mm_move_ss(vi2x4567, vzero);

      // vi0x5678 = ( vi08, vi07, vi06, vi05 )
      const __m128 vi0x5678 = _mm_shuffle_ps(vi0x8567, vi0x8567, _MM_SHUFFLE(0, 3, 2, 1));
      // vi1x5678 = ( vi18, vi17, vi16, vi15 )
      const __m128 vi1x5678 = _mm_shuffle_ps(vi1x8567, vi1x8567, _MM_SHUFFLE(0, 3, 2, 1));
      // vi2x5678 = ( vi28, vi27, vi26, vi25 )
      const __m128 vi2x5678 = _mm_shuffle_ps(vi2x8567, vi2x8567, _MM_SHUFFLE(0, 3, 2, 1));

      vo4567p0 = _mm_add_ps(vo4567p0, _mm_mul_ps(vi0x5678, vk02));
      vo4567p1 = _mm_add_ps(vo4567p1, _mm_mul_ps(vi1x5678, vk12));
      vo4567p2 = _mm_add_ps(vo4567p2, _mm_mul_ps(vi2x5678, vk22));

      __m128 vo = _mm_add_ps(vo4567p0, vo4567p1);
      vo = _mm_add_ps(vo, vo4567p2);

      vo = _mm_max_ps(vo, vmin);
      vo = _mm_min_ps(vo, vmax);

      if XNN_LIKELY(w == 4 * sizeof(float)) {
        _mm_storeu_ps(output, vo);
        output += 4;
      } else {
        if (w & (2 * sizeof(float))) {
          _mm_storel_pi((__m64*) output, vo);
          output += 2;
          vo = _mm_movehl_ps(vo, vo);
        }
        if (w & (1 * sizeof(float))) {
          _mm_store_ss(output, vo);
          output += 1;
        }
      }
    }

    i0 = (const float*) ((uintptr_t) i1 - input_decrement);
    i1 = (const float*) ((uintptr_t) i2 - input_decrement);
    i2 = (const float*) ((uintptr_t) i1 + input_width);
  } while (--output_height != 0);
}
