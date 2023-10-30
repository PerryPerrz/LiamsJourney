#include "pageseven.h"
#include "ui_pageseven.h"
#include "mainwindow.h"

#include <QLabel>

PageSeven::PageSeven(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSeven)
{
    ui->setupUi(this);
}

PageSeven::~PageSeven()
{
    delete ui;
}

void PageSeven::initializePage() {

}
