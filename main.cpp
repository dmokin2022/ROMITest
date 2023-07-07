#include <QCoreApplication>

#include "Message.h"
#include <QDebug>

#define TEST_INPUT_MESSAGE       "12345678abcdefghABCDEFGH"
#define TEST_OUTPUT_MESSAGE "HELLO23456789bcdefghiBCDEFGHI"

bool testMessage() {
    Message message(TEST_INPUT_MESSAGE);
    if (message.encryptToQString() == TEST_OUTPUT_MESSAGE) {
        qDebug() << "Coding successfull";
        return true;
    } else {
        qDebug() << "Coding failed";
        return false;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (testMessage()) return 0;
    else return -1;

    return a.exec();
}

