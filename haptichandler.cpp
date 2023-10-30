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
        qDebug() << "===>  Loading sucessfull ! :)";

       createEffects();
    } else {
        qDebug()<<"===> Erreur chargement projet IFR avec code ! :("
                    <<CIFCErrors::GetLastErrorCode();
    }
}

/**
 * @brief This where the different effects are created
 */
void HapticHandler::createEffects() {
    scene_1 = mProject->CreateEffect("scene_1", mSouris, IMM_PARAM_NODOWNLOAD);

    // We modify the parameters : apparently they are not correctly charged from ImmStudio
   CImmFriction *myEffect = static_cast<CImmFriction*>(scene_1->GetContainedEffect(0L));
    myEffect->ChangeNegativeCoefficient(8000);
    myEffect->ChangePositiveCoefficient(8000);
    myEffect->ChangeNegativeSaturation(10000);
    myEffect->ChangePositiveSaturation(10000);
    myEffect->ChangeMinVelocity(0);
    myEffect->ChangeDirection(IMM_EFFECT_AXIS_BOTH);

    if (!scene_1) {
        qDebug()<<"===> Error loading scene_1 ";
        scene_1 = NULL;
    } else {
        qDebug()<<"===> Loading scene_1 sucessfull ";
    }

    scene_2 = mProject->CreateEffect("scene_2",  mSouris, IMM_PARAM_NODOWNLOAD);
    if (!scene_2) {
        qDebug()<<"===> Error loading scene_2 ";
        scene_1 = NULL;
    } else {
        qDebug()<<"===> Loading scene_2 sucessfull ";
    }

    scene_3 = mProject->CreateEffect("scene_3",  mSouris, IMM_PARAM_NODOWNLOAD);

    if (!scene_3) {
        qDebug()<<"===> Error loading scene_3 ";
        scene_1 = NULL;
    } else {
        qDebug()<<"===> Loading scene_3 sucessfull ";
    }

    scene_4 = mProject->CreateEffect("scene_4",  mSouris, IMM_PARAM_NODOWNLOAD);

    if (!scene_4) {
        qDebug()<<"===> Error loading scene_4 ";
        scene_1 = NULL;
    } else {
        qDebug()<<"===> Loading scene_4 sucessfull ";
    }
}

/**
  * @brief Start the vibratons of the haptic mouse
  */
 void HapticHandler::startEffect(const int effect) {
    switch (effect) {
        case HapticHandler::SCENE_1:
            scene_1->Start();
            break;
        case HapticHandler::SCENE_2:
            scene_2->Start();
            break;
        case HapticHandler::SCENE_3:
            scene_3->Start();
            break;
        case HapticHandler::SCENE_4:
            scene_4->Start();
            break;
    }
 }

 /**
  * @brief Stop the vibrations
  */
 void HapticHandler::stopEffect(const int effect) {
     switch (effect) {
         case HapticHandler::SCENE_1:
             scene_1->Stop();
             break;
         case HapticHandler::SCENE_2:
             scene_2->Stop();
             break;
         case HapticHandler::SCENE_3:
             scene_3->Stop();
             break;
         case HapticHandler::SCENE_4:
             scene_4->Stop();
             break;
     }
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

  void HapticHandler::changeMagnitudeOfScene_2(DWORD magnitude) {
     // this->scene_2->Stop();
     static_cast<CImmPeriodic*>(this->scene_2->GetContainedEffect(0L))
              ->ChangeMagnitude(magnitude);
 }
