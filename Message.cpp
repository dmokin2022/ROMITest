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
        auto code =  simbol.unicode();
        if (simbol.isDigit() || simbol.isLetter()) {
            code++;
        }
        QChar newSimbol(code);
        outputString.append(newSimbol);
    }
    return outputString;
}
