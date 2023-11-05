#ifndef PAGETHREE_H
#define PAGETHREE_H

#include "page.h"

#include <QWidget>

namespace Ui
{
    class PageThree;
}

class PageThree : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageThree(QWidget *parent = 0);
    void initializePage() override;
    ~PageThree();

public slots:
    void changeLiamState();
    void shotArrow();

private:
    Ui::PageThree *ui;
    int liamState;
};

#endif // PAGETHREE_H
