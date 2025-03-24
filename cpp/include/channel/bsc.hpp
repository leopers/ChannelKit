#ifndef BSC_HPP
#define BSC_HPP

#include "../utils/matrix.hpp"
#include <vector>
namespace channel {

class BSC {
public:
  BSC(double p);
  utils::Array transmit(const utils::Array &bits);

private:
  double p;
};
} // namespace channel

#endif // BSC_HPP