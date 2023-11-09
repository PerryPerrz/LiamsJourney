#include "soundhandler.h"
#include "mainwindow.h"
#include "qdebug.h"

SoundHandler::SoundHandler(MainWindow *fen, QObject *parent) : QObject(parent), mFenetre(fen)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    player->setPlaylist(playlist);

    scene1 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene2 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
    scene3 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/bzzbzz.mp3"));
    scene4 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/shot.mp3"));
    scene5 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/scratch.mp3"));
    scene6 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/fire.mp3"));
    scene7 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene8 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
    scene9 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene10 = new QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
}

void SoundHandler::startSound(const int sound)
{
    // Stop the currently playing sound (if any)
    player->stop();
    playlist->clear();

    switch (sound)
    {
    case SoundHandler::SCENE_1:
        playlist->addMedia(*scene1);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        player->setVolume(50);
        qDebug() << "1";
        break;

    case SoundHandler::SCENE_2:
        playlist->addMedia(*scene2);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        player->setVolume(50);
        qDebug() << "2";
        break;

    case SoundHandler::SCENE_3:
        playlist->addMedia(*scene3);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        player->setVolume(50);
        qDebug() << "3";
        break;

    case SoundHandler::SCENE_4:
        playlist->addMedia(*scene4);
        player->setVolume(50);
        qDebug() << "4";
        break;

    case SoundHandler::SCENE_5:
        playlist->addMedia(*scene5);
        player->setVolume(50);
        qDebug() << "5";
        break;

    case SoundHandler::SCENE_6:
        playlist->addMedia(*scene6);
        player->setVolume(50);
        qDebug() << "6";
        break;

    case SoundHandler::SCENE_7:
        playlist->addMedia(*scene7);
        player->setVolume(50);
        qDebug() << "7";
        break;

    case SoundHandler::SCENE_8:
        playlist->addMedia(*scene8);
        player->setVolume(50);
        qDebug() << "8";
        break;

    case SoundHandler::SCENE_9:
        playlist->addMedia(*scene9);
        player->setVolume(50);
        qDebug() << "9";
        break;

    case SoundHandler::SCENE_10:
        playlist->addMedia(*scene10);
        player->setVolume(50);
        qDebug() << "10";
        break;
    }

    player->play();
}

void SoundHandler::stopSound(const int sound)
{
    if (player->state() == QMediaPlayer::PlayingState)
    {
        player->stop();
    }
}

SoundHandler::~SoundHandler()
{
    delete playlist;
    delete player;
}
