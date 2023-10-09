#include "mainwindow.h"
#include "ui_mainwindow.h"

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

MainWindow::~MainWindow()
{
    delete ui;
}
