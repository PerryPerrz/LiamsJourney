#ifndef PAGEONE_H
#define PAGEONE_H

#include <QWidget>

namespace Ui {
class PageOne;
}

class PageOne : public QWidget
{
    Q_OBJECT

public:
    explicit PageOne(QWidget *parent = 0);
    ~PageOne();

public slots :
    void onCollide();
    void onStopDragAndDrop();

private:
    Ui::PageOne *ui;
    bool isWalking;

signals:
    void walk();
};

#endif // PAGEONE_H
