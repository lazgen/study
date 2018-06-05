#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#define _CRT_RAND_S
#include <stdlib.h>
#include <stdint.h>

class RandomGenerator
{
    enum Primality{
        Composite,
        Pseudoprime
    };

public:
    explicit RandomGenerator();

    static uint64_t maxRandomInteger();

    static uint64_t maxPrimeNumber();

    static uint64_t generateRandomNumber();

    static uint64_t generateRandomPrimeNumber();

private:
    static Primality checkPrimalityMillerRabin(uint64_t n, uint16_t k);
};

#endif // RANDOMNUMBER_H
