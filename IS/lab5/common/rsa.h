#ifndef RSA_H
#define RSA_H

#include "randomgenerator.h"
#include "tools.h"
#include <QString>

class RSA
{
public:
    RSA();

    void generatePQ();
    void generateED();

    QByteArray encrypt(QByteArray data);
    QByteArray decrypt(QByteArray data);

    QString encrypt(const QString &text);
    QString decrypt(const QString &text);

//private:
    uint64_t P;
    uint64_t Q;
    uint64_t N;
    uint64_t K;

    uint64_t D;
    uint64_t E;
};

#endif // RSA_H
