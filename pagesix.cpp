#include "pagesix.h"
#include "ui_pagesix.h"
#include "mainwindow.h"

#include <QLabel>

PageSix::PageSix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSix)
{
    ui->setupUi(this);
}

PageSix::~PageSix()
{
    delete ui;
}
