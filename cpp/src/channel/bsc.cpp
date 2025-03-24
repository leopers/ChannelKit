#include "../../include/channel/bsc.hpp"
#include <random>

namespace channel {

BSC::BSC(double p) : p(p) {}

utils::Array BSC::transmit(const utils::Array &bits) {
  utils::Array received(bits.size());
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  for (size_t i = 0; i < bits.size(); i++) {
    if (dis(gen) < p) {
      received[i] = 1 - bits[i];
    } else {
      received[i] = bits[i];
    }
  }
  return received;
}
} // namespace channel
