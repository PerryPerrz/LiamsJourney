#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gestionhaptique.h>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyReleaseEvent(QKeyEvent *event);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GestionHaptique *mHaptique;
    QWidget *currentPage;

public slots:
    void onPlayButtonClicked();
};

#endif // MAINWINDOW_H
