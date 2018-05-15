#ifndef DIFFHELMAN_H
#define DIFFHELMAN_H

class DiffHelman
{
public:
    DiffHelman();

    int secretKey;
    int publicKey;
    int G;
    int P;
    int key;

    void computePublicKey();
    void computeKey(int clientKey);
    int simpleRand();
};

#endif // DIFFHELMAN_H
