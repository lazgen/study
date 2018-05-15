#include "diffhelman.h"

#include <QRandomGenerator>

DiffHelman::DiffHelman()
    : secretKey(simpleRand())
    , G(0)
    , P(0)
{

}

void DiffHelman::computePublicKey()
{
    unsigned long long x = static_cast<unsigned long long>(pow(G,secretKey));
    publicKey = x % P;
}

void DiffHelman::computeKey(int clientKey)
{
    unsigned long long x = static_cast<unsigned long long>(pow(clientKey,secretKey));
    key = x % P;
}

int DiffHelman::simpleRand()
{
    return QRandomGenerator::global()->bounded(1, 50);
}
