#include "pageone.h"
#include "ui_pageone.h"
#include "haptichandler.h"
#include "mainwindow.h"

#include <QPushButton>

PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);

    // Set the signals and slots of the button start and stop
    QPushButton* startButton = this->findChild<QPushButton*>("startButton");
    connect(startButton, &QPushButton::clicked,
            dynamic_cast<MainWindow*>(this->parent())->getGestionHaptique(),
            &HapticHandler::onStartVibrator);

    QPushButton* stopButton = this->findChild<QPushButton*>("stopButton");
    connect(stopButton, &QPushButton::clicked,
            dynamic_cast<MainWindow*>(this->parent())->getGestionHaptique(),
            &HapticHandler::onStopVibrator);
}

PageOne::~PageOne()
{
    delete ui;
}
