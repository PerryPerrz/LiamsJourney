#ifndef PAGEFOUR_H
#define PAGEFOUR_H

#include "page.h"

#include <QWidget>

namespace Ui
{
    class PageFour;
}

class PageFour : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageFour(QWidget *parent = 0);
    void initializePage() override;
    void setState(bool isActive) override;
    ~PageFour();

public slots:
    void onCollide();
    void onStopDragAndDrop();

private:
    Ui::PageFour *ui;
    bool isTriggered;
    bool isActive;
};

#endif // PAGEFOUR_H
