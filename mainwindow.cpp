#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pageone.h"

#include <QPushButton>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mHaptique = new GestionHaptique(this);

    // Set the background image
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QImage("E:\\LiamsJourney\\ressources\\images\\home_image.png")));
    setPalette(palette);

    // Turn on fullscreen
    setWindowState(Qt::WindowFullScreen);

    //Add play button
    QPushButton *playButton = new QPushButton("Jouer", this);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::onPlayButtonClicked);
}

/**
 * @brief Close the application when the escape key is released
 * @param event
 */
void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        close();
    }
}

/**
 * @brief Set the first Page
 */
void MainWindow::onPlayButtonClicked() {
    PageOne *pageOne = new PageOne(this);
    setCentralWidget(pageOne);
}

MainWindow::~MainWindow()
{
    delete ui;
}
