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
    if(mProject->OpenFile("E:\\LiamsJourney\\ressources\\effects\\vibreur.ifr", mSouris))
    {
        qDebug() << "===> Chargement réussi ! :)";

        mVibreur = mProject->CreateEffect("Periodic", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mVibreur) {
            qDebug()<<"===>Erreur chargement eau ";
            delete mVibreur;
            mVibreur = NULL;
        } else {
            qDebug()<<"===>Chargement vibreur réussi ";
            //mVibreur->Start();
        }
    } else {
        qDebug()<<"===> Erreur chargement projet IFR avec code ! :("
                    <<CIFCErrors::GetLastErrorCode();
    }
}
