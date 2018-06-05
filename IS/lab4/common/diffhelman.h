#ifndef DIFFHELMAN_H
#define DIFFHELMAN_H

#include "randomgenerator.h"
#include "tools.h"

class DiffHelman
{
public:
    DiffHelman();

    uint64_t secretKey;
    uint64_t publicKey;
    uint64_t G;
    uint64_t P;
    uint64_t key;

    void computePublicKey();
    void computeKey(uint64_t clientKey);
};

#endif // DIFFHELMAN_H
