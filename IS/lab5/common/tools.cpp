#include "tools.h"

#include <iostream>
#include <sstream>

#include <string>
#include <algorithm>

namespace Tools {

uint64_t XpowYmodN(uint64_t x, uint64_t y, uint64_t n)
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

uint32_t toInt32FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian)
{
    uint32_t result = 0;
    for (uint32_t i = 0; i < 4; i++)
    {
        result += static_cast<uint32_t>(bytes[i + startIndex]) << static_cast<uint32_t>((bigEndian ? ((3 - i) * 8) : (i * 8)));
    }
    return result;
}

uint16_t toInt16FromBytes(std::vector<uint8_t> bytes, unsigned int startIndex, bool bigEndian)
{
    uint16_t result = 0;
    for (uint32_t i = 0; i < 2; i++)
    {
        result += static_cast<uint16_t>(bytes[i + startIndex]) << static_cast<uint16_t>((bigEndian ? ((3 - i) * 8) : (i * 8)));
    }
    return result;
}

std::string getString(const std::vector<uint8_t> &data, int begin, int length, bool binary)
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

uint64_t gcd(uint64_t n1, uint64_t n2)
{
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

uint64_t egcd(uint64_t a, uint64_t b, uint64_t &x, uint64_t &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    uint64_t x1, y1;
    uint64_t g = egcd(b % a, a , y1, x1);
    x = x1 - static_cast<int64_t>((b / a)) * y1;
    y = y1;
    return g;
}

}

