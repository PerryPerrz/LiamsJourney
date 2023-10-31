#ifndef PAGEONE_H
#define PAGEONE_H

#include "page.h"

#include <QWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>

namespace Ui {
class PageOne;
}

class PageOne : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageOne(QWidget *parent = 0);
    void startSound();
    void initializePage() override;
    ~PageOne();

public slots :
    void onCollide();
    void onStopDragAndDrop();

private:
    Ui::PageOne *ui;
    bool isWalking;
    QMediaPlaylist *playlist;
    QMediaPlayer* player;
    bool isFirstSound;

signals:
    void walk();
};

#endif // PAGEONE_H
