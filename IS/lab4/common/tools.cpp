#include "tools.h"

#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>

uint16_t Tools::getCrc16(const std::vector<uint8_t> &data, int size, int offset)
{
    uint16_t CRC = CRC_SSP_SEED;
    uint8_t val;

    for (auto it = data.begin() + offset; it != (data.begin() + size + offset) && it != data.end(); ++it)
    {
        val = *it;
        CRC ^= val << 8;
        for (int j = 0; j < 8; j++)
        {
            CRC = CRC & 0x8000 ? static_cast<uint16_t>((CRC << 1) ^ CRC_SSP_POLYNOMIAL)
                               : static_cast<uint16_t>(CRC << 1);
        }
    }
    return CRC;
}

uint64_t Tools::XpowYmodN(uint64_t x, uint64_t y, uint64_t n)
{
    uint64_t num = x;
    uint64_t num2 = 1;
    while (y != 0) {
        if ((y & 1) != 0)
        {
            num2 = num2 * num % n;
        }
        num *= num;
        num %= n;
        y >>= 1;
    }
    return num2;
}

uint32_t Tools::toInt32FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian)
{
    uint32_t result = 0;
    for (uint32_t i = 0; i < 4; i++)
    {
        result += static_cast<uint32_t>(bytes[i + startIndex]) << static_cast<uint32_t>((bigEndian ? ((3 - i) * 8) : (i * 8)));
    }
    return result;
}

uint16_t Tools::toInt16FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian)
{
    uint16_t result = 0;
    for (uint32_t i = 0; i < 2; i++)
    {
        result += static_cast<uint16_t>(bytes[i + startIndex]) << static_cast<uint16_t>((bigEndian ? ((3 - i) * 8) : (i * 8)));
    }
    return result;
}

std::string Tools::getString(const std::vector<uint8_t> &data, int begin, int length, bool binary)
{
    std::string output = "";
    std::vector<uint8_t> d(length);
    std::copy(data.begin() + begin, data.begin() + begin + length, d.begin());

    bool first = true;
    for (uint8_t i : d){
        if (binary){
            std::stringstream stream;
            stream << std::uppercase << std::hex << static_cast<int>(i);
            if (first){
                output += stream.str();
                first = false;
            }
            else{
                output += "-" + stream.str();
            }
        }
        else{
            output += std::to_string(i);
        }
    }
    return output;
}


