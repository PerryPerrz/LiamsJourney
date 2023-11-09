#ifndef PAGEFIVE_H
#define PAGEFIVE_H

#include "page.h"

#include <QWidget>

namespace Ui
{
    class PageFive;
}

class PageFive : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageFive(QWidget *parent = 0);
    void initializePage() override;
    void setState(bool isActive) override;
    ~PageFive();

public slots:
    void onLiamMouved();
    void onStopDragAndDrop();

private:
    Ui::PageFive *ui;
    bool areEffectsActive;
    bool isActive;
};

#endif // PAGEFIVE_H
