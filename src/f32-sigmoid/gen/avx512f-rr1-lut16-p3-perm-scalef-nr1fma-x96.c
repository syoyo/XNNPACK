// Auto-generated file. Do not edit!
//   Template: src/f32-sigmoid/avx512f-lut16-p3-perm-scalef.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <immintrin.h>

#include <xnnpack/common.h>
#include <xnnpack/vunary.h>


void xnn_f32_sigmoid_ukernel__avx512f_rr1_lut16_p3_perm_scalef_nr1fma_x96(
    size_t n,
    const float* x,
    float* y,
    const void* params)
{
  assert(n % sizeof(float) == 0);

  const __m512i vsign_mask = _mm512_set1_epi32(0x80000000);
  const __m512 vmagic_bias = _mm512_set1_ps(0x1.800000p19f);
  const __m512 vlog2e = _mm512_set1_ps(0x1.715476p0f);
  const __m512 vtable = _mm512_set_ps(
    0x1.EA4AFAp+0f, 0x1.D5818Ep+0f, 0x1.C199BEp+0f, 0x1.AE89FAp+0f,
    0x1.9C4918p+0f, 0x1.8ACE54p+0f, 0x1.7A1148p+0f, 0x1.6A09E6p+0f,
    0x1.5AB07Ep+0f, 0x1.4BFDAEp+0f, 0x1.3DEA64p+0f, 0x1.306FE0p+0f,
    0x1.2387A6p+0f, 0x1.172B84p+0f, 0x1.0B5586p+0f, 0x1.000000p+0f);
  const __m512 vminus_ln2 = _mm512_set1_ps(-0x1.62E43p-1f);
  const __m512 vc3 = _mm512_set1_ps(0x1.55559Ap-3f);
  const __m512 vc2 = _mm512_set1_ps(0x1.00021Ep-1f);
  const __m512 vone = _mm512_set1_ps(1.0f);

  for (; n >= 96 * sizeof(float); n -= 96 * sizeof(float)) {
    const __m512 vx0 = _mm512_loadu_ps(x);
    const __m512 vx1 = _mm512_loadu_ps(x + 16);
    const __m512 vx2 = _mm512_loadu_ps(x + 32);
    const __m512 vx3 = _mm512_loadu_ps(x + 48);
    const __m512 vx4 = _mm512_loadu_ps(x + 64);
    const __m512 vx5 = _mm512_loadu_ps(x + 80);
    x += 96;

    const __m512 vz0 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx0), vsign_mask));
    const __m512 vz1 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx1), vsign_mask));
    const __m512 vz2 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx2), vsign_mask));
    const __m512 vz3 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx3), vsign_mask));
    const __m512 vz4 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx4), vsign_mask));
    const __m512 vz5 = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx5), vsign_mask));

    __m512 vn0 = _mm512_fmadd_ps(vz0, vlog2e, vmagic_bias);
    __m512 vn1 = _mm512_fmadd_ps(vz1, vlog2e, vmagic_bias);
    __m512 vn2 = _mm512_fmadd_ps(vz2, vlog2e, vmagic_bias);
    __m512 vn3 = _mm512_fmadd_ps(vz3, vlog2e, vmagic_bias);
    __m512 vn4 = _mm512_fmadd_ps(vz4, vlog2e, vmagic_bias);
    __m512 vn5 = _mm512_fmadd_ps(vz5, vlog2e, vmagic_bias);

    const __m512 vl0 = _mm512_permutexvar_ps(_mm512_castps_si512(vn0), vtable);
    const __m512 vl1 = _mm512_permutexvar_ps(_mm512_castps_si512(vn1), vtable);
    const __m512 vl2 = _mm512_permutexvar_ps(_mm512_castps_si512(vn2), vtable);
    const __m512 vl3 = _mm512_permutexvar_ps(_mm512_castps_si512(vn3), vtable);
    const __m512 vl4 = _mm512_permutexvar_ps(_mm512_castps_si512(vn4), vtable);
    const __m512 vl5 = _mm512_permutexvar_ps(_mm512_castps_si512(vn5), vtable);

    vn0 = _mm512_sub_ps(vn0, vmagic_bias);
    vn1 = _mm512_sub_ps(vn1, vmagic_bias);
    vn2 = _mm512_sub_ps(vn2, vmagic_bias);
    vn3 = _mm512_sub_ps(vn3, vmagic_bias);
    vn4 = _mm512_sub_ps(vn4, vmagic_bias);
    vn5 = _mm512_sub_ps(vn5, vmagic_bias);

    __m512 vt0 = _mm512_fmadd_ps(vn0, vminus_ln2, vz0);
    __m512 vt1 = _mm512_fmadd_ps(vn1, vminus_ln2, vz1);
    __m512 vt2 = _mm512_fmadd_ps(vn2, vminus_ln2, vz2);
    __m512 vt3 = _mm512_fmadd_ps(vn3, vminus_ln2, vz3);
    __m512 vt4 = _mm512_fmadd_ps(vn4, vminus_ln2, vz4);
    __m512 vt5 = _mm512_fmadd_ps(vn5, vminus_ln2, vz5);

    __m512 vp0 = _mm512_fmadd_ps(vt0, vc3, vc2);
    __m512 vp1 = _mm512_fmadd_ps(vt1, vc3, vc2);
    __m512 vp2 = _mm512_fmadd_ps(vt2, vc3, vc2);
    __m512 vp3 = _mm512_fmadd_ps(vt3, vc3, vc2);
    __m512 vp4 = _mm512_fmadd_ps(vt4, vc3, vc2);
    __m512 vp5 = _mm512_fmadd_ps(vt5, vc3, vc2);

    vp0 = _mm512_mul_ps(vp0, vt0);
    vp1 = _mm512_mul_ps(vp1, vt1);
    vp2 = _mm512_mul_ps(vp2, vt2);
    vp3 = _mm512_mul_ps(vp3, vt3);
    vp4 = _mm512_mul_ps(vp4, vt4);
    vp5 = _mm512_mul_ps(vp5, vt5);

    vp0 = _mm512_fmadd_ps(vt0, vp0, vt0);
    vp1 = _mm512_fmadd_ps(vt1, vp1, vt1);
    vp2 = _mm512_fmadd_ps(vt2, vp2, vt2);
    vp3 = _mm512_fmadd_ps(vt3, vp3, vt3);
    vp4 = _mm512_fmadd_ps(vt4, vp4, vt4);
    vp5 = _mm512_fmadd_ps(vt5, vp5, vt5);

    vp0 = _mm512_fmadd_ps(vl0, vp0, vl0);
    vp1 = _mm512_fmadd_ps(vl1, vp1, vl1);
    vp2 = _mm512_fmadd_ps(vl2, vp2, vl2);
    vp3 = _mm512_fmadd_ps(vl3, vp3, vl3);
    vp4 = _mm512_fmadd_ps(vl4, vp4, vl4);
    vp5 = _mm512_fmadd_ps(vl5, vp5, vl5);

    const __m512 ve0 = _mm512_scalef_ps(vp0, vn0);
    const __m512 ve1 = _mm512_scalef_ps(vp1, vn1);
    const __m512 ve2 = _mm512_scalef_ps(vp2, vn2);
    const __m512 ve3 = _mm512_scalef_ps(vp3, vn3);
    const __m512 ve4 = _mm512_scalef_ps(vp4, vn4);
    const __m512 ve5 = _mm512_scalef_ps(vp5, vn5);

    const __m512 vd0 = _mm512_add_ps(ve0, vone);
    const __m512 vd1 = _mm512_add_ps(ve1, vone);
    const __m512 vd2 = _mm512_add_ps(ve2, vone);
    const __m512 vd3 = _mm512_add_ps(ve3, vone);
    const __m512 vd4 = _mm512_add_ps(ve4, vone);
    const __m512 vd5 = _mm512_add_ps(ve5, vone);

    __m512 vr0 = _mm512_rcp14_ps(vd0);
    __m512 vr1 = _mm512_rcp14_ps(vd1);
    __m512 vr2 = _mm512_rcp14_ps(vd2);
    __m512 vr3 = _mm512_rcp14_ps(vd3);
    __m512 vr4 = _mm512_rcp14_ps(vd4);
    __m512 vr5 = _mm512_rcp14_ps(vd5);

    vr0 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr0, vd0, vone), vr0, vr0);
    vr1 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr1, vd1, vone), vr1, vr1);
    vr2 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr2, vd2, vone), vr2, vr2);
    vr3 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr3, vd3, vone), vr3, vr3);
    vr4 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr4, vd4, vone), vr4, vr4);
    vr5 = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr5, vd5, vone), vr5, vr5);

    __m512 vf0 = _mm512_mul_ps(ve0, vr0);
    __m512 vf1 = _mm512_mul_ps(ve1, vr1);
    __m512 vf2 = _mm512_mul_ps(ve2, vr2);
    __m512 vf3 = _mm512_mul_ps(ve3, vr3);
    __m512 vf4 = _mm512_mul_ps(ve4, vr4);
    __m512 vf5 = _mm512_mul_ps(ve5, vr5);


    vf0 = _mm512_mask_sub_ps(vf0, _mm512_testn_epi32_mask(_mm512_castps_si512(vx0), vsign_mask), vone, vf0);
    vf1 = _mm512_mask_sub_ps(vf1, _mm512_testn_epi32_mask(_mm512_castps_si512(vx1), vsign_mask), vone, vf1);
    vf2 = _mm512_mask_sub_ps(vf2, _mm512_testn_epi32_mask(_mm512_castps_si512(vx2), vsign_mask), vone, vf2);
    vf3 = _mm512_mask_sub_ps(vf3, _mm512_testn_epi32_mask(_mm512_castps_si512(vx3), vsign_mask), vone, vf3);
    vf4 = _mm512_mask_sub_ps(vf4, _mm512_testn_epi32_mask(_mm512_castps_si512(vx4), vsign_mask), vone, vf4);
    vf5 = _mm512_mask_sub_ps(vf5, _mm512_testn_epi32_mask(_mm512_castps_si512(vx5), vsign_mask), vone, vf5);

    _mm512_storeu_ps(y, vf0);
    _mm512_storeu_ps(y + 16, vf1);
    _mm512_storeu_ps(y + 32, vf2);
    _mm512_storeu_ps(y + 48, vf3);
    _mm512_storeu_ps(y + 64, vf4);
    _mm512_storeu_ps(y + 80, vf5);
    y += 96;
  }
  for (; n >= 16 * sizeof(float); n -= 16 * sizeof(float)) {
    const __m512 vx = _mm512_loadu_ps(x);
    x += 16;

    const __m512 vz = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx), vsign_mask));

    __m512 vn = _mm512_fmadd_ps(vz, vlog2e, vmagic_bias);
    const __m512 vl = _mm512_permutexvar_ps(_mm512_castps_si512(vn), vtable);
    vn = _mm512_sub_ps(vn, vmagic_bias);

    __m512 vt = _mm512_fmadd_ps(vn, vminus_ln2, vz);

    __m512 vp = _mm512_fmadd_ps(vt, vc3, vc2);
    vp = _mm512_mul_ps(vp, vt);
    vp = _mm512_fmadd_ps(vt, vp, vt);
    vp = _mm512_fmadd_ps(vl, vp, vl);

    const __m512 ve = _mm512_scalef_ps(vp, vn);
    const __m512 vd = _mm512_add_ps(ve, vone);

    __m512 vr = _mm512_rcp14_ps(vd);
    vr = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr, vd, vone), vr, vr);

    __m512 vf = _mm512_mul_ps(ve, vr);

    vf = _mm512_mask_sub_ps(vf, _mm512_testn_epi32_mask(_mm512_castps_si512(vx), vsign_mask), vone, vf);

    _mm512_storeu_ps(y, vf);
    y += 16;
  }
  if XNN_UNLIKELY(n != 0) {
    assert(n >= 1 * sizeof(float));
    assert(n <= 15 * sizeof(float));

    // Prepare mask for valid 32-bit elements (depends on n).
    n >>= 2 /* log2(sizeof(float)) */;
    const __mmask16 vmask = _cvtu32_mask16((uint16_t) ((uint32_t) (UINT32_C(1) << n) - UINT32_C(1)));

    const __m512 vx = _mm512_maskz_loadu_ps(vmask, x);
    const __m512 vz = _mm512_castsi512_ps(_mm512_or_epi32(_mm512_castps_si512(vx), vsign_mask));

    __m512 vn = _mm512_fmadd_ps(vz, vlog2e, vmagic_bias);
    const __m512 vl = _mm512_permutexvar_ps(_mm512_castps_si512(vn), vtable);
    vn = _mm512_sub_ps(vn, vmagic_bias);

    __m512 vt = _mm512_fmadd_ps(vn, vminus_ln2, vz);

    __m512 vp = _mm512_fmadd_ps(vt, vc3, vc2);
    vp = _mm512_mul_ps(vp, vt);
    vp = _mm512_fmadd_ps(vt, vp, vt);
    vp = _mm512_fmadd_ps(vl, vp, vl);

    const __m512 ve = _mm512_scalef_ps(vp, vn);
    const __m512 vd = _mm512_add_ps(ve, vone);

    __m512 vr = _mm512_rcp14_ps(vd);
    vr = _mm512_fmadd_ps(_mm512_fnmadd_ps(vr, vd, vone), vr, vr);

    __m512 vf = _mm512_mul_ps(ve, vr);

    vf = _mm512_mask_sub_ps(vf, _mm512_testn_epi32_mask(_mm512_castps_si512(vx), vsign_mask), vone, vf);

    _mm512_mask_storeu_ps(y, vmask, vf);
  }
}
