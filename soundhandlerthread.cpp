#include "soundhandlerthread.h"
#include <QMediaPlayer>
#include <QUrl>
#include <QDebug>

SoundHandlerThread::SoundHandlerThread(QObject *parent) : QThread(parent), player(nullptr) {
    player = new QMediaPlayer();
    audio = QMediaContent(QUrl("file:///E:/LiamsJourney/sounds/forest.mp3"));
}

SoundHandlerThread::~SoundHandlerThread() {
    if (player) {
        delete player;
        player = nullptr;
    }
}

void SoundHandlerThread::run() {

    qDebug() << audio.isNull();

   // qDebug() << player->isAudioAvailable();

    /*connect(player, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state){
        if (state == QMediaPlayer::StoppedState)
            emit playbackFinished();
    });*/

    try {
        player->setMedia(audio);
        player->play();
    } catch (const std::exception &e) {
        qDebug() << "Erreur : " << e.what();
    }



    exec();
}
