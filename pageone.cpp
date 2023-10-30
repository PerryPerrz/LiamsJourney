#include "pageone.h"
#include "ui_pageone.h"
#include "haptichandler.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QPushButton>

PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);

    // Set the signals and slots of the button start and stop
    /*QPushButton* startButton = this->findChild<QPushButton*>("startButton");
    connect(startButton, &QPushButton::clicked,
            dynamic_cast<MainWindow*>(this->parent())->getGestionHaptique(),
            &HapticHandler::onStartVibrator);

    QPushButton* stopButton = this->findChild<QPushButton*>("stopButton");
    connect(stopButton, &QPushButton::clicked,
            dynamic_cast<MainWindow*>(this->parent())->getGestionHaptique(),
            &HapticHandler::onStopVibrator);*/

    //Define liam moveable
    ClickableLabel *liam = this->findChild<ClickableLabel*>("liam");
    liam->setMoveable(true);
    connect(liam, &ClickableLabel::moved, this, &PageOne::onCollide);

    QLabel* road = this->findChild<QLabel*>("road");
    road->setVisible(false);

    QLabel* exit = this->findChild<QLabel*>("exit");
    exit->setVisible(false);

     this->isWalking = false;
    connect(liam, &ClickableLabel::stopDragAndDrop, this, &PageOne::onStopDragAndDrop);
}

PageOne::~PageOne()
{
    delete ui;
}

/**
 * @brief PageOne::onCollide
 */
void PageOne::onCollide(){
    //Getting all the objects that we're going to test.
    QLabel *exit = this->findChild<QLabel*>("exit");
    QLabel *road = this->findChild<QLabel*>("road");
    ClickableLabel *liam = this->findChild<ClickableLabel*>("liam");

    Utils utils = Utils();
    bool isLiamAndRoadColliding = utils.areLabelsColliding(road,liam);
    if ( isLiamAndRoadColliding && !this->isWalking) {
        dynamic_cast<MainWindow*>(this->parent()->parent())
                ->getGestionHaptique()->startEffect(HapticHandler::SCENE_1);
        this->isWalking = true;
    } else if(this->isWalking && !isLiamAndRoadColliding){
        dynamic_cast<MainWindow*>(this->parent()->parent())
                ->getGestionHaptique()->stopEffect(HapticHandler::SCENE_1);
        this->isWalking = false;
    }

    if (utils.areLabelsColliding(exit, liam)) {
         dynamic_cast<MainWindow*>(this->parent()->parent())
                ->getGestionHaptique()->stopEffect(HapticHandler::SCENE_1);

        dynamic_cast<MainWindow*>(this->parent()->parent())->setCurrentPage(2);
    }
}

void PageOne::onStopDragAndDrop(){
    this->isWalking = false;
    dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getGestionHaptique()->stopEffect(HapticHandler::SCENE_1);
}

void PageOne::initializePage() {

}

