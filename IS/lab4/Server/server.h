#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QVariantMap>
#include "diffhelman.h"

class QLocalServer;
class QLocalSocket;

class Server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap keys READ keys NOTIFY keysChanged)

public:
    explicit Server(QObject *parent = nullptr);

    QVariantMap keys() const;

signals:
    void log(const QString &entry);

    void keysChanged(QVariantMap keys);

public slots:
    void start();
    void sendMessage(const QString &message);
    void generateKeys();
    void saveKeys();

private:
    void handshake();

private slots:
    void onNewConnection();
    void onReadyRead();

private:
    QLocalServer *m_server;
    QLocalSocket *m_clientConnection;
    DiffHelman m_secure;
};

#endif // SERVER_H
