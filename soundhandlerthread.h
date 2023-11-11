#ifndef SOUNDHANDLERTHREAD_H
#define SOUNDHANDLERTHREAD_H

#include <QThread>
#include <QMediaContent>

class QMediaPlayer;

class SoundHandlerThread : public QThread {
    Q_OBJECT
public:
    explicit SoundHandlerThread(QObject *parent = nullptr);
    ~SoundHandlerThread();

signals:
    void playbackFinished();

protected:
    void run() override;
    QMediaPlayer *player;
    QMediaContent audio;

};

#endif // SOUNDHANDLERTHREAD_H
