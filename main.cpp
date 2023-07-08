#include <QCoreApplication>

#include "Message.h"
#include <QDebug>

#include "Device.h"

#define TEST_INPUT_MESSAGE       ".,!?-=+/12345678abcdefghABCDEFGH"
#define TEST_OUTPUT_MESSAGE "HELLO.,!?-=+/23456789bcdefghiBCDEFGHI"

bool testMessage() {
    Message message(TEST_INPUT_MESSAGE);
    QString outputString = message.encryptToQString();
    qDebug() << TEST_INPUT_MESSAGE << "->" << outputString;
    if (outputString == TEST_OUTPUT_MESSAGE) {
        qDebug() << "Coding successfull";
        return true;
    } else {
        qDebug() << "Coding failed";
        return false;
    }
}

#define DEFAULT_COMPORT "COM1"
//#define DEFAULT_COMPORT "/dev/tty"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << QString::number(argc) << QString(argv[0]);

    const char *comPortName = DEFAULT_COMPORT;
    if (argc > 1) {
        comPortName = argv[1];
    }

    Device(QString(comPortName));

    testMessage();

    return a.exec();
}

