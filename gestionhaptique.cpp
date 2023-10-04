#include <mainwindow.h>

GestionHaptique::GestionHaptique(MainWindow *fen): mFenetre(fen)
{
    mSouris = new CImmMouse();

    if(!mSouris -> Initialize(qWinAppInst(), (HWND)mFenetre-> effectiveWinId()))
    {
        delete mSouris;
        mSouris = NULL;
       qApp->quit();
        qDebug()<<"===>Erreur chargemet souris ! :(";
    }
}
