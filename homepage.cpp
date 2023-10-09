#include "homepage.h"
#include "ui_homepage.h"
#include "mainwindow.h"

#include <QPushButton>

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    // Signal defined for the play button
    QPushButton *playButton = this->findChild<QPushButton*>("playButton");
    connect(playButton, &QPushButton::clicked, dynamic_cast<MainWindow*>(this->parent()), &MainWindow::onPlayButtonClicked);
}

HomePage::~HomePage()
{
    delete ui;
}
