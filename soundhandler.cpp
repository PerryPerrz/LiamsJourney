#include "soundhandler.h"
#include "mainwindow.h"
#include "qdebug.h"

/**
 * @brief Class that handle the sound all over the app
 * @param fen
 * @param parent
 */
SoundHandler::SoundHandler(MainWindow *fen, QObject *parent) : QObject(parent), mFenetre(fen)
{
    player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    player->setVolume(50);

    scene1 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
    scene2 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/walking.mp3"));
    scene3 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/bzzbzz.mp3"));
    scene4 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/shot.mp3"));
    scene5 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/scratch.mp3"));
    scene6 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/fire.mp3"));
    scene7 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/labyrinth.mp3"));
    scene8 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/honey.mp3"));
    scene9 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest_two.mp3"));
    scene10 = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/end.mp3"));

    isLooping = false;

    // We connect the player with the handler to ensure that the player is looping
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &SoundHandler::restartSound);
}

/**
 * @brief Start the sound
 * @param sound
 */
void SoundHandler::startSound(const int sound)
{
    // Stop the currently playing sound (if any)
    player->pause();
    isLooping = false;

    switch (sound)
    {
    case SoundHandler::SCENE_1:
        player->setMedia(scene1);
        player->setVolume(50);
        isLooping = true;
        qDebug() << "1";
        break;

    case SoundHandler::SCENE_2:
        player->setMedia(scene2);
        player->setVolume(100);
        isLooping = true;
        qDebug() << "2";
        break;

    case SoundHandler::SCENE_3:
        player->setMedia(scene3);
        player->setVolume(35);
        isLooping = true;
        qDebug() << "3";
        break;

    case SoundHandler::SCENE_4:
        player->setMedia(scene4);
        player->setVolume(50);
        qDebug() << "4";
        break;

    case SoundHandler::SCENE_5:
        player->setMedia(scene5);
        qDebug() << "5";
        break;

    case SoundHandler::SCENE_6:
        player->setMedia(scene6);
        qDebug() << "6";
        break;

    case SoundHandler::SCENE_7:
        player->setMedia(scene7);
        qDebug() << "7";
        break;

    case SoundHandler::SCENE_8:
        player->setMedia(scene8);
        qDebug() << "8";
        break;

    case SoundHandler::SCENE_9:
        player->setMedia(scene9);
        qDebug() << "9";
        break;

    case SoundHandler::SCENE_10:
        player->setMedia(scene10);
        player->setVolume(35);
        qDebug() << "10";
        break;
    }

    player->play();
}

/**
 * @brief Stop the sound
 * @param sound
 */
void SoundHandler::stopSound(const int sound)
{
    if (player->state() == QMediaPlayer::PlayingState)
    {
        player->pause();
        isLooping = false;
    }
}

/**
 * @brief Restart the sound
 * @param status
 */
void SoundHandler::restartSound(QMediaPlayer::MediaStatus status) {
    if (isLooping && status == QMediaPlayer::EndOfMedia) {
        player->play();
    }
}

/**
 * @brief Destructor of the class SoundHandler
 */
SoundHandler::~SoundHandler()
{
    delete player;
}
