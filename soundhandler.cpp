#include "soundhandler.h"
#include "mainwindow.h"
#include "qdebug.h"

SoundHandler::SoundHandler(MainWindow *fen, QObject *parent) : QObject(parent), mFenetre(fen)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(playlist);
}

void SoundHandler::startSounds(const int sound)
{
    // Stop the currently playing sound (if any)
    player->stop();
    playlist->clear();

    switch (sound)
    {
    case SoundHandler::SCENE_1:
        playlist->addMedia(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
        player->setVolume(50);
        qDebug() << "1";
        break;

    case SoundHandler::SCENE_2:
        playlist->addMedia(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
        player->setVolume(50);
        qDebug() << "2";
        break;

    case SoundHandler::SCENE_3:
       playlist->addMedia(QUrl("file:///E:/LiamsJourney/sounds/bzzbzz.mp3"));
        player->setVolume(50);
        qDebug() << "3";
        break;

    case SoundHandler::SCENE_4:
        playlist->addMedia(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
        player->setVolume(50);
        qDebug() << "4";
        break;
    }

    player->play();
}

void SoundHandler::stopSounds(const int sound)
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
