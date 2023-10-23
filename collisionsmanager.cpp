#include "collisionsmanager.h"

#include <QRect>

CollisionsManager::CollisionsManager(QObject *parent) : QObject(parent)
{

}

void CollisionsManager::areLabelsColliding(QLabel *label1, QLabel *label2) {
    QRect rect1 = label1->geometry();
    QRect rect2 = label2->geometry();

    // Utilisez les coordonnées des coins des rectangles pour vérifier la collision
    int left1 = rect1.left();
    int right1 = rect1.right();
    int top1 = rect1.top();
    int bottom1 = rect1.bottom();

    int left2 = rect2.left();
    int right2 = rect2.right();
    int top2 = rect2.top();
    int bottom2 = rect2.bottom();

    // Vérifiez si les rectangles se chevauchent
    // Il faut envoyé un signal
   // return !(right1 < left2 || left1 > right2 || bottom1 < top2 || top1 > bottom2);
}

