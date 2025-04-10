#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
namespace utils {

class Node {
public:
  std::vector<int> connections;
  int sum_connections;
  int bit;
  int position;

private:
  bool check_connection(int n);
};
} // namespace utils
#endif // NODE_HPP