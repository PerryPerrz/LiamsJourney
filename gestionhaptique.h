#ifndef GESTIONHAPTIQUE_H
#define GESTIONHAPTIQUE_H

#undef UNICODE

#include <ifc.h>
#include <QMainWindow>
#include <QApplication>
#include <QDebug>
class MainWindow;

class GestionHaptique
{
public:
    GestionHaptique(MainWindow *fen);
    CImmProject *GetProject() const;

    ~GestionHaptique();
private:
    CImmMouse *mSouris;
    MainWindow *mFenetre;

    CImmProject *mProject;
};
#endif
