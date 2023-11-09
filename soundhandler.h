#ifndef SOUNDHANDLER_H
#define SOUNDHANDLER_H

#include <QMainWindow>
#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>

class MainWindow;

class SoundHandler : public QObject
{
    Q_OBJECT
public:
    explicit SoundHandler(MainWindow *fen, QObject *parent = nullptr);
    ~SoundHandler();

    void startSound(const int sound);
    void stopSound(const int sound);

    enum Sounds
    {
        SCENE_1,
        SCENE_2,
        SCENE_3,
        SCENE_4,
        SCENE_5,
        SCENE_6,
        SCENE_7,
        SCENE_8,
        SCENE_9,
        SCENE_10
    };

public slots:

private:
    MainWindow *mFenetre;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;

    QMediaContent scene1;
    QMediaContent scene2;
    QMediaContent scene3;
    QMediaContent scene4;
    QMediaContent scene5;
    QMediaContent scene6;
    QMediaContent scene7;
    QMediaContent scene8;
    QMediaContent scene9;
    QMediaContent scene10;
    QMediaContent scene11;
    QMediaContent scene12;
};

#endif // SOUNDHANDLER_H
