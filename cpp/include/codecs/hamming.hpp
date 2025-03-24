#ifndef HAMMING_HPP
#define HAMMING_HPP

#include "../utils/matrix.hpp"
#include "encoder.hpp"

namespace codecs {

class Hamming : public Encoder {
public:
  Hamming();
  utils::Array encode(const utils::Array &bits) const override;
  utils::Array decode(const utils::Array &bits) const override;

private:
  utils::Matrix G;
  utils::Matrix H;
};
} // namespace codecs

#endif // HAMMING_HPP