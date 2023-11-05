#include "soundhandler.h"
#include "mainwindow.h"
#include "qdebug.h"

SoundHandler::SoundHandler(MainWindow *fen, QObject *parent) : QObject(parent), mFenetre(fen)
{
    player = new QMediaPlayer(this);

    // Initialize playlists for different scenes
    scene_1 = new QMediaPlaylist();
    scene_2 = new QMediaPlaylist();
    scene_3 = new QMediaPlaylist();
    scene_4 = new QMediaPlaylist();
    scene_5 = new QMediaPlaylist();
    scene_6 = new QMediaPlaylist();
    scene_7 = new QMediaPlaylist();

    // Set up different media files for each scene here
    scene_1->addMedia(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene_2->addMedia(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
    scene_3->addMedia(QUrl("file:///E:/LiamsJourney/sounds/bzzbzz.mp3"));
    scene_4->addMedia(QUrl("file:///E:/LiamsJourney/sounds/bzzbzz.mp3"));

    // Set the playback mode for each scene (e.g., Loop)
    scene_1->setPlaybackMode(QMediaPlaylist::Loop);
    scene_2->setPlaybackMode(QMediaPlaylist::Loop);
    scene_3->setPlaybackMode(QMediaPlaylist::Loop);
    scene_4->setPlaybackMode(QMediaPlaylist::Loop);

    player->setPlaylist(NULL);
}

void SoundHandler::startSounds(const int sound)
{
    // Stop the currently playing sound (if any)
    player->stop();

    switch (sound)
    {
    case SoundHandler::SCENE_1:
        player->setPlaylist(scene_1);
        player->setVolume(50);
        qDebug() << "1";
        player->play();
        break;

    case SoundHandler::SCENE_2:
        player->setPlaylist(scene_2);
        player->setVolume(50);
        qDebug() << "2";
        player->play();
        break;

    case SoundHandler::SCENE_3:
        player->setPlaylist(scene_3);
        player->setVolume(50);
        qDebug() << "3";
        player->play();
        break;

    case SoundHandler::SCENE_4:
        player->setPlaylist(scene_4);
        player->setVolume(50);
        qDebug() << "4";
        player->play();
        break;
    }
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
    delete player;
    delete scene_1;
    delete scene_2;
    delete scene_3;
    delete scene_4;
    delete scene_5;
    delete scene_6;
    delete scene_7;
}