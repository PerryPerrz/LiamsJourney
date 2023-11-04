#ifndef SOUNDHANDLER_H
#define SOUNDHANDLER_H

#include <QMainWindow>
#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class MainWindow;

class SoundHandler : public QObject
{
    Q_OBJECT
public:
    explicit SoundHandler(MainWindow *fen, QObject *parent = nullptr);
    ~SoundHandler();

    void startSounds(const int sound);
    void stopSounds(const int sound);

    enum Sounds {
        SCENE_1,
        SCENE_2,
        SCENE_3,
        SCENE_4,
        SCENE_5,
        SCENE_6,
        SCENE_7
    };

public slots:

private:
    MainWindow* mFenetre;
    QMediaPlayer *player;
    QMediaPlaylist *scene_1;
    QMediaPlaylist *scene_2;
    QMediaPlaylist *scene_3;
    QMediaPlaylist *scene_4;
    QMediaPlaylist *scene_5;
    QMediaPlaylist *scene_6;
    QMediaPlaylist *scene_7;
};

#endif // SOUNDHANDLER_H
