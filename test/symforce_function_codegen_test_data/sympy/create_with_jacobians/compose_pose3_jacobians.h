// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>
#include <sym/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Returns:
 *     res_D_a: (6x6) jacobian of res (6) wrt arg a (6)
 *     res_D_b: (6x6) jacobian of res (6) wrt arg b (6)
 */
template <typename Scalar>
void ComposePose3Jacobians(const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
                           Eigen::Matrix<Scalar, 6, 6>* const res_D_a = nullptr,
                           Eigen::Matrix<Scalar, 6, 6>* const res_D_b = nullptr) {
  // Total ops: 335

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (134)
  const Scalar _tmp0 = _a[0] * _b[0];
  const Scalar _tmp1 = _a[1] * _b[1];
  const Scalar _tmp2 = _a[2] * _b[2];
  const Scalar _tmp3 = _a[3] * _b[3];
  const Scalar _tmp4 = -2 * _tmp0 - 2 * _tmp1 - 2 * _tmp2 + 2 * _tmp3;
  const Scalar _tmp5 = (Scalar(1) / Scalar(2)) * _tmp1;
  const Scalar _tmp6 = (Scalar(1) / Scalar(2)) * _tmp0;
  const Scalar _tmp7 = -_tmp6;
  const Scalar _tmp8 = (Scalar(1) / Scalar(2)) * _tmp2;
  const Scalar _tmp9 = (Scalar(1) / Scalar(2)) * _tmp3;
  const Scalar _tmp10 = _tmp8 + _tmp9;
  const Scalar _tmp11 = _tmp10 + _tmp5 + _tmp7;
  const Scalar _tmp12 = _a[2] * _b[3];
  const Scalar _tmp13 = (Scalar(1) / Scalar(2)) * _tmp12;
  const Scalar _tmp14 = _a[3] * _b[2];
  const Scalar _tmp15 = (Scalar(1) / Scalar(2)) * _tmp14;
  const Scalar _tmp16 = -_tmp15;
  const Scalar _tmp17 = _a[0] * _b[1];
  const Scalar _tmp18 = (Scalar(1) / Scalar(2)) * _tmp17;
  const Scalar _tmp19 = -_tmp18;
  const Scalar _tmp20 = _a[1] * _b[0];
  const Scalar _tmp21 = (Scalar(1) / Scalar(2)) * _tmp20;
  const Scalar _tmp22 = -_tmp21;
  const Scalar _tmp23 = _tmp19 + _tmp22;
  const Scalar _tmp24 = _tmp13 + _tmp16 + _tmp23;
  const Scalar _tmp25 = 2 * _tmp17;
  const Scalar _tmp26 = 2 * _tmp20;
  const Scalar _tmp27 = 2 * _tmp12;
  const Scalar _tmp28 = 2 * _tmp14;
  const Scalar _tmp29 = _tmp25 - _tmp26 + _tmp27 + _tmp28;
  const Scalar _tmp30 = _a[3] * _b[1];
  const Scalar _tmp31 = (Scalar(1) / Scalar(2)) * _tmp30;
  const Scalar _tmp32 = _a[2] * _b[0];
  const Scalar _tmp33 = (Scalar(1) / Scalar(2)) * _tmp32;
  const Scalar _tmp34 = -_tmp33;
  const Scalar _tmp35 = _a[0] * _b[2];
  const Scalar _tmp36 = (Scalar(1) / Scalar(2)) * _tmp35;
  const Scalar _tmp37 = -_tmp36;
  const Scalar _tmp38 = _a[1] * _b[3];
  const Scalar _tmp39 = (Scalar(1) / Scalar(2)) * _tmp38;
  const Scalar _tmp40 = -_tmp39;
  const Scalar _tmp41 = _tmp37 + _tmp40;
  const Scalar _tmp42 = _tmp31 + _tmp34 + _tmp41;
  const Scalar _tmp43 = 2 * _tmp35;
  const Scalar _tmp44 = 2 * _tmp38;
  const Scalar _tmp45 = 2 * _tmp32;
  const Scalar _tmp46 = 2 * _tmp30;
  const Scalar _tmp47 = _tmp43 - _tmp44 - _tmp45 - _tmp46;
  const Scalar _tmp48 = _a[0] * _b[3];
  const Scalar _tmp49 = 2 * _tmp48;
  const Scalar _tmp50 = _a[1] * _b[2];
  const Scalar _tmp51 = 2 * _tmp50;
  const Scalar _tmp52 = _a[2] * _b[1];
  const Scalar _tmp53 = 2 * _tmp52;
  const Scalar _tmp54 = _a[3] * _b[0];
  const Scalar _tmp55 = 2 * _tmp54;
  const Scalar _tmp56 = -_tmp49 - _tmp51 + _tmp53 - _tmp55;
  const Scalar _tmp57 = (Scalar(1) / Scalar(2)) * _tmp50;
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _tmp48;
  const Scalar _tmp59 = -_tmp58;
  const Scalar _tmp60 = (Scalar(1) / Scalar(2)) * _tmp52;
  const Scalar _tmp61 = -_tmp60;
  const Scalar _tmp62 = (Scalar(1) / Scalar(2)) * _tmp54;
  const Scalar _tmp63 = -_tmp62;
  const Scalar _tmp64 = _tmp61 + _tmp63;
  const Scalar _tmp65 = _tmp57 + _tmp59 + _tmp64;
  const Scalar _tmp66 = -_tmp13;
  const Scalar _tmp67 = _tmp15 + _tmp23 + _tmp66;
  const Scalar _tmp68 = -_tmp5;
  const Scalar _tmp69 = _tmp10 + _tmp6 + _tmp68;
  const Scalar _tmp70 = -_tmp31;
  const Scalar _tmp71 = _tmp33 + _tmp41 + _tmp70;
  const Scalar _tmp72 = -_tmp57;
  const Scalar _tmp73 = _tmp58 + _tmp64 + _tmp72;
  const Scalar _tmp74 = _tmp34 + _tmp70;
  const Scalar _tmp75 = _tmp37 + _tmp39;
  const Scalar _tmp76 = _tmp74 + _tmp75;
  const Scalar _tmp77 = -_tmp8 + _tmp9;
  const Scalar _tmp78 = _tmp5 + _tmp6 + _tmp77;
  const Scalar _tmp79 = _tmp18 + _tmp22;
  const Scalar _tmp80 = _tmp16 + _tmp66;
  const Scalar _tmp81 = _tmp79 + _tmp80;
  const Scalar _tmp82 = _tmp59 + _tmp72;
  const Scalar _tmp83 = _tmp61 + _tmp62;
  const Scalar _tmp84 = _tmp82 + _tmp83;
  const Scalar _tmp85 = -_tmp25 + _tmp26 - _tmp27 - _tmp28;
  const Scalar _tmp86 = _tmp49 + _tmp51 - _tmp53 + _tmp55;
  const Scalar _tmp87 = -_tmp43 + _tmp44 + _tmp45 + _tmp46;
  const Scalar _tmp88 = 2 * _a[0];
  const Scalar _tmp89 = _a[2] * _tmp88;
  const Scalar _tmp90 = 2 * _a[3];
  const Scalar _tmp91 = _a[1] * _tmp90;
  const Scalar _tmp92 = _tmp89 + _tmp91;
  const Scalar _tmp93 = _a[1] * _tmp88;
  const Scalar _tmp94 = -_tmp93;
  const Scalar _tmp95 = _a[2] * _tmp90;
  const Scalar _tmp96 = -_tmp89;
  const Scalar _tmp97 = -_tmp91;
  const Scalar _tmp98 = std::pow(_a[0], Scalar(2));
  const Scalar _tmp99 = std::pow(_a[1], Scalar(2));
  const Scalar _tmp100 = -_tmp99;
  const Scalar _tmp101 = _tmp100 + _tmp98;
  const Scalar _tmp102 = std::pow(_a[3], Scalar(2));
  const Scalar _tmp103 = std::pow(_a[2], Scalar(2));
  const Scalar _tmp104 = -_tmp103;
  const Scalar _tmp105 = _tmp102 + _tmp104;
  const Scalar _tmp106 = -_tmp95;
  const Scalar _tmp107 = _tmp106 + _tmp93;
  const Scalar _tmp108 = -_tmp102;
  const Scalar _tmp109 = _tmp103 + _tmp108;
  const Scalar _tmp110 = -_tmp98;
  const Scalar _tmp111 = _tmp110 + _tmp99;
  const Scalar _tmp112 = _a[3] * _tmp88;
  const Scalar _tmp113 = -_tmp112;
  const Scalar _tmp114 = 2 * _a[1] * _a[2];
  const Scalar _tmp115 = _tmp113 + _tmp114;
  const Scalar _tmp116 = -_tmp114;
  const Scalar _tmp117 = _tmp93 + _tmp95;
  const Scalar _tmp118 = _tmp89 + _tmp97;
  const Scalar _tmp119 = _tmp112 + _tmp114;
  const Scalar _tmp120 = _tmp13 + _tmp15 + _tmp79;
  const Scalar _tmp121 = _tmp60 + _tmp63 + _tmp82;
  const Scalar _tmp122 = _tmp121 * _tmp56;
  const Scalar _tmp123 = _tmp36 + _tmp40 + _tmp74;
  const Scalar _tmp124 = _tmp68 + _tmp7 + _tmp77;
  const Scalar _tmp125 = _tmp124 * _tmp4;
  const Scalar _tmp126 = _tmp123 * _tmp47 + _tmp125;
  const Scalar _tmp127 = _tmp19 + _tmp21 + _tmp80;
  const Scalar _tmp128 = _tmp57 + _tmp58 + _tmp83;
  const Scalar _tmp129 = _tmp31 + _tmp33 + _tmp75;
  const Scalar _tmp130 = _tmp127 * _tmp85;
  const Scalar _tmp131 = -2 * _tmp99;
  const Scalar _tmp132 = 1 - 2 * _tmp103;
  const Scalar _tmp133 = -2 * _tmp98;

  // Output terms (2)
  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp11 * _tmp4 + _tmp24 * _tmp29 + _tmp42 * _tmp47 + _tmp56 * _tmp65;
    _res_D_a(0, 1) = _tmp29 * _tmp69 + _tmp4 * _tmp67 + _tmp47 * _tmp73 + _tmp56 * _tmp71;
    _res_D_a(0, 2) = _tmp29 * _tmp84 + _tmp4 * _tmp76 + _tmp47 * _tmp78 + _tmp56 * _tmp81;
    _res_D_a(0, 3) = 0;
    _res_D_a(0, 4) = 0;
    _res_D_a(0, 5) = 0;
    _res_D_a(1, 0) = _tmp11 * _tmp85 + _tmp24 * _tmp4 + _tmp42 * _tmp86 + _tmp47 * _tmp65;
    _res_D_a(1, 1) = _tmp4 * _tmp69 + _tmp47 * _tmp71 + _tmp67 * _tmp85 + _tmp73 * _tmp86;
    _res_D_a(1, 2) = _tmp4 * _tmp84 + _tmp47 * _tmp81 + _tmp76 * _tmp85 + _tmp78 * _tmp86;
    _res_D_a(1, 3) = 0;
    _res_D_a(1, 4) = 0;
    _res_D_a(1, 5) = 0;
    _res_D_a(2, 0) = _tmp11 * _tmp87 + _tmp24 * _tmp56 + _tmp4 * _tmp42 + _tmp65 * _tmp85;
    _res_D_a(2, 1) = _tmp4 * _tmp73 + _tmp56 * _tmp69 + _tmp67 * _tmp87 + _tmp71 * _tmp85;
    _res_D_a(2, 2) = _tmp4 * _tmp78 + _tmp56 * _tmp84 + _tmp76 * _tmp87 + _tmp81 * _tmp85;
    _res_D_a(2, 3) = 0;
    _res_D_a(2, 4) = 0;
    _res_D_a(2, 5) = 0;
    _res_D_a(3, 0) = _b[5] * _tmp92 + _b[6] * (_tmp94 + _tmp95);
    _res_D_a(3, 1) = _b[4] * (_tmp96 + _tmp97) + _b[6] * (_tmp101 + _tmp105);
    _res_D_a(3, 2) = _b[4] * _tmp107 + _b[5] * (_tmp109 + _tmp111);
    _res_D_a(3, 3) = 1;
    _res_D_a(3, 4) = 0;
    _res_D_a(3, 5) = 0;
    _res_D_a(4, 0) = _b[5] * _tmp115 + _b[6] * (_tmp101 + _tmp109);
    _res_D_a(4, 1) = _b[4] * (_tmp112 + _tmp116) + _b[6] * _tmp117;
    _res_D_a(4, 2) = _b[4] * (_tmp105 + _tmp111) + _b[5] * (_tmp106 + _tmp94);
    _res_D_a(4, 3) = 0;
    _res_D_a(4, 4) = 1;
    _res_D_a(4, 5) = 0;
    _res_D_a(5, 0) = _b[5] * (_tmp100 + _tmp102 + _tmp103 + _tmp110) + _b[6] * (_tmp113 + _tmp116);
    _res_D_a(5, 1) = _b[4] * (_tmp104 + _tmp108 + _tmp98 + _tmp99) + _b[6] * _tmp118;
    _res_D_a(5, 2) = _b[4] * _tmp119 + _b[5] * (_tmp91 + _tmp96);
    _res_D_a(5, 3) = 0;
    _res_D_a(5, 4) = 0;
    _res_D_a(5, 5) = 1;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp120 * _tmp29 + _tmp122 + _tmp126;
    _res_D_b(0, 1) = _tmp123 * _tmp56 + _tmp124 * _tmp29 + _tmp127 * _tmp4 + _tmp128 * _tmp47;
    _res_D_b(0, 2) = _tmp121 * _tmp29 + _tmp124 * _tmp47 + _tmp127 * _tmp56 + _tmp129 * _tmp4;
    _res_D_b(0, 3) = 0;
    _res_D_b(0, 4) = 0;
    _res_D_b(0, 5) = 0;
    _res_D_b(1, 0) = _tmp120 * _tmp4 + _tmp121 * _tmp47 + _tmp123 * _tmp86 + _tmp124 * _tmp85;
    _res_D_b(1, 1) = _tmp126 + _tmp128 * _tmp86 + _tmp130;
    _res_D_b(1, 2) = _tmp121 * _tmp4 + _tmp124 * _tmp86 + _tmp127 * _tmp47 + _tmp129 * _tmp85;
    _res_D_b(1, 3) = 0;
    _res_D_b(1, 4) = 0;
    _res_D_b(1, 5) = 0;
    _res_D_b(2, 0) = _tmp120 * _tmp56 + _tmp121 * _tmp85 + _tmp123 * _tmp4 + _tmp124 * _tmp87;
    _res_D_b(2, 1) = _tmp123 * _tmp85 + _tmp124 * _tmp56 + _tmp127 * _tmp87 + _tmp128 * _tmp4;
    _res_D_b(2, 2) = _tmp122 + _tmp125 + _tmp129 * _tmp87 + _tmp130;
    _res_D_b(2, 3) = 0;
    _res_D_b(2, 4) = 0;
    _res_D_b(2, 5) = 0;
    _res_D_b(3, 0) = 0;
    _res_D_b(3, 1) = 0;
    _res_D_b(3, 2) = 0;
    _res_D_b(3, 3) = _tmp131 + _tmp132;
    _res_D_b(3, 4) = _tmp107;
    _res_D_b(3, 5) = _tmp92;
    _res_D_b(4, 0) = 0;
    _res_D_b(4, 1) = 0;
    _res_D_b(4, 2) = 0;
    _res_D_b(4, 3) = _tmp117;
    _res_D_b(4, 4) = _tmp132 + _tmp133;
    _res_D_b(4, 5) = _tmp115;
    _res_D_b(5, 0) = 0;
    _res_D_b(5, 1) = 0;
    _res_D_b(5, 2) = 0;
    _res_D_b(5, 3) = _tmp118;
    _res_D_b(5, 4) = _tmp119;
    _res_D_b(5, 5) = _tmp131 + _tmp133 + 1;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
