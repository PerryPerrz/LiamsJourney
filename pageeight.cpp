#include "pageeight.h"
#include "ui_pageeight.h"
#include "clickablelabel.h"
#include "mainwindow.h"

/**
 * @brief Constructor of the class PageEight
 * @param parent
 */
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

/**
 * @brief Destructor of the class PageEight
 */
PageEight::~PageEight()
{
    delete ui;
}

/**
 * @brief Initialize the page
 */
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

/**
 * @brief Set the state of the page
 * @param isActive
 */
void PageEight::setState(bool isActive)
{
    this->isActive = isActive;
}
