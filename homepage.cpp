#include "homepage.h"
#include "ui_homepage.h"
#include "mainwindow.h"
#include "clickablelabel.h"

#include <QDebug>
#include <QMediaPlaylist>

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    // Define the sound background
    QMediaPlaylist *playlist;
    playlist = new QMediaPlaylist(this);
    playlist->addMedia(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer(this);
    player->setPlaylist(playlist);
    player->setVolume(75);
    player->play();

    // Signal defined for the play button
    ClickableLabel *playButton = this->findChild<ClickableLabel*>("playButton");
    connect(playButton, &ClickableLabel::clicked, dynamic_cast<MainWindow*>(this->parent()), &MainWindow::nextPage);
    connect(playButton, &ClickableLabel::clicked, this, &HomePage::stopSound);
}

void HomePage::initializePage() {

}

void HomePage::stopSound() {
 player->stop();
}

HomePage::~HomePage()
{
    delete ui;
}
