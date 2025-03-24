#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

namespace utils {

class Array {
public:
  std::vector<int> array;
  Array(const std::vector<int> &d);
  Array(std::size_t size);
  std::size_t size() const;

  Array operator+(const Array &rhs) const;

  int &operator[](std::size_t i);

  const int &operator[](std::size_t i) const;

  bool operator==(const Array &rhs) const;

  Array operator()(std::size_t i, std::size_t j) const;
};
class Matrix {
public:
  std::vector<std::vector<int>> matrix;
  Matrix(const std::vector<std::vector<int>> &d);
  std::size_t rows() const;
  std::size_t cols() const;

  Matrix operator*(const Matrix &rhs) const;

  friend Array operator*(const Array &v, const Matrix &rhs);

  Matrix transpose() const;

  int &operator()(std::size_t i, std::size_t j);

  Array operator()(std::size_t i);
};
} // namespace utils
#endif // MATRIX_HPP