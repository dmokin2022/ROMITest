#include "Message.h"


Message::Message(const QString &string, QObject *parent) {
   inputString = string;
}

const char *Message::encrypt() {
    return encryptToQString().toStdString().c_str();
}

// Метод для удобства тестирования
QString &Message::encryptToQString() {
    outputString = MESSAGE_HEADER;

    for (auto simbol : inputString) {
        if (simbol.isDigit() || simbol.isLetter()) {
            auto code =  simbol.unicode();
            QChar newSimbol(code + 1);
            outputString.append(newSimbol);
        }
    }
    return outputString;
}
