//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./storage_ops.h"

namespace sym {
namespace rot3 {

template <typename ScalarType>
void StorageOps<ScalarType>::ToStorage(const sym::Rot3<ScalarType>& a, ScalarType* out) {
  assert(out != nullptr);
  std::copy_n(a.Data().data(), a.StorageDim(), out);
}

template <typename ScalarType>
sym::Rot3<ScalarType> StorageOps<ScalarType>::FromStorage(const ScalarType* data) {
  assert(data != nullptr);
  return sym::Rot3<ScalarType>(Eigen::Map<const typename sym::Rot3<ScalarType>::DataVec>(data));
}

}  // namespace rot3
}  // namespace sym

// Explicit instantiation
template struct sym::rot3::StorageOps<double>;
template struct sym::rot3::StorageOps<float>;
