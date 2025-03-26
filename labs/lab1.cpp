#include "../include/channel/bsc.hpp"
#include "../include/codecs/custom.hpp"
#include "../include/codecs/hamming.hpp"
#include "../include/utils/message.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
  std::size_t size = 999996;
  std::vector<double> probabilities = {0.5,    0.2,    0.1,     0.05,   0.02,
                                       0.01,   0.005,  0.002,   0.001,  0.0005,
                                       0.0002, 0.0001, 0.00005, 0.00002};

  codecs::Hamming hamming;
  codecs::Custom custom;

  std::ofstream file("../data/lab1.csv", std::ios::app);
  file.close();
  file.open("../data/lab1.csv", std::ios::out | std::ios::trunc);

  for (double p : probabilities) {
    utils::Array message = utils::generateRandomMessage(size);
    utils::Array hDecoded(size);
    utils::Array cDecoded(size);
    channel::BSC bsc(p);

    utils::Array transmittedMsg = bsc.transmit(message);

    for (std::size_t i = 0; i < size; i += 4) {
      utils::Array hEncoded = hamming.encode(message(i, i + 4));
      utils::Array hReceived = bsc.transmit(hEncoded);
      utils::Array hDecodedPart = hamming.decode(hReceived);

      for (std::size_t j = 0; j < 4; j++) {
        hDecoded[i + j] = hDecodedPart[j];
      }
    }

    for (std::size_t i = 0; i < size; i += 6) {
      utils::Array cEncoded = custom.encode(message(i, i + 6));
      utils::Array cReceived = bsc.transmit(cEncoded);
      utils::Array cDecodedPart = custom.decode(cReceived);

      for (std::size_t j = 0; j < 6; j++) {
        cDecoded[i + j] = cDecodedPart[j];
      }
    }

    double ber = utils::calculateBER(message, transmittedMsg);
    double berHamming = utils::calculateBER(message, hDecoded);
    double berCustom = utils::calculateBER(message, cDecoded);

    file << std::fixed << std::setprecision(10) << p << "," << ber << ","
         << berHamming << "," << berCustom << std::endl;
  }

  file.close();
}