#ifndef PAGEEIGHT_H
#define PAGEEIGHT_H

#include "page.h"

#include <QWidget>

namespace Ui
{
    class PageEight;
}

class PageEight : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageEight(QWidget *parent = 0);
    void initializePage() override;
    void setState(bool isActive) override;
    ~PageEight();

private:
    Ui::PageEight *ui;
    bool isActive;
};

#endif // PAGEEIGHT_H
