#ifndef COMPORTCONNECTOR_H
#define COMPORTCONNECTOR_H

#include <QObject>

class ComportConnector : public QObject
{
    Q_OBJECT
public:
    explicit ComportConnector(QObject *parent = nullptr);

signals:

};

#endif // COMPORTCONNECTOR_H
