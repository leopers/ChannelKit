#include "../../include/utils/matrix.hpp"
#include <vector>

namespace utils {

Matrix::Matrix(const std::vector<std::vector<int>> &d) : matrix(d) {}

std::size_t Matrix::rows() const { return matrix.size(); }

std::size_t Matrix::cols() const {
  return matrix.empty() ? 0 : matrix[0].size();
}

Matrix Matrix::operator*(const Matrix &rhs) const {
  if (cols() != rhs.rows()) {
    throw std::invalid_argument("Matrix::operator*: cols() != rhs.rows()");
  }

  std::size_t m = rows();
  std::size_t n = cols();
  std::size_t p = rhs.cols();

  std::vector<std::vector<int>> result(m, std::vector<int>(p, 0));

  for (std::size_t i = 0; i < m; i++) {
    for (std::size_t j = 0; j < p; j++) {
      int sum = 0;
      for (std::size_t k = 0; k < n; k++) {
        sum += matrix[i][k] * rhs.matrix[k][j];
      }
      result[i][j] = sum % 2;
    }
  }
  return Matrix(result);
}

std::vector<int> operator*(const std::vector<int> &v, const Matrix &rhs) {
  if (v.size() != rhs.rows()) {
    throw std::invalid_argument("operator*: v.size() != rhs.rows()");
  }
  std::size_t n = rhs.rows();
  std::size_t p = rhs.cols();

  std::vector<int> result(p, 0);
  for (std::size_t i = 0; i < p; i++) {
    int sum = 0;
    for (std::size_t j = 0; j < n; j++) {
      sum += v[j] * rhs.matrix[j][i];
    }
    result[i] = sum % 2;
  }
  return result;
}

Matrix Matrix::transpose() const {
  std::vector<std::vector<int>> result(cols(), std::vector<int>(rows(), 0));
  for (std::size_t i = 0; i < rows(); i++) {
    for (std::size_t j = 0; j < cols(); j++) {
      result[j][i] = matrix[i][j];
    }
  }
  return Matrix(result);
}

} // namespace utils