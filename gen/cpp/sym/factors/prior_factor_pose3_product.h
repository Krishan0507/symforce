// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <geo/pose3.h>

namespace sym {

/**
 * Residual that penalizes the difference between a value and prior (desired / measured value).
 *
 * In vector space terms that would be:
 *     prior - value
 *
 * In lie group terms:
 *     to_tangent(compose(inverse(value), prior))
 *
 * Args:
 *     sqrt_info: Square root information matrix to whiten residual. This can be computed from
 *                a covariance matrix as the cholesky decomposition of the inverse. In the case
 *                of a diagonal it will contain 1/sigma values. Must match the tangent dim.
 *
 */
template <typename Scalar>
void PriorFactorPose3Product(const sym::Pose3<Scalar>& value, const sym::Pose3<Scalar>& prior,
                             const Eigen::Matrix<Scalar, 6, 6>& sqrt_info, const Scalar epsilon,
                             Eigen::Matrix<Scalar, 6, 1>* const res = nullptr,
                             Eigen::Matrix<Scalar, 6, 6>* const jac = nullptr) {
  // Total ops: 987

  // Input arrays
  const Eigen::Matrix<Scalar, 7, 1>& _value = value.Data();
  const Eigen::Matrix<Scalar, 7, 1>& _prior = prior.Data();

  // Intermediate terms (116)
  const Scalar _tmp0 = -_prior[6] + _value[6];
  const Scalar _tmp1 = -_prior[5] + _value[5];
  const Scalar _tmp2 = -_prior[0] * _value[3] - _prior[1] * _value[2] + _prior[2] * _value[1] +
                       _prior[3] * _value[0];
  const Scalar _tmp3 =
      _prior[0] * _value[0] + _prior[1] * _value[1] + _prior[2] * _value[2] + _prior[3] * _value[3];
  const Scalar _tmp4 = (((_tmp3) > 0) - ((_tmp3) < 0));
  const Scalar _tmp5 = 2 * std::min<Scalar>(0, _tmp4) + 1;
  const Scalar _tmp6 = std::fabs(_tmp3);
  const Scalar _tmp7 = 1 - epsilon;
  const Scalar _tmp8 = std::min<Scalar>(_tmp6, _tmp7);
  const Scalar _tmp9 = std::acos(_tmp8);
  const Scalar _tmp10 = 1 - (_tmp8 * _tmp8);
  const Scalar _tmp11 = 2 * _tmp9 / std::sqrt(_tmp10);
  const Scalar _tmp12 = _tmp11 * _tmp5;
  const Scalar _tmp13 = _tmp12 * _tmp2;
  const Scalar _tmp14 =
      _prior[0] * _value[2] - _prior[1] * _value[3] - _prior[2] * _value[0] + _prior[3] * _value[1];
  const Scalar _tmp15 = _tmp12 * _tmp14;
  const Scalar _tmp16 = -_prior[4] + _value[4];
  const Scalar _tmp17 = -_prior[0] * _value[1] + _prior[1] * _value[0] - _prior[2] * _value[3] +
                        _prior[3] * _value[2];
  const Scalar _tmp18 = _tmp12 * _tmp17;
  const Scalar _tmp19 = _tmp12 * sqrt_info(5, 2);
  const Scalar _tmp20 = _tmp17 * sqrt_info(0, 2);
  const Scalar _tmp21 = _tmp4 * ((((-_tmp6 + _tmp7) > 0) - ((-_tmp6 + _tmp7) < 0)) + 1);
  const Scalar _tmp22 = _tmp21 * _tmp8 * _tmp9 / (_tmp10 * std::sqrt(_tmp10));
  const Scalar _tmp23 = _tmp22 * _tmp5;
  const Scalar _tmp24 = _prior[3] * _tmp23;
  const Scalar _tmp25 = _prior[1] * _tmp12;
  const Scalar _tmp26 = _prior[2] * _tmp12;
  const Scalar _tmp27 = _tmp21 / _tmp10;
  const Scalar _tmp28 = _tmp27 * _tmp5;
  const Scalar _tmp29 = _prior[3] * _tmp28;
  const Scalar _tmp30 = _tmp14 * _tmp29;
  const Scalar _tmp31 = _tmp2 * sqrt_info(0, 0);
  const Scalar _tmp32 = _prior[0] * _tmp5;
  const Scalar _tmp33 = _tmp11 * _tmp32;
  const Scalar _tmp34 = _tmp14 * _tmp24;
  const Scalar _tmp35 = _tmp20 * _tmp24 - _tmp20 * _tmp29 + _tmp24 * _tmp31 -
                        _tmp25 * sqrt_info(0, 1) - _tmp26 * sqrt_info(0, 2) - _tmp29 * _tmp31 -
                        _tmp30 * sqrt_info(0, 1) - _tmp33 * sqrt_info(0, 0) +
                        _tmp34 * sqrt_info(0, 1);
  const Scalar _tmp36 = (1.0 / 2.0) * _value[0];
  const Scalar _tmp37 = _prior[3] * _tmp12;
  const Scalar _tmp38 = _prior[2] * _tmp28;
  const Scalar _tmp39 = _tmp17 * _tmp38;
  const Scalar _tmp40 = _prior[2] * _tmp23;
  const Scalar _tmp41 = _tmp14 * _tmp38;
  const Scalar _tmp42 = _tmp14 * _tmp40;
  const Scalar _tmp43 = _tmp20 * _tmp40 - _tmp25 * sqrt_info(0, 0) - _tmp31 * _tmp38 +
                        _tmp31 * _tmp40 + _tmp33 * sqrt_info(0, 1) + _tmp37 * sqrt_info(0, 2) -
                        _tmp39 * sqrt_info(0, 2) - _tmp41 * sqrt_info(0, 1) +
                        _tmp42 * sqrt_info(0, 1);
  const Scalar _tmp44 = (1.0 / 2.0) * _tmp43;
  const Scalar _tmp45 = _prior[1] * _tmp23;
  const Scalar _tmp46 = _prior[1] * _tmp28;
  const Scalar _tmp47 = _tmp14 * _tmp46;
  const Scalar _tmp48 = _tmp14 * _tmp45;
  const Scalar _tmp49 = _tmp20 * _tmp45 - _tmp20 * _tmp46 + _tmp26 * sqrt_info(0, 0) +
                        _tmp31 * _tmp45 - _tmp31 * _tmp46 - _tmp33 * sqrt_info(0, 2) +
                        _tmp37 * sqrt_info(0, 1) - _tmp47 * sqrt_info(0, 1) +
                        _tmp48 * sqrt_info(0, 1);
  const Scalar _tmp50 = (1.0 / 2.0) * _tmp49;
  const Scalar _tmp51 = _tmp27 * _tmp32;
  const Scalar _tmp52 = _tmp22 * _tmp32;
  const Scalar _tmp53 = _tmp14 * _tmp51;
  const Scalar _tmp54 = _tmp14 * _tmp52;
  const Scalar _tmp55 = -_tmp20 * _tmp51 + _tmp20 * _tmp52 + _tmp25 * sqrt_info(0, 2) -
                        _tmp26 * sqrt_info(0, 1) - _tmp31 * _tmp51 + _tmp31 * _tmp52 +
                        _tmp37 * sqrt_info(0, 0) - _tmp53 * sqrt_info(0, 1) +
                        _tmp54 * sqrt_info(0, 1);
  const Scalar _tmp56 = (1.0 / 2.0) * _value[3];
  const Scalar _tmp57 = (1.0 / 2.0) * _value[1];
  const Scalar _tmp58 = (1.0 / 2.0) * _value[2];
  const Scalar _tmp59 = 2 * _value[1] * _value[3];
  const Scalar _tmp60 = 2 * _value[2];
  const Scalar _tmp61 = _tmp60 * _value[0];
  const Scalar _tmp62 = -_tmp59 + _tmp61;
  const Scalar _tmp63 = _tmp60 * _value[3];
  const Scalar _tmp64 = 2 * _value[0];
  const Scalar _tmp65 = _tmp64 * _value[1];
  const Scalar _tmp66 = _tmp63 + _tmp65;
  const Scalar _tmp67 = -2 * (_value[2] * _value[2]);
  const Scalar _tmp68 = -2 * (_value[1] * _value[1]);
  const Scalar _tmp69 = _tmp67 + _tmp68 + 1;
  const Scalar _tmp70 = _tmp64 * _value[3];
  const Scalar _tmp71 = _tmp60 * _value[1];
  const Scalar _tmp72 = _tmp70 + _tmp71;
  const Scalar _tmp73 = 1 - 2 * (_value[0] * _value[0]);
  const Scalar _tmp74 = _tmp67 + _tmp73;
  const Scalar _tmp75 = -_tmp63 + _tmp65;
  const Scalar _tmp76 = _tmp68 + _tmp73;
  const Scalar _tmp77 = -_tmp70 + _tmp71;
  const Scalar _tmp78 = _tmp59 + _tmp61;
  const Scalar _tmp79 = _tmp17 * sqrt_info(1, 2);
  const Scalar _tmp80 = _tmp2 * sqrt_info(1, 0);
  const Scalar _tmp81 = -_tmp25 * sqrt_info(1, 0) + _tmp33 * sqrt_info(1, 1) +
                        _tmp37 * sqrt_info(1, 2) - _tmp38 * _tmp79 - _tmp38 * _tmp80 +
                        _tmp40 * _tmp79 + _tmp40 * _tmp80 - _tmp41 * sqrt_info(1, 1) +
                        _tmp42 * sqrt_info(1, 1);
  const Scalar _tmp82 = _tmp26 * sqrt_info(1, 0) - _tmp33 * sqrt_info(1, 2) +
                        _tmp37 * sqrt_info(1, 1) + _tmp45 * _tmp79 + _tmp45 * _tmp80 -
                        _tmp46 * _tmp79 - _tmp46 * _tmp80 - _tmp47 * sqrt_info(1, 1) +
                        _tmp48 * sqrt_info(1, 1);
  const Scalar _tmp83 = (1.0 / 2.0) * _tmp82;
  const Scalar _tmp84 = _tmp24 * _tmp79 + _tmp24 * _tmp80 - _tmp25 * sqrt_info(1, 1) -
                        _tmp26 * sqrt_info(1, 2) - _tmp29 * _tmp79 - _tmp29 * _tmp80 -
                        _tmp30 * sqrt_info(1, 1) - _tmp33 * sqrt_info(1, 0) +
                        _tmp34 * sqrt_info(1, 1);
  const Scalar _tmp85 = _tmp25 * sqrt_info(1, 2) - _tmp26 * sqrt_info(1, 1) +
                        _tmp37 * sqrt_info(1, 0) - _tmp51 * _tmp79 - _tmp51 * _tmp80 +
                        _tmp52 * _tmp79 + _tmp52 * _tmp80 - _tmp53 * sqrt_info(1, 1) +
                        _tmp54 * sqrt_info(1, 1);
  const Scalar _tmp86 = _tmp17 * sqrt_info(2, 2);
  const Scalar _tmp87 = _tmp2 * sqrt_info(2, 0);
  const Scalar _tmp88 = _tmp26 * sqrt_info(2, 0) - _tmp33 * sqrt_info(2, 2) +
                        _tmp37 * sqrt_info(2, 1) + _tmp45 * _tmp86 + _tmp45 * _tmp87 -
                        _tmp46 * _tmp86 - _tmp46 * _tmp87 - _tmp47 * sqrt_info(2, 1) +
                        _tmp48 * sqrt_info(2, 1);
  const Scalar _tmp89 = (1.0 / 2.0) * _tmp88;
  const Scalar _tmp90 = _tmp24 * _tmp86 + _tmp24 * _tmp87 - _tmp25 * sqrt_info(2, 1) -
                        _tmp26 * sqrt_info(2, 2) - _tmp29 * _tmp86 - _tmp29 * _tmp87 -
                        _tmp30 * sqrt_info(2, 1) - _tmp33 * sqrt_info(2, 0) +
                        _tmp34 * sqrt_info(2, 1);
  const Scalar _tmp91 = -_tmp25 * sqrt_info(2, 0) + _tmp33 * sqrt_info(2, 1) +
                        _tmp37 * sqrt_info(2, 2) - _tmp38 * _tmp87 - _tmp39 * sqrt_info(2, 2) +
                        _tmp40 * _tmp86 + _tmp40 * _tmp87 - _tmp41 * sqrt_info(2, 1) +
                        _tmp42 * sqrt_info(2, 1);
  const Scalar _tmp92 = (1.0 / 2.0) * _tmp91;
  const Scalar _tmp93 = _tmp25 * sqrt_info(2, 2) - _tmp26 * sqrt_info(2, 1) +
                        _tmp37 * sqrt_info(2, 0) - _tmp51 * _tmp86 - _tmp51 * _tmp87 +
                        _tmp52 * _tmp86 + _tmp52 * _tmp87 - _tmp53 * sqrt_info(2, 1) +
                        _tmp54 * sqrt_info(2, 1);
  const Scalar _tmp94 = _tmp17 * sqrt_info(3, 2);
  const Scalar _tmp95 = _tmp2 * sqrt_info(3, 0);
  const Scalar _tmp96 = _tmp2 * _tmp38;
  const Scalar _tmp97 = -_tmp25 * sqrt_info(3, 0) + _tmp33 * sqrt_info(3, 1) +
                        _tmp37 * sqrt_info(3, 2) - _tmp39 * sqrt_info(3, 2) + _tmp40 * _tmp94 +
                        _tmp40 * _tmp95 - _tmp41 * sqrt_info(3, 1) + _tmp42 * sqrt_info(3, 1) -
                        _tmp96 * sqrt_info(3, 0);
  const Scalar _tmp98 = _tmp24 * _tmp94 + _tmp24 * _tmp95 - _tmp25 * sqrt_info(3, 1) -
                        _tmp26 * sqrt_info(3, 2) - _tmp29 * _tmp94 - _tmp29 * _tmp95 -
                        _tmp30 * sqrt_info(3, 1) - _tmp33 * sqrt_info(3, 0) +
                        _tmp34 * sqrt_info(3, 1);
  const Scalar _tmp99 = _tmp26 * sqrt_info(3, 0) - _tmp33 * sqrt_info(3, 2) +
                        _tmp37 * sqrt_info(3, 1) + _tmp45 * _tmp94 + _tmp45 * _tmp95 -
                        _tmp46 * _tmp94 - _tmp46 * _tmp95 - _tmp47 * sqrt_info(3, 1) +
                        _tmp48 * sqrt_info(3, 1);
  const Scalar _tmp100 = _tmp25 * sqrt_info(3, 2) - _tmp26 * sqrt_info(3, 1) +
                         _tmp37 * sqrt_info(3, 0) - _tmp51 * _tmp94 - _tmp51 * _tmp95 +
                         _tmp52 * _tmp94 + _tmp52 * _tmp95 - _tmp53 * sqrt_info(3, 1) +
                         _tmp54 * sqrt_info(3, 1);
  const Scalar _tmp101 = _tmp17 * sqrt_info(4, 2);
  const Scalar _tmp102 = _tmp2 * sqrt_info(4, 0);
  const Scalar _tmp103 = _tmp102 * _tmp23;
  const Scalar _tmp104 = _prior[2] * _tmp103 + _tmp101 * _tmp40 - _tmp25 * sqrt_info(4, 0) +
                         _tmp33 * sqrt_info(4, 1) + _tmp37 * sqrt_info(4, 2) -
                         _tmp39 * sqrt_info(4, 2) - _tmp41 * sqrt_info(4, 1) +
                         _tmp42 * sqrt_info(4, 1) - _tmp96 * sqrt_info(4, 0);
  const Scalar _tmp105 = _prior[1] * _tmp103 + _tmp101 * _tmp45 - _tmp101 * _tmp46 -
                         _tmp102 * _tmp46 + _tmp26 * sqrt_info(4, 0) - _tmp33 * sqrt_info(4, 2) +
                         _tmp37 * sqrt_info(4, 1) - _tmp47 * sqrt_info(4, 1) +
                         _tmp48 * sqrt_info(4, 1);
  const Scalar _tmp106 = _prior[3] * _tmp103 + _tmp101 * _tmp24 - _tmp101 * _tmp29 -
                         _tmp102 * _tmp29 - _tmp25 * sqrt_info(4, 1) - _tmp26 * sqrt_info(4, 2) -
                         _tmp30 * sqrt_info(4, 1) - _tmp33 * sqrt_info(4, 0) +
                         _tmp34 * sqrt_info(4, 1);
  const Scalar _tmp107 = -_tmp101 * _tmp51 + _tmp101 * _tmp52 - _tmp102 * _tmp51 +
                         _tmp102 * _tmp52 + _tmp25 * sqrt_info(4, 2) - _tmp26 * sqrt_info(4, 1) +
                         _tmp37 * sqrt_info(4, 0) - _tmp53 * sqrt_info(4, 1) +
                         _tmp54 * sqrt_info(4, 1);
  const Scalar _tmp108 = _tmp17 * sqrt_info(5, 2);
  const Scalar _tmp109 = _tmp2 * sqrt_info(5, 0);
  const Scalar _tmp110 = -_prior[2] * _tmp19 + _tmp108 * _tmp24 - _tmp108 * _tmp29 +
                         _tmp109 * _tmp24 - _tmp109 * _tmp29 - _tmp25 * sqrt_info(5, 1) -
                         _tmp30 * sqrt_info(5, 1) - _tmp33 * sqrt_info(5, 0) +
                         _tmp34 * sqrt_info(5, 1);
  const Scalar _tmp111 = _prior[3] * _tmp19 + _tmp108 * _tmp40 + _tmp109 * _tmp40 -
                         _tmp25 * sqrt_info(5, 0) + _tmp33 * sqrt_info(5, 1) -
                         _tmp39 * sqrt_info(5, 2) - _tmp41 * sqrt_info(5, 1) +
                         _tmp42 * sqrt_info(5, 1) - _tmp96 * sqrt_info(5, 0);
  const Scalar _tmp112 = _tmp32 * sqrt_info(5, 2);
  const Scalar _tmp113 = _tmp108 * _tmp45 - _tmp108 * _tmp46 + _tmp109 * _tmp45 - _tmp109 * _tmp46 -
                         _tmp11 * _tmp112 + _tmp26 * sqrt_info(5, 0) + _tmp37 * sqrt_info(5, 1) -
                         _tmp47 * sqrt_info(5, 1) + _tmp48 * sqrt_info(5, 1);
  const Scalar _tmp114 = _tmp112 * _tmp17;
  const Scalar _tmp115 = _prior[1] * _tmp19 - _tmp109 * _tmp51 + _tmp109 * _tmp52 +
                         _tmp114 * _tmp22 - _tmp114 * _tmp27 - _tmp26 * sqrt_info(5, 1) +
                         _tmp37 * sqrt_info(5, 0) - _tmp53 * sqrt_info(5, 1) +
                         _tmp54 * sqrt_info(5, 1);

  // Output terms (2)
  if (res != nullptr) {
    Eigen::Matrix<Scalar, 6, 1>& _res = (*res);

    _res(0, 0) = _tmp0 * sqrt_info(0, 5) + _tmp1 * sqrt_info(0, 4) + _tmp13 * sqrt_info(0, 0) +
                 _tmp15 * sqrt_info(0, 1) + _tmp16 * sqrt_info(0, 3) + _tmp18 * sqrt_info(0, 2);
    _res(1, 0) = _tmp0 * sqrt_info(1, 5) + _tmp1 * sqrt_info(1, 4) + _tmp13 * sqrt_info(1, 0) +
                 _tmp15 * sqrt_info(1, 1) + _tmp16 * sqrt_info(1, 3) + _tmp18 * sqrt_info(1, 2);
    _res(2, 0) = _tmp0 * sqrt_info(2, 5) + _tmp1 * sqrt_info(2, 4) + _tmp13 * sqrt_info(2, 0) +
                 _tmp15 * sqrt_info(2, 1) + _tmp16 * sqrt_info(2, 3) + _tmp18 * sqrt_info(2, 2);
    _res(3, 0) = _tmp0 * sqrt_info(3, 5) + _tmp1 * sqrt_info(3, 4) + _tmp13 * sqrt_info(3, 0) +
                 _tmp15 * sqrt_info(3, 1) + _tmp16 * sqrt_info(3, 3) + _tmp18 * sqrt_info(3, 2);
    _res(4, 0) = _tmp0 * sqrt_info(4, 5) + _tmp1 * sqrt_info(4, 4) + _tmp13 * sqrt_info(4, 0) +
                 _tmp15 * sqrt_info(4, 1) + _tmp16 * sqrt_info(4, 3) + _tmp18 * sqrt_info(4, 2);
    _res(5, 0) = _tmp0 * sqrt_info(5, 5) + _tmp1 * sqrt_info(5, 4) + _tmp13 * sqrt_info(5, 0) +
                 _tmp15 * sqrt_info(5, 1) + _tmp16 * sqrt_info(5, 3) + _tmp17 * _tmp19;
  }

  if (jac != nullptr) {
    Eigen::Matrix<Scalar, 6, 6>& _jac = (*jac);

    _jac(0, 0) = -_tmp35 * _tmp36 - _tmp44 * _value[1] + _tmp50 * _value[2] + _tmp55 * _tmp56;
    _jac(0, 1) = -_tmp35 * _tmp57 + _tmp44 * _value[0] + _tmp49 * _tmp56 - _tmp55 * _tmp58;
    _jac(0, 2) = -_tmp35 * _tmp58 + _tmp43 * _tmp56 - _tmp50 * _value[0] + _tmp55 * _tmp57;
    _jac(0, 3) = _tmp62 * sqrt_info(0, 5) + _tmp66 * sqrt_info(0, 4) + _tmp69 * sqrt_info(0, 3);
    _jac(0, 4) = _tmp72 * sqrt_info(0, 5) + _tmp74 * sqrt_info(0, 4) + _tmp75 * sqrt_info(0, 3);
    _jac(0, 5) = _tmp76 * sqrt_info(0, 5) + _tmp77 * sqrt_info(0, 4) + _tmp78 * sqrt_info(0, 3);
    _jac(1, 0) = -_tmp36 * _tmp84 + _tmp56 * _tmp85 - _tmp57 * _tmp81 + _tmp83 * _value[2];
    _jac(1, 1) = _tmp36 * _tmp81 + _tmp56 * _tmp82 - _tmp57 * _tmp84 - _tmp58 * _tmp85;
    _jac(1, 2) = _tmp56 * _tmp81 + _tmp57 * _tmp85 - _tmp58 * _tmp84 - _tmp83 * _value[0];
    _jac(1, 3) = _tmp62 * sqrt_info(1, 5) + _tmp66 * sqrt_info(1, 4) + _tmp69 * sqrt_info(1, 3);
    _jac(1, 4) = _tmp72 * sqrt_info(1, 5) + _tmp74 * sqrt_info(1, 4) + _tmp75 * sqrt_info(1, 3);
    _jac(1, 5) = _tmp76 * sqrt_info(1, 5) + _tmp77 * sqrt_info(1, 4) + _tmp78 * sqrt_info(1, 3);
    _jac(2, 0) = -_tmp36 * _tmp90 + _tmp56 * _tmp93 + _tmp89 * _value[2] - _tmp92 * _value[1];
    _jac(2, 1) = _tmp56 * _tmp88 - _tmp57 * _tmp90 - _tmp58 * _tmp93 + _tmp92 * _value[0];
    _jac(2, 2) = _tmp56 * _tmp91 + _tmp57 * _tmp93 - _tmp58 * _tmp90 - _tmp89 * _value[0];
    _jac(2, 3) = _tmp62 * sqrt_info(2, 5) + _tmp66 * sqrt_info(2, 4) + _tmp69 * sqrt_info(2, 3);
    _jac(2, 4) = _tmp72 * sqrt_info(2, 5) + _tmp74 * sqrt_info(2, 4) + _tmp75 * sqrt_info(2, 3);
    _jac(2, 5) = _tmp76 * sqrt_info(2, 5) + _tmp77 * sqrt_info(2, 4) + _tmp78 * sqrt_info(2, 3);
    _jac(3, 0) = _tmp100 * _tmp56 - _tmp36 * _tmp98 - _tmp57 * _tmp97 + _tmp58 * _tmp99;
    _jac(3, 1) = -_tmp100 * _tmp58 + _tmp36 * _tmp97 + _tmp56 * _tmp99 - _tmp57 * _tmp98;
    _jac(3, 2) = _tmp100 * _tmp57 - _tmp36 * _tmp99 + _tmp56 * _tmp97 - _tmp58 * _tmp98;
    _jac(3, 3) = _tmp62 * sqrt_info(3, 5) + _tmp66 * sqrt_info(3, 4) + _tmp69 * sqrt_info(3, 3);
    _jac(3, 4) = _tmp72 * sqrt_info(3, 5) + _tmp74 * sqrt_info(3, 4) + _tmp75 * sqrt_info(3, 3);
    _jac(3, 5) = _tmp76 * sqrt_info(3, 5) + _tmp77 * sqrt_info(3, 4) + _tmp78 * sqrt_info(3, 3);
    _jac(4, 0) = -_tmp104 * _tmp57 + _tmp105 * _tmp58 - _tmp106 * _tmp36 + _tmp107 * _tmp56;
    _jac(4, 1) = _tmp104 * _tmp36 + _tmp105 * _tmp56 - _tmp106 * _tmp57 - _tmp107 * _tmp58;
    _jac(4, 2) = _tmp104 * _tmp56 - _tmp105 * _tmp36 - _tmp106 * _tmp58 + _tmp107 * _tmp57;
    _jac(4, 3) = _tmp62 * sqrt_info(4, 5) + _tmp66 * sqrt_info(4, 4) + _tmp69 * sqrt_info(4, 3);
    _jac(4, 4) = _tmp72 * sqrt_info(4, 5) + _tmp74 * sqrt_info(4, 4) + _tmp75 * sqrt_info(4, 3);
    _jac(4, 5) = _tmp76 * sqrt_info(4, 5) + _tmp77 * sqrt_info(4, 4) + _tmp78 * sqrt_info(4, 3);
    _jac(5, 0) = -_tmp110 * _tmp36 - _tmp111 * _tmp57 + _tmp113 * _tmp58 + _tmp115 * _tmp56;
    _jac(5, 1) = -_tmp110 * _tmp57 + _tmp111 * _tmp36 + _tmp113 * _tmp56 - _tmp115 * _tmp58;
    _jac(5, 2) = -_tmp110 * _tmp58 + _tmp111 * _tmp56 - _tmp113 * _tmp36 + _tmp115 * _tmp57;
    _jac(5, 3) = _tmp62 * sqrt_info(5, 5) + _tmp66 * sqrt_info(5, 4) + _tmp69 * sqrt_info(5, 3);
    _jac(5, 4) = _tmp72 * sqrt_info(5, 5) + _tmp74 * sqrt_info(5, 4) + _tmp75 * sqrt_info(5, 3);
    _jac(5, 5) = _tmp76 * sqrt_info(5, 5) + _tmp77 * sqrt_info(5, 4) + _tmp78 * sqrt_info(5, 3);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
