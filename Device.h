#ifndef DEVICE_H
#define DEVICE_H


#include "ComportConnector.h"
#include "UdpConnector.h"
#include "Message.h"

#include <QObject>
#include <QQueue>

class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(const QString &porname, QObject *parent = nullptr);

private slots:
    void onReceivedByComport(const QString &inputString);
    void deleteMessageFromQueue();
signals:
    void transmitByUdp(const char* data, int length);
private:
    ComportConnector *comport;
    UdpConnector *udp;
    QQueue<Message*> queue;    // Очередь не потребуется так как QUdpSocket создаёт собственную очередь на отправку
};

#endif // DEVICE_H
