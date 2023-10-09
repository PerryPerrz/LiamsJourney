#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pageone.h"
#include "homepage.h"

#include <QPushButton>
#include <QStackedWidget>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mHaptique = new GestionHaptique(this);

    currentPage = new HomePage(this);
    setCentralWidget(currentPage);

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

/**
 * @brief Set the first Page
 */
void MainWindow::onPlayButtonClicked() {
     currentPage = new PageOne(this);
    setCentralWidget(currentPage);
}

MainWindow::~MainWindow()
{
    delete currentPage;
    delete ui;
}
