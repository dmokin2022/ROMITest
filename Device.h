#ifndef DEVICE_H
#define DEVICE_H


#include "ComportConnector.h"
#include "UdpConnector.h"
#include "Message.h"

#include <QObject>
#include <QQueue>

#include "Config.h"

class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(const QString &porname, QObject *parent = nullptr);

public slots:
    void reset();

private slots:
    void onReceivedByComport(const QString &inputString);
    void deleteMessageFromQueue();
signals:
    void transmitByUdp(const char* data, int length);
private:
    ComportConnector *comport;
    UdpConnector *udp;
    QQueue<Message*> queue;
    int inputStringCounter;
};

#endif // DEVICE_H
