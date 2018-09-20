#ifndef TOOLS_H
#define TOOLS_H

#include <stdint.h>
#include <stdlib.h>
#include <vector>

namespace Tools
{

    uint64_t XpowYmodN(uint64_t x, uint64_t y, uint64_t n);

    uint32_t toInt32FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian);

    uint16_t toInt16FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian);

    std::string getString(const std::vector<uint8_t> &data, int begin, int length, bool binary = false);

    uint64_t gcd(uint64_t n1, uint64_t n2);

    uint64_t egcd(uint64_t a, uint64_t b, uint64_t &x, uint64_t &y);

};

#endif // TOOLS_H
