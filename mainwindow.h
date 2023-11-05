#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "haptichandler.h"
#include "soundhandler.h"

#include <QMainWindow>
#include <QKeyEvent>
#include <QStackedWidget>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyReleaseEvent(QKeyEvent *event);
    HapticHandler *getHapticHandler() const;
    SoundHandler *getSoundHandler() const;

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    HapticHandler *mHaptique;
    SoundHandler *mSon;
    QStackedWidget *currentPage;

public slots:
    void nextPage();
    void setCurrentPage(int pageNumber);
};

#endif // MAINWINDOW_H
