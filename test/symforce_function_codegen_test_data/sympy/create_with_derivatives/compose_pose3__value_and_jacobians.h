// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <geo/pose3.h>

namespace sym {

/**
 * Composition of two elements in the group.
 *
 * Args:
 *     a (Element):
 *     b (Element):
 *
 * Returns:
 *     Element: a @ b
 *     geo.Matrix: Jacobian for arg 0 (a)
 *     geo.Matrix: Jacobian for arg 1 (b)
 */
template <typename Scalar>
sym::Pose3<Scalar> ComposePose3_ValueAndJacobians(
    const sym::Pose3<Scalar>& a, const sym::Pose3<Scalar>& b,
    Eigen::Matrix<Scalar, 6, 6>* const res_D_a = nullptr,
    Eigen::Matrix<Scalar, 6, 6>* const res_D_b = nullptr) {
  // Total ops: 695

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _b = b.Data();

  // Intermediate terms (211)
  const Scalar _tmp0 = _a[0] * _b[3];
  const Scalar _tmp1 = _a[1] * _b[2];
  const Scalar _tmp2 = _a[3] * _b[0];
  const Scalar _tmp3 = _a[2] * _b[1];
  const Scalar _tmp4 = _tmp0 + _tmp1 + _tmp2 - _tmp3;
  const Scalar _tmp5 = _a[1] * _b[3];
  const Scalar _tmp6 = _a[2] * _b[0];
  const Scalar _tmp7 = _a[3] * _b[1];
  const Scalar _tmp8 = _a[0] * _b[2];
  const Scalar _tmp9 = _tmp5 + _tmp6 + _tmp7 - _tmp8;
  const Scalar _tmp10 = _a[0] * _b[1];
  const Scalar _tmp11 = _a[2] * _b[3];
  const Scalar _tmp12 = _a[3] * _b[2];
  const Scalar _tmp13 = _a[1] * _b[0];
  const Scalar _tmp14 = _tmp10 + _tmp11 + _tmp12 - _tmp13;
  const Scalar _tmp15 = _a[3] * _b[3];
  const Scalar _tmp16 = _a[0] * _b[0];
  const Scalar _tmp17 = _a[1] * _b[1];
  const Scalar _tmp18 = _a[2] * _b[2];
  const Scalar _tmp19 = _tmp15 - _tmp16 - _tmp17 - _tmp18;
  const Scalar _tmp20 = 2 * _a[1];
  const Scalar _tmp21 = _a[0] * _tmp20;
  const Scalar _tmp22 = 2 * _a[2];
  const Scalar _tmp23 = _a[3] * _tmp22;
  const Scalar _tmp24 = _tmp21 - _tmp23;
  const Scalar _tmp25 = _a[0] * _tmp22;
  const Scalar _tmp26 = _a[3] * _tmp20;
  const Scalar _tmp27 = _tmp25 + _tmp26;
  const Scalar _tmp28 = -2 * (_a[1] * _a[1]);
  const Scalar _tmp29 = 1 - 2 * (_a[2] * _a[2]);
  const Scalar _tmp30 = _tmp28 + _tmp29;
  const Scalar _tmp31 = _tmp21 + _tmp23;
  const Scalar _tmp32 = 2 * _a[3];
  const Scalar _tmp33 = _a[0] * _tmp32;
  const Scalar _tmp34 = _a[1] * _tmp22;
  const Scalar _tmp35 = -_tmp33 + _tmp34;
  const Scalar _tmp36 = -2 * (_a[0] * _a[0]);
  const Scalar _tmp37 = _tmp29 + _tmp36;
  const Scalar _tmp38 = _tmp25 - _tmp26;
  const Scalar _tmp39 = _tmp33 + _tmp34;
  const Scalar _tmp40 = _tmp28 + _tmp36 + 1;
  const Scalar _tmp41 = 2 * _tmp15 - 2 * _tmp16 - 2 * _tmp17 - 2 * _tmp18;
  const Scalar _tmp42 = _b[0] * _tmp41;
  const Scalar _tmp43 = 2 * _tmp10;
  const Scalar _tmp44 = 2 * _tmp13;
  const Scalar _tmp45 = 2 * _tmp11;
  const Scalar _tmp46 = 2 * _tmp12;
  const Scalar _tmp47 = _tmp43 - _tmp44 + _tmp45 + _tmp46;
  const Scalar _tmp48 = 2 * _tmp8;
  const Scalar _tmp49 = 2 * _tmp5;
  const Scalar _tmp50 = 2 * _tmp6;
  const Scalar _tmp51 = 2 * _tmp7;
  const Scalar _tmp52 = _tmp48 - _tmp49 - _tmp50 - _tmp51;
  const Scalar _tmp53 = _b[2] * _tmp52;
  const Scalar _tmp54 = 2 * _tmp0;
  const Scalar _tmp55 = 2 * _tmp1;
  const Scalar _tmp56 = 2 * _tmp3;
  const Scalar _tmp57 = 2 * _tmp2;
  const Scalar _tmp58 = -_tmp54 - _tmp55 + _tmp56 - _tmp57;
  const Scalar _tmp59 = _b[3] * _tmp58;
  const Scalar _tmp60 = _b[1] * _tmp47 + _tmp42 + _tmp53 + _tmp59;
  const Scalar _tmp61 = (1.0 / 2.0) * _a[0];
  const Scalar _tmp62 = _b[3] * _tmp52;
  const Scalar _tmp63 = _b[1] * _tmp41;
  const Scalar _tmp64 = -_b[2] * _tmp58;
  const Scalar _tmp65 = _b[0] * _tmp47 + _tmp62 - _tmp63 + _tmp64;
  const Scalar _tmp66 = (1.0 / 2.0) * _a[1];
  const Scalar _tmp67 = _b[2] * _tmp41;
  const Scalar _tmp68 = -_b[0] * _tmp52;
  const Scalar _tmp69 = _b[1] * _tmp58;
  const Scalar _tmp70 = (1.0 / 2.0) * _b[3] * _tmp47 + (1.0 / 2.0) * _tmp67 + (1.0 / 2.0) * _tmp68 -
                        1.0 / 2.0 * _tmp69;
  const Scalar _tmp71 = _b[1] * _tmp52;
  const Scalar _tmp72 = _b[3] * _tmp41;
  const Scalar _tmp73 = _b[0] * _tmp58;
  const Scalar _tmp74 = -1.0 / 2.0 * _b[2] * _tmp47 + (1.0 / 2.0) * _tmp71 + (1.0 / 2.0) * _tmp72 -
                        1.0 / 2.0 * _tmp73;
  const Scalar _tmp75 = (1.0 / 2.0) * _a[2];
  const Scalar _tmp76 = (1.0 / 2.0) * _a[3];
  const Scalar _tmp77 = -_tmp43 + _tmp44 - _tmp45 - _tmp46;
  const Scalar _tmp78 = _b[0] * _tmp77;
  const Scalar _tmp79 = _tmp54 + _tmp55 - _tmp56 + _tmp57;
  const Scalar _tmp80 = _b[2] * _tmp79 + _tmp62 + _tmp63 + _tmp78;
  const Scalar _tmp81 = -_b[1] * _tmp77;
  const Scalar _tmp82 = _b[3] * _tmp79 + _tmp42 - _tmp53 + _tmp81;
  const Scalar _tmp83 = _b[2] * _tmp77;
  const Scalar _tmp84 = -_b[0] * _tmp79 - _tmp71 + _tmp72 + _tmp83;
  const Scalar _tmp85 = _b[3] * _tmp77;
  const Scalar _tmp86 = _b[1] * _tmp79 - _tmp67 + _tmp68 + _tmp85;
  const Scalar _tmp87 = -_tmp48 + _tmp49 + _tmp50 + _tmp51;
  const Scalar _tmp88 = _b[0] * _tmp87 + _tmp67 + _tmp69 + _tmp85;
  const Scalar _tmp89 = -_b[1] * _tmp87 + _tmp72 + _tmp73 - _tmp83;
  const Scalar _tmp90 = _b[2] * _tmp87 - _tmp42 + _tmp59 + _tmp81;
  const Scalar _tmp91 = _b[3] * _tmp87 + _tmp63 + _tmp64 - _tmp78;
  const Scalar _tmp92 = _b[6] * _tmp20;
  const Scalar _tmp93 = _b[5] * _tmp22;
  const Scalar _tmp94 = _tmp92 - _tmp93;
  const Scalar _tmp95 = -2 * (_tmp9 * _tmp9);
  const Scalar _tmp96 = 1 - 2 * (_tmp14 * _tmp14);
  const Scalar _tmp97 = _tmp95 + _tmp96;
  const Scalar _tmp98 = 2 * _a[0];
  const Scalar _tmp99 = _b[6] * _tmp98;
  const Scalar _tmp100 = _b[4] * _tmp22;
  const Scalar _tmp101 = _tmp100 - _tmp99;
  const Scalar _tmp102 = _tmp79 * _tmp9;
  const Scalar _tmp103 = _tmp19 * _tmp47;
  const Scalar _tmp104 = _tmp102 + _tmp103;
  const Scalar _tmp105 = _b[5] * _tmp98;
  const Scalar _tmp106 = _b[4] * _tmp20;
  const Scalar _tmp107 = _tmp105 - _tmp106;
  const Scalar _tmp108 = _tmp14 * _tmp79;
  const Scalar _tmp109 = _tmp19 * _tmp87;
  const Scalar _tmp110 = _tmp108 - _tmp109;
  const Scalar _tmp111 = _tmp101 * _tmp104 + _tmp107 * _tmp110 + _tmp94 * _tmp97;
  const Scalar _tmp112 = 4 * _a[2];
  const Scalar _tmp113 = _b[5] * _tmp32;
  const Scalar _tmp114 = -_b[4] * _tmp112 - _tmp113 + _tmp99;
  const Scalar _tmp115 = _b[4] * _tmp98;
  const Scalar _tmp116 = _b[5] * _tmp20;
  const Scalar _tmp117 = _tmp115 + _tmp116;
  const Scalar _tmp118 = _b[4] * _tmp32;
  const Scalar _tmp119 = -_b[5] * _tmp112 + _tmp118 + _tmp92;
  const Scalar _tmp120 = _tmp104 * _tmp119 + _tmp110 * _tmp117 + _tmp114 * _tmp97;
  const Scalar _tmp121 = 4 * _a[1];
  const Scalar _tmp122 = _b[6] * _tmp32;
  const Scalar _tmp123 = -_b[4] * _tmp121 + _tmp105 + _tmp122;
  const Scalar _tmp124 = _b[6] * _tmp22;
  const Scalar _tmp125 = _tmp115 + _tmp124;
  const Scalar _tmp126 = -_b[6] * _tmp121 - _tmp118 + _tmp93;
  const Scalar _tmp127 = _tmp104 * _tmp125 + _tmp110 * _tmp126 + _tmp123 * _tmp97;
  const Scalar _tmp128 = _tmp116 + _tmp124;
  const Scalar _tmp129 = 4 * _a[0];
  const Scalar _tmp130 = -_b[5] * _tmp129 + _tmp106 - _tmp122;
  const Scalar _tmp131 = -_b[6] * _tmp129 + _tmp100 + _tmp113;
  const Scalar _tmp132 = _tmp104 * _tmp130 + _tmp110 * _tmp131 + _tmp128 * _tmp97;
  const Scalar _tmp133 = _tmp104 * _tmp31 + _tmp110 * _tmp38 + _tmp30 * _tmp97;
  const Scalar _tmp134 = _tmp104 * _tmp37 + _tmp110 * _tmp39 + _tmp24 * _tmp97;
  const Scalar _tmp135 = _tmp104 * _tmp35 + _tmp110 * _tmp40 + _tmp27 * _tmp97;
  const Scalar _tmp136 = -2 * (_tmp4 * _tmp4);
  const Scalar _tmp137 = _tmp136 + _tmp96;
  const Scalar _tmp138 = _tmp14 * _tmp87;
  const Scalar _tmp139 = _tmp19 * _tmp79;
  const Scalar _tmp140 = _tmp138 + _tmp139;
  const Scalar _tmp141 = _tmp102 - _tmp103;
  const Scalar _tmp142 = _tmp101 * _tmp137 + _tmp107 * _tmp140 + _tmp141 * _tmp94;
  const Scalar _tmp143 = _tmp114 * _tmp141 + _tmp117 * _tmp140 + _tmp119 * _tmp137;
  const Scalar _tmp144 = _tmp123 * _tmp141 + _tmp125 * _tmp137 + _tmp126 * _tmp140;
  const Scalar _tmp145 = _tmp128 * _tmp141 + _tmp130 * _tmp137 + _tmp131 * _tmp140;
  const Scalar _tmp146 = _tmp137 * _tmp31 + _tmp140 * _tmp38 + _tmp141 * _tmp30;
  const Scalar _tmp147 = _tmp137 * _tmp37 + _tmp140 * _tmp39 + _tmp141 * _tmp24;
  const Scalar _tmp148 = _tmp137 * _tmp35 + _tmp140 * _tmp40 + _tmp141 * _tmp27;
  const Scalar _tmp149 = _tmp136 + _tmp95 + 1;
  const Scalar _tmp150 = _tmp108 + _tmp109;
  const Scalar _tmp151 = _tmp138 - _tmp139;
  const Scalar _tmp152 = _tmp101 * _tmp151 + _tmp107 * _tmp149 + _tmp150 * _tmp94;
  const Scalar _tmp153 = _tmp114 * _tmp150 + _tmp117 * _tmp149 + _tmp119 * _tmp151;
  const Scalar _tmp154 = _tmp123 * _tmp150 + _tmp125 * _tmp151 + _tmp126 * _tmp149;
  const Scalar _tmp155 = _tmp128 * _tmp150 + _tmp130 * _tmp151 + _tmp131 * _tmp149;
  const Scalar _tmp156 = _tmp149 * _tmp38 + _tmp150 * _tmp30 + _tmp151 * _tmp31;
  const Scalar _tmp157 = _tmp149 * _tmp39 + _tmp150 * _tmp24 + _tmp151 * _tmp37;
  const Scalar _tmp158 = _tmp149 * _tmp40 + _tmp150 * _tmp27 + _tmp151 * _tmp35;
  const Scalar _tmp159 = _a[2] * _tmp52;
  const Scalar _tmp160 = _a[0] * _tmp41;
  const Scalar _tmp161 = _a[3] * _tmp58 + _tmp160;
  const Scalar _tmp162 = _a[1] * _tmp47 + _tmp159 + _tmp161;
  const Scalar _tmp163 = (1.0 / 2.0) * _b[0];
  const Scalar _tmp164 = _a[2] * _tmp58;
  const Scalar _tmp165 = _a[1] * _tmp41;
  const Scalar _tmp166 = _a[3] * _tmp52 + _tmp165;
  const Scalar _tmp167 = -_a[0] * _tmp47 - _tmp164 + _tmp166;
  const Scalar _tmp168 = (1.0 / 2.0) * _b[1];
  const Scalar _tmp169 = _a[0] * _tmp52;
  const Scalar _tmp170 = _a[1] * _tmp58;
  const Scalar _tmp171 = _a[2] * _tmp41;
  const Scalar _tmp172 = (1.0 / 2.0) * _a[3] * _tmp47 + (1.0 / 2.0) * _tmp169 -
                         1.0 / 2.0 * _tmp170 - 1.0 / 2.0 * _tmp171;
  const Scalar _tmp173 = -_a[0] * _tmp58;
  const Scalar _tmp174 = _a[3] * _tmp41;
  const Scalar _tmp175 = -_a[1] * _tmp52 + _tmp174;
  const Scalar _tmp176 =
      (1.0 / 2.0) * _a[2] * _tmp47 + (1.0 / 2.0) * _tmp173 + (1.0 / 2.0) * _tmp175;
  const Scalar _tmp177 = (1.0 / 2.0) * _b[2];
  const Scalar _tmp178 = (1.0 / 2.0) * _b[3];
  const Scalar _tmp179 = _a[0] * _tmp77;
  const Scalar _tmp180 = _a[2] * _tmp79 + _tmp166 + _tmp179;
  const Scalar _tmp181 = _a[1] * _tmp77;
  const Scalar _tmp182 = _a[3] * _tmp79 - _tmp159 - _tmp160 + _tmp181;
  const Scalar _tmp183 = -_a[2] * _tmp77;
  const Scalar _tmp184 = _a[0] * _tmp79 + _tmp175 + _tmp183;
  const Scalar _tmp185 = _a[3] * _tmp77 + _tmp171;
  const Scalar _tmp186 = -_a[1] * _tmp79 - _tmp169 + _tmp185;
  const Scalar _tmp187 = _a[0] * _tmp87 + _tmp170 + _tmp185;
  const Scalar _tmp188 = _a[1] * _tmp87 + _tmp173 + _tmp174 + _tmp183;
  const Scalar _tmp189 = -_a[2] * _tmp87 + _tmp161 - _tmp181;
  const Scalar _tmp190 = _a[3] * _tmp87 + _tmp164 - _tmp165 - _tmp179;
  const Scalar _tmp191 = 2 * _b[1];
  const Scalar _tmp192 = _b[0] * _tmp191;
  const Scalar _tmp193 = 2 * _b[2];
  const Scalar _tmp194 = _b[3] * _tmp193;
  const Scalar _tmp195 = _tmp192 + _tmp194;
  const Scalar _tmp196 = _b[0] * _tmp193;
  const Scalar _tmp197 = _b[3] * _tmp191;
  const Scalar _tmp198 = _tmp196 - _tmp197;
  const Scalar _tmp199 = -2 * (_b[1] * _b[1]);
  const Scalar _tmp200 = 1 - 2 * (_b[2] * _b[2]);
  const Scalar _tmp201 = _tmp199 + _tmp200;
  const Scalar _tmp202 = _tmp192 - _tmp194;
  const Scalar _tmp203 = 2 * _b[0] * _b[3];
  const Scalar _tmp204 = _b[2] * _tmp191;
  const Scalar _tmp205 = _tmp203 + _tmp204;
  const Scalar _tmp206 = -2 * (_b[0] * _b[0]);
  const Scalar _tmp207 = _tmp200 + _tmp206;
  const Scalar _tmp208 = _tmp196 + _tmp197;
  const Scalar _tmp209 = -_tmp203 + _tmp204;
  const Scalar _tmp210 = _tmp199 + _tmp206 + 1;

  // Output terms (3)
  Eigen::Matrix<Scalar, 7, 1> _res;

  _res[0] = _tmp4;
  _res[1] = _tmp9;
  _res[2] = _tmp14;
  _res[3] = _tmp19;
  _res[4] = _a[4] + _b[4] * _tmp30 + _b[5] * _tmp24 + _b[6] * _tmp27;
  _res[5] = _a[5] + _b[4] * _tmp31 + _b[5] * _tmp37 + _b[6] * _tmp35;
  _res[6] = _a[6] + _b[4] * _tmp38 + _b[5] * _tmp39 + _b[6] * _tmp40;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _a[2] * _tmp70 + _a[3] * _tmp74 - _tmp60 * _tmp61 - _tmp65 * _tmp66;
    _res_D_a(0, 1) = -_a[2] * _tmp74 + _a[3] * _tmp70 - _tmp60 * _tmp66 + _tmp61 * _tmp65;
    _res_D_a(0, 2) = -_a[0] * _tmp70 + _a[1] * _tmp74 - _tmp60 * _tmp75 + _tmp65 * _tmp76;
    _res_D_a(0, 3) = 0;
    _res_D_a(0, 4) = 0;
    _res_D_a(0, 5) = 0;
    _res_D_a(1, 0) = -_tmp61 * _tmp80 - _tmp66 * _tmp82 + _tmp75 * _tmp84 + _tmp76 * _tmp86;
    _res_D_a(1, 1) = _tmp61 * _tmp82 - _tmp66 * _tmp80 - _tmp75 * _tmp86 + _tmp76 * _tmp84;
    _res_D_a(1, 2) = -_tmp61 * _tmp84 + _tmp66 * _tmp86 - _tmp75 * _tmp80 + _tmp76 * _tmp82;
    _res_D_a(1, 3) = 0;
    _res_D_a(1, 4) = 0;
    _res_D_a(1, 5) = 0;
    _res_D_a(2, 0) = -_tmp61 * _tmp88 - _tmp66 * _tmp89 + _tmp75 * _tmp90 + _tmp76 * _tmp91;
    _res_D_a(2, 1) = _tmp61 * _tmp89 - _tmp66 * _tmp88 - _tmp75 * _tmp91 + _tmp76 * _tmp90;
    _res_D_a(2, 2) = -_tmp61 * _tmp90 + _tmp66 * _tmp91 - _tmp75 * _tmp88 + _tmp76 * _tmp89;
    _res_D_a(2, 3) = 0;
    _res_D_a(2, 4) = 0;
    _res_D_a(2, 5) = 0;
    _res_D_a(3, 0) = -_tmp111 * _tmp61 - _tmp120 * _tmp66 + _tmp127 * _tmp75 + _tmp132 * _tmp76;
    _res_D_a(3, 1) = -_tmp111 * _tmp66 + _tmp120 * _tmp61 + _tmp127 * _tmp76 - _tmp132 * _tmp75;
    _res_D_a(3, 2) = -_tmp111 * _tmp75 + _tmp120 * _tmp76 - _tmp127 * _tmp61 + _tmp132 * _tmp66;
    _res_D_a(3, 3) = _tmp133;
    _res_D_a(3, 4) = _tmp134;
    _res_D_a(3, 5) = _tmp135;
    _res_D_a(4, 0) = -_tmp142 * _tmp61 - _tmp143 * _tmp66 + _tmp144 * _tmp75 + _tmp145 * _tmp76;
    _res_D_a(4, 1) = -_tmp142 * _tmp66 + _tmp143 * _tmp61 + _tmp144 * _tmp76 - _tmp145 * _tmp75;
    _res_D_a(4, 2) = -_tmp142 * _tmp75 + _tmp143 * _tmp76 - _tmp144 * _tmp61 + _tmp145 * _tmp66;
    _res_D_a(4, 3) = _tmp146;
    _res_D_a(4, 4) = _tmp147;
    _res_D_a(4, 5) = _tmp148;
    _res_D_a(5, 0) = -_tmp152 * _tmp61 - _tmp153 * _tmp66 + _tmp154 * _tmp75 + _tmp155 * _tmp76;
    _res_D_a(5, 1) = -_tmp152 * _tmp66 + _tmp153 * _tmp61 + _tmp154 * _tmp76 - _tmp155 * _tmp75;
    _res_D_a(5, 2) = -_tmp152 * _tmp75 + _tmp153 * _tmp76 - _tmp154 * _tmp61 + _tmp155 * _tmp66;
    _res_D_a(5, 3) = _tmp156;
    _res_D_a(5, 4) = _tmp157;
    _res_D_a(5, 5) = _tmp158;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _b[2] * _tmp172 + _b[3] * _tmp176 - _tmp162 * _tmp163 - _tmp167 * _tmp168;
    _res_D_b(0, 1) = -_b[2] * _tmp176 + _b[3] * _tmp172 - _tmp162 * _tmp168 + _tmp163 * _tmp167;
    _res_D_b(0, 2) = -_b[0] * _tmp172 + _b[1] * _tmp176 - _tmp162 * _tmp177 + _tmp167 * _tmp178;
    _res_D_b(0, 3) = 0;
    _res_D_b(0, 4) = 0;
    _res_D_b(0, 5) = 0;
    _res_D_b(1, 0) = -_tmp163 * _tmp180 - _tmp168 * _tmp182 + _tmp177 * _tmp184 + _tmp178 * _tmp186;
    _res_D_b(1, 1) = _tmp163 * _tmp182 - _tmp168 * _tmp180 - _tmp177 * _tmp186 + _tmp178 * _tmp184;
    _res_D_b(1, 2) = -_tmp163 * _tmp184 + _tmp168 * _tmp186 - _tmp177 * _tmp180 + _tmp178 * _tmp182;
    _res_D_b(1, 3) = 0;
    _res_D_b(1, 4) = 0;
    _res_D_b(1, 5) = 0;
    _res_D_b(2, 0) = -_tmp163 * _tmp187 - _tmp168 * _tmp188 + _tmp177 * _tmp189 + _tmp178 * _tmp190;
    _res_D_b(2, 1) = _tmp163 * _tmp188 - _tmp168 * _tmp187 - _tmp177 * _tmp190 + _tmp178 * _tmp189;
    _res_D_b(2, 2) = -_tmp163 * _tmp189 + _tmp168 * _tmp190 - _tmp177 * _tmp187 + _tmp178 * _tmp188;
    _res_D_b(2, 3) = 0;
    _res_D_b(2, 4) = 0;
    _res_D_b(2, 5) = 0;
    _res_D_b(3, 0) = 0;
    _res_D_b(3, 1) = 0;
    _res_D_b(3, 2) = 0;
    _res_D_b(3, 3) = _tmp133 * _tmp201 + _tmp134 * _tmp195 + _tmp135 * _tmp198;
    _res_D_b(3, 4) = _tmp133 * _tmp202 + _tmp134 * _tmp207 + _tmp135 * _tmp205;
    _res_D_b(3, 5) = _tmp133 * _tmp208 + _tmp134 * _tmp209 + _tmp135 * _tmp210;
    _res_D_b(4, 0) = 0;
    _res_D_b(4, 1) = 0;
    _res_D_b(4, 2) = 0;
    _res_D_b(4, 3) = _tmp146 * _tmp201 + _tmp147 * _tmp195 + _tmp148 * _tmp198;
    _res_D_b(4, 4) = _tmp146 * _tmp202 + _tmp147 * _tmp207 + _tmp148 * _tmp205;
    _res_D_b(4, 5) = _tmp146 * _tmp208 + _tmp147 * _tmp209 + _tmp148 * _tmp210;
    _res_D_b(5, 0) = 0;
    _res_D_b(5, 1) = 0;
    _res_D_b(5, 2) = 0;
    _res_D_b(5, 3) = _tmp156 * _tmp201 + _tmp157 * _tmp195 + _tmp158 * _tmp198;
    _res_D_b(5, 4) = _tmp156 * _tmp202 + _tmp157 * _tmp207 + _tmp158 * _tmp205;
    _res_D_b(5, 5) = _tmp156 * _tmp208 + _tmp157 * _tmp209 + _tmp158 * _tmp210;
  }

  return sym::Pose3<Scalar>(_res);
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
