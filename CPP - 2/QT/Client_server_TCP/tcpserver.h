#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = nullptr);

signals:

public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
};

#endif // TCPSERVER_H
