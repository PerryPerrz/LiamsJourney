#include "pagethree.h"
#include "ui_pagethree.h"
#include "clickablelabel.h"
#include "utils.h"
#include "mainwindow.h"

#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QTimer>

PageThree::PageThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageThree)
{
    ui->setupUi(this);

    this->liamState = 0;    // Start position of liam

    ClickableLabel *arrow = this->findChild<ClickableLabel*>("arrow");
    arrow->setMoveable(true);
    arrow->setRestriction("x");

    connect(arrow, &ClickableLabel::moved, this, &PageThree::changeLiamState);
    connect(arrow, &ClickableLabel::stopDragAndDrop, this, &PageThree::shotArrow);

   QLabel *secondPos = this->findChild<QLabel*>("secondPos");
   secondPos->setVisible(false);
   QLabel *thirdPos =  this->findChild<QLabel*>("thirdPos");
   thirdPos->setVisible(false);
}

PageThree::~PageThree()
{
    delete ui;
}

/**
  * @brief Change the background related to the position of the arrow during
  * the drang and drop event
  */
 void PageThree::changeLiamState() {
     dynamic_cast<MainWindow*>(this->parent()->parent())
             ->getGestionHaptique()
             ->startEffect(HapticHandler::SCENE_3);
   ClickableLabel *arrow = this->findChild<ClickableLabel*>("arrow");
    QLabel *secondPos = this->findChild<QLabel*>("secondPos");
     QLabel *thirdPos = this->findChild<QLabel*>("thirdPos");
    QLabel *liam = this->findChild<QLabel*>("liam");

     Utils utils = Utils();
     bool collisionWithSencondPos = utils.areLabelsColliding(arrow, secondPos);
     bool collisionWithThirdPos = utils.areLabelsColliding(arrow, thirdPos);

    if (this->liamState == 0 && collisionWithSencondPos) {
         this->liamState = 1;
        liam->setStyleSheet(QString("background-image: url(:/images/shot_two.png);"));
     } else if (this->liamState == 2 && !collisionWithThirdPos && collisionWithSencondPos) {
        this->liamState = 1;
       liam->setStyleSheet(QString("background-image: url(:/images/shot_two.png);"));
    } else  if (this->liamState == 1 && collisionWithThirdPos ) {
        this->liamState = 2;
       liam->setStyleSheet(QString("background-image: url(:/images/shot_three.png);"));
    } else if (this->liamState == 1 && !collisionWithThirdPos && !collisionWithSencondPos) {
        this->liamState = 0;
       liam->setStyleSheet(QString("background-image: url(:/images/shot_one.png);"));
    }
 }

 /**
  * @brief Shot the arrow if drag and drop is stop and liamState == 2
  */
 void PageThree::shotArrow() {
     ClickableLabel *arrow = this->findChild<ClickableLabel*>("arrow");
     QLabel *liam = this->findChild<QLabel*>("liam");

     if (this->liamState == 2) {
         arrow->setMoveable(false);
         QPropertyAnimation *shotAnimation = new QPropertyAnimation(arrow, "geometry");
         shotAnimation->setDuration(200);
         shotAnimation->setStartValue(arrow->geometry());
          shotAnimation->setEndValue(QRect(500, arrow->geometry().y(), arrow->geometry().width(), arrow->geometry().height()));


      // Change page after 1s
      QTimer::singleShot(1000, dynamic_cast<MainWindow*>(this->parent()->parent()), &MainWindow::nextPage);

      shotAnimation->start();
     } else {
         liam->setStyleSheet(QString("background-image: url(:/images/shot_one.png);"));
         this->liamState = 0;
         arrow->move(208, arrow->geometry().y());
     }

     dynamic_cast<MainWindow*>(this->parent()->parent())
             ->getGestionHaptique()
             ->stopEffect(HapticHandler::SCENE_3);
 }

 void PageThree::initializePage() {
     dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getGestionHaptique()->stopEffect(HapticHandler::SCENE_2);

 }

