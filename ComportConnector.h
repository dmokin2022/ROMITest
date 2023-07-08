#ifndef COMPORTCONNECTOR_H
#define COMPORTCONNECTOR_H

#include <QObject>
#include <QTimer>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#define COMPORT_TIMEOUT 5000 //миллисекунды
#define END_OF_STRING_SYMBOL "\r"
#define COMPORT_BITRATE 115200


class ComportConnector : public QObject
{
    Q_OBJECT
public:
    explicit ComportConnector(const QString &comport, QObject *parent = nullptr);

    void initPort(QString portName);
signals:
    void ready(const QString &string);

public slots:
    void onSerialPortDataReceived();

private:
    void output();
    QSerialPort *serialPort;
    QSerialPortInfo serialInfo;
    QTimer *timer;
    QString inputString;


};

#endif // COMPORTCONNECTOR_H
