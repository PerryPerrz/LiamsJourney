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
    // Center of hive X : 737, Y : 346 -> 10 000 of magnitude
    // Max Circle (top-right corner of label liam)  X : 280, Y : 400
    QPoint hiveCenter = QPoint(737, 346);
    QPoint maxPoint = QPoint(200, 768);

    int maxDistance = (hiveCenter.x() - maxPoint.x()) * (hiveCenter.x() - maxPoint.x())
            + (hiveCenter.y() - maxPoint.y()) * (hiveCenter.y() - maxPoint.y());

    QPoint mousePos = this->mapToGlobal(event->pos());
    int currentDistance = (hiveCenter.x() - mousePos.x()) * (hiveCenter.x() - mousePos.x())
            + (hiveCenter.y() - mousePos.y()) * (hiveCenter.y() - mousePos.y());

    int diff = maxDistance - currentDistance;
    if (diff < 0) {
        diff = 1;
    }
    dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getGestionHaptique()
            ->changeMagnitudeOfScene_2( (10000 * diff) / maxDistance);

    qDebug() << (10000 * diff) / maxDistance;

    QWidget::mouseMoveEvent(event);
}

