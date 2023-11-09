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

    enum Sounds
    {
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
    MainWindow *mFenetre;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
};

#endif // SOUNDHANDLER_H
