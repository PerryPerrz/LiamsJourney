#include "homepage.h"
#include "ui_homepage.h"
#include "mainwindow.h"
#include "clickablelabel.h"

#include <QDebug>

HomePage::HomePage(QWidget *parent) : QWidget(parent),
                                      ui(new Ui::HomePage)
{
    ui->setupUi(this);

    // Get the sound handler from the main window
    MainWindow *mainWindow = dynamic_cast<MainWindow *>(this->parent());
    if (mainWindow)
    {
        SoundHandler *soundHandler = mainWindow->getSoundHandler();
        if (soundHandler)
        {
            soundHandler->startSounds(SoundHandler::SCENE_1);
        }
        else
        {
            qDebug() << "Error: could not start sound";
        }
    }
    else
    {
        qDebug() << "Error: could not get sound handler";
    }

    // Signal defined for the play button
    ClickableLabel *playButton = this->findChild<ClickableLabel *>("playButton");
    connect(playButton, &ClickableLabel::clicked, dynamic_cast<MainWindow *>(this->parent()), &MainWindow::nextPage);
    connect(playButton, &ClickableLabel::clicked, this, &HomePage::stopSound);

    isActive = false;
}

void HomePage::initializePage()
{
    setState(true);
}

void HomePage::stopSound()
{
    if (isActive) {
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getSoundHandler()
            ->stopSounds(SoundHandler::SCENE_1);
    }
}

void HomePage::setState(bool isActive) {
    this->isActive =isActive;
}

HomePage::~HomePage()
{
    delete ui;
}
