#ifndef UDPCONNECTOR_H
#define UDPCONNECTOR_H

#include <QObject>
#include <QtNetwork/QUdpSocket>

#define UDP_PORT 1000

class UdpConnector : public QObject
{
    Q_OBJECT
public:
    explicit UdpConnector(QObject *parent = nullptr);
    void initSocket();
public slots:
    void sendToAll(const char *data, int length);

signals:



private:
    QUdpSocket *udpSocket;
};

#endif // UDPCONNECTOR_H
