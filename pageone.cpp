#include "pageone.h"
#include "ui_pageone.h"
#include "haptichandler.h"
#include "soundhandler.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QPushButton>

/**
 * @brief Constructor of the class PageOne
 * @param parent
 */
PageOne::PageOne(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::PageOne)
{
    ui->setupUi(this);
    setState(false);
}

/**
 * @brief Destructor of the class PageOne
 */
PageOne::~PageOne()
{
    delete ui;
}

/**
 * @brief Function called when Liam is colliding with the road, the exit or the wall
 */
void PageOne::onCollide()
{
    if (isActive)
    {
        // Getting all the objects that we're going to test.
        QLabel *exit = this->findChild<QLabel *>("exit");
        QLabel *road = this->findChild<QLabel *>("road");
        ClickableLabel *liam = this->findChild<ClickableLabel *>("liam");

        Utils utils = Utils();
        bool isLiamAndRoadColliding = utils.areLabelsColliding(road, liam);
        if (isLiamAndRoadColliding && !this->isWalking)
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->startEffect(HapticHandler::SCENE_1);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getSoundHandler()
                ->startSound(SoundHandler::SCENE_2);

            this->isWalking = true;
        }
        else if (this->isWalking && !isLiamAndRoadColliding)
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_1);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getSoundHandler()
                ->stopSound(SoundHandler::SCENE_2);

            this->isWalking = false;
        }

        if (utils.areLabelsColliding(exit, liam))
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_1);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getSoundHandler()
                ->stopSound(SoundHandler::SCENE_2);

            dynamic_cast<MainWindow *>(this->parent()->parent())->setCurrentPage(2);
            disconnect(liam, 0, 0, 0);
        }
    }
}

/**
 * @brief Function called when drag and drop is stopped
 */
void PageOne::onStopDragAndDrop()
{
    if (isActive)
    {
        this->isWalking = false;
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getHapticHandler()
            ->stopEffect(HapticHandler::SCENE_1);

        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getSoundHandler()
            ->stopSound(SoundHandler::SCENE_2);
    }
}

/**
 * @brief Initialize the page
 */
void PageOne::initializePage()
{
    if (!isActive) {
        // Define liam moveable
        ClickableLabel *liam = this->findChild<ClickableLabel *>("liam");
        liam->setMoveable(true);
        connect(liam, &ClickableLabel::moved, this, &PageOne::onCollide);

        QLabel *road = this->findChild<QLabel *>("road");
        road->setVisible(false);

        QLabel *exit = this->findChild<QLabel *>("exit");
        exit->setVisible(false);

        this->isWalking = false;
        connect(liam, &ClickableLabel::stopDragAndDrop, this, &PageOne::onStopDragAndDrop);

        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getSoundHandler()
            ->stopSound(SoundHandler::SCENE_1);

        setState(true);
    }
}

/**
 * @brief Set the state of the page
 * @param isActive
 */
void PageOne::setState(bool isActive)
{
    this->isActive = isActive;
}
