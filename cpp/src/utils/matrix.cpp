#include "../../include/utils/matrix.hpp"
#include <vector>

namespace utils {

Array::Array(const std::vector<int> &d) : array(d) {}

Array::Array(std::size_t size) : array(size, 0) {}

std::size_t Array::size() const { return array.size(); }

Array Array::operator+(const Array &rhs) const {
  if (size() != rhs.size()) {
    throw std::invalid_argument("Array::operator+: size() != rhs.size()");
  }

  std::vector<int> result(size());
  for (std::size_t i = 0; i < size(); i++) {
    result[i] = (array[i] + rhs.array[i]) % 2;
  }
  return Array(result);
}

int &Array::operator[](std::size_t i) { return array[i]; }

const int &Array::operator[](std::size_t i) const { return array[i]; }

bool Array::operator==(const Array &rhs) const { return array == rhs.array; }

Array Array::operator()(std::size_t i, std::size_t j) const {
  if (i > j || j >= size()) {
    throw std::out_of_range("Array::operator(): invalid indices");
  }
  std::vector<int> result(j - i + 1);
  for (std::size_t k = i; k <= j; k++) {
    result[k - i] = array[k];
  }
  return Array(result);
}

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

Array operator*(const Array &v, const Matrix &rhs) {
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
  return Array(result);
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

int &Matrix::operator()(std::size_t i, std::size_t j) {
  if (i >= rows() || j >= cols()) {
    throw std::out_of_range("Matrix::operator()(i,j) index out of range");
  }

  return matrix[i][j];
}

Array Matrix::operator()(std::size_t i) { return Array(matrix[i]); }
} // namespace utils