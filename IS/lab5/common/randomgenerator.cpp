#include "randomgenerator.h"
#include "tools.h"

RandomGenerator::RandomGenerator()
{
}

uint64_t RandomGenerator::maxRandomInteger()
{
    return 32768;//2147483648;
}

uint64_t RandomGenerator::maxPrimeNumber()
{
    return 1217; // 32768;//2147483648;
}

uint64_t RandomGenerator::generateRandomNumber()
{
    uint32_t num = 0;
    rand_s(&num);
    uint64_t result = num;
    result <<= 32;
    rand_s(&num);
    result |= num;
    return result;
}

uint64_t RandomGenerator::generateRandomPrimeNumber()
{
    auto num = generateRandomNumber();
    num %= maxPrimeNumber();
    if ((num & 1) == 0)
    {
        num += 1;
    }
    while (checkPrimalityMillerRabin(num, 5) == Primality::Composite) {
        num += 2;
    }
    return num;
}

RandomGenerator::Primality RandomGenerator::checkPrimalityMillerRabin(uint64_t n, uint16_t k)
{
    uint16_t s = 0;
    uint64_t t = n - 1;
    while ((t & 1) == 0) {
        t >>= 1;
        s++;
    }
    for (uint16_t i = 0; i < k; i++)
    {
        auto a = generateRandomNumber();
        a %= n - 1;//!
        auto x = Tools::XpowYmodN(a, t, n);
        if (x == 1 || x == n - 1)
            continue;
        Primality prime = Primality::Composite;
        for (uint16_t j = 0; j < s - 1; j++)
        {
            x = Tools::XpowYmodN(x, 2, n);
            if (x == 1){
                return Primality::Composite;
            }
            if (x == n - 1){
                prime = Primality::Pseudoprime;
                break;
            }
        }
        if (prime == Primality::Composite)
            return prime;
    }
    return Primality::Pseudoprime;
}
