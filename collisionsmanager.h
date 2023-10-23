#ifndef COLLISIONSMANAGER_H
#define COLLISIONSMANAGER_H

#include <QObject>

class CollisionsManager : public QObject
{
    Q_OBJECT
public:
    explicit CollisionsManager(QObject *parent = 0);

signals:

public slots:
};

#endif // COLLISIONSMANAGER_H