# ChannelKit 

**ChannelKit** is a telecommunications toolbox written in C++ with Python integration for testing, plotting, and simulation. It focuses mainly on channel encoding and noise modeling.

---

## Features

- Efficient C++ implementations of common coding schemes:
  - Convolutional Codes
  - Block codes
- Channel models:
  - BSC 
- Python utilities for:
  - Bit Error Rate (BER) analysis

---

## Getting Started

### Requirements

- C++17 compiler (GCC/Clang/MSVC)
- Python 3.8+
- [CMake](https://cmake.org/) ≥ 3.15
- Python packages (see `requirements.txt`)

### Build Instructions

```bash
git clone https://github.com/yourusername/channelkit.git
cd channelkit
mkdir build && cd build
cmake ..
make
