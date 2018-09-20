#include "server.h"

#include <QtNetwork>
#include <QLocalServer>
#include <QLocalSocket>
#include <QSettings>

#include <QDebug>

Server::Server(QObject *parent)
    : QObject(parent)
    , m_clientConnection(nullptr)
{
    generateKeys();
}

QVariantMap Server::keys() const
{
    return QVariantMap
    {
        {"N", m_secure.N},
        {"D", m_secure.D},
        {"E", m_secure.E}
    };
}

void Server::start()
{
    m_server = new QLocalServer(this);
    if (!m_server->listen("lab5")) {
        emit log(QString("Unable to start the server: %1.")
                 .arg(m_server->errorString()));
        return;
    }

    connect(m_server, &QLocalServer::newConnection, this, &Server::onNewConnection);

    emit log("The server is running.\n"
             "Run the Client now.");


}

void Server::sendMessage(const QString &message)
{
    QByteArray encrypted = m_secure.encrypt(message.toUtf8());
    QByteArray decrypted = m_secure.decrypt(encrypted);
    qDebug() << __FUNCTION__ << "original:" << message;
    qDebug() << __FUNCTION__ << "encrypted:" << encrypted;
    qDebug() << __FUNCTION__ << "decrypted:" << decrypted << QString::fromUtf8(decrypted);

    emit log("original:  " + message);
    emit log("encrypted: " + QString::fromUtf8(encrypted));
    emit log("decrypted: " + QString::fromUtf8(decrypted));
    send(encrypted);
}

void Server::generateKeys()
{
    m_secure.generatePQ();
    m_secure.generateED();

    if(m_clientConnection) {
        handshake();
    }

    emit keysChanged(keys());
}

void Server::saveKeys()
{
    QSettings settings("keys.ini",QSettings::IniFormat);
    settings.setValue("P", m_secure.P);
    settings.setValue("E", m_secure.E);
    settings.setValue("N", m_secure.N);
}

void Server::handshake()
{
    QStringList list;
    list.append("N="+QString::number(m_secure.N));
    list.append("PublicKey="+QString::number(m_secure.D));

    QString s = "handshake:"+list.join(";");
    QByteArray a = s.toUtf8();
    send(a);

    emit log("Publick key sent to client: " + list.join("; "));
}

void Server::send(QByteArray &message)
{
    if(!m_clientConnection)
        return;

    qDebug() << __FUNCTION__ << message;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint32)0;
    out << message;
    out.device()->seek(0);
    out << (quint32)(block.size() - sizeof(quint32));

    m_clientConnection->write(block);
    m_clientConnection->flush();
    //clientConnection->disconnectFromServer();
}

void Server::onNewConnection()
{
    emit log("New connection.");

    m_clientConnection = m_server->nextPendingConnection();
    connect(m_clientConnection, &QLocalSocket::readyRead, this, &Server::onReadyRead);
    connect(m_clientConnection, &QLocalSocket::disconnected, [this](){
        m_clientConnection->deleteLater();
        m_clientConnection = nullptr;
    });

    handshake();
}

void Server::onReadyRead()
{
    QDataStream in(m_clientConnection);
    in.setVersion(QDataStream::Qt_4_0);
    quint32 blockSize = 0;
    // Relies on the fact that QDataStream format streams a quint32 into sizeof(quint32) bytes
    if (m_clientConnection->bytesAvailable() < static_cast<int>(sizeof(quint32)))
        return;
    in >> blockSize;

    if (m_clientConnection->bytesAvailable() < blockSize || in.atEnd())
        return;

    QString message;
    in >> message;

    qDebug() << __FUNCTION__ << message;

    emit log("~"+message);
    emit log("~decrypted: "+ m_secure.decrypt(message));


//    if(message.startsWith("handshake:"))
//        message.remove(0, QString("handshake:").length());

//    QStringList values = message.split("=");
//    if(values.length() == 2 && values.at(0) == "PublicKey") {
//        m_secure.computeKey(values.at(1).toInt());
//        emit keysChanged(keys());
//        qDebug() << "Secret key =" << m_secure.key;
//    }

}
