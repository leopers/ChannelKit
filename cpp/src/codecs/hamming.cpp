#include "../../include/codecs/hamming.hpp"
#include <vector>

namespace codecs {

static const std::vector<std::vector<int>> Generator = {{1, 0, 0, 0, 1, 1, 1},
                                                        {0, 1, 0, 0, 1, 0, 1},
                                                        {0, 0, 1, 0, 1, 1, 0},
                                                        {0, 0, 0, 1, 0, 1, 1}};

static const std::vector<std::vector<int>> Verificator = {
    {1, 1, 1, 0, 1, 0, 0}, {1, 0, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 0, 1}};

Hamming::Hamming() : G(Generator), H(Verificator) {}

utils::Array Hamming::encode(const utils::Array &bits) const {
  if (bits.size() != 4) {
    throw std::invalid_argument("Hamming::encode: bits.size() != 4");
  }

  return bits * G;
}

utils::Array Hamming::decode(const utils::Array &bits) const {
  if (bits.size() != 7) {
    throw std::invalid_argument("Hamming::decode: bits.size() != 7");
  }

  utils::Matrix Ht = H.transpose();
  utils::Array syndrome = bits * Ht;

  utils::Array zerosyndrome({0, 0, 0});
  if (syndrome == zerosyndrome) {
    return bits(0, 4);
  }

  int error = -1;
  for (std::size_t i = 0; i < Ht.rows(); i++) {
    if (Ht(i) == syndrome) {
      error = i;
      break;
    }
  }

  if (error == -1) {
    return bits(0, 4);
  }

  utils::Array corrected = bits;
  corrected[error] = 1 - corrected[error];
  return corrected(0, 4);
}

} // namespace codecs