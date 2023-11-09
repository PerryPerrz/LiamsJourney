#include "soundhandler.h"
#include "mainwindow.h"
#include "qdebug.h"

SoundHandler::SoundHandler(MainWindow *fen, QObject *parent) : QObject(parent), mFenetre(fen)
{
    player = new QMediaPlayer(this, QMediaPlayer::LowLatency);
    playlist = new QMediaPlaylist(this);
    player->setPlaylist(playlist);
    player->setVolume(50);

    scene1 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene2 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
    scene3 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/bzzbzz.mp3"));
    scene4 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/shot.mp3"));
    scene5 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/scratch.mp3"));
    scene6 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/fire.mp3"));
    scene7 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene8 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
    scene9 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene10 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
}

void SoundHandler::startSound(const int sound)
{
    // Stop the currently playing sound (if any)
    player->pause();
    playlist->clear();


    switch (sound)
    {
    case SoundHandler::SCENE_1:
        playlist->addMedia(scene1);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        qDebug() << "1";
        break;

    case SoundHandler::SCENE_2:
        playlist->addMedia(scene2);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        qDebug() << "2";
        break;

    case SoundHandler::SCENE_3:
        playlist->addMedia(scene3);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        qDebug() << "3";
        break;

    case SoundHandler::SCENE_4:
        playlist->addMedia(scene4);
        qDebug() << "4";
        break;

    case SoundHandler::SCENE_5:
        playlist->addMedia(scene5);
        qDebug() << "5";
        break;

    case SoundHandler::SCENE_6:
        playlist->addMedia(scene6);
        qDebug() << "6";
        break;

    case SoundHandler::SCENE_7:
        playlist->addMedia(scene7);
        qDebug() << "7";
        break;

    case SoundHandler::SCENE_8:
        playlist->addMedia(scene8);
        qDebug() << "8";
        break;

    case SoundHandler::SCENE_9:
        playlist->addMedia(scene9);
        qDebug() << "9";
        break;

    case SoundHandler::SCENE_10:
        playlist->addMedia(scene10);
        qDebug() << "10";
        break;
    }

    player->play();
}

void SoundHandler::stopSound(const int sound)
{
    if (player->state() == QMediaPlayer::PlayingState)
    {
        player->pause();
    }
}

SoundHandler::~SoundHandler()
{
    delete playlist;
    delete player;
}
