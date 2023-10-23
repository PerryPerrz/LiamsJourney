#include "pageone.h"
#include "ui_pageone.h"
#include "haptichandler.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QPushButton>

PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);

    // Set the signals and slots of the button start and stop
    /*QPushButton* startButton = this->findChild<QPushButton*>("startButton");
    connect(startButton, &QPushButton::clicked,
            dynamic_cast<MainWindow*>(this->parent())->getGestionHaptique(),
            &HapticHandler::onStartVibrator);

    QPushButton* stopButton = this->findChild<QPushButton*>("stopButton");
    connect(stopButton, &QPushButton::clicked,
            dynamic_cast<MainWindow*>(this->parent())->getGestionHaptique(),
            &HapticHandler::onStopVibrator);*/

    //Define liam moveable
    ClickableLabel *liam = this->findChild<ClickableLabel*>("liam");
    liam->setMoveable(true);
    connect(liam, &ClickableLabel::moved, this, &PageOne::onExit);

    QLabel* exit = this->findChild<QLabel*>("exit");
    exit->setVisible(false);
}

PageOne::~PageOne()
{
    delete ui;
}

/**
 * @brief PageOne::onExit
 */
void PageOne::onExit(){
    //get the size of the parent window
    QLabel *exit = this->findChild<QLabel*>("exit");
    ClickableLabel *liam = this->findChild<ClickableLabel*>("liam");

    Utils utils = Utils();
    if (utils.areLabelsColliding(exit, liam)) {
        dynamic_cast<MainWindow*>(this->parent()->parent())->setCurrentPage(2);
    }
}
