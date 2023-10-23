#ifndef COLLISIONSMANAGER_H
#define COLLISIONSMANAGER_H

#include <QObject>
#include <QLabel>

class CollisionsManager : public QObject
{
    Q_OBJECT
public:
    explicit CollisionsManager(QObject *parent = 0);
    void areLabelsColliding(QLabel *label1, QLabel *label2);

signals:

public slots:
};

#endif // COLLISIONSMANAGER_H
