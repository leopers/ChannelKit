#ifndef HAMMING_HPP
#define HAMMING_HPP

#include "../utils/matrix.hpp"
#include <vector>

namespace codecs {

class Hamming {
public:
  Hamming();
  std::vector<int> encode(const std::vector<int> &bits);
  std::vector<int> decode(const std::vector<int> &bits);

private:
  utils::Matrix G;
  utils::Matrix H;
};
} // namespace codecs

#endif // HAMMING_HPP