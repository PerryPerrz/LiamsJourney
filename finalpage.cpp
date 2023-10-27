#include "finalpage.h"
#include "ui_finalpage.h"
#include "mainwindow.h"

#include <QLabel>

FinalPage::FinalPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FinalPage)
{
    ui->setupUi(this);
}

FinalPage::~FinalPage()
{
    delete ui;
}

