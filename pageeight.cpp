#include "pageeight.h"
#include "ui_pageeight.h"
#include "clickablelabel.h"
#include "mainwindow.h"

PageEight::PageEight(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::PageEight)
{
    ui->setupUi(this);

    ClickableLabel *nextButton = this->findChild<ClickableLabel *>("nextButton");

    connect(nextButton, &ClickableLabel::clicked,
            dynamic_cast<MainWindow *>(this->parent()),
            &MainWindow::nextPage);
    setState(false);
}

PageEight::~PageEight()
{
    delete ui;
}

void PageEight::initializePage()
{
    dynamic_cast<MainWindow *>(this->parent()->parent())
        ->getSoundHandler()
        ->stopSound(SoundHandler::SCENE_9);

    dynamic_cast<MainWindow *>(this->parent()->parent())
        ->getSoundHandler()
        ->startSound(SoundHandler::SCENE_10);

    setState(true);
}

void PageEight::setState(bool isActive)
{
    this->isActive = isActive;
}
