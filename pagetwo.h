#ifndef PAGETWO_H
#define PAGETWO_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class PageTwo;
}

class PageTwo : public QWidget
{
    Q_OBJECT

public:
    explicit PageTwo(QWidget *parent = 0);
    ~PageTwo();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::PageTwo *ui;
};

#endif // PAGETWO_H
