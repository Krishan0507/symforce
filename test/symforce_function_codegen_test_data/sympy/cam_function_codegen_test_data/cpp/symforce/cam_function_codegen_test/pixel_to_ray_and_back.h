// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

namespace cam_function_codegen_test {

/**
 * Transform a given pixel into a ray and project the ray back to
 * pixel coordinates. Input and output should match.
 *
 */
template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> PixelToRayAndBack(const Eigen::Matrix<Scalar, 2, 1>& pixel,
                                              const sym::LinearCameraCal<Scalar>& cam,
                                              const Scalar epsilon) {
  // Total ops: 8

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _cam = cam.Data();

  // Intermediate terms (1)
  const Scalar _tmp0 = 1.0 / (std::max<Scalar>(1, epsilon));

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res(0, 0) = _cam[2] + _tmp0 * (-_cam[2] + pixel(0, 0));
  _res(1, 0) = _cam[3] + _tmp0 * (-_cam[3] + pixel(1, 0));

  return _res;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace cam_function_codegen_test
