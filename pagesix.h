#ifndef PAGESIX_H
#define PAGESIX_H

#include <QWidget>

namespace Ui {
class PageSix;
}

class PageSix : public QWidget
{
    Q_OBJECT

public:
    explicit PageSix(QWidget *parent = 0);
    ~PageSix();

private:
    Ui::PageSix *ui;
};

#endif // PAGESIX_H
