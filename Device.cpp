#include "Device.h"


Device::Device(const QString &porname, QObject *parent) : QObject(parent) {
    reset();

    // Подключение модуля com-порта
    comport = new ComportConnector(porname, this);
    connect(comport, &ComportConnector::ready, this, &Device::onReceivedByComport);

    // Подключение модуля udp
    udp = new UdpConnector(this);
    connect(this, &Device::transmitByUdp, udp, &UdpConnector::sendToAll);
    connect(udp, &UdpConnector::bytesWritten, this, &Device::deleteMessageFromQueue);
}

void Device::reset(){
    inputStringCounter = 0;
}


void Device::onReceivedByComport(const QString &inputString) {
    if (inputStringCounter >= MAX_STRING_COUNT) return;

    inputStringCounter++;
    auto message = new Message(inputString);
    queue.enqueue(message);

    const char *data = message->encrypt();
    int size = message->size();
    emit transmitByUdp(data, size);
}

void Device::deleteMessageFromQueue() {
    if (queue.head() != nullptr) delete queue.head();
    if (!queue.isEmpty()) queue.dequeue();
}
