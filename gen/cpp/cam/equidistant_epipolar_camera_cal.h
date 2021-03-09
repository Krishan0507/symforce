//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <ostream>
#include <random>
#include <vector>

#include <Eigen/Dense>
#include <geo/ops/storage_ops.h>

namespace sym {

/**
 * Autogenerated C++ implementation of <class
 * 'symforce.cam.equidistant_epipolar_cal.EquidistantEpipolarCameraCal'>.
 *
 * Equidistant epipolar camera model with parameters [fx, fy, cx, cy].
 * (fx, fy) representing focal length; (cx, cy) representing principal point.
 *
 * See here for more details:
 * http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.473.5861&rep=rep1&type=pdf
 */
template <typename ScalarType>
class EquidistantEpipolarCameraCal {
 public:
  // Typedefs
  using Scalar = ScalarType;
  using Self = EquidistantEpipolarCameraCal<Scalar>;
  using DataVec = Eigen::Matrix<Scalar, 4, 1>;

  // Construct from data vec
  explicit EquidistantEpipolarCameraCal(const DataVec& data) : data_(data) {}

  // Access underlying storage as const
  inline const DataVec& Data() const {
    return data_;
  }

  // --------------------------------------------------------------------------
  // StorageOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t StorageDim() {
    return sym::StorageOps<Self>::StorageDim();
  }

  void ToStorage(Scalar* const vec) const {
    return sym::StorageOps<Self>::ToStorage(*this, vec);
  }

  static EquidistantEpipolarCameraCal FromStorage(const Scalar* const vec) {
    return sym::StorageOps<Self>::FromStorage(vec);
  }

  // --------------------------------------------------------------------------
  // Camera model methods
  // --------------------------------------------------------------------------

  /**
   * Return the focal length.
   */
  Eigen::Matrix<Scalar, 2, 1> FocalLength() const;

  /**
   * Return the principal point.
   */
  Eigen::Matrix<Scalar, 2, 1> PrincipalPoint() const;

  /**
   * Project a 3D point in the camera frame into 2D pixel coordinates.
   *
   * Return:
   *     pixel: (x, y) coordinate in pixels if valid
   *     is_valid: 1 if the operation is within bounds else 0
   *
   */
  Eigen::Matrix<Scalar, 2, 1> PixelFromCameraPoint(const Eigen::Matrix<Scalar, 3, 1>& point,
                                                   const Scalar epsilon,
                                                   Scalar* const is_valid = nullptr) const;

  /**
   * Backproject a 2D pixel coordinate into a 3D ray in the camera frame.
   *
   * Return:
   *     camera_ray: The ray in the camera frame (NOT normalized)
   *     is_valid: 1 if the operation is within bounds else 0
   *
   */
  Eigen::Matrix<Scalar, 3, 1> CameraRayFromPixel(const Eigen::Matrix<Scalar, 2, 1>& pixel,
                                                 const Scalar epsilon,
                                                 Scalar* const is_valid = nullptr) const;

  // --------------------------------------------------------------------------
  // General Helpers
  // --------------------------------------------------------------------------

  bool IsApprox(const Self& b, const Scalar tol) const {
    // isApprox is multiplicative so we check the norm for the exact zero case
    // https://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ae8443357b808cd393be1b51974213f9c
    if (b.Data() == DataVec::Zero()) {
      return Data().norm() < tol;
    }

    return Data().isApprox(b.Data(), tol);
  }

  template <typename ToScalar>
  EquidistantEpipolarCameraCal<ToScalar> Cast() const {
    return EquidistantEpipolarCameraCal<ToScalar>(Data().template cast<ToScalar>());
  }

  bool operator==(const EquidistantEpipolarCameraCal& rhs) const {
    return data_ == rhs.Data();
  }

  // Included from "custom_methods/equidistant_epipolar_camera_cal.h.jinja":

 protected:
  DataVec data_;
};

// Shorthand for scalar types
using EquidistantEpipolarCameraCald = EquidistantEpipolarCameraCal<double>;
using EquidistantEpipolarCameraCalf = EquidistantEpipolarCameraCal<float>;

}  // namespace sym

// Externs to reduce duplicate instantiation
extern template class sym::EquidistantEpipolarCameraCal<double>;
extern template class sym::EquidistantEpipolarCameraCal<float>;

// Print definitions
std::ostream& operator<<(std::ostream& os, const sym::EquidistantEpipolarCameraCal<double>& a);
std::ostream& operator<<(std::ostream& os, const sym::EquidistantEpipolarCameraCal<float>& a);

// Concept implementations for this class
#include "./ops/equidistant_epipolar_camera_cal/storage_ops.h"
