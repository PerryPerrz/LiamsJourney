#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QLabel>

class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = 0);

signals:

public slots:
    bool areLabelsColliding(QLabel *a, QLabel *b);
};

#endif // UTILS_H
