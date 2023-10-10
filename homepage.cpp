#include "homepage.h"
#include "ui_homepage.h"
#include "mainwindow.h"
#include "clickablelabel.h"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    // Signal defined for the play button
    ClickableLabel *playButton = this->findChild<ClickableLabel*>("playButton");
    connect(playButton, &ClickableLabel::clicked, dynamic_cast<MainWindow*>(this->parent()), &MainWindow::onPlayButtonClicked);
}

HomePage::~HomePage()
{
    delete ui;
}
