#include "pagesix.h"
#include "ui_pagesix.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QLabel>
#include <QTimer>

/**
 * @brief Constructor of the class PageSix
 * @param parent
 */
PageSix::PageSix(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::PageSix)
{
    ui->setupUi(this);

    ClickableLabel *knife = this->findChild<ClickableLabel *>("knife");
    knife->setMoveable(true);
    connect(knife, &ClickableLabel::moved, this, &PageSix::onKnifeMove);
    connect(knife, &ClickableLabel::stopDragAndDrop, this, &PageSix::onDragAndDropStopped);

    isEnter = false;
    jarState = 0;
    done = false;

    setState(false);
    isColliding = false;
}

/**
 * @brief Destructor of the class PageSix
 */
PageSix::~PageSix()
{
    delete ui;
}

/**
 * @brief Initialize the page
 */
void PageSix::initializePage()
{
    setState(true);
}

/**
 * @brief Function called when the knife is moved
 */
void PageSix::onKnifeMove()
{
    if (isActive)
    {
        ClickableLabel *knife = this->findChild<ClickableLabel *>("knife");
        QLabel *grid = this->findChild<QLabel *>("grid");
        QLabel *enter = this->findChild<QLabel *>("enter");
        QLabel *exit = this->findChild<QLabel *>("exit");
        QLabel *jar = this->findChild<QLabel *>("jar");

        Utils utils = Utils();

        if (utils.areLabelsColliding(knife, grid) && !isColliding)
        {
            isColliding = true;
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->startEffect(HapticHandler::SCENE_6);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getSoundHandler()
                ->startSound(SoundHandler::SCENE_8);
        }
        else if (!utils.areLabelsColliding(knife, grid) && isColliding)
        {
            isColliding = false;
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_6);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getSoundHandler()
                ->stopSound(SoundHandler::SCENE_8);
        }

        if (isEnter && !done && utils.areLabelsColliding(knife, exit))
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
                        ->stopSound(SoundHandler::SCENE_8);

                    QTimer::singleShot(1000, dynamic_cast<MainWindow *>(this->parent()->parent()), &MainWindow::nextPage);
                    done = true;
                    disconnect(knife, 0, 0, 0);
                }

                break;
            }
        }
        else if (!isEnter && utils.areLabelsColliding(knife, enter))
        {
            isEnter = true;
        }
    }
}

/**
 * @brief Function called when drag and drop is stopped
 */
void PageSix::onDragAndDropStopped()
{
    if (isActive)
    {
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getHapticHandler()
            ->stopEffect(HapticHandler::SCENE_6);

        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getSoundHandler()
            ->stopSound(SoundHandler::SCENE_8);

        isEnter = false;
        isColliding = false;
    }
}

/**
 * @brief Set the state of the page
 * @param isActive
 */
void PageSix::setState(bool isActive)
{
    this->isActive = isActive;
}
