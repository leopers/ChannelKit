#include "../include/channel/bsc.hpp"
#include "../include/codecs/hamming.hpp"
#include "../include/utils/message.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  std::size_t size = 1000000;
  std::vector<double> probabilities = {0.5,    0.2,    0.1,     0.05,   0.02,
                                       0.01,   0.005,  0.002,   0.001,  0.0005,
                                       0.0002, 0.0001, 0.00005, 0.00002};

  codecs::Hamming hamming;

  for (double p : probabilities) {
    utils::Array message = utils::generateRandomMessage(size);
    channel::BSC bsc(p);
    utils::Array decoded(size);

    utils::Array transmitedMsg = bsc.transmit(message);

    for (std::size_t i = 0; i < size; i += 4) {
      utils::Array encoded = hamming.encode(message(i, i + 4));
      utils::Array received = bsc.transmit(encoded);
      utils::Array decodedPart = hamming.decode(received);

      for (std::size_t j = 0; j < 4; j++) {
        decoded[i + j] = decodedPart[j];
      }
    }

    double ber = utils::calculateBER(message, transmitedMsg);
    double berHamming = utils::calculateBER(message, decoded);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "p = " << p << ", BER = " << ber
              << ", BER with Hamming = " << berHamming << std::endl;
  }
}