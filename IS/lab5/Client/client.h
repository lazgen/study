#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalSocket>

#include "rsa.h"

class QLocalSocket;

class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap keys READ keys NOTIFY keysChanged)

public:
    explicit Client(QObject *parent = nullptr);

    QVariantMap keys() const;

signals:
    void log(const QString &entry);

    void keysChanged(QVariantMap keys);

public slots:
    void start();
    void sendMessage(const QString &message);
    void saveKeys();

private slots:
    void read();
    void error(QLocalSocket::LocalSocketError error);
    void stateChanged(QLocalSocket::LocalSocketState state);

private:
    void setupHandshake(QString &message);

private:
    QLocalSocket *m_socket;
    quint32 m_blockSize;
    RSA m_secure;
};

#endif // SERVER_H
