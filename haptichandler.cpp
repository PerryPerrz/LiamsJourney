#include "haptichandler.h"
#include "mainwindow.h"

HapticHandler::HapticHandler(MainWindow *fen, QObject *parent) : QObject(parent), mFenetre(fen)
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
    if(mProject->OpenFile("E:\\LiamsJourney\\effects\\vibreur.ifr", mSouris))
    {
        qDebug() << "===> Chargement réussi ! :)";

        mVibreur = mProject->CreateEffect("Periodic", mSouris, IMM_PARAM_NODOWNLOAD);
        if (!mVibreur) {
            qDebug()<<"===>Erreur chargement eau ";
            delete mVibreur;
            mVibreur = NULL;
        } else {
            qDebug()<<"===>Chargement vibreur réussi ";
        }
    } else {
        qDebug()<<"===> Erreur chargement projet IFR avec code ! :("
                    <<CIFCErrors::GetLastErrorCode();
    }
}

/**
  * @brief Start the vibratons of the haptic mouse
  */
 void HapticHandler::onStartVibrator() {
    mVibreur->Start();
 }

 /**
  * @brief Stop the vibrations
  */
 void HapticHandler::onStopVibrator() {
      mVibreur->Stop();
  }