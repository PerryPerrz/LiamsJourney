#ifndef PAGETHREE_H
#define PAGETHREE_H

#include <QWidget>

namespace Ui {
class PageThree;
}

class PageThree : public QWidget
{
    Q_OBJECT

public:
    explicit PageThree(QWidget *parent = 0);
    ~PageThree();

public slots:
    void changeLiamState();
    void shotArrow();

private:
    Ui::PageThree *ui;
    int liamState;
};

#endif // PAGETHREE_H
