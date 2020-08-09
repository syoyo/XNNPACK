// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: test/f32-vmulc-relu.yaml
//   Generator: tools/generate-vbinary-test.py


#include <gtest/gtest.h>

#include <xnnpack/common.h>
#include <xnnpack/isa-checks.h>

#include <xnnpack/vbinary.h>
#include "vbinaryc-microkernel-tester.h"


#if XNN_ARCH_WASMSIMD
  TEST(F32_VMULC_RELU__WASMSIMD_X4, batch_eq_4) {
    VBinOpCMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x4, VBinOpCMicrokernelTester::OpType::MulC);
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X4, batch_div_4) {
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X4, batch_lt_4) {
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X4, batch_gt_4) {
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X4, inplace) {
    for (size_t batch_size = 1; batch_size <= 20; batch_size += 3) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .inplace(true)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }
#endif  // XNN_ARCH_WASMSIMD


#if XNN_ARCH_WASMSIMD
  TEST(F32_VMULC_RELU__WASMSIMD_X8, batch_eq_8) {
    VBinOpCMicrokernelTester()
      .batch_size(8)
      .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x8, VBinOpCMicrokernelTester::OpType::MulC);
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X8, batch_div_8) {
    for (size_t batch_size = 16; batch_size < 80; batch_size += 8) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x8, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X8, batch_lt_8) {
    for (size_t batch_size = 1; batch_size < 8; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x8, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X8, batch_gt_8) {
    for (size_t batch_size = 9; batch_size < 16; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x8, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASMSIMD_X8, inplace) {
    for (size_t batch_size = 1; batch_size <= 40; batch_size += 7) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .inplace(true)
        .Test(xnn_f32_vmulc_relu_ukernel__wasmsimd_x8, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }
#endif  // XNN_ARCH_WASMSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD
  TEST(F32_VMULC_RELU__WASM_X1, batch_eq_1) {
    VBinOpCMicrokernelTester()
      .batch_size(1)
      .Test(xnn_f32_vmulc_relu_ukernel__wasm_x1, VBinOpCMicrokernelTester::OpType::MulC);
  }

  TEST(F32_VMULC_RELU__WASM_X1, batch_gt_1) {
    for (size_t batch_size = 2; batch_size < 10; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x1, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X1, inplace) {
    for (size_t batch_size = 1; batch_size <= 5; batch_size += 1) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .inplace(true)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x1, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD
  TEST(F32_VMULC_RELU__WASM_X2, batch_eq_2) {
    VBinOpCMicrokernelTester()
      .batch_size(2)
      .Test(xnn_f32_vmulc_relu_ukernel__wasm_x2, VBinOpCMicrokernelTester::OpType::MulC);
  }

  TEST(F32_VMULC_RELU__WASM_X2, batch_div_2) {
    for (size_t batch_size = 4; batch_size < 20; batch_size += 2) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x2, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X2, batch_lt_2) {
    for (size_t batch_size = 1; batch_size < 2; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x2, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X2, batch_gt_2) {
    for (size_t batch_size = 3; batch_size < 4; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x2, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X2, inplace) {
    for (size_t batch_size = 1; batch_size <= 10; batch_size += 1) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .inplace(true)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x2, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD


#if XNN_ARCH_WASM || XNN_ARCH_WASMSIMD
  TEST(F32_VMULC_RELU__WASM_X4, batch_eq_4) {
    VBinOpCMicrokernelTester()
      .batch_size(4)
      .Test(xnn_f32_vmulc_relu_ukernel__wasm_x4, VBinOpCMicrokernelTester::OpType::MulC);
  }

  TEST(F32_VMULC_RELU__WASM_X4, batch_div_4) {
    for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X4, batch_lt_4) {
    for (size_t batch_size = 1; batch_size < 4; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X4, batch_gt_4) {
    for (size_t batch_size = 5; batch_size < 8; batch_size++) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }

  TEST(F32_VMULC_RELU__WASM_X4, inplace) {
    for (size_t batch_size = 1; batch_size <= 20; batch_size += 3) {
      VBinOpCMicrokernelTester()
        .batch_size(batch_size)
        .inplace(true)
        .Test(xnn_f32_vmulc_relu_ukernel__wasm_x4, VBinOpCMicrokernelTester::OpType::MulC);
    }
  }
#endif  // XNN_ARCH_WASM || XNN_ARCH_WASMSIMD


TEST(F32_VMULC_RELU__SCALAR_X1, batch_eq_1) {
  VBinOpCMicrokernelTester()
    .batch_size(1)
    .Test(xnn_f32_vmulc_relu_ukernel__scalar_x1, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
}

TEST(F32_VMULC_RELU__SCALAR_X1, batch_gt_1) {
  for (size_t batch_size = 2; batch_size < 10; batch_size++) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x1, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X1, inplace) {
  for (size_t batch_size = 1; batch_size <= 5; batch_size += 1) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .inplace(true)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x1, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}


TEST(F32_VMULC_RELU__SCALAR_X2, batch_eq_2) {
  VBinOpCMicrokernelTester()
    .batch_size(2)
    .Test(xnn_f32_vmulc_relu_ukernel__scalar_x2, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
}

TEST(F32_VMULC_RELU__SCALAR_X2, batch_div_2) {
  for (size_t batch_size = 4; batch_size < 20; batch_size += 2) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x2, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X2, batch_lt_2) {
  for (size_t batch_size = 1; batch_size < 2; batch_size++) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x2, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X2, batch_gt_2) {
  for (size_t batch_size = 3; batch_size < 4; batch_size++) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x2, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X2, inplace) {
  for (size_t batch_size = 1; batch_size <= 10; batch_size += 1) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .inplace(true)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x2, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}


TEST(F32_VMULC_RELU__SCALAR_X4, batch_eq_4) {
  VBinOpCMicrokernelTester()
    .batch_size(4)
    .Test(xnn_f32_vmulc_relu_ukernel__scalar_x4, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
}

TEST(F32_VMULC_RELU__SCALAR_X4, batch_div_4) {
  for (size_t batch_size = 8; batch_size < 40; batch_size += 4) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x4, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X4, batch_lt_4) {
  for (size_t batch_size = 1; batch_size < 4; batch_size++) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x4, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X4, batch_gt_4) {
  for (size_t batch_size = 5; batch_size < 8; batch_size++) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x4, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}

TEST(F32_VMULC_RELU__SCALAR_X4, inplace) {
  for (size_t batch_size = 1; batch_size <= 20; batch_size += 3) {
    VBinOpCMicrokernelTester()
      .batch_size(batch_size)
      .inplace(true)
      .Test(xnn_f32_vmulc_relu_ukernel__scalar_x4, VBinOpCMicrokernelTester::OpType::MulC, VBinOpCMicrokernelTester::Variant::Scalar);
  }
}
