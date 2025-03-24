#ifndef HAMMING_HPP
#define HAMMING_HPP

#include "../utils/matrix.hpp"
#include <vector>

namespace codecs {

class Hamming {
public:
  Hamming();
  utils::Array encode(const utils::Array &bits);
  utils::Array decode(const utils::Array &bits);

private:
  utils::Matrix G;
  utils::Matrix H;
};
} // namespace codecs

#endif // HAMMING_HPP