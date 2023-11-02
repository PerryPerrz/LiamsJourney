#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QMediaPlayer>

#include "page.h"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    void initializePage() override;
    void stopSound();
    ~HomePage();

private:
    Ui::HomePage *ui;
    QMediaPlayer* player;
};

#endif // HOMEPAGE_H
