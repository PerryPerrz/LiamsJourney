#ifndef PAGESEVEN_H
#define PAGESEVEN_H

#include "page.h"

#include <QWidget>

namespace Ui
{
    class PageSeven;
}

class PageSeven : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageSeven(QWidget *parent = 0);
    void initializePage() override;
    void setState(bool isActive) override;
    ~PageSeven();

public slots:
    void onSpoonMoved();
    void onSpoonReleased();

private:
    Ui::PageSeven *ui;
    int count;
    bool done;
    bool isTriggered;
    bool isActive;
};

#endif // PAGESEVEN_H
