#ifndef LDPC_HPP
#define LDPC_HPP

#include "codecs/encoder.hpp"
#include "utils/matrix.hpp"
#include "utils/node.hpp"
#include <list>
#include <vector>

namespace codecs {

class Ldpc : public Encoder {
public:
  Ldpc(int N, int dv, int dc);
  utils::Array encode(const utils::Array &bits) const override;
  utils::Array decode(const utils::Array &bits) const override;

private:
  int N;
  int dv;
  int dc;

  std::vector<utils::Node> CND;
  std::vector<utils::Node> VND;

  void generate_graph();
};

class NodeV : public utils::Node {
private:
  void add_connections();
  void calculate_sum();
};

class NodeC : public utils::Node {
private:
  void add_connections();
  void calculate_intentions();
};
} // namespace codecs
#endif // LDPC_HPP