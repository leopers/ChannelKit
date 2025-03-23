#ifndef BSC_HPP
#define BSC_HPP

#include <vector>

namespace channel {

class BSC {
public:
  BSC(double p);
  std::vector<int> transmit(const std::vector<int> &bits);

private:
  double p;
};
} // namespace channel

#endif