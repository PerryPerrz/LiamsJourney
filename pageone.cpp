#include "pageone.h"
#include "ui_pageone.h"
#include "haptichandler.h"
#include "mainwindow.h"
#include "clickablelabel.h"

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

    //Check if Liam's left corner is on the exit or no.
    QRect rect1 = exit->geometry();
    QRect rect2 = liam->geometry();

    // Utilisez les coordonnées des coins des rectangles pour vérifier la collision
    int left1 = rect1.left();
    int right1 = rect1.right();
    int top1 = rect1.top();
    int bottom1 = rect1.bottom();

    int left2 = rect2.left();
    int right2 = rect2.right();
    int top2 = rect2.top();
    int bottom2 = rect2.bottom();

    // Vérifiez si les rectangles se chevauchent
    // Il faut envoyé un signal
   if ( !(right1 < left2 || left1 > right2 || bottom1 < top2 || top1 > bottom2)) {
        dynamic_cast<MainWindow*>(this->parent()->parent())->setCurrentPage(2);
       qDebug() << "Collision !";
   }
}
