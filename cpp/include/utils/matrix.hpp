#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

namespace utils {
class Matrix {
public:
  std::vector<std::vector<int>> matrix;
  Matrix(const std::vector<std::vector<int>> &d);
  std::size_t rows() const;
  std::size_t cols() const;

  Matrix operator*(const Matrix &rhs) const;

  friend std::vector<int> operator*(const std::vector<int> &v,
                                    const Matrix &rhs);

  Matrix transpose() const;
};
} // namespace utils
#endif // MATRIX_HPP