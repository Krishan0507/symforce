//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./rot2.h"

// Explicit instantiation
template class sym::Rot2<double>;
template class sym::Rot2<float>;

// Print implementations
std::ostream& operator<<(std::ostream& os, const sym::Rot2d& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<Rot2d " << a.Data().transpose().format(fmt) << ">";
  return os;
}
std::ostream& operator<<(std::ostream& os, const sym::Rot2f& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<Rot2f " << a.Data().transpose().format(fmt) << ">";
  return os;
}

// --------------------------------------------------------------------------
// Custom generated methods
// --------------------------------------------------------------------------

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 2> sym::Rot2<Scalar>::ToRotationMatrix() const {
  // Total ops: 1

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 2> _res;

  _res(0, 0) = _self[0];
  _res(0, 1) = -_self[1];
  _res(1, 0) = _self[1];
  _res(1, 1) = _self[0];

  return _res;
}
