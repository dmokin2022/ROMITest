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

signals:

private:
    QString inputString;
    QString outputString;
};

#endif // MESSAGE_H
