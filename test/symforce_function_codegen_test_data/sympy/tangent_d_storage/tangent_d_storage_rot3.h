// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>
#include <geo/rot3.h>

namespace sym {

/**
 * Computes the jacobian of the tangent space around an element with respect to the storage space of
 * that element.
 *
 */
template <typename Scalar>
Eigen::Matrix<Scalar, 3, 4> Tangent_D_Storage(const sym::Rot3<Scalar>& a, const Scalar epsilon) {
  // Total ops: 7

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (7)
  const Scalar _tmp0 = 2 * _a[3];
  const Scalar _tmp1 = 2 * _a[2];
  const Scalar _tmp2 = 2 * _a[1];
  const Scalar _tmp3 = -_tmp2;
  const Scalar _tmp4 = 2 * _a[0];
  const Scalar _tmp5 = -_tmp4;
  const Scalar _tmp6 = -_tmp1;

  // Output terms (1)
  Eigen::Matrix<Scalar, 3, 4> _res;

  _res(0, 0) = _tmp0;
  _res(0, 1) = _tmp1;
  _res(0, 2) = _tmp3;
  _res(0, 3) = _tmp5;
  _res(1, 0) = _tmp6;
  _res(1, 1) = _tmp0;
  _res(1, 2) = _tmp4;
  _res(1, 3) = _tmp3;
  _res(2, 0) = _tmp2;
  _res(2, 1) = _tmp5;
  _res(2, 2) = _tmp0;
  _res(2, 3) = _tmp6;

  return _res;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
