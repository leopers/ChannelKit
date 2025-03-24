#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "../utils/matrix.hpp"

namespace codecs {

class Encoder {
public:
  ~Encoder() = default;
  virtual utils::Array encode(const utils::Array &bits) const = 0;
  virtual utils::Array decode(const utils::Array &bits) const = 0;
};

} // namespace codecs

#endif // ENCODER_HPP