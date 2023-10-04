#include <mainwindow.h>

GestionHaptique::GestionHaptique(MainWindow *fen): mFenetre(fen)
{
    mSouris = new CImmMouse();

    if(!mSouris -> Initialize(qWinAppInst(), (HWND)mFenetre-> effectiveWinId()))
    {
        delete mSouris;
        mSouris = NULL;
       qApp->quit();
        qDebug()<<"===>Erreur chargement souris ! :(";
    }

    mProject = new CImmProject();
    if(mProject->OpenFile("vibreur.ifr", mSouris))
    {
    }
    else {
        qDebug()<<"===> Erreur chargement projet IFR avec code ! :("
                    <<CIFCErrors::GetLastErrorCode();
    }
}
