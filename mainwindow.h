#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "haptichandler.h"

#include <QMainWindow>
#include <QKeyEvent>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyReleaseEvent(QKeyEvent *event);
    HapticHandler* getGestionHaptique() const;

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    HapticHandler *mHaptique;
    QStackedWidget *currentPage;

public slots:
    void onPlayButtonClicked();
};

#endif // MAINWINDOW_H
