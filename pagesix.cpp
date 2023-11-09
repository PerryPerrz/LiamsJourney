#include "pagesix.h"
#include "ui_pagesix.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QLabel>
#include <QTimer>

PageSix::PageSix(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::PageSix)
{
    ui->setupUi(this);

    ClickableLabel *spoon = this->findChild<ClickableLabel *>("spoon");
    spoon->setMoveable(true);
    connect(spoon, &ClickableLabel::moved, this, &PageSix::onSpoonMouve);
    connect(spoon, &ClickableLabel::stopDragAndDrop, this, &PageSix::onDragAndDropStopped);

    isEnter = false;
    jarState = 0;
    done = false;

    setState(false);
}

PageSix::~PageSix()
{
    delete ui;
}

void PageSix::initializePage()
{
    setState(true);
}

void PageSix::onSpoonMouve()
{
    if (isActive) {
        ClickableLabel *spoon = this->findChild<ClickableLabel *>("spoon");
        QLabel *grid = this->findChild<QLabel *>("grid");
        QLabel *enter = this->findChild<QLabel *>("enter");
        QLabel *exit = this->findChild<QLabel *>("exit");
        QLabel *jar = this->findChild<QLabel *>("jar");

        Utils utils = Utils();

        if (utils.areLabelsColliding(spoon, grid))
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->startEffect(HapticHandler::SCENE_6);

            MainWindow *mainWindow = dynamic_cast<MainWindow *>(this->parent()->parent());
            SoundHandler *soundHandler = mainWindow->getSoundHandler();
            soundHandler->startSounds(SoundHandler::SCENE_8);
        }
        else
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_6);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getSoundHandler()
                ->stopSounds(SoundHandler::SCENE_8);
        }

        if (isEnter && utils.areLabelsColliding(spoon, exit))
        {
            isEnter = false;
            jarState++;

            switch (jarState)
            {
            case 1:
                jar->setStyleSheet(QString("background-image:url(:/images/1_of_4_jar.png)"));
                break;
            case 2:
                jar->setStyleSheet(QString("background-image:url(:/images/2_of_4_jar.png)"));
                break;
            case 3:
                jar->setStyleSheet(QString("background-image:url(:/images/3_of_4_jar.png)"));
                break;
            case 4:
                jar->setStyleSheet(QString("background-image:url(:/images/full_jar.png)"));

                if (!done)
                {
                    dynamic_cast<MainWindow *>(this->parent()->parent())
                        ->getHapticHandler()
                        ->stopEffect(HapticHandler::SCENE_6);

                    dynamic_cast<MainWindow *>(this->parent()->parent())
                        ->getSoundHandler()
                        ->stopSounds(SoundHandler::SCENE_8);

                    QTimer::singleShot(1000, dynamic_cast<MainWindow *>(this->parent()->parent()), &MainWindow::nextPage);
                    done = true;
                }

                break;
            }
        }
        else if (!isEnter && utils.areLabelsColliding(spoon, enter))
        {
            isEnter = true;
        }
    }
}

void PageSix::onDragAndDropStopped()
{
    if (isActive) {
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getHapticHandler()
            ->stopEffect(HapticHandler::SCENE_6);

        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getSoundHandler()
            ->stopSounds(SoundHandler::SCENE_8);

        isEnter = false;
    }
}

void PageSix::setState(bool isActive) {
    this->isActive = isActive;
}
