#include "pageeight.h"
#include "ui_pageeight.h"

PageEight::PageEight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageEight)
{
    ui->setupUi(this);
}

PageEight::~PageEight()
{
    delete ui;
}

void PageEight::initializePage() {

}
