#ifndef CUSTOM_HPP
#define CUSTOM_HPP

#include "../utils/matrix.hpp"
#include "encoder.hpp"

namespace codecs {

class Custom : public Encoder {
public:
  Custom();
  utils::Array encode(const utils::Array &bits) const override;
  utils::Array decode(const utils::Array &bits) const override;

private:
  utils::Matrix G;
  utils::Matrix H;
};
} // namespace codecs

#endif // CUSTOM_HPP
