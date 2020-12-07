// Auto-generated file. Do not edit!
//   Template: src/f32-velu/scalar-rr2-lut16-p3.c.in
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


extern XNN_INTERNAL const uint32_t xnn_table_exp2minus_k_over_16[16];

void xnn_f32_velu_ukernel__scalar_rr2_lut16_p3_x2(
    size_t n,
    const float* x,
    float* y,
    const union xnn_f32_elu_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(n % sizeof(float) == 0);

  const float vprescale = params->scalar.prescale;
  const float valpha = params->scalar.alpha;
  const float vbeta = params->scalar.beta;

  const float vmagic_bias = 0x1.800000p19f;
  const float vlog2e = 0x1.715476p+0f;
  const uint32_t vindex_mask = UINT32_C(0xF);
  const float vsat_cutoff = -0x1.154246p+4f;
  const float vminus_ln2_hi = -0x1.62E400p-1f;
  const float vminus_ln2_lo = -0x1.7F7D1Cp-20f;
  const float vc3 = 0x1.55561Cp-3f;
  const float vc2 = 0x1.0001ECp-1f;
  const float vone = 1.0f;

  for (; n >= 2 * sizeof(float); n -= 2 * sizeof(float)) {
    float vx0 = x[0];
    float vx1 = x[1];
    x += 2;

    const float vz0 = vx0 * vprescale;
    const float vz1 = vx1 * vprescale;

    float vn0 = vz0 * vlog2e + vmagic_bias;
    float vn1 = vz1 * vlog2e + vmagic_bias;

    const uint32_t ven0 = fp32_to_bits(vn0) << 19;
    const uint32_t vidx0 = fp32_to_bits(vn0) & vindex_mask;
    vn0 -= vmagic_bias;
    const uint32_t ven1 = fp32_to_bits(vn1) << 19;
    const uint32_t vidx1 = fp32_to_bits(vn1) & vindex_mask;
    vn1 -= vmagic_bias;

    float vt0 = vn0 * vminus_ln2_hi + vz0;
    float vs0 = fp32_from_bits(xnn_table_exp2minus_k_over_16[vidx0] + ven0);
    float vt1 = vn1 * vminus_ln2_hi + vz1;
    float vs1 = fp32_from_bits(xnn_table_exp2minus_k_over_16[vidx1] + ven1);

    vt0 = vn0 * vminus_ln2_lo + vt0;
    if XNN_UNPREDICTABLE(vz0 <= vsat_cutoff) {
      vs0 = 0.0f;
    }
    vt1 = vn1 * vminus_ln2_lo + vt1;
    if XNN_UNPREDICTABLE(vz1 <= vsat_cutoff) {
      vs1 = 0.0f;
    }

    float vp0 = vc3 * vt0 + vc2;
    float vp1 = vc3 * vt1 + vc2;

    vp0 *= vt0;
    vp1 *= vt1;

    vt0 *= vs0;
    vs0 -= vone;
    vt1 *= vs1;
    vs1 -= vone;

    vp0 = vp0 * vt0 + vt0;
    vp1 = vp1 * vt1 + vt1;

    const float ve0 = (vp0 + vs0) * valpha;
    float vy0 = vx0 * vbeta;
    const float ve1 = (vp1 + vs1) * valpha;
    float vy1 = vx1 * vbeta;

    if XNN_UNPREDICTABLE(vx0 < 0.0f) {
      vy0 = ve0;
    }
    if XNN_UNPREDICTABLE(vx1 < 0.0f) {
      vy1 = ve1;
    }

    y[0] = vy0;
    y[1] = vy1;
    y += 2;
  }
  if XNN_UNLIKELY(n != 0) {
    float vx = *x;

    const float vz = vx * vprescale;

    float vn = vz * vlog2e + vmagic_bias;
    const uint32_t ven = fp32_to_bits(vn) << 19;
    const uint32_t vidx = fp32_to_bits(vn) & vindex_mask;

    vn -= vmagic_bias;
    float vs = fp32_from_bits(xnn_table_exp2minus_k_over_16[vidx] + ven);
    if XNN_UNPREDICTABLE(vz <= vsat_cutoff) {
      vs = 0.0f;
    }

    float vt = vn * vminus_ln2_hi + vz;
    vt = vn * vminus_ln2_lo + vt;

    float vp = vc3 * vt + vc2;
    vp *= vt;

    vt *= vs;
    vs -= vone;
    vp = vp * vt + vt;
    const float ve = (vp + vs) * valpha;

    float vy = vx * vbeta;
    if XNN_UNPREDICTABLE(vx < 0.0f) {
      vy = ve;
    }

    *y = vy;
  }
}
