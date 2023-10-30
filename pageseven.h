#ifndef PAGESEVEN_H
#define PAGESEVEN_H

#include "page.h"

#include <QWidget>

namespace Ui {
class PageSeven;
}

class PageSeven : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageSeven(QWidget *parent = 0);
    void initializePage() override;
    ~PageSeven();

private:
    Ui::PageSeven *ui;
};

#endif // PAGESEVEN_H
