#include "../include/codecs/hamming.hpp"
#include <cassert>
#include <iostream>

int main() {
  // Create the Hamming(7,4) codec
  codecs::Hamming hamming;

  // Test all possible 4-bit messages
  for (int m = 0; m < 16; m++) {
    // Convert integer 'm' to a 4-bit Array
    utils::Array message(4);
    for (int bit = 0; bit < 4; bit++) {
      message[bit] = ((m >> bit) & 1) ? 1 : 0;
    }

    // Encode into a 7-bit codeword
    utils::Array codeword = hamming.encode(message);

    // Now flip *two bits* in the codeword and check if decoding recovers the
    // message (We expect it to fail, because Hamming(7,4) cannot correct
    // double-bit errors)
    for (int i = 0; i < 7; i++) {
      for (int j = i + 1; j < 7; j++) {
        // Make a copy of the correct codeword
        utils::Array corrupted = codeword;

        // Flip bits i and j
        corrupted[i] = 1 - corrupted[i];
        corrupted[j] = 1 - corrupted[j];

        // Decode
        utils::Array decoded = hamming.decode(corrupted);

        // This assertion will FAIL for at least one pair (i,j),
        // because the code cannot reliably correct 2-bit errors.
        // We intentionally force it to fail to demonstrate the limitation.
        assert(decoded == message && "Hamming(7,4) cannot correct 2-bit "
                                     "errors, so this test should fail.");
      }
    }
  }

  std::cout
      << "If you see this message, somehow the code corrected 2-bit errors "
         "for all pairs, which should not happen!"
      << std::endl;
  return 0;
}
