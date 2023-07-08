#ifndef UDPCONNECTOR_H
#define UDPCONNECTOR_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include "Config.h"

class UdpConnector : public QObject
{
    Q_OBJECT
public:
    explicit UdpConnector(QObject *parent = nullptr);
    void initSocket();
public slots:
    void sendToAll(const char *data, int length);

signals:
    void bytesWritten(qint64 bytes);


private:
    QUdpSocket *udpSocket;
};

#endif // UDPCONNECTOR_H
