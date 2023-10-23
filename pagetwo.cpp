#include "pagetwo.h"
#include "ui_pagetwo.h"

#include <QLabel>

PageTwo::PageTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);

    //Define liam moveable
    ClickableLabel *liam = this->findChild<ClickableLabel*>("liam");
    liam->setMoveable(true);
}

PageTwo::~PageTwo()
{
    delete ui;
}
