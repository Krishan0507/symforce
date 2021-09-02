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
 * Return the 2dof residual of reprojecting the landmark into the target camera and comparing
 * against the correspondence in the target camera.
 *
 * The landmark is specified as a pixel in the source camera and an inverse range; this means the
 * landmark is fixed in the source camera and always has residual 0 there (this 0 residual is not
 * returned, only the residual in the target camera is returned).
 *
 * The norm of the residual is whitened using the Barron noise model.  Whitening each component of
 * the reprojection error separately would result in rejecting individual components as outliers.
 * Instead, we minimize the whitened norm of the full reprojection error for each point.  See the
 * docstring for `NoiseModel.whiten_norm` for more information on this, and the docstring of
 * `BarronNoiseModel` for more information on the noise model.
 *
 * Args:
 *     source_pose: The pose of the source camera
 *     source_calibration_storage: The storage vector of the source (Linear) camera calibration
 *     target_pose: The pose of the target camera
 *     target_calibration_storage: The storage vector of the target (Linear) camera calibration
 *     source_inverse_range: The inverse range of the landmark in the source camera
 *     source_pixel: The location of the landmark in the source camera
 *     target_pixel: The location of the correspondence in the target camera
 *     weight: The weight of the factor
 *     gnc_mu: The mu convexity parameter for the Barron noise model
 *     gnc_scale: The scale parameter for the Barron noise model
 *     epsilon: Small positive value
 *
 * Outputs:
 *     res: 2dof residual of the reprojection
 *     jacobian: (2x13) jacobian of res wrt args source_pose (6), target_pose (6),
 *               source_inverse_range (1)
 *     hessian: (13x13) Gauss-Newton hessian for args source_pose (6), target_pose (6),
 *              source_inverse_range (1)
 *     rhs: (13x1) Gauss-Newton rhs for args source_pose (6), target_pose (6), source_inverse_range
 *          (1)
 */
template <typename Scalar>
void InverseRangeLandmarkReprojectionErrorFactor(
    const sym::Pose3<Scalar>& source_pose,
    const Eigen::Matrix<Scalar, 4, 1>& source_calibration_storage,
    const sym::Pose3<Scalar>& target_pose,
    const Eigen::Matrix<Scalar, 4, 1>& target_calibration_storage,
    const Scalar source_inverse_range, const Eigen::Matrix<Scalar, 2, 1>& source_pixel,
    const Eigen::Matrix<Scalar, 2, 1>& target_pixel, const Scalar weight, const Scalar gnc_mu,
    const Scalar gnc_scale, const Scalar epsilon, Eigen::Matrix<Scalar, 2, 1>* const res = nullptr,
    Eigen::Matrix<Scalar, 2, 13>* const jacobian = nullptr,
    Eigen::Matrix<Scalar, 13, 13>* const hessian = nullptr,
    Eigen::Matrix<Scalar, 13, 1>* const rhs = nullptr) {
  // Total ops: 1003

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _source_pose = source_pose.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _target_pose = target_pose.Data();

  // Intermediate terms (247)
  const Scalar _tmp0 = std::pow(_target_pose[2], Scalar(2));
  const Scalar _tmp1 = -2 * _tmp0;
  const Scalar _tmp2 = std::pow(_target_pose[1], Scalar(2));
  const Scalar _tmp3 = -2 * _tmp2;
  const Scalar _tmp4 = _tmp1 + _tmp3 + 1;
  const Scalar _tmp5 = _source_pose[4] - _target_pose[4];
  const Scalar _tmp6 = 2 * _target_pose[0];
  const Scalar _tmp7 = _target_pose[2] * _tmp6;
  const Scalar _tmp8 = 2 * _target_pose[3];
  const Scalar _tmp9 = _target_pose[1] * _tmp8;
  const Scalar _tmp10 = -_tmp9;
  const Scalar _tmp11 = _tmp10 + _tmp7;
  const Scalar _tmp12 = _source_pose[6] - _target_pose[6];
  const Scalar _tmp13 = _target_pose[2] * _tmp8;
  const Scalar _tmp14 = _target_pose[1] * _tmp6;
  const Scalar _tmp15 = _tmp13 + _tmp14;
  const Scalar _tmp16 = _source_pose[5] - _target_pose[5];
  const Scalar _tmp17 = _tmp11 * _tmp12 + _tmp15 * _tmp16;
  const Scalar _tmp18 = _tmp17 + _tmp4 * _tmp5;
  const Scalar _tmp19 = 2 * _source_pose[1];
  const Scalar _tmp20 = _source_pose[3] * _tmp19;
  const Scalar _tmp21 = 2 * _source_pose[0] * _source_pose[2];
  const Scalar _tmp22 = -source_calibration_storage(3, 0) + source_pixel(1, 0);
  const Scalar _tmp23 = -source_calibration_storage(2, 0) + source_pixel(0, 0);
  const Scalar _tmp24 = std::pow(
      Scalar(std::pow(_tmp22, Scalar(2)) / std::pow(source_calibration_storage(1, 0), Scalar(2)) +
             std::pow(_tmp23, Scalar(2)) / std::pow(source_calibration_storage(0, 0), Scalar(2)) +
             1),
      Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp25 = _tmp24 * (_tmp20 + _tmp21);
  const Scalar _tmp26 = std::pow(_source_pose[1], Scalar(2));
  const Scalar _tmp27 = -2 * _tmp26;
  const Scalar _tmp28 = std::pow(_source_pose[2], Scalar(2));
  const Scalar _tmp29 = 1 - 2 * _tmp28;
  const Scalar _tmp30 = _tmp23 / source_calibration_storage(0, 0);
  const Scalar _tmp31 = _tmp24 * _tmp30;
  const Scalar _tmp32 = _source_pose[0] * _tmp19;
  const Scalar _tmp33 = 2 * _source_pose[3];
  const Scalar _tmp34 = _source_pose[2] * _tmp33;
  const Scalar _tmp35 = -_tmp34;
  const Scalar _tmp36 = _tmp32 + _tmp35;
  const Scalar _tmp37 = _tmp22 / source_calibration_storage(1, 0);
  const Scalar _tmp38 = _tmp24 * _tmp37;
  const Scalar _tmp39 = _tmp25 + _tmp31 * (_tmp27 + _tmp29) + _tmp36 * _tmp38;
  const Scalar _tmp40 = _source_pose[2] * _tmp19;
  const Scalar _tmp41 = _source_pose[0] * _tmp33;
  const Scalar _tmp42 = -_tmp41;
  const Scalar _tmp43 = _tmp24 * (_tmp40 + _tmp42);
  const Scalar _tmp44 = std::pow(_source_pose[0], Scalar(2));
  const Scalar _tmp45 = -2 * _tmp44;
  const Scalar _tmp46 = _tmp24 * (_tmp32 + _tmp34);
  const Scalar _tmp47 = _tmp30 * _tmp46 + _tmp38 * (_tmp29 + _tmp45) + _tmp43;
  const Scalar _tmp48 = _tmp24 * (_tmp40 + _tmp41);
  const Scalar _tmp49 = -_tmp20;
  const Scalar _tmp50 = _tmp24 * (_tmp21 + _tmp49);
  const Scalar _tmp51 = _tmp24 * (_tmp27 + _tmp45 + 1) + _tmp30 * _tmp50 + _tmp37 * _tmp48;
  const Scalar _tmp52 = _tmp11 * _tmp51 + _tmp15 * _tmp47;
  const Scalar _tmp53 = _tmp18 * source_inverse_range + _tmp39 * _tmp4 + _tmp52;
  const Scalar _tmp54 = std::pow(_target_pose[0], Scalar(2));
  const Scalar _tmp55 = 1 - 2 * _tmp54;
  const Scalar _tmp56 = _tmp3 + _tmp55;
  const Scalar _tmp57 = _tmp7 + _tmp9;
  const Scalar _tmp58 = 2 * _target_pose[1] * _target_pose[2];
  const Scalar _tmp59 = _target_pose[3] * _tmp6;
  const Scalar _tmp60 = -_tmp59;
  const Scalar _tmp61 = _tmp58 + _tmp60;
  const Scalar _tmp62 = _tmp16 * _tmp61 + _tmp5 * _tmp57;
  const Scalar _tmp63 = _tmp12 * _tmp56 + _tmp62;
  const Scalar _tmp64 = _tmp39 * _tmp57 + _tmp47 * _tmp61;
  const Scalar _tmp65 = _tmp51 * _tmp56 + _tmp63 * source_inverse_range + _tmp64;
  const Scalar _tmp66 = std::fabs(_tmp65);
  const Scalar _tmp67 = std::max<Scalar>(_tmp66, epsilon);
  const Scalar _tmp68 = Scalar(1.0) / (_tmp67);
  const Scalar _tmp69 = _tmp68 * target_calibration_storage(0, 0);
  const Scalar _tmp70 = _tmp53 * _tmp69 + target_calibration_storage(2, 0) - target_pixel(0, 0);
  const Scalar _tmp71 = _tmp1 + _tmp55;
  const Scalar _tmp72 = _tmp58 + _tmp59;
  const Scalar _tmp73 = -_tmp13;
  const Scalar _tmp74 = _tmp14 + _tmp73;
  const Scalar _tmp75 = _tmp12 * _tmp72 + _tmp5 * _tmp74;
  const Scalar _tmp76 = _tmp16 * _tmp71 + _tmp75;
  const Scalar _tmp77 = _tmp39 * _tmp74 + _tmp51 * _tmp72;
  const Scalar _tmp78 = _tmp47 * _tmp71 + _tmp76 * source_inverse_range + _tmp77;
  const Scalar _tmp79 = _tmp68 * target_calibration_storage(1, 0);
  const Scalar _tmp80 = _tmp78 * _tmp79 + target_calibration_storage(3, 0) - target_pixel(1, 0);
  const Scalar _tmp81 = std::pow(_tmp70, Scalar(2)) + std::pow(_tmp80, Scalar(2)) + epsilon;
  const Scalar _tmp82 = std::pow(_tmp81, Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp83 = (((_tmp65) > 0) - ((_tmp65) < 0));
  const Scalar _tmp84 = std::sqrt(weight) * std::sqrt(std::max<Scalar>(0, _tmp83));
  const Scalar _tmp85 = Scalar(1.0) / (epsilon - gnc_mu + 1);
  const Scalar _tmp86 = epsilon + std::fabs(_tmp85);
  const Scalar _tmp87 = std::pow(gnc_scale, Scalar(-2));
  const Scalar _tmp88 = _tmp81 * _tmp87 / _tmp86 + 1;
  const Scalar _tmp89 = 2 - _tmp85;
  const Scalar _tmp90 =
      _tmp89 + epsilon * (2 * std::min<Scalar>(0, (((_tmp89) > 0) - ((_tmp89) < 0))) + 1);
  const Scalar _tmp91 = (Scalar(1) / Scalar(2)) * _tmp90;
  const Scalar _tmp92 = std::sqrt(2) * std::sqrt(_tmp86 * (std::pow(_tmp88, _tmp91) - 1) / _tmp90);
  const Scalar _tmp93 = _tmp84 * _tmp92;
  const Scalar _tmp94 = _tmp82 * _tmp93;
  const Scalar _tmp95 = _tmp70 * _tmp94;
  const Scalar _tmp96 = _tmp80 * _tmp94;
  const Scalar _tmp97 = -_tmp32;
  const Scalar _tmp98 = _tmp24 * (_tmp34 + _tmp97) + _tmp25 * _tmp37;
  const Scalar _tmp99 = -_tmp26;
  const Scalar _tmp100 = _tmp28 + _tmp99;
  const Scalar _tmp101 = std::pow(_source_pose[3], Scalar(2));
  const Scalar _tmp102 = -_tmp101;
  const Scalar _tmp103 = _tmp102 + _tmp44;
  const Scalar _tmp104 = _tmp24 * (_tmp100 + _tmp103) + _tmp37 * _tmp43;
  const Scalar _tmp105 = -_tmp40;
  const Scalar _tmp106 = -_tmp44;
  const Scalar _tmp107 = _tmp101 + _tmp106;
  const Scalar _tmp108 = _tmp24 * (_tmp105 + _tmp42) + _tmp38 * (_tmp100 + _tmp107);
  const Scalar _tmp109 = _tmp104 * _tmp61 + _tmp108 * _tmp56 + _tmp57 * _tmp98;
  const Scalar _tmp110 = _tmp83 * ((((_tmp66 - epsilon) > 0) - ((_tmp66 - epsilon) < 0)) + 1) /
                         std::pow(_tmp67, Scalar(2));
  const Scalar _tmp111 = (Scalar(1) / Scalar(2)) * _tmp110;
  const Scalar _tmp112 = _tmp78 * target_calibration_storage(1, 0);
  const Scalar _tmp113 = _tmp111 * _tmp112;
  const Scalar _tmp114 =
      -_tmp109 * _tmp113 + _tmp79 * (_tmp104 * _tmp71 + _tmp108 * _tmp72 + _tmp74 * _tmp98);
  const Scalar _tmp115 = 2 * _tmp80;
  const Scalar _tmp116 = _tmp53 * target_calibration_storage(0, 0);
  const Scalar _tmp117 = _tmp111 * _tmp116;
  const Scalar _tmp118 =
      -_tmp109 * _tmp117 + _tmp69 * (_tmp104 * _tmp15 + _tmp108 * _tmp11 + _tmp4 * _tmp98);
  const Scalar _tmp119 = 2 * _tmp70;
  const Scalar _tmp120 = _tmp114 * _tmp115 + _tmp118 * _tmp119;
  const Scalar _tmp121 = (Scalar(1) / Scalar(2)) * _tmp70;
  const Scalar _tmp122 = _tmp82 * _tmp84 * _tmp87 * std::pow(_tmp88, Scalar(_tmp91 - 1)) / _tmp92;
  const Scalar _tmp123 = _tmp121 * _tmp122;
  const Scalar _tmp124 = _tmp93 / (_tmp81 * std::sqrt(_tmp81));
  const Scalar _tmp125 = _tmp121 * _tmp124;
  const Scalar _tmp126 = _tmp118 * _tmp94 + _tmp120 * _tmp123 - _tmp120 * _tmp125;
  const Scalar _tmp127 = -_tmp28;
  const Scalar _tmp128 = _tmp127 + _tmp26;
  const Scalar _tmp129 = _tmp31 * (_tmp103 + _tmp128) + _tmp50;
  const Scalar _tmp130 = -_tmp21;
  const Scalar _tmp131 =
      _tmp24 * (_tmp101 + _tmp127 + _tmp44 + _tmp99) + _tmp31 * (_tmp130 + _tmp49);
  const Scalar _tmp132 = _tmp31 * (_tmp105 + _tmp41) + _tmp46;
  const Scalar _tmp133 = _tmp129 * _tmp56 + _tmp131 * _tmp57 + _tmp132 * _tmp61;
  const Scalar _tmp134 =
      -_tmp117 * _tmp133 + _tmp69 * (_tmp11 * _tmp129 + _tmp131 * _tmp4 + _tmp132 * _tmp15);
  const Scalar _tmp135 =
      -_tmp113 * _tmp133 + _tmp79 * (_tmp129 * _tmp72 + _tmp131 * _tmp74 + _tmp132 * _tmp71);
  const Scalar _tmp136 = _tmp115 * _tmp135 + _tmp119 * _tmp134;
  const Scalar _tmp137 = _tmp123 * _tmp136 - _tmp125 * _tmp136 + _tmp134 * _tmp94;
  const Scalar _tmp138 = _tmp31 * (_tmp107 + _tmp128) + _tmp38 * (_tmp35 + _tmp97);
  const Scalar _tmp139 = _tmp31 * _tmp36 + _tmp38 * (_tmp102 + _tmp106 + _tmp26 + _tmp28);
  const Scalar _tmp140 = _tmp30 * _tmp48 + _tmp38 * (_tmp130 + _tmp20);
  const Scalar _tmp141 = _tmp111 * (_tmp138 * _tmp61 + _tmp139 * _tmp57 + _tmp140 * _tmp56);
  const Scalar _tmp142 =
      -_tmp112 * _tmp141 + _tmp79 * (_tmp138 * _tmp71 + _tmp139 * _tmp74 + _tmp140 * _tmp72);
  const Scalar _tmp143 =
      -_tmp116 * _tmp141 + _tmp69 * (_tmp11 * _tmp140 + _tmp138 * _tmp15 + _tmp139 * _tmp4);
  const Scalar _tmp144 = _tmp115 * _tmp142 + _tmp119 * _tmp143;
  const Scalar _tmp145 = _tmp123 * _tmp144 - _tmp125 * _tmp144 + _tmp143 * _tmp94;
  const Scalar _tmp146 = _tmp69 * source_inverse_range;
  const Scalar _tmp147 = _tmp146 * _tmp4;
  const Scalar _tmp148 = _tmp117 * source_inverse_range;
  const Scalar _tmp149 = _tmp148 * _tmp57;
  const Scalar _tmp150 = _tmp147 - _tmp149;
  const Scalar _tmp151 = _tmp79 * source_inverse_range;
  const Scalar _tmp152 = _tmp151 * _tmp74;
  const Scalar _tmp153 = _tmp113 * source_inverse_range;
  const Scalar _tmp154 = _tmp153 * _tmp57;
  const Scalar _tmp155 = _tmp152 - _tmp154;
  const Scalar _tmp156 = _tmp115 * _tmp155 + _tmp119 * _tmp150;
  const Scalar _tmp157 = _tmp122 * _tmp156;
  const Scalar _tmp158 = _tmp121 * _tmp157 - _tmp125 * _tmp156 + _tmp150 * _tmp94;
  const Scalar _tmp159 = _tmp148 * _tmp61;
  const Scalar _tmp160 = _tmp146 * _tmp15;
  const Scalar _tmp161 = -_tmp159 + _tmp160;
  const Scalar _tmp162 = _tmp151 * _tmp71;
  const Scalar _tmp163 = _tmp153 * _tmp61;
  const Scalar _tmp164 = _tmp162 - _tmp163;
  const Scalar _tmp165 = _tmp115 * _tmp164 + _tmp119 * _tmp161;
  const Scalar _tmp166 = _tmp123 * _tmp165 - _tmp125 * _tmp165 + _tmp161 * _tmp94;
  const Scalar _tmp167 = _tmp11 * _tmp146;
  const Scalar _tmp168 = _tmp148 * _tmp56;
  const Scalar _tmp169 = _tmp167 - _tmp168;
  const Scalar _tmp170 = _tmp153 * _tmp56;
  const Scalar _tmp171 = _tmp151 * _tmp72;
  const Scalar _tmp172 = -_tmp170 + _tmp171;
  const Scalar _tmp173 = _tmp115 * _tmp172 + _tmp119 * _tmp169;
  const Scalar _tmp174 = _tmp123 * _tmp173 - _tmp125 * _tmp173 + _tmp169 * _tmp94;
  const Scalar _tmp175 = -_tmp58;
  const Scalar _tmp176 = _tmp175 + _tmp60;
  const Scalar _tmp177 = -_tmp14;
  const Scalar _tmp178 = _tmp13 + _tmp177;
  const Scalar _tmp179 = std::pow(_target_pose[3], Scalar(2));
  const Scalar _tmp180 = -_tmp179;
  const Scalar _tmp181 = -_tmp2;
  const Scalar _tmp182 = _tmp0 + _tmp180 + _tmp181 + _tmp54;
  const Scalar _tmp183 =
      _tmp176 * _tmp51 + _tmp178 * _tmp39 + _tmp182 * _tmp47 +
      source_inverse_range * (_tmp12 * _tmp176 + _tmp16 * _tmp182 + _tmp178 * _tmp5);
  const Scalar _tmp184 = _tmp116 * _tmp183;
  const Scalar _tmp185 = _tmp179 + _tmp181;
  const Scalar _tmp186 = -_tmp54;
  const Scalar _tmp187 = _tmp0 + _tmp186;
  const Scalar _tmp188 = _tmp185 + _tmp187;
  const Scalar _tmp189 =
      -_tmp113 * _tmp183 +
      _tmp79 * (_tmp188 * _tmp51 + _tmp64 + source_inverse_range * (_tmp12 * _tmp188 + _tmp62));
  const Scalar _tmp190 = -_tmp110 * _tmp184 * _tmp70 + _tmp115 * _tmp189;
  const Scalar _tmp191 = -_tmp111 * _tmp184 * _tmp94 + _tmp123 * _tmp190 - _tmp125 * _tmp190;
  const Scalar _tmp192 = -_tmp7;
  const Scalar _tmp193 = _tmp10 + _tmp192;
  const Scalar _tmp194 = _tmp175 + _tmp59;
  const Scalar _tmp195 = -_tmp0;
  const Scalar _tmp196 = _tmp195 + _tmp54;
  const Scalar _tmp197 = _tmp180 + _tmp2;
  const Scalar _tmp198 = _tmp196 + _tmp197;
  const Scalar _tmp199 = _tmp185 + _tmp196;
  const Scalar _tmp200 =
      _tmp199 * _tmp39 + _tmp52 + source_inverse_range * (_tmp17 + _tmp199 * _tmp5);
  const Scalar _tmp201 =
      -_tmp117 * _tmp200 +
      _tmp69 * (_tmp193 * _tmp39 + _tmp194 * _tmp47 + _tmp198 * _tmp51 +
                source_inverse_range * (_tmp12 * _tmp198 + _tmp16 * _tmp194 + _tmp193 * _tmp5));
  const Scalar _tmp202 = -_tmp110 * _tmp112 * _tmp200 * _tmp80 + _tmp119 * _tmp201;
  const Scalar _tmp203 = _tmp123 * _tmp202 - _tmp125 * _tmp202 + _tmp201 * _tmp94;
  const Scalar _tmp204 = _tmp179 + _tmp186 + _tmp195 + _tmp2;
  const Scalar _tmp205 =
      _tmp69 * (_tmp204 * _tmp47 + _tmp77 + source_inverse_range * (_tmp16 * _tmp204 + _tmp75));
  const Scalar _tmp206 = _tmp192 + _tmp9;
  const Scalar _tmp207 = _tmp177 + _tmp73;
  const Scalar _tmp208 = _tmp187 + _tmp197;
  const Scalar _tmp209 =
      _tmp79 * (_tmp206 * _tmp51 + _tmp207 * _tmp47 + _tmp208 * _tmp39 +
                source_inverse_range * (_tmp12 * _tmp206 + _tmp16 * _tmp207 + _tmp208 * _tmp5));
  const Scalar _tmp210 = _tmp115 * _tmp209 + _tmp119 * _tmp205;
  const Scalar _tmp211 = _tmp123 * _tmp210 - _tmp125 * _tmp210 + _tmp205 * _tmp94;
  const Scalar _tmp212 = -_tmp147 + _tmp149;
  const Scalar _tmp213 = -_tmp152 + _tmp154;
  const Scalar _tmp214 = _tmp115 * _tmp213 + _tmp119 * _tmp212;
  const Scalar _tmp215 = _tmp123 * _tmp214 - _tmp125 * _tmp214 + _tmp212 * _tmp94;
  const Scalar _tmp216 = _tmp159 - _tmp160;
  const Scalar _tmp217 = -_tmp162 + _tmp163;
  const Scalar _tmp218 = _tmp115 * _tmp217 + _tmp119 * _tmp216;
  const Scalar _tmp219 = _tmp123 * _tmp218 - _tmp125 * _tmp218 + _tmp216 * _tmp94;
  const Scalar _tmp220 = -_tmp167 + _tmp168;
  const Scalar _tmp221 = _tmp170 - _tmp171;
  const Scalar _tmp222 = _tmp115 * _tmp221 + _tmp119 * _tmp220;
  const Scalar _tmp223 = _tmp123 * _tmp222 - _tmp125 * _tmp222 + _tmp220 * _tmp94;
  const Scalar _tmp224 = _tmp111 * _tmp63;
  const Scalar _tmp225 = -_tmp112 * _tmp224 + _tmp76 * _tmp79;
  const Scalar _tmp226 = -_tmp116 * _tmp224 + _tmp18 * _tmp69;
  const Scalar _tmp227 = _tmp115 * _tmp225 + _tmp119 * _tmp226;
  const Scalar _tmp228 = _tmp124 * _tmp227;
  const Scalar _tmp229 = -_tmp121 * _tmp228 + _tmp123 * _tmp227 + _tmp226 * _tmp94;
  const Scalar _tmp230 = (Scalar(1) / Scalar(2)) * _tmp80;
  const Scalar _tmp231 = _tmp122 * _tmp230;
  const Scalar _tmp232 = _tmp124 * _tmp230;
  const Scalar _tmp233 = _tmp114 * _tmp94 + _tmp120 * _tmp231 - _tmp120 * _tmp232;
  const Scalar _tmp234 = _tmp135 * _tmp94 + _tmp136 * _tmp231 - _tmp136 * _tmp232;
  const Scalar _tmp235 = _tmp142 * _tmp94 + _tmp144 * _tmp231 - _tmp144 * _tmp232;
  const Scalar _tmp236 = _tmp155 * _tmp94 - _tmp156 * _tmp232 + _tmp157 * _tmp230;
  const Scalar _tmp237 = _tmp164 * _tmp94 + _tmp165 * _tmp231 - _tmp165 * _tmp232;
  const Scalar _tmp238 = _tmp172 * _tmp94 + _tmp173 * _tmp231 - _tmp173 * _tmp232;
  const Scalar _tmp239 = _tmp190 * _tmp230;
  const Scalar _tmp240 = _tmp122 * _tmp239 - _tmp124 * _tmp239 + _tmp189 * _tmp94;
  const Scalar _tmp241 = -_tmp113 * _tmp200 * _tmp94 + _tmp202 * _tmp231 - _tmp202 * _tmp232;
  const Scalar _tmp242 = _tmp209 * _tmp94 + _tmp210 * _tmp231 - _tmp210 * _tmp232;
  const Scalar _tmp243 = _tmp213 * _tmp94 + _tmp214 * _tmp231 - _tmp214 * _tmp232;
  const Scalar _tmp244 = _tmp217 * _tmp94 + _tmp218 * _tmp231 - _tmp218 * _tmp232;
  const Scalar _tmp245 = _tmp221 * _tmp94 + _tmp222 * _tmp231 - _tmp222 * _tmp232;
  const Scalar _tmp246 = _tmp225 * _tmp94 + _tmp227 * _tmp231 - _tmp228 * _tmp230;

  // Output terms (4)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 2, 1>& _res = (*res);

    _res(0, 0) = _tmp95;
    _res(1, 0) = _tmp96;
  }

  if (jacobian != nullptr) {
    Eigen::Matrix<Scalar, 2, 13>& _jacobian = (*jacobian);

    _jacobian(0, 0) = _tmp126;
    _jacobian(0, 1) = _tmp137;
    _jacobian(0, 2) = _tmp145;
    _jacobian(0, 3) = _tmp158;
    _jacobian(0, 4) = _tmp166;
    _jacobian(0, 5) = _tmp174;
    _jacobian(0, 6) = _tmp191;
    _jacobian(0, 7) = _tmp203;
    _jacobian(0, 8) = _tmp211;
    _jacobian(0, 9) = _tmp215;
    _jacobian(0, 10) = _tmp219;
    _jacobian(0, 11) = _tmp223;
    _jacobian(0, 12) = _tmp229;
    _jacobian(1, 0) = _tmp233;
    _jacobian(1, 1) = _tmp234;
    _jacobian(1, 2) = _tmp235;
    _jacobian(1, 3) = _tmp236;
    _jacobian(1, 4) = _tmp237;
    _jacobian(1, 5) = _tmp238;
    _jacobian(1, 6) = _tmp240;
    _jacobian(1, 7) = _tmp241;
    _jacobian(1, 8) = _tmp242;
    _jacobian(1, 9) = _tmp243;
    _jacobian(1, 10) = _tmp244;
    _jacobian(1, 11) = _tmp245;
    _jacobian(1, 12) = _tmp246;
  }

  if (hessian != nullptr) {
    Eigen::Matrix<Scalar, 13, 13>& _hessian = (*hessian);

    _hessian(0, 0) = std::pow(_tmp126, Scalar(2)) + std::pow(_tmp233, Scalar(2));
    _hessian(0, 1) = 0;
    _hessian(0, 2) = 0;
    _hessian(0, 3) = 0;
    _hessian(0, 4) = 0;
    _hessian(0, 5) = 0;
    _hessian(0, 6) = 0;
    _hessian(0, 7) = 0;
    _hessian(0, 8) = 0;
    _hessian(0, 9) = 0;
    _hessian(0, 10) = 0;
    _hessian(0, 11) = 0;
    _hessian(0, 12) = 0;
    _hessian(1, 0) = _tmp126 * _tmp137 + _tmp233 * _tmp234;
    _hessian(1, 1) = std::pow(_tmp137, Scalar(2)) + std::pow(_tmp234, Scalar(2));
    _hessian(1, 2) = 0;
    _hessian(1, 3) = 0;
    _hessian(1, 4) = 0;
    _hessian(1, 5) = 0;
    _hessian(1, 6) = 0;
    _hessian(1, 7) = 0;
    _hessian(1, 8) = 0;
    _hessian(1, 9) = 0;
    _hessian(1, 10) = 0;
    _hessian(1, 11) = 0;
    _hessian(1, 12) = 0;
    _hessian(2, 0) = _tmp126 * _tmp145 + _tmp233 * _tmp235;
    _hessian(2, 1) = _tmp137 * _tmp145 + _tmp234 * _tmp235;
    _hessian(2, 2) = std::pow(_tmp145, Scalar(2)) + std::pow(_tmp235, Scalar(2));
    _hessian(2, 3) = 0;
    _hessian(2, 4) = 0;
    _hessian(2, 5) = 0;
    _hessian(2, 6) = 0;
    _hessian(2, 7) = 0;
    _hessian(2, 8) = 0;
    _hessian(2, 9) = 0;
    _hessian(2, 10) = 0;
    _hessian(2, 11) = 0;
    _hessian(2, 12) = 0;
    _hessian(3, 0) = _tmp126 * _tmp158 + _tmp233 * _tmp236;
    _hessian(3, 1) = _tmp137 * _tmp158 + _tmp234 * _tmp236;
    _hessian(3, 2) = _tmp145 * _tmp158 + _tmp235 * _tmp236;
    _hessian(3, 3) = std::pow(_tmp158, Scalar(2)) + std::pow(_tmp236, Scalar(2));
    _hessian(3, 4) = 0;
    _hessian(3, 5) = 0;
    _hessian(3, 6) = 0;
    _hessian(3, 7) = 0;
    _hessian(3, 8) = 0;
    _hessian(3, 9) = 0;
    _hessian(3, 10) = 0;
    _hessian(3, 11) = 0;
    _hessian(3, 12) = 0;
    _hessian(4, 0) = _tmp126 * _tmp166 + _tmp233 * _tmp237;
    _hessian(4, 1) = _tmp137 * _tmp166 + _tmp234 * _tmp237;
    _hessian(4, 2) = _tmp145 * _tmp166 + _tmp235 * _tmp237;
    _hessian(4, 3) = _tmp158 * _tmp166 + _tmp236 * _tmp237;
    _hessian(4, 4) = std::pow(_tmp166, Scalar(2)) + std::pow(_tmp237, Scalar(2));
    _hessian(4, 5) = 0;
    _hessian(4, 6) = 0;
    _hessian(4, 7) = 0;
    _hessian(4, 8) = 0;
    _hessian(4, 9) = 0;
    _hessian(4, 10) = 0;
    _hessian(4, 11) = 0;
    _hessian(4, 12) = 0;
    _hessian(5, 0) = _tmp126 * _tmp174 + _tmp233 * _tmp238;
    _hessian(5, 1) = _tmp137 * _tmp174 + _tmp234 * _tmp238;
    _hessian(5, 2) = _tmp145 * _tmp174 + _tmp235 * _tmp238;
    _hessian(5, 3) = _tmp158 * _tmp174 + _tmp236 * _tmp238;
    _hessian(5, 4) = _tmp166 * _tmp174 + _tmp237 * _tmp238;
    _hessian(5, 5) = std::pow(_tmp174, Scalar(2)) + std::pow(_tmp238, Scalar(2));
    _hessian(5, 6) = 0;
    _hessian(5, 7) = 0;
    _hessian(5, 8) = 0;
    _hessian(5, 9) = 0;
    _hessian(5, 10) = 0;
    _hessian(5, 11) = 0;
    _hessian(5, 12) = 0;
    _hessian(6, 0) = _tmp126 * _tmp191 + _tmp233 * _tmp240;
    _hessian(6, 1) = _tmp137 * _tmp191 + _tmp234 * _tmp240;
    _hessian(6, 2) = _tmp145 * _tmp191 + _tmp235 * _tmp240;
    _hessian(6, 3) = _tmp158 * _tmp191 + _tmp236 * _tmp240;
    _hessian(6, 4) = _tmp166 * _tmp191 + _tmp237 * _tmp240;
    _hessian(6, 5) = _tmp174 * _tmp191 + _tmp238 * _tmp240;
    _hessian(6, 6) = std::pow(_tmp191, Scalar(2)) + std::pow(_tmp240, Scalar(2));
    _hessian(6, 7) = 0;
    _hessian(6, 8) = 0;
    _hessian(6, 9) = 0;
    _hessian(6, 10) = 0;
    _hessian(6, 11) = 0;
    _hessian(6, 12) = 0;
    _hessian(7, 0) = _tmp126 * _tmp203 + _tmp233 * _tmp241;
    _hessian(7, 1) = _tmp137 * _tmp203 + _tmp234 * _tmp241;
    _hessian(7, 2) = _tmp145 * _tmp203 + _tmp235 * _tmp241;
    _hessian(7, 3) = _tmp158 * _tmp203 + _tmp236 * _tmp241;
    _hessian(7, 4) = _tmp166 * _tmp203 + _tmp237 * _tmp241;
    _hessian(7, 5) = _tmp174 * _tmp203 + _tmp238 * _tmp241;
    _hessian(7, 6) = _tmp191 * _tmp203 + _tmp240 * _tmp241;
    _hessian(7, 7) = std::pow(_tmp203, Scalar(2)) + std::pow(_tmp241, Scalar(2));
    _hessian(7, 8) = 0;
    _hessian(7, 9) = 0;
    _hessian(7, 10) = 0;
    _hessian(7, 11) = 0;
    _hessian(7, 12) = 0;
    _hessian(8, 0) = _tmp126 * _tmp211 + _tmp233 * _tmp242;
    _hessian(8, 1) = _tmp137 * _tmp211 + _tmp234 * _tmp242;
    _hessian(8, 2) = _tmp145 * _tmp211 + _tmp235 * _tmp242;
    _hessian(8, 3) = _tmp158 * _tmp211 + _tmp236 * _tmp242;
    _hessian(8, 4) = _tmp166 * _tmp211 + _tmp237 * _tmp242;
    _hessian(8, 5) = _tmp174 * _tmp211 + _tmp238 * _tmp242;
    _hessian(8, 6) = _tmp191 * _tmp211 + _tmp240 * _tmp242;
    _hessian(8, 7) = _tmp203 * _tmp211 + _tmp241 * _tmp242;
    _hessian(8, 8) = std::pow(_tmp211, Scalar(2)) + std::pow(_tmp242, Scalar(2));
    _hessian(8, 9) = 0;
    _hessian(8, 10) = 0;
    _hessian(8, 11) = 0;
    _hessian(8, 12) = 0;
    _hessian(9, 0) = _tmp126 * _tmp215 + _tmp233 * _tmp243;
    _hessian(9, 1) = _tmp137 * _tmp215 + _tmp234 * _tmp243;
    _hessian(9, 2) = _tmp145 * _tmp215 + _tmp235 * _tmp243;
    _hessian(9, 3) = _tmp158 * _tmp215 + _tmp236 * _tmp243;
    _hessian(9, 4) = _tmp166 * _tmp215 + _tmp237 * _tmp243;
    _hessian(9, 5) = _tmp174 * _tmp215 + _tmp238 * _tmp243;
    _hessian(9, 6) = _tmp191 * _tmp215 + _tmp240 * _tmp243;
    _hessian(9, 7) = _tmp203 * _tmp215 + _tmp241 * _tmp243;
    _hessian(9, 8) = _tmp211 * _tmp215 + _tmp242 * _tmp243;
    _hessian(9, 9) = std::pow(_tmp215, Scalar(2)) + std::pow(_tmp243, Scalar(2));
    _hessian(9, 10) = 0;
    _hessian(9, 11) = 0;
    _hessian(9, 12) = 0;
    _hessian(10, 0) = _tmp126 * _tmp219 + _tmp233 * _tmp244;
    _hessian(10, 1) = _tmp137 * _tmp219 + _tmp234 * _tmp244;
    _hessian(10, 2) = _tmp145 * _tmp219 + _tmp235 * _tmp244;
    _hessian(10, 3) = _tmp158 * _tmp219 + _tmp236 * _tmp244;
    _hessian(10, 4) = _tmp166 * _tmp219 + _tmp237 * _tmp244;
    _hessian(10, 5) = _tmp174 * _tmp219 + _tmp238 * _tmp244;
    _hessian(10, 6) = _tmp191 * _tmp219 + _tmp240 * _tmp244;
    _hessian(10, 7) = _tmp203 * _tmp219 + _tmp241 * _tmp244;
    _hessian(10, 8) = _tmp211 * _tmp219 + _tmp242 * _tmp244;
    _hessian(10, 9) = _tmp215 * _tmp219 + _tmp243 * _tmp244;
    _hessian(10, 10) = std::pow(_tmp219, Scalar(2)) + std::pow(_tmp244, Scalar(2));
    _hessian(10, 11) = 0;
    _hessian(10, 12) = 0;
    _hessian(11, 0) = _tmp126 * _tmp223 + _tmp233 * _tmp245;
    _hessian(11, 1) = _tmp137 * _tmp223 + _tmp234 * _tmp245;
    _hessian(11, 2) = _tmp145 * _tmp223 + _tmp235 * _tmp245;
    _hessian(11, 3) = _tmp158 * _tmp223 + _tmp236 * _tmp245;
    _hessian(11, 4) = _tmp166 * _tmp223 + _tmp237 * _tmp245;
    _hessian(11, 5) = _tmp174 * _tmp223 + _tmp238 * _tmp245;
    _hessian(11, 6) = _tmp191 * _tmp223 + _tmp240 * _tmp245;
    _hessian(11, 7) = _tmp203 * _tmp223 + _tmp241 * _tmp245;
    _hessian(11, 8) = _tmp211 * _tmp223 + _tmp242 * _tmp245;
    _hessian(11, 9) = _tmp215 * _tmp223 + _tmp243 * _tmp245;
    _hessian(11, 10) = _tmp219 * _tmp223 + _tmp244 * _tmp245;
    _hessian(11, 11) = std::pow(_tmp223, Scalar(2)) + std::pow(_tmp245, Scalar(2));
    _hessian(11, 12) = 0;
    _hessian(12, 0) = _tmp126 * _tmp229 + _tmp233 * _tmp246;
    _hessian(12, 1) = _tmp137 * _tmp229 + _tmp234 * _tmp246;
    _hessian(12, 2) = _tmp145 * _tmp229 + _tmp235 * _tmp246;
    _hessian(12, 3) = _tmp158 * _tmp229 + _tmp236 * _tmp246;
    _hessian(12, 4) = _tmp166 * _tmp229 + _tmp237 * _tmp246;
    _hessian(12, 5) = _tmp174 * _tmp229 + _tmp238 * _tmp246;
    _hessian(12, 6) = _tmp191 * _tmp229 + _tmp240 * _tmp246;
    _hessian(12, 7) = _tmp203 * _tmp229 + _tmp241 * _tmp246;
    _hessian(12, 8) = _tmp211 * _tmp229 + _tmp242 * _tmp246;
    _hessian(12, 9) = _tmp215 * _tmp229 + _tmp243 * _tmp246;
    _hessian(12, 10) = _tmp219 * _tmp229 + _tmp244 * _tmp246;
    _hessian(12, 11) = _tmp223 * _tmp229 + _tmp245 * _tmp246;
    _hessian(12, 12) = std::pow(_tmp229, Scalar(2)) + std::pow(_tmp246, Scalar(2));
  }

  if (rhs != nullptr) {
    Eigen::Matrix<Scalar, 13, 1>& _rhs = (*rhs);

    _rhs(0, 0) = _tmp126 * _tmp95 + _tmp233 * _tmp96;
    _rhs(1, 0) = _tmp137 * _tmp95 + _tmp234 * _tmp96;
    _rhs(2, 0) = _tmp145 * _tmp95 + _tmp235 * _tmp96;
    _rhs(3, 0) = _tmp158 * _tmp95 + _tmp236 * _tmp96;
    _rhs(4, 0) = _tmp166 * _tmp95 + _tmp237 * _tmp96;
    _rhs(5, 0) = _tmp174 * _tmp95 + _tmp238 * _tmp96;
    _rhs(6, 0) = _tmp191 * _tmp95 + _tmp240 * _tmp96;
    _rhs(7, 0) = _tmp203 * _tmp95 + _tmp241 * _tmp96;
    _rhs(8, 0) = _tmp211 * _tmp95 + _tmp242 * _tmp96;
    _rhs(9, 0) = _tmp215 * _tmp95 + _tmp243 * _tmp96;
    _rhs(10, 0) = _tmp219 * _tmp95 + _tmp244 * _tmp96;
    _rhs(11, 0) = _tmp223 * _tmp95 + _tmp245 * _tmp96;
    _rhs(12, 0) = _tmp229 * _tmp95 + _tmp246 * _tmp96;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
