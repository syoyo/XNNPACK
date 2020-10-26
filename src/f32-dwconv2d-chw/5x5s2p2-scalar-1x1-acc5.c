// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/dwconv.h>
#include <xnnpack/math.h>


void xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_1x1_acc5(
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
  assert(padding_top >= 1);
  assert(padding_top <= 2);

  const float params_max = params->scalar.max;
  const float params_min = params->scalar.min;

  const float vbias = weights[0];
  const float vk00 = weights[1];
  const float vk01 = weights[2];
  const float vk02 = weights[3];
  const float vk03 = weights[4];
  const float vk04 = weights[5];
  const float vk10 = weights[6];
  const float vk11 = weights[7];
  const float vk12 = weights[8];
  const float vk13 = weights[9];
  const float vk14 = weights[10];
  const float vk20 = weights[11];
  const float vk21 = weights[12];
  const float vk22 = weights[13];
  const float vk23 = weights[14];
  const float vk24 = weights[15];
  const float vk30 = weights[16];
  const float vk31 = weights[17];
  const float vk32 = weights[18];
  const float vk33 = weights[19];
  const float vk34 = weights[20];
  const float vk40 = weights[21];
  const float vk41 = weights[22];
  const float vk42 = weights[23];
  const float vk43 = weights[24];
  const float vk44 = weights[25];

  const uint32_t padding_top_less_1 = padding_top - 1;
  const size_t input_decrement = round_down_po2(input_width - 1 * sizeof(float), 2 * sizeof(float)) + 1 * sizeof(float);

  const float* i0 = zero;
  const float* i1 = (const float*) ((uintptr_t) input - ((-padding_top_less_1) & input_width));
  const float* i2 = (const float*) ((uintptr_t) i1 + input_width);
  if XNN_UNPREDICTABLE(padding_top_less_1 != 0) {
    i1 = zero;
  }
  const float* i3 = (const float*) ((uintptr_t) i2 + input_width);
  const float* i4 = (const float*) ((uintptr_t) i3 + input_width);

  size_t padded_input_height = input_height + (padding_top_less_1 + 1) + 2 /* padding bottom */;
  size_t output_height = (padded_input_height - 5 /* kernel size */ + 2 /* subsampling */) / 2;
  do {
    if XNN_UNPREDICTABLE(padded_input_height <= 6) {
      i4 = zero;
    }
    if XNN_UNPREDICTABLE(padded_input_height < 6) {
      i3 = zero;
    }

    float vi0x0 = 0.0f;
    float vi1x0 = 0.0f;
    float vi2x0 = 0.0f;
    float vi3x0 = 0.0f;
    float vi4x0 = 0.0f;
    float vi0x1 = 0.0f;
    float vi1x1 = 0.0f;
    float vi2x1 = 0.0f;
    float vi3x1 = 0.0f;
    float vi4x1 = 0.0f;
    float vi0x2 = *i0++;
    float vi1x2 = *i1++;
    float vi2x2 = *i2++;
    float vi3x2 = *i3++;
    float vi4x2 = *i4++;

    size_t w = input_width;
    for (; w > 2 * sizeof(float); w -= 2 * sizeof(float)) {
      const float vi0x3 = i0[0];
      const float vi1x3 = i1[0];
      const float vi2x3 = i2[0];
      const float vi3x3 = i3[0];
      const float vi4x3 = i4[0];

      const float vi0x4 = i0[1];
      i0 += 2;
      const float vi1x4 = i1[1];
      i1 += 2;
      const float vi2x4 = i2[1];
      i2 += 2;
      const float vi3x4 = i3[1];
      i3 += 2;
      const float vi4x4 = i4[1];
      i4 += 2;

      float vacc0 = vk00 * vi0x0;
      vi0x0 = vi0x2;
      float vacc1 = vk10 * vi1x0;
      vi1x0 = vi1x2;
      float vacc2 = vk20 * vi2x0;
      vi2x0 = vi2x2;
      float vacc3 = vk30 * vi3x0;
      vi3x0 = vi3x2;
      float vacc4 = vk40 * vi4x0;
      vi4x0 = vi4x2;

      vacc0 += vk01 * vi0x1;
      vi0x1 = vi0x3;
      vacc1 += vk11 * vi1x1;
      vi1x1 = vi1x3;
      vacc2 += vk21 * vi2x1;
      vi2x1 = vi2x3;
      vacc3 += vk31 * vi3x1;
      vi3x1 = vi3x3;
      vacc4 += vk41 * vi4x1;
      vi4x1 = vi4x3;

      vacc0 += vk02 * vi0x2;
      vi0x2 = vi0x4;
      vacc1 += vk12 * vi1x2;
      vi1x2 = vi1x4;
      vacc2 += vk22 * vi2x2;
      vi2x2 = vi2x4;
      vacc3 += vk32 * vi3x2;
      vi3x2 = vi3x4;
      vacc4 += vk42 * vi4x2;
      vi4x2 = vi4x4;

      vacc0 += vk03 * vi0x3;
      vacc1 += vk13 * vi1x3;
      vacc2 += vk23 * vi2x3;
      vacc3 += vk33 * vi3x3;
      vacc4 += vk43 * vi4x3;

      vacc0 += vk04 * vi0x4;
      vacc1 += vk14 * vi1x4;
      vacc2 += vk24 * vi2x4;
      vacc3 += vk34 * vi3x4;
      vacc4 += vk44 * vi4x4;

      float voutput = (vbias + vacc0) + (vacc1 + vacc2) + (vacc3 + vacc4);

      voutput = math_max_f32(voutput, params_min);
      voutput = math_min_f32(voutput, params_max);

      *output++ = voutput;
    }
    if XNN_UNPREDICTABLE(w == 2 * sizeof(float)) {
      const float vi0x3 = *i0;
      const float vi1x3 = *i1;
      const float vi2x3 = *i2;
      const float vi3x3 = *i3;
      const float vi4x3 = *i4;

      float vacc0 = vk00 * vi0x0;
      float vacc1 = vk10 * vi1x0;
      float vacc2 = vk20 * vi2x0;
      float vacc3 = vk30 * vi3x0;
      float vacc4 = vk40 * vi4x0;

      vacc0 += vk01 * vi0x1;
      vacc1 += vk11 * vi1x1;
      vacc2 += vk21 * vi2x1;
      vacc3 += vk31 * vi3x1;
      vacc4 += vk41 * vi4x1;

      vacc0 += vk02 * vi0x2;
      vacc1 += vk12 * vi1x2;
      vacc2 += vk22 * vi2x2;
      vacc3 += vk32 * vi3x2;
      vacc4 += vk42 * vi4x2;

      vacc0 += vk03 * vi0x3;
      vacc1 += vk13 * vi1x3;
      vacc2 += vk23 * vi2x3;
      vacc3 += vk33 * vi3x3;
      vacc4 += vk43 * vi4x3;

      float voutput = (vbias + vacc0) + (vacc1 + vacc2) + (vacc3 + vacc4);

      voutput = math_max_f32(voutput, params_min);
      voutput = math_min_f32(voutput, params_max);

      *output++ = voutput;
    } else {
      float vacc0 = vk00 * vi0x0;
      float vacc1 = vk10 * vi1x0;
      float vacc2 = vk20 * vi2x0;
      float vacc3 = vk30 * vi3x0;
      float vacc4 = vk40 * vi4x0;

      vacc0 += vk01 * vi0x1;
      vacc1 += vk11 * vi1x1;
      vacc2 += vk21 * vi2x1;
      vacc3 += vk31 * vi3x1;
      vacc4 += vk41 * vi4x1;

      vacc0 += vk02 * vi0x2;
      vacc1 += vk12 * vi1x2;
      vacc2 += vk22 * vi2x2;
      vacc3 += vk32 * vi3x2;
      vacc4 += vk42 * vi4x2;

      float voutput = (vbias + vacc0) + (vacc1 + vacc2) + (vacc3 + vacc4);

      voutput = math_max_f32(voutput, params_min);
      voutput = math_min_f32(voutput, params_max);

      *output++ = voutput;
    }

    i0 = (const float*) ((uintptr_t) i2 - input_decrement);
    i1 = (const float*) ((uintptr_t) i3 - input_decrement);
    i2 = (const float*) ((uintptr_t) i4 - input_decrement);
    i3 = (const float*) ((uintptr_t) i2 + input_width);
    i4 = (const float*) ((uintptr_t) i3 + input_width);

    output_height -= 1;
    padded_input_height -= 2;
  } while (output_height != 0);
}
