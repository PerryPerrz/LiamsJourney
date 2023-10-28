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
    if(mProject->OpenFile("E:\\LiamsJourney\\effects\\effets.ifr", mSouris))
    {
        qDebug() << "===> Chargement réussi ! :)";

        mVibreur = mProject->CreateEffect("scene_1", mSouris, IMM_PARAM_NODOWNLOAD);

        // We modify the parameters : apparently they are not correctly charged from ImmStudio
       CImmFriction *myEffect = static_cast<CImmFriction*>(mVibreur->GetContainedEffect(0L));
        myEffect->ChangeNegativeCoefficient(8000);
        myEffect->ChangePositiveCoefficient(8000);
        myEffect->ChangeNegativeSaturation(10000);
        myEffect->ChangePositiveSaturation(10000);
        myEffect->ChangeMinVelocity(0);
        myEffect->ChangeDirection(IMM_EFFECT_AXIS_BOTH);

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
 void HapticHandler::startVibrator() {
   mVibreur->Start();
 }

 /**
  * @brief Stop the vibrations
  */
 void HapticHandler::stopVibrator() {
      mVibreur->Stop();
  }

 HapticHandler::~HapticHandler() {
     if (mProject) {
         delete mProject;
     }
     if (mSouris) {
         delete mSouris;
     }

     /**
       This is an exemple of creating an Effect

         CImmFriction *effect = new CImmFriction();
         effect->Initialize(
                     this->mSouris,
                     8000,
                     IMM_FRICTION_DEFAULT_MIN_VELOCITY,
                     IMM_EFFECT_AXIS_BOTH,
                     IMM_EFFECT_DEFAULT_DIRECTION_X,
                     IMM_EFFECT_DEFAULT_DIRECTION_Y);
    **/
 }
