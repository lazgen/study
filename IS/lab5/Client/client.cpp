#include "client.h"

#include <QtNetwork>
#include <QDebug>
#include <QSettings>

Client::Client(QObject *parent)
    : QObject(parent)
{

}

QVariantMap Client::keys() const
{
    return QVariantMap
    {
        {"N", m_secure.N},
        {"D", m_secure.D}
    };
}

void Client::start()
{
    m_socket = new QLocalSocket(this);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(m_socket, SIGNAL(error(QLocalSocket::LocalSocketError)),
            this, SLOT(error(QLocalSocket::LocalSocketError)));

    connect(m_socket, &QLocalSocket::stateChanged, this, &Client::stateChanged);

    emit log("The client is running.\n"
             "Try to connect to server.");

    m_blockSize = 0;

    m_socket->connectToServer("lab5");

}

void Client::read()
{
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_4_0);

    if (m_blockSize == 0) {
        // Relies on the fact that QDataStream format streams a quint32 into sizeof(quint32) bytes
        if (m_socket->bytesAvailable() < static_cast<int>(sizeof(quint32)))
            return;
        in >> m_blockSize;
    }

    if (m_socket->bytesAvailable() < m_blockSize || in.atEnd())
        return;

    QByteArray data;
    in >> data;

    QString message = QString::fromUtf8(data);
    QString decrypted = QString::fromUtf8(m_secure.decrypt(data));

    qDebug() << __FUNCTION__ << "message:" << message << data;
    qDebug() << __FUNCTION__ << "decrypted:" << decrypted;

    emit log("~recieved:  "+ message);
    emit log("~decrypted: "+ decrypted);

    m_blockSize = 0;

    if(message.startsWith("handshake:"))
        setupHandshake(message);

}

void Client::sendMessage(const QString &message)
{
    if(!m_socket)
        return;

    qDebug() << __FUNCTION__ << message;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint32)0;
    out << message;
    out.device()->seek(0);
    out << (quint32)(block.size() - sizeof(quint32));

    m_socket->write(block);
    m_socket->flush();
}

void Client::saveKeys()
{
    QSettings settings("keys.ini",QSettings::IniFormat);
    settings.setValue("D", m_secure.E);
    settings.setValue("N", m_secure.N);
}

void Client::error(QLocalSocket::LocalSocketError error)
{
    QString errorString;
    switch (error) {
    case QLocalSocket::ServerNotFoundError:
        errorString = tr("The host was not found. Please check the "
                         "host name and port settings.");
        break;
    case QLocalSocket::ConnectionRefusedError:
        errorString = tr("The connection was refused by the peer. "
                         "Make sure the fortune server is running, "
                         "and check that the host name and port "
                         "settings are correct.");
        break;
    case QLocalSocket::PeerClosedError:
        errorString = tr("The remote socket closed the connection. "
                         "Note that the client socket (i.e., this socket) "
                         "will be closed after the remote close notification has been sent");
        break;
    default:
        errorString = tr("The following error occurred: %1.")
                .arg(m_socket->errorString());
    }

    emit log(errorString);
}

void Client::stateChanged(QLocalSocket::LocalSocketState state)
{
    QString stateString("Connection state: ");
    switch (state) {
    case QLocalSocket::UnconnectedState:
        stateString += tr("The socket is not connected.");
        break;
    case QLocalSocket::ConnectingState:
        stateString += tr("The socket has started establishing a connection.");
        break;
    case QLocalSocket::ConnectedState:
        stateString += tr("A connection is established.");
        break;
    case QLocalSocket::ClosingState:
        stateString += tr("The socket is about to close (data may still be waiting to be written).");
        break;
    }

    emit log(stateString);
}

void Client::setupHandshake(QString &message)
{
    if(message.startsWith("handshake:"))
        message.remove(0, QString("handshake:").length());

    QStringList list = message.split(";");
    for(QString data : list)
    {
        QStringList values = data.split("=");
        if(values.length() != 2)
            continue;

        if(values.at(0) == "N")
            m_secure.N = values.at(1).toULongLong();
        else if(values.at(0) == "PublicKey")
            m_secure.D = values.at(1).toULongLong();
    }

    emit keysChanged(keys());
}

















