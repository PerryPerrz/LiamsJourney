#ifndef PAGEFOUR_H
#define PAGEFOUR_H

#include <QWidget>

namespace Ui {
class PageFour;
}

class PageFour : public QWidget
{
    Q_OBJECT

public:
    explicit PageFour(QWidget *parent = 0);
    ~PageFour();

private:
    Ui::PageFour *ui;
};

#endif // PAGEFOUR_H
