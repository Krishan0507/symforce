#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>

#include <symforce/codegen_sparse_matrices/get_diagonal_sparse.h>
#include <symforce/codegen_sparse_matrices/update_sparse_mat.h>


const int DIM = 100;

// TODO(hayk): Use the catch unit testing framework (single header).
#define assertTrue(a)                                      \
  if (!(a)) {                                              \
    std::ostringstream o;                                  \
    o << __FILE__ << ":" << __LINE__ << ": Test failure."; \
    throw std::runtime_error(o.str());                     \
  }

int main(int argc, char** argv) {
    std::cout << "*** Testing sparse matrix codegen function ***" << std::endl;

    // Create and return sparse matrix
    Eigen::Matrix<double, DIM, DIM> dense_mat = Eigen::Matrix<double, DIM, DIM>::Identity();
    Eigen::SparseMatrix<double> sparse_mat = codegen_sparse_matrices::GetDiagonalSparse<double>(dense_mat);
    assertTrue(sparse_mat.nonZeros() == DIM);
    for (int i = 0; i < DIM; ++i) {
      assertTrue(sparse_mat.coeff(i, i) == 1);
    }

    // If a pre-constructed sparse matrix of the correct dimensions is passed, we should only update its data
    codegen_sparse_matrices::UpdateSparseMat<double>(dense_mat, &sparse_mat);
    assertTrue(sparse_mat.nonZeros() == DIM);
    for (int i = 0; i < DIM; ++i) {
      assertTrue(sparse_mat.coeff(i, i) == 2);
    }

    // If an uninitialized sparse matrix pointer is passed, we should return a sparse matrix of the correct dimensions
    Eigen::SparseMatrix<double> new_sparse_mat;
    codegen_sparse_matrices::UpdateSparseMat<double>(dense_mat, &new_sparse_mat);
    assertTrue(new_sparse_mat.nonZeros() == DIM);
    for (int i = 0; i < DIM; ++i) {
      assertTrue(new_sparse_mat.coeff(i, i) == 2);
    }
}
