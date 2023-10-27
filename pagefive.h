#ifndef PAGEFIVE_H
#define PAGEFIVE_H

#include <QWidget>

namespace Ui {
class PageFive;
}

class PageFive : public QWidget
{
    Q_OBJECT

public:
    explicit PageFive(QWidget *parent = 0);
    ~PageFive();

private:
    Ui::PageFive *ui;
};

#endif // PAGEFIVE_H
