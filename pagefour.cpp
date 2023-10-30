#include "pagefour.h"
#include "ui_pagefour.h"
#include "mainwindow.h"

#include <QLabel>

PageFour::PageFour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageFour)
{
    ui->setupUi(this);
}

PageFour::~PageFour()
{
    delete ui;
}

void PageFour::initializePage() {

}
