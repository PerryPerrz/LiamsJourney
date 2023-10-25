#include "pagethree.h"
#include "ui_pagethree.h"

PageThree::PageThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageThree)
{
    ui->setupUi(this);
}

PageThree::~PageThree()
{
    delete ui;
}
