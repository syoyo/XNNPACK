// Auto-generated file. Do not edit!
//   Template: src/f32-velu/scalar-rr2-p6.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <math.h>

#include <xnnpack/common.h>
#include <xnnpack/vunary.h>

#include <fp16/bitcasts.h>


void xnn_f32_velu_ukernel__wasm_rr2_p6_x1(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_elu_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(n % sizeof(float) == 0);

  const float vprescale = params->scalar.prescale;
  const float valpha = params->scalar.alpha;
  const float vbeta = params->scalar.beta;

  const float vmagic_bias = 0x1.8000FEp23f;
  const float vlog2e = 0x1.715476p+0f;
  const float vsat_cutoff = -0x1.154246p+4f;
  const float vminus_ln2_hi = -0x1.62E440p-1f;
  const float vminus_ln2_lo = 0x1.0105C6p-21f;
  const float vc6 = 0x1.6b7338p-10f;
  const float vc5 = 0x1.12278Ep-7f;
  const float vc4 = 0x1.555716p-5f;
  const float vc3 = 0x1.5554B0p-3f;
  const float vc2 = 0x1.FFFFFEp-2f;
  const float vone = 1.0f;

  do {
    float vx = *x++;

    const float vz = __builtin_wasm_min_f32(__builtin_wasm_max_f32(vx * vprescale, vsat_cutoff), 0.0f);

    float vn = vz * vlog2e + vmagic_bias;
    float vs = fp32_from_bits(fp32_to_bits(vn) << 23);
    vn -= vmagic_bias;

    float vt = vn * vminus_ln2_hi + vz;
    vt = vn * vminus_ln2_lo + vt;

    float vp = vc6 * vt + vc5;
    vp = vp * vt + vc4;
    vp = vp * vt + vc3;
    vp = vp * vt + vc2;
    vp *= vt;

    vt *= vs;
    vs -= vone;
    vp = vp * vt + vt;
    const float ve = (vp + vs) * valpha;

    float vy = __builtin_wasm_max_f32(vx * vbeta, 0.0f);
    vy += __builtin_wasm_min_f32(ve, 0.0f);

    *y++ = vy;

    n -= sizeof(float);
  } while (n != 0);
}
