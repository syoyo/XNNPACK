// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <gtest/gtest.h>

#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>

#include <xnnpack/dwconv.h>
#include "dwconv-chw-microkernel-tester.h"

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_DWCONV_CHW_3X3P1__SSE_1X4_ACC3, input_width_eq_4) {
    TEST_REQUIRES_X86_SSE;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__sse_1x4_acc3);
  }

  TEST(F32_DWCONV_CHW_3X3P1__SSE_1X4_ACC3, input_width_lt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__SSE_1X4_ACC3, input_width_gt_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__SSE_1X4_ACC3, input_width_div_4) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__SSE_1X4_ACC3, output_height_gt_1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(1)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__sse_1x4_acc3);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC
  TEST(F32_DWCONV_CHW_3X3P1__PSIMD_1X4_ACC3, input_width_eq_4) {
    TEST_REQUIRES_PSIMD;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_DWCONV_CHW_3X3P1__PSIMD_1X4_ACC3, input_width_lt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__PSIMD_1X4_ACC3, input_width_gt_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__PSIMD_1X4_ACC3, input_width_div_4) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__PSIMD_1X4_ACC3, output_height_gt_1) {
    TEST_REQUIRES_PSIMD;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(1)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
      }
    }
  }
#endif  // !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC

#if !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC
  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_eq_4_pad0) {
    TEST_REQUIRES_PSIMD;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(0)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_lt_4_pad0) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_gt_4_pad0) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_div_4_pad0) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, output_height_gt_1_pad0) {
    TEST_REQUIRES_PSIMD;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(0)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_eq_4_pad1) {
    TEST_REQUIRES_PSIMD;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_lt_4_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_gt_4_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, input_width_div_4_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__PSIMD_1X4_ACC3, output_height_gt_1_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(1)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__psimd_1x4_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
      }
    }
  }
#endif  // !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC

#if !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC
  TEST(F32_DWCONV_CHW_5X5P2__PSIMD_3X4, input_width_eq_4_pad2) {
    TEST_REQUIRES_PSIMD;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__psimd_3x4, DWConvCHWMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_DWCONV_CHW_5X5P2__PSIMD_3X4, input_width_lt_4_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__psimd_3x4, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__PSIMD_3X4, input_width_gt_4_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__psimd_3x4, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__PSIMD_3X4, input_width_div_4_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__psimd_3x4, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__PSIMD_3X4, output_height_eq_2_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(2)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__psimd_3x4, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__PSIMD_3X4, output_height_gt_2_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t output_height = 3; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(2)
          .padding_right(2)
          .padding_top(2)
          .padding_bottom(2)
          .kernel_height(5)
          .kernel_width(5)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__psimd_3x4, DWConvCHWMicrokernelTester::Variant::Scalar);
      }
    }
  }
#endif  // !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC

#if !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC
  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_eq_8_pad2) {
    TEST_REQUIRES_PSIMD;
    DWConvCHWMicrokernelTester()
      .input_width(8)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_eq_8_pad1) {
    TEST_REQUIRES_PSIMD;
    DWConvCHWMicrokernelTester()
      .input_width(8)
      .padding_left(2)
      .padding_right(2)
      .padding_top(1)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_lt_8_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(1)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_lt_8_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 1; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_gt_8_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 8; input_width < 16; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(1)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_gt_8_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 8; input_width < 16; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_div_4_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 16; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(1)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, input_width_div_4_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t input_width = 16; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, output_height_gt_1_pad1) {
    TEST_REQUIRES_PSIMD;
    for (size_t output_height = 3; output_height < 4; output_height++) {
      for (size_t input_width = 4; input_width < 5; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(2)
          .padding_right(2)
          .padding_top(1)
          .padding_bottom(2)
          .kernel_height(5)
          .kernel_width(5)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
      }
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__PSIMD_1X4_ACC2, output_height_gt_1_pad2) {
    TEST_REQUIRES_PSIMD;
    for (size_t output_height = 3; output_height < 4; output_height++) {
      for (size_t input_width = 4; input_width < 5; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(2)
          .padding_right(2)
          .padding_top(2)
          .padding_bottom(2)
          .kernel_height(5)
          .kernel_width(5)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__psimd_1x4_acc2, DWConvCHWMicrokernelTester::Variant::Scalar);
      }
    }
  }
#endif  // !XNN_ARCH_WASM && !XNN_COMPILER_MSVC && !XNN_COMPILER_ICC

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_eq_4_pad0) {
    TEST_REQUIRES_X86_SSE;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(0)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_lt_4_pad0) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_gt_4_pad0) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_div_4_pad0) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, output_height_gt_1_pad0) {
    TEST_REQUIRES_X86_SSE;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(0)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
      }
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_eq_4_pad1) {
    TEST_REQUIRES_X86_SSE;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_lt_4_pad1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_gt_4_pad1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, input_width_div_4_pad1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__SSE_1X4_ACC3, output_height_gt_1_pad1) {
    TEST_REQUIRES_X86_SSE;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(1)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__sse_1x4_acc3);
      }
    }
  }
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64


#if XNN_ARCH_ARM64
  TEST(F32_DWCONV_CHW_3X3P1__NEONFMA_3X4, input_width_eq_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__neonfma_3x4);
  }

  TEST(F32_DWCONV_CHW_3X3P1__NEONFMA_3X4, input_width_lt_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__NEONFMA_3X4, input_width_gt_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__NEONFMA_3X4, input_width_div_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_3X3P1__NEONFMA_3X4, output_height_gt_1_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t output_height = 2; output_height <= 5; output_height++) {
      for (size_t input_width = 8; input_width < 9; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(1)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__neonfma_3x4);
      }
    }
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_eq_4_pad0) {
    TEST_REQUIRES_ARM_NEON_FMA;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(0)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_eq_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_lt_4_pad0) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_lt_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_gt_4_pad0) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_gt_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_div_4_pad0) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, input_width_div_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, output_height_gt_1_pad0) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(0)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
      }
    }
  }

  TEST(F32_DWCONV_CHW_3X3S2P1__NEONFMA_1X4_ACC3, output_height_gt_1_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t output_height = 2; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(1)
          .padding_right(1)
          .padding_top(1)
          .padding_bottom(1)
          .kernel_height(3)
          .kernel_width(3)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__neonfma_1x4_acc3);
      }
    }
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_DWCONV_CHW_5X5P2__NEONFMA_3X4, input_width_eq_4_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    DWConvCHWMicrokernelTester()
      .input_width(4)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__neonfma_3x4);
  }

  TEST(F32_DWCONV_CHW_5X5P2__NEONFMA_3X4, input_width_lt_4_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 4; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__NEONFMA_3X4, input_width_gt_4_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 5; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__NEONFMA_3X4, input_width_div_4_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 8; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__NEONFMA_3X4, output_height_eq_2_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(2)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__neonfma_3x4);
    }
  }

  TEST(F32_DWCONV_CHW_5X5P2__NEONFMA_3X4, output_height_gt_2_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t output_height = 3; output_height < 5; output_height++) {
      for (size_t input_width = 1; input_width < 32; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(2)
          .padding_right(2)
          .padding_top(2)
          .padding_bottom(2)
          .kernel_height(5)
          .kernel_width(5)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__neonfma_3x4);
      }
    }
  }
#endif  // XNN_ARCH_ARM64


#if XNN_ARCH_ARM64
  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_eq_8_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    DWConvCHWMicrokernelTester()
      .input_width(8)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_eq_8_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    DWConvCHWMicrokernelTester()
      .input_width(8)
      .padding_left(2)
      .padding_right(2)
      .padding_top(1)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_lt_8_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(1)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_lt_8_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 1; input_width < 8; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_gt_8_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 8; input_width < 16; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(1)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_gt_8_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 8; input_width < 16; input_width++) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_div_4_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 16; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(1)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, input_width_div_4_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t input_width = 16; input_width < 32; input_width += 4) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .subsampling(2)
        .output_height(1)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, output_height_gt_1_pad1) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t output_height = 3; output_height < 4; output_height++) {
      for (size_t input_width = 4; input_width < 5; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(2)
          .padding_right(2)
          .padding_top(1)
          .padding_bottom(2)
          .kernel_height(5)
          .kernel_width(5)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
      }
    }
  }

  TEST(F32_DWCONV_CHW_5X5S2P2__NEONFMA_1X4_ACC2, output_height_gt_1_pad2) {
    TEST_REQUIRES_ARM_NEON_FMA;
    for (size_t output_height = 3; output_height < 4; output_height++) {
      for (size_t input_width = 4; input_width < 5; input_width += 3) {
        DWConvCHWMicrokernelTester()
          .input_width(input_width)
          .padding_left(2)
          .padding_right(2)
          .padding_top(2)
          .padding_bottom(2)
          .kernel_height(5)
          .kernel_width(5)
          .subsampling(2)
          .output_height(output_height)
          .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__neonfma_1x4_acc2);
      }
    }
  }
#endif  // XNN_ARCH_ARM64


TEST(F32_DWCONV_CHW_3X3P1__SCALAR_1X1_ACC3, input_width_eq_1) {
  DWConvCHWMicrokernelTester()
    .input_width(1)
    .padding_left(1)
    .padding_right(1)
    .padding_top(1)
    .padding_bottom(1)
    .kernel_height(3)
    .kernel_width(3)
    .output_height(1)
    .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
}

TEST(F32_DWCONV_CHW_3X3P1__SCALAR_1X1_ACC3, input_width_gt_1) {
  for (size_t input_width = 2; input_width < 32; input_width++) {
    DWConvCHWMicrokernelTester()
      .input_width(input_width)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_DWCONV_CHW_3X3P1__SCALAR_1X1_ACC3, output_height_gt_1) {
  for (size_t output_height = 2; output_height < 5; output_height++) {
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .output_height(output_height)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_DWCONV_CHW_3X3S2P1__SCALAR_1X1_ACC3, input_width_eq_1_pad0) {
  DWConvCHWMicrokernelTester()
    .input_width(1)
    .padding_left(1)
    .padding_right(1)
    .padding_top(0)
    .padding_bottom(1)
    .kernel_height(3)
    .kernel_width(3)
    .subsampling(2)
    .output_height(1)
    .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
}

TEST(F32_DWCONV_CHW_3X3S2P1__SCALAR_1X1_ACC3, input_width_gt_1_pad0) {
  for (size_t input_width = 2; input_width < 32; input_width++) {
    DWConvCHWMicrokernelTester()
      .input_width(input_width)
      .padding_left(1)
      .padding_right(1)
      .padding_top(0)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_DWCONV_CHW_3X3S2P1__SCALAR_1X1_ACC3, output_height_gt_1_pad0) {
  for (size_t output_height = 2; output_height < 5; output_height++) {
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(0)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(output_height)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_DWCONV_CHW_3X3S2P1__SCALAR_1X1_ACC3, input_width_eq_1_pad1) {
  DWConvCHWMicrokernelTester()
    .input_width(1)
    .padding_left(1)
    .padding_right(1)
    .padding_top(1)
    .padding_bottom(1)
    .kernel_height(3)
    .kernel_width(3)
    .subsampling(2)
    .output_height(1)
    .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
}

TEST(F32_DWCONV_CHW_3X3S2P1__SCALAR_1X1_ACC3, input_width_gt_1_pad1) {
  for (size_t input_width = 2; input_width < 32; input_width++) {
    DWConvCHWMicrokernelTester()
      .input_width(input_width)
      .padding_left(1)
      .padding_right(1)
      .padding_top(1)
      .padding_bottom(1)
      .kernel_height(3)
      .kernel_width(3)
      .subsampling(2)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_DWCONV_CHW_3X3S2P1__SCALAR_1X1_ACC3, output_height_gt_1_pad1) {
  for (size_t output_height = 2; output_height < 5; output_height++) {
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(1)
        .padding_right(1)
        .padding_top(1)
        .padding_bottom(1)
        .kernel_height(3)
        .kernel_width(3)
        .subsampling(2)
        .output_height(output_height)
        .Test(xnn_f32_dwconv_chw_ukernel_3x3s2p1__scalar_1x1_acc3, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_DWCONV_CHW_5X5P2__SCALAR_1X1_ACC5, input_width_eq_1_pad2) {
  DWConvCHWMicrokernelTester()
    .input_width(1)
    .padding_left(2)
    .padding_right(2)
    .padding_top(2)
    .padding_bottom(2)
    .kernel_height(5)
    .kernel_width(5)
    .output_height(1)
    .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
}

TEST(F32_DWCONV_CHW_5X5P2__SCALAR_1X1_ACC5, input_width_gt_1_pad2) {
  for (size_t input_width = 2; input_width < 32; input_width++) {
    DWConvCHWMicrokernelTester()
      .input_width(input_width)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .output_height(1)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_DWCONV_CHW_5X5P2__SCALAR_1X1_ACC5, output_height_gt_1_pad2) {
  for (size_t output_height = 2; output_height < 5; output_height++) {
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(output_height)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_DWCONV_CHW_5X5S2P2__SCALAR_1X1_ACC5, input_width_eq_1_pad1) {
  DWConvCHWMicrokernelTester()
    .input_width(1)
    .padding_left(2)
    .padding_right(2)
    .padding_top(2)
    .padding_bottom(2)
    .kernel_height(5)
    .kernel_width(5)
    .output_height(1)
    .subsampling(2)
    .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
}

TEST(F32_DWCONV_CHW_5X5S2P2__SCALAR_1X1_ACC5, input_width_gt_1_pad1) {
  for (size_t input_width = 2; input_width < 32; input_width++) {
    DWConvCHWMicrokernelTester()
      .input_width(input_width)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .output_height(1)
      .subsampling(2)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_DWCONV_CHW_5X5S2P2__SCALAR_1X1_ACC5, output_height_gt_1_pad1) {
  for (size_t output_height = 2; output_height < 5; output_height++) {
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(output_height)
        .subsampling(2)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }
}

TEST(F32_DWCONV_CHW_5X5S2P2__SCALAR_1X1_ACC5, input_width_eq_1_pad2) {
  DWConvCHWMicrokernelTester()
    .input_width(1)
    .padding_left(2)
    .padding_right(2)
    .padding_top(2)
    .padding_bottom(2)
    .kernel_height(5)
    .kernel_width(5)
    .output_height(1)
    .subsampling(2)
    .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
}

TEST(F32_DWCONV_CHW_5X5S2P2__SCALAR_1X1_ACC5, input_width_gt_1_pad2) {
  for (size_t input_width = 2; input_width < 32; input_width++) {
    DWConvCHWMicrokernelTester()
      .input_width(input_width)
      .padding_left(2)
      .padding_right(2)
      .padding_top(2)
      .padding_bottom(2)
      .kernel_height(5)
      .kernel_width(5)
      .output_height(1)
      .subsampling(2)
      .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_DWCONV_CHW_5X5S2P2__SCALAR_1X1_ACC5, output_height_gt_1_pad2) {
  for (size_t output_height = 2; output_height < 5; output_height++) {
    for (size_t input_width = 1; input_width < 32; input_width += 3) {
      DWConvCHWMicrokernelTester()
        .input_width(input_width)
        .padding_left(2)
        .padding_right(2)
        .padding_top(2)
        .padding_bottom(2)
        .kernel_height(5)
        .kernel_width(5)
        .output_height(output_height)
        .subsampling(2)
        .Test(xnn_f32_dwconv_chw_ukernel_5x5s2p2__scalar_1x1_acc5, DWConvCHWMicrokernelTester::Variant::Scalar);
    }
  }
}
