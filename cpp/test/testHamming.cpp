#include "../include/codecs/hamming.hpp" // Adjust include path as needed
#include <cassert>
#include <iostream>

int main() {
  // Instantiate your Hamming(7,4) codec
  codecs::Hamming hamming;

  // We'll test all 16 possible 4-bit messages (0..15).
  for (int m = 0; m < 16; m++) {
    // Convert integer 'm' into a 4-bit Array (LSB is array[0] or however you
    // prefer).
    utils::Array message(4);
    for (int bit = 0; bit < 4; bit++) {
      // Extract bit 'bit' of 'm'
      int mask = 1 << bit; // 1 << 0 => 1, 1 << 1 => 2, etc.
      message[bit] = (m & mask) ? 1 : 0;
    }

    // Encode the 4-bit message into a 7-bit codeword
    utils::Array codeword = hamming.encode(message);
    // Decode immediately (no error)
    utils::Array decoded = hamming.decode(codeword);

    // Check that decoding a correct codeword recovers the original message
    assert(decoded.size() == 4 && "Decoded message must be 4 bits.");
    for (std::size_t i = 0; i < 4; i++) {
      assert(decoded[i] == message[i] && "Decode mismatch with no error.");
    }

    // Now test single-bit errors in the codeword
    for (int errPos = 0; errPos < 7; errPos++) {
      // Copy the codeword
      utils::Array corrupted = codeword;
      // Flip the bit at errPos
      corrupted[errPos] = 1 - corrupted[errPos];

      // Decode the corrupted codeword
      utils::Array decodedErr = hamming.decode(corrupted);

      // Check that it still decodes to the original 4-bit message
      assert(decodedErr.size() == 4 && "Decoded message must be 4 bits.");
      for (std::size_t i = 0; i < 4; i++) {
        assert(decodedErr[i] == message[i] &&
               "Decode mismatch with single-bit error.");
      }
    }
  }

  std::cout << "All Hamming(7,4) tests passed successfully!" << std::endl;
  return 0;
}
