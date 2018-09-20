#include "rsa.h"

RSA::RSA()
{
}

void RSA::generatePQ()
{
    P = RandomGenerator::generateRandomPrimeNumber() % RandomGenerator::maxPrimeNumber();
    Q = RandomGenerator::generateRandomPrimeNumber() % RandomGenerator::maxPrimeNumber();
    N = P * Q;
    K = (P - 1) * (Q - 1);
}

void RSA::generateED()
{
    uint64_t x, y;
    D = RandomGenerator::generateRandomPrimeNumber() % RandomGenerator::maxPrimeNumber();

    while (Tools::egcd(D, K, x, y) != 1 || x < 0)
    {
        D = RandomGenerator::generateRandomPrimeNumber() % RandomGenerator::maxPrimeNumber();
    }

    E = (x % K + K) % K;
}

QByteArray RSA::encrypt(QByteArray data)
{
    QByteArray encrypted;
    for (auto ch : data)
    {
        encrypted += QString::number(Tools::XpowYmodN(static_cast<uint64_t>(ch), E, N));
        encrypted += ' ';
    }
    return encrypted;
}

QByteArray RSA::decrypt(QByteArray data)
{
    QByteArray decrypted;
    auto list = data.split(' ');
    list.removeLast();
    for (auto word : list)
    {
        char s = static_cast<char>(Tools::XpowYmodN(word.toULongLong(), D, N));
        decrypted += s;
    }
    return decrypted;
}

QString RSA::encrypt(const QString &text)
{
    QString result;
    std::for_each(text.constBegin(), text.constEnd(), [this, &result](const QChar ch){
        result.append(static_cast<uint16_t>(Tools::XpowYmodN(static_cast<uint64_t>(ch.unicode()), E, N)));
    });
    return result;
}

QString RSA::decrypt(const QString &text)
{
    QString result;
    std::for_each(text.constBegin(), text.constEnd(), [this, &result](const QChar ch){
        result.append(static_cast<uint16_t>(Tools::XpowYmodN(static_cast<uint64_t>(ch.unicode()), D, N)));
    });
    return result;
}

