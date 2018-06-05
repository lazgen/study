#ifndef TOOLS_H
#define TOOLS_H

#include <stdint.h>
#include <stdlib.h>
#include <vector>

#define CRC_SSP_POLYNOMIAL 0x8005 /* x^16 + x^15 + x^2 + 1 */
#define CRC_SSP_SEED 0xFFFF

class Tools
{
public:

    static uint16_t getCrc16(const std::vector<uint8_t> &data, int size, int offset);

    static uint64_t XpowYmodN(uint64_t x, uint64_t y, uint64_t n);

    static uint32_t toInt32FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian);

    static uint16_t toInt16FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian);

    static std::string getString(const std::vector<uint8_t> &data, int begin, int length, bool binary = false);

};

#endif // TOOLS_H
