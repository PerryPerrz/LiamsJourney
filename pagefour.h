#ifndef PAGEFOUR_H
#define PAGEFOUR_H

#include "page.h"

#include <QWidget>

namespace Ui {
class PageFour;
}

class PageFour : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageFour(QWidget *parent = 0);
    void initializePage() override;
    ~PageFour();

private:
    Ui::PageFour *ui;
};

#endif // PAGEFOUR_H
