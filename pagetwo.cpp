#include "pagetwo.h"
#include "ui_pagetwo.h"
#include "mainwindow.h"

#include <QLabel>
#include <QDebug>

PageTwo::PageTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);

    ClickableLabel *hive = this->findChild<ClickableLabel*>("hive");

    connect(hive, &ClickableLabel::clicked,
            dynamic_cast<MainWindow*>(this->parent()),
            &MainWindow::nextPage);
}

PageTwo::~PageTwo()
{
    delete ui;
}

/**
 * @brief Overide mouseEvent in order to adjust the magnitude of the effect
 * @param event
 */
void PageTwo::mouseMoveEvent(QMouseEvent *event) {

}

void PageTwo::initializePage()  {
    dynamic_cast<MainWindow*>(this->parent()->parent())
           ->getGestionHaptique()->startEffect(HapticHandler::SCENE_2);
   startTimer(50);
}

void PageTwo::timerEvent(QTimerEvent *event){
    // Center of hive X : 737, Y : 346 -> 10 000 of magnitude
    // Max Circle (top-right corner of label liam)  X : 280, Y : 400
    QPoint hiveCenter = QPoint(737, 346);
    QPoint maxPoint = QPoint(200, 400);

    int maxDistance = (hiveCenter.x() - maxPoint.x()) * (hiveCenter.x() - maxPoint.x())
            + (hiveCenter.y() - maxPoint.y()) * (hiveCenter.y() - maxPoint.y());

    QPoint mousePos = QCursor::pos();
    int currentDistance = (hiveCenter.x() - mousePos.x()) * (hiveCenter.x() - mousePos.x())
            + (hiveCenter.y() - mousePos.y()) * (hiveCenter.y() - mousePos.y());

    currentDistance = qBound(0, currentDistance, maxDistance);

    float percent = static_cast<float>(maxDistance - currentDistance)/ maxDistance;

    int val = qBound(0, static_cast<int>(10000 * percent), 10000);
    dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getGestionHaptique()
            ->changeMagnitudeOfScene_2(val);
}



