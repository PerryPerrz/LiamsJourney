#ifndef PAGESIX_H
#define PAGESIX_H

#include "page.h"

#include <QWidget>

namespace Ui {
class PageSix;
}

class PageSix : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageSix(QWidget *parent = 0);
    void initializePage() override;
    ~PageSix();

private:
    Ui::PageSix *ui;
};

#endif // PAGESIX_H
