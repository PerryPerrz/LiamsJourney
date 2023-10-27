#ifndef PAGESEVEN_H
#define PAGESEVEN_H

#include <QWidget>

namespace Ui {
class PageSeven;
}

class PageSeven : public QWidget
{
    Q_OBJECT

public:
    explicit PageSeven(QWidget *parent = 0);
    ~PageSeven();

private:
    Ui::PageSeven *ui;
};

#endif // PAGESEVEN_H
