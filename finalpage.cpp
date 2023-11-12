#include "finalpage.h"
#include "ui_finalpage.h"
#include "mainwindow.h"
#include "clickablelabel.h"

#include <QLabel>

/**
 * @brief Constructor of the class FinalPage
 * @param parent
 */
FinalPage::FinalPage(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::FinalPage)
{
    ui->setupUi(this);

    ClickableLabel *exitButton = this->findChild<ClickableLabel *>("exitButton");
    connect(exitButton, &ClickableLabel::clicked,
            dynamic_cast<MainWindow *>(this->parent()),
            &MainWindow::close);

    connect(exitButton, &ClickableLabel::clicked, this, &FinalPage::stopSound);
}

/**
 * @brief Destructor of the class FinalPage
 */
FinalPage::~FinalPage()
{
    delete ui;
}

/**
 * @brief Initialize the page
 */
void FinalPage::initializePage()
{
}

/**
 * @brief Set the state of the page
 * @param isActive
 */
void FinalPage::setState(bool isActive)
{
    this->isActive = isActive;
}

/**
 * @brief Stop the sound of the page
 */
void FinalPage::stopSound()
{
    dynamic_cast<MainWindow *>(this->parent()->parent())
        ->getSoundHandler()
        ->stopSound(SoundHandler::SCENE_10);
}
