#include "pagefour.h"
#include "ui_pagefour.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QLabel>

PageFour::PageFour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageFour)
{
    ui->setupUi(this);

    ClickableLabel *match = this->findChild<ClickableLabel*>("match");
    match->setMoveable(true);

    QLabel *grip = this->findChild<QLabel*>("grip");
    grip->setVisible(false);

    connect(match, &ClickableLabel::moved, this, &PageFour::onCollide);
    connect(match, &ClickableLabel::stopDragAndDrop, this, &PageFour::onStopDragAndDrop);
}

PageFour::~PageFour()
{
    delete ui;
}

 void PageFour::onCollide() {
     Utils utils = Utils();

     ClickableLabel *match = this->findChild<ClickableLabel*>("match");
     QLabel *grip = this->findChild<QLabel*>("grip");

     if (utils.areLabelsColliding(match, grip)) {
         dynamic_cast<MainWindow*>(this->parent()->parent())
                 ->getGestionHaptique()
                 ->startEffect(HapticHandler::SCENE_4);
     } else {
         dynamic_cast<MainWindow*>(this->parent()->parent())
                 ->getGestionHaptique()
                 ->stopEffect(HapticHandler::SCENE_4);
     }
 }

 void PageFour::onStopDragAndDrop() {
     dynamic_cast<MainWindow*>(this->parent()->parent())
             ->getGestionHaptique()
             ->stopEffect(HapticHandler::SCENE_4);
 }

void PageFour::initializePage() {

}
