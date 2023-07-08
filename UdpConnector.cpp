#include "UdpConnector.h"

UdpConnector::UdpConnector(QObject *parent) : QObject(parent) {
    initSocket();
}

void UdpConnector::initSocket() {
    udpSocket = new QUdpSocket(this);
    //udpSocket->bind(QHostAddress::LocalHost, 7755);
    udpSocket->bind(QHostAddress::Broadcast, UDP_PORT);
    //connect(udpSocket, &QUdpSocket::readyRead, this, &UdpConnector::readPendingDatagrams);
    connect(udpSocket, &QUdpSocket::bytesWritten, this, &UdpConnector::bytesWritten);
}

void UdpConnector::sendToAll(const char *data, int length) {
    udpSocket->writeDatagram(data, length, QHostAddress::Broadcast, UDP_PORT);
}

