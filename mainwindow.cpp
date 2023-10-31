#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pageone.h"
#include "pagetwo.h"
#include "homepage.h"
#include "pagethree.h"
#include "pagefour.h"
#include "pagefive.h"
#include "pagesix.h"
#include "pageseven.h"
#include "pageeight.h"

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
    this->mHaptique = new HapticHandler(this);
    currentPage = new QStackedWidget();
    currentPage->insertWidget(0, new HomePage(this));
    currentPage->insertWidget(1, new PageOne(this));
    currentPage->insertWidget(2, new PageTwo(this));
    currentPage->insertWidget(3, new PageThree(this));
    currentPage->insertWidget(4, new PageFour(this));
    currentPage->insertWidget(5, new PageFive(this));
    currentPage->insertWidget(6, new PageSix(this));
    currentPage->insertWidget(7, new PageSeven(this));
    currentPage->insertWidget(8, new PageEight(this));
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
void MainWindow::nextPage() {
    int index = this->currentPage->currentIndex();
    currentPage->setCurrentIndex(++index);
    dynamic_cast<Page*>(currentPage->currentWidget())->initializePage();
}

/**
  * @brief MainWindow::getGestionHaptique
  * @return the haptic handler
  */
 HapticHandler* MainWindow::getGestionHaptique() const {
    return mHaptique;
 }

 void MainWindow::setCurrentPage(int pageNumber){
    this->currentPage->setCurrentIndex(pageNumber);
    dynamic_cast<Page*>(currentPage->currentWidget())->initializePage();
 }

MainWindow::~MainWindow()
{
    delete currentPage;
    delete mHaptique;
    delete ui;
}
