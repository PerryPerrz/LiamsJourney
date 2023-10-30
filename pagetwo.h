#ifndef PAGETWO_H
#define PAGETWO_H

#include "page.h"

#include <QWidget>
#include <QMouseEvent>
#include <QTimer>

namespace Ui {
class PageTwo;
}

class PageTwo : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageTwo(QWidget *parent = 0);
    void initializePage() override;
    ~PageTwo();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    Ui::PageTwo *ui;
};

#endif // PAGETWO_H
