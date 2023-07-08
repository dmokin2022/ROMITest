#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

#define MESSAGE_HEADER "HELLO"

class Message : public QObject
{
    Q_OBJECT
public:
    explicit Message(const QString &string, QObject *parent = nullptr);

    const char *encrypt();
    QString &encryptToQString();
    int size();

signals:

private:
    QString inputString;
    QString outputString;
    int outputStringSize;
};

#endif // MESSAGE_H
