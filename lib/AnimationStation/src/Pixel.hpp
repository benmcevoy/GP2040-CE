#ifndef PIXEL_HPP_
#define PIXEL_HPP_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

struct Pixel {
  uint8_t index;                  // The pixel index
  uint32_t mask;                  // Used to detect per-pixel lighting
  std::vector<uint8_t> positions; // The actual LED indexes on the chain

  static uint16_t getPixelCount(std::vector<Pixel> pixels) {
    uint16_t count = 0;
    for (int i = 0; i != pixels.size(); i++)
      count += pixels[i].positions.size();

    return count;
  }
};

inline bool operator==(const Pixel &lhs, const Pixel &rhs) {
  return lhs.index == rhs.index;
}

#endif
