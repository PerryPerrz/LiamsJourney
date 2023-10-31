#include "pageone.h"
#include "ui_pageone.h"
#include "haptichandler.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QPushButton>
#include <QMediaPlaylist>

PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);

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

    this->isFirstSound = true;
    connect(liam, &ClickableLabel::moved, this, &PageOne::startSound);
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
    //Stop the walking soud
    player->stop();
    this->isFirstSound = true;

    this->isWalking = false;
    dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getGestionHaptique()->stopEffect(HapticHandler::SCENE_1);
}

void PageOne::startSound() {
    if(isFirstSound){
        // Define the sound background
        playlist = new QMediaPlaylist(this);
        playlist->addMedia(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);

        player = new QMediaPlayer(this);
        player->setPlaylist(playlist);
        player->play();
        this->isFirstSound = false;
    }
}

void PageOne::initializePage() {

}

