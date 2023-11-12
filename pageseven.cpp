#include "pageseven.h"
#include "ui_pageseven.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QLabel>

/**
 * @brief Constructor of the class PageSeven
 * @param parent
 */
PageSeven::PageSeven(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::PageSeven)
{
    ui->setupUi(this);

    ClickableLabel *spoon = this->findChild<ClickableLabel *>("spoon");
    spoon->setMoveable(true);

    connect(spoon, &ClickableLabel::moved, this, &PageSeven::onSpoonMoved);
    connect(spoon, &ClickableLabel::stopDragAndDrop, this, &PageSeven::onSpoonReleased);

    count = 0;
    done = false;
    isTriggered = false;

    setState(false);
}

/**
 * @brief Destructor of the class PageSeven
 */
PageSeven::~PageSeven()
{
    delete ui;
}

/**
 * @brief Initialize the page
 */
void PageSeven::initializePage()
{
    setState(true);
    dynamic_cast<MainWindow *>(this->parent()->parent())
        ->getHapticHandler()
        ->stopEffect(HapticHandler::SCENE_6);

    dynamic_cast<MainWindow *>(this->parent()->parent())
        ->getSoundHandler()
        ->startSound(SoundHandler::SCENE_9);
}

/**
 * @brief Function called when the spoon is moved
 */
void PageSeven::onSpoonMoved()
{
    if (isActive)
    {
        ClickableLabel *spoon = this->findChild<ClickableLabel *>("spoon");
        QLabel *honey = this->findChild<QLabel *>("honey");
        QLabel *counter = this->findChild<QLabel *>("counter");

        Utils utils = Utils();

        if (utils.areLabelsColliding(spoon, honey) && !isColliding)
        {
            isColliding = true;
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->startEffect(HapticHandler::SCENE_7);
        }
        else if (!utils.areLabelsColliding(spoon, honey) && isColliding)
        {
            isColliding = false;
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_7);
        }

        if (count < 10 && utils.areLabelsColliding(spoon, counter) && !isTriggered)
        {
            count++;
            isTriggered = true;
        }
        else if (count == 10 && !done && utils.areLabelsColliding(spoon, counter))
        {
            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_7);

            dynamic_cast<MainWindow *>(this->parent()->parent())
                ->nextPage();
            done = true;
            disconnect(spoon, 0, 0, 0);
        }
        else if (!utils.areLabelsColliding(spoon, counter))
        {
            isTriggered = false;
        }
    }
}

/**
 * @brief Function called when the spoon is released
 */
void PageSeven::onSpoonReleased()
{
    if (isActive)
    {
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getHapticHandler()
            ->stopEffect(HapticHandler::SCENE_7);

         isColliding = false;
    }
}

/**
 * @brief Set the state of the page
 * @param isActive
 */
void PageSeven::setState(bool isActive)
{
    this->isActive = isActive;
}
