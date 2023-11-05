#include "pagefive.h"
#include "ui_pagefive.h"
#include "mainwindow.h"
#include "utils.h"
#include "clickablelabel.h"
#include "haptichandler.h"

#include <QLabel>
#include <QDebug>

PageFive::PageFive(QWidget *parent) : QWidget(parent),
                                      ui(new Ui::PageFive)
{
    ui->setupUi(this);

    ClickableLabel *liam = this->findChild<ClickableLabel *>("liam");
    liam->setMoveable(true);

    connect(liam, &ClickableLabel::moved, this, &PageFive::onLiamMouved);
    connect(liam, &ClickableLabel::stopDragAndDrop, this, &PageFive::onStopDragAndDrop);

    areEffectsActive = false;

    this->findChild<QLabel *>("zone_1")->setVisible(false);
    this->findChild<QLabel *>("zone_2")->setVisible(false);
    this->findChild<QLabel *>("zone_3")->setVisible(false);
    this->findChild<QLabel *>("zone_4")->setVisible(false);
    this->findChild<QLabel *>("zone_5")->setVisible(false);
    this->findChild<QLabel *>("zone_6")->setVisible(false);
    this->findChild<QLabel *>("zone_7")->setVisible(false);
    this->findChild<QLabel *>("zone_8")->setVisible(false);
    this->findChild<QLabel *>("zone_9")->setVisible(false);
    this->findChild<QLabel *>("zone_10")->setVisible(false);
    this->findChild<QLabel *>("zone_11")->setVisible(false);
}

PageFive::~PageFive()
{
    delete ui;
}

void PageFive::initializePage()
{
    /*dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getGestionHaptique()
            ->startEffect(HapticHandler::UP_WALL);*/
}

void PageFive::onLiamMouved()
{
    QLabel *zone_1 = this->findChild<QLabel *>("zone_1");
    QLabel *zone_2 = this->findChild<QLabel *>("zone_2");
    QLabel *zone_3 = this->findChild<QLabel *>("zone_3");
    QLabel *zone_4 = this->findChild<QLabel *>("zone_4");
    QLabel *zone_5 = this->findChild<QLabel *>("zone_5");
    QLabel *zone_6 = this->findChild<QLabel *>("zone_6");
    QLabel *zone_7 = this->findChild<QLabel *>("zone_7");
    QLabel *zone_8 = this->findChild<QLabel *>("zone_8");
    QLabel *zone_9 = this->findChild<QLabel *>("zone_9");
    QLabel *zone_10 = this->findChild<QLabel *>("zone_10");
    QLabel *zone_11 = this->findChild<QLabel *>("zone_11");

    ClickableLabel *liam = this->findChild<ClickableLabel *>("liam");

    Utils utils = Utils();

    bool isInZone1 = utils.areLabelsColliding(liam, zone_1);
    bool isInZone2 = utils.areLabelsColliding(liam, zone_2);
    bool isInZone3 = utils.areLabelsColliding(liam, zone_3);
    bool isInZone4 = utils.areLabelsColliding(liam, zone_4);
    bool isInZone5 = utils.areLabelsColliding(liam, zone_5);
    bool isInZone6 = utils.areLabelsColliding(liam, zone_6);
    bool isInZone7 = utils.areLabelsColliding(liam, zone_7);
    bool isInZone8 = utils.areLabelsColliding(liam, zone_8);
    bool isInZone9 = utils.areLabelsColliding(liam, zone_9);
    bool isInZone10 = utils.areLabelsColliding(liam, zone_10);
    bool isInZone11 = utils.areLabelsColliding(liam, zone_11);

    HapticHandler *hapticHandler = dynamic_cast<MainWindow *>(this->parent()->parent())->getHapticHandler();

    if ((isInZone1 || isInZone2 || isInZone3 || isInZone4 || isInZone5 || isInZone6 || isInZone7 || isInZone8 || isInZone9 || isInZone10 || isInZone11) && !areEffectsActive)
    {

        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 0});
        hapticHandler->startEffect(HapticHandler::UP_WALL);

        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 768});
        hapticHandler->startEffect(HapticHandler::DOWN_WALL);

        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {1024, 0});
        hapticHandler->startEffect(HapticHandler::RIGHT_WALL);

        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {0, 0});
        hapticHandler->startEffect(HapticHandler::LEFT_WALL);
        areEffectsActive = true;
    }

    if (isInZone1 && isInZone2)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 200});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 768});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {124, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {121, 0});
    }
    else if (isInZone2 && isInZone3)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 358});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 363});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {314, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {121, 0});
    }
    else if (isInZone3 && isInZone4)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 358});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 591});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {314, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {313, 0});
    }
    else if (isInZone4 && isInZone5)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 593});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 591});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {424, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {313, 0});
    }
    else if (isInZone5 && isInZone6)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 593});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 685});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {424, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {321, 0});
    }
    else if (isInZone6 && isInZone7)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 684});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 685});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {424, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {421, 0});
    }
    else if (isInZone7 && isInZone8)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {475, 0});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 685});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {837, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {830, 0});
    }
    else if (isInZone8 && isInZone9)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 475});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 488});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {950, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {830, 0});
    }
    else if (isInZone9 && isInZone10)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 475});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 686});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {950, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {947, 0});
    }
    else if (isInZone10 && isInZone11)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 662});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 686});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {1024, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {947, 0});
    }
    else if (isInZone1)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 200});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 226});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {124, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {50, 0});
    }
    else if (isInZone2)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 50});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 363});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {124, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {121, 0});
    }
    else if (isInZone3)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 358});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 363});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {314, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {121, 0});
    }
    else if (isInZone4)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 358});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 591});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {314, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {313, 0});
    }
    else if (isInZone5)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 593});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 591});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {424, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {313, 0});
    }
    else if (isInZone6)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 593});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 685});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {424, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {421, 0});
    }
    else if (isInZone7)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 684});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 685});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {837, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {421, 0});
    }
    else if (isInZone8)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 475});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 685});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {837, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {830, 0});
    }
    else if (isInZone9)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 475});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 488});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {950, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {830, 0});
    }
    else if (isInZone10)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 475});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 686});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {950, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {947, 0});
    }
    else if (isInZone11)
    {
        hapticHandler->changeWallPosition(HapticHandler::UP_WALL, {0, 662});
        hapticHandler->changeWallPosition(HapticHandler::DOWN_WALL, {0, 686});
        hapticHandler->changeWallPosition(HapticHandler::RIGHT_WALL, {1024, 0});
        hapticHandler->changeWallPosition(HapticHandler::LEFT_WALL, {947, 0});
    }

    QLabel *exit = this->findChild<QLabel *>("exit");
    if (utils.areLabelsColliding(liam, exit))
    {
        hapticHandler->stopEffect(HapticHandler::UP_WALL);
        hapticHandler->stopEffect(HapticHandler::DOWN_WALL);
        hapticHandler->stopEffect(HapticHandler::RIGHT_WALL);
        hapticHandler->stopEffect(HapticHandler::LEFT_WALL);
        areEffectsActive = false;
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->setCurrentPage(6);
    }
}

void PageFive::onStopDragAndDrop()
{
    HapticHandler *hapticHandler = dynamic_cast<MainWindow *>(this->parent()->parent())->getHapticHandler();
    hapticHandler->stopEffect(HapticHandler::UP_WALL);
    hapticHandler->stopEffect(HapticHandler::DOWN_WALL);
    hapticHandler->stopEffect(HapticHandler::RIGHT_WALL);
    hapticHandler->stopEffect(HapticHandler::LEFT_WALL);
    areEffectsActive = false;
}
