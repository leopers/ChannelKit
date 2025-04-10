#include "codecs/ldpc.hpp"
#include <random>
#include <vector>

namespace codecs {

Ldpc::Ldpc(int N, int dv, int dc) {
  N = N;
  dv = dv;
  dc = dc;

  generate_graph();
}

void Ldpc::generate_graph() {
  std::random_device rd;
  std::mt19937 gen(rd());
  int M = N * dv / dc;
  std::uniform_int_distribution<> dist(0, M - 1);

  CND.resize(M);
  VND.resize(N);

  for (auto node : VND) {
    for (int i = 0; i < dv; ++i) {
      int m = dist(gen);
      if () {
        --i;
        continue;
      }
    }
  }
}
} // namespace codecs