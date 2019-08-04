#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &TCPServer::slotNewConnection);
    if(!mTcpServer->listen(QHostAddress::Any, 6000)){
           qDebug() << "server is not started";
       } else {
           qDebug() << "server is started";
    }
}

void TCPServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();

    mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

    connect(mTcpSocket, &QTcpSocket::readyRead, this, &TCPServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &TCPServer::slotClientDisconnected);
}

void TCPServer::slotServerRead()
{
    qDebug() << "Server_recieving file";
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array = mTcpSocket->readAll();
        QFile file("new.msi");
        file.open(QIODevice::Append);
        mTcpSocket->write(array);
        file.write(array);
    }
}

void TCPServer::slotClientDisconnected()
{
    mTcpSocket->close();
}
