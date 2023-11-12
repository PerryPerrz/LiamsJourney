#include "homepage.h"
#include "ui_homepage.h"
#include "mainwindow.h"
#include "clickablelabel.h"

#include <QDebug>

/**
 * @brief Constructor of the class HomePage
 * @param parent
 */
HomePage::HomePage(QWidget *parent) : QWidget(parent),
                                      ui(new Ui::HomePage)
{
    ui->setupUi(this);

    // Get the sound handler from the main window
    dynamic_cast<MainWindow *>(this->parent())
        ->getSoundHandler()
        ->startSound(SoundHandler::SCENE_1);

    // Signal defined for the play button
    ClickableLabel *playButton = this->findChild<ClickableLabel *>("playButton");
    connect(playButton, &ClickableLabel::clicked, dynamic_cast<MainWindow *>(this->parent()), &MainWindow::nextPage);
    connect(playButton, &ClickableLabel::clicked, this, &HomePage::stopSound);

    isActive = false;
}

/**
 * @brief Initialize the page
 */
void HomePage::initializePage()
{
    setState(true);
}

/**
 * @brief Stop the sound of the page
 */
void HomePage::stopSound()
{
    if (isActive)
    {
        dynamic_cast<MainWindow *>(this->parent()->parent())
            ->getSoundHandler()
            ->stopSound(SoundHandler::SCENE_1);
    }
}

/**
 * @brief Set the state of the page
 * @param isActive
 */
void HomePage::setState(bool isActive)
{
    this->isActive = isActive;
}

/**
 * @brief Destructor of the class HomePage
 */
HomePage::~HomePage()
{
    delete ui;
}
