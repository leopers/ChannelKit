#include "../../include/codecs/hamming.cpp"
#include <vector>

namespace codecs {

static std::vector<std::vector<int>> Generator = {{1, 0, 0, 0, 1, 1, 1},
                                                  {0, 1, 0, 0, 1, 0, 1},
                                                  {0, 0, 1, 0, 1, 1, 0},
                                                  {0, 0, 0, 1, 0, 1, 1}};

static const std::vector<std::vector<int>> Verificator = {
    {1, 1, 1, 0, 1, 0, 0}, {1, 0, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 0, 0, 1}};

Hamming::Hamming() : G(Generator), H(Verificator) {}

std::vector<int> Hamming::encode(const std::vector<int> &bits) {
  if (bits.size() != 4) {
    throw std::invalid_argument("Hamming::encode: bits.size() != 4");
    return {};
  }

  return bits * G;
}

} // namespace codecs