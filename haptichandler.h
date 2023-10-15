#ifndef HAPTICHANDLER_H
#define HAPTICHANDLER_H

#undef UNICODE

#include <ifc.h>
#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QObject>

class MainWindow;

class HapticHandler : public QObject
{
    Q_OBJECT
public:
    explicit HapticHandler(MainWindow *fen, QObject *parent = 0);
    ~HapticHandler();
    CImmProject *GetProject() const;

public slots:
    void onStartVibrator();
    void onStopVibrator();

private:
    CImmMouse *mSouris;
    MainWindow *mFenetre;

    CImmProject *mProject;
    CImmCompoundEffect *mVibreur;
};

#endif // HAPTICHANDLER_H
