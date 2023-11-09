#include "pagefour.h"
#include "ui_pagefour.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QLabel>
#include <ctime>
#include <QPropertyAnimation>
#include <QTimer>

PageFour::PageFour(QWidget *parent) : QWidget(parent),
                                      ui(new Ui::PageFour)
{
    ui->setupUi(this);

    ClickableLabel *match = this->findChild<ClickableLabel *>("match");
    match->setMoveable(true);

    ClickableLabel *head_match = this->findChild<ClickableLabel *>("head_match");
    head_match->setMoveable(true);
    head_match->setVisible(false);

    QLabel *grip = this->findChild<QLabel *>("grip");
    grip->setVisible(false);

    QLabel *trigger = this->findChild<QLabel *>("trigger");
    trigger->setVisible(false);

    connect(head_match, &ClickableLabel::moved, this, &PageFour::onCollide);
    connect(head_match, &ClickableLabel::stopDragAndDrop, this, &PageFour::onStopDragAndDrop);
    connect(match, &ClickableLabel::moved, this, &PageFour::onCollide);
    connect(match, &ClickableLabel::stopDragAndDrop, this, &PageFour::onStopDragAndDrop);

    this->isTriggered = false;
    std::srand(std::time(nullptr));

    setState(false);
}

PageFour::~PageFour()
{
    delete ui;
}

void PageFour::onCollide()
{
    if (isActive)
    {
        Utils utils = Utils();

        ClickableLabel *match = this->findChild<ClickableLabel *>("match");
        ClickableLabel *head_match = this->findChild<ClickableLabel *>("head_match");
        QLabel *trigger = this->findChild<QLabel *>("trigger");

        head_match->move(match->pos());

        QLabel *grip = this->findChild<QLabel *>("grip");

        if (utils.areLabelsColliding(head_match, grip))
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->startEffect(HapticHandler::SCENE_4);

            MainWindow *mainWindow = dynamic_cast<MainWindow *>(this->parent()->parent());
            SoundHandler *soundHandler = mainWindow->getSoundHandler();
            soundHandler->startSound(SoundHandler::SCENE_5);
        }
        else
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_4);
            isTriggered = false;

            MainWindow *mainWindow = dynamic_cast<MainWindow *>(this->parent()->parent());
            SoundHandler *soundHandler = mainWindow->getSoundHandler();
            soundHandler->stopSound(SoundHandler::SCENE_5);
        }

        if (utils.areLabelsColliding(head_match, trigger) && !isTriggered)
        {
            float randomValue = static_cast<float>((std::rand())) / RAND_MAX;
            if (randomValue <= 0.4f)
            {
                match->setMoveable(false);

                dynamic_cast<MainWindow *>(this->parent()->parent())
                    ->getHapticHandler()
                    ->stopEffect(HapticHandler::SCENE_4);

                MainWindow *mainWindow = dynamic_cast<MainWindow *>(this->parent()->parent());
                SoundHandler *soundHandler = mainWindow->getSoundHandler();
                soundHandler->startSound(SoundHandler::SCENE_6);

                match->setStyleSheet(QString("background-image: url(:/images/match_on_fire.png);"));
                match->resize(54, 228);

                QPropertyAnimation *mouveAnimation = new QPropertyAnimation(match, "geometry");
                mouveAnimation->setDuration(500);
                mouveAnimation->setStartValue(match->geometry());
                mouveAnimation->setEndValue(QRect(900, 500, match->geometry().width(), match->geometry().height()));

                mouveAnimation->start();

                this->setStyleSheet(QString("background-image: url(:/images/page_four_light.png);"));

                QTimer::singleShot(3000, dynamic_cast<MainWindow *>(this->parent()->parent()), &MainWindow::nextPage);
            }

            isTriggered = true;
        }
    }
}

void PageFour::onStopDragAndDrop()
{
    if (isActive)
    {
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getHapticHandler()
            ->stopEffect(HapticHandler::SCENE_4);

        MainWindow *mainWindow = dynamic_cast<MainWindow *>(this->parent()->parent());
        SoundHandler *soundHandler = mainWindow->getSoundHandler();
        soundHandler->startSound(SoundHandler::SCENE_5);
    }
}

void PageFour::initializePage()
{
    dynamic_cast<MainWindow *>(this->parent()->parent())
        ->getSoundHandler()
        ->stopSound(SoundHandler::SCENE_4);

    setState(true);
}

void PageFour::setState(bool isActive)
{
    this->isActive = isActive;
}
