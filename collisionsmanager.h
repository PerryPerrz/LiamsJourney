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
    void addObject(QLabel *label);

signals:
    void collision();

public slots:

private:
};

#endif // COLLISIONSMANAGER_H
