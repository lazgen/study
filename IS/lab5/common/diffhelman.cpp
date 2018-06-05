#include "diffhelman.h"

DiffHelman::DiffHelman()
    : secretKey(RandomGenerator::generateRandomPrimeNumber())
    , G(0)
    , P(0)
{
}

void DiffHelman::computePublicKey()
{
    publicKey = Tools::XpowYmodN(G,secretKey,P);
}

void DiffHelman::computeKey(uint64_t clientKey)
{
    key = Tools::XpowYmodN(clientKey,secretKey,P);
}
