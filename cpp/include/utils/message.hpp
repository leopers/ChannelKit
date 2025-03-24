#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "matrix.hpp"
#include <random>

namespace utils {

utils::Array generateRandomMessage(std::size_t size);

double calculateBER(const utils::Array &a, const utils::Array &b);
} // namespace utils

#endif // MESSAGE_HPP