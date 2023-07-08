#include "ComportConnector.h"
#include <QDebug>

ComportConnector::ComportConnector(const QString &comport, QObject *parent) : QObject(parent) {
    initPort(comport);
    timer = new QTimer();

    connect(timer, &QTimer::timeout, this, [this]() {
        output();
    });
}

void ComportConnector::initPort(QString portName) {
    serialPort = new QSerialPort;
    serialPort->setPortName(portName);     // имя последовательного порта
    serialPort->setBaudRate(COMPORT_BITRATE);    // Скорость бода
    serialPort->setDataBits(QSerialPort::Data8);     // Data Bit.
    serialPort->setParity(QSerialPort::NoParity);    //Контрольная цифра
    serialPort->setStopBits(QSerialPort::OneStop);   // остановка
    serialPort->setFlowControl(QSerialPort::NoFlowControl); // Управление потоком обычно бесполезно

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug()<< "Serial port" << portName << "was open, read/write mode";
    } else {
        qDebug()<< "Serial port port open error" << portName << serialPort->errorString();
        serialPort->clearError();
    }

    // Настройка обработчика сигнала по приёму данных
    connect(serialPort, &QSerialPort::readyRead, this, &ComportConnector::onSerialPortDataReceived);
}

void ComportConnector::onSerialPortDataReceived() {
    if (serialPort->bytesAvailable()) {
        timer->start(COMPORT_TIMEOUT);
        const QByteArray recv_data = serialPort->readAll();
        QString inputSymbols = QString::fromUtf8(recv_data);
        qDebug() << "Получено из COM-порта:" << inputSymbols;

        if (inputSymbols.contains(END_OF_STRING_SYMBOL)) {
            inputSymbols.remove(END_OF_STRING_SYMBOL);
            inputString.append(inputSymbols);
            output();
            return;
        }

        inputString.append(inputSymbols);
    }
}


void ComportConnector::output() {
    if (!inputString.isEmpty()) emit ready(inputString);
}

