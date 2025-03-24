#include "../../include/utils/message.hpp"
#include <random>

namespace utils {

utils::Array generateRandomMessage(std::size_t size) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 1);

  std::vector<int> data(size);
  for (std::size_t i = 0; i < size; i++) {
    data[i] = dis(gen);
  }

  return utils::Array(data);
}

double calculateBER(const utils::Array &a, const utils::Array &b) {
  if (a.size() != b.size()) {
    throw std::invalid_argument("calculateBER: a.size() != b.size()");
  }

  std::size_t size = a.size();
  std::size_t errors = 0;
  for (std::size_t i = 0; i < size; i++) {
    if (a[i] != b[i]) {
      errors++;
    }
  }

  return static_cast<double>(errors) / static_cast<double>(size);
}

} // namespace utils