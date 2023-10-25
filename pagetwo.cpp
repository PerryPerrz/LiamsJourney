#include "pagetwo.h"
#include "ui_pagetwo.h"
#include "mainwindow.h"

#include <QLabel>

PageTwo::PageTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);

    //Define liam moveable
    ClickableLabel *liam = this->findChild<ClickableLabel*>("liam");
    liam->setMoveable(false);

    // Hidde zone of ruche
    ClickableLabel *ruche = this->findChild<ClickableLabel*>("ruche");
    ruche->setMoveable(false);

    connect(ruche, &ClickableLabel::clicked,
            dynamic_cast<MainWindow*>(this->parent()),
            &MainWindow::nextPage);
}

PageTwo::~PageTwo()
{
    delete ui;
}
