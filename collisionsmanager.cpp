#include "collisionsmanager.h"

CollisionsManager::CollisionsManager(QObject *parent) : QObject(parent)
{

}

bool areWidgetsColliding(QWidget *widget1, QWidget *widget2) {
    QRect rect1 = widget1->geometry();
    QRect rect2 = widget2->geometry();

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
    return !(right1 < left2 || left1 > right2 || bottom1 < top2 || top1 > bottom2);
}

