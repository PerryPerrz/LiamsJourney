#include "pagefive.h"
#include "ui_pagefive.h"
#include "mainwindow.h"

#include <QLabel>

PageFive::PageFive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageFive)
{
    ui->setupUi(this);
}

PageFive::~PageFive()
{
    delete ui;
}

void PageFive::initializePage() {

}
