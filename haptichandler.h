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
    void startEffect(const int effect);
    void stopEffect(const int effect);
    void changeMagnitudeOfScene_2(DWORD magnitude);

    enum Effects {
            SCENE_1,
            SCENE_2,
            SCENE_3,
            SCENE_4
        };

public slots:

private:
    void createEffects();

    CImmMouse *mSouris;
    MainWindow *mFenetre;

    CImmProject *mProject;
    CImmCompoundEffect *scene_1;
    CImmCompoundEffect *scene_2;
    CImmCompoundEffect *scene_3;
    CImmCompoundEffect *scene_4;
};

#endif // HAPTICHANDLER_H
