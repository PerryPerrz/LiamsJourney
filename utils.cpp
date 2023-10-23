#include "utils.h"

Utils::Utils(QObject *parent) : QObject(parent)
{

}

bool Utils::areLabelsColliding(QLabel *a, QLabel *b){
    //Check if Liam's left corner is on the exit or no.
    QRect rect1 = a->geometry();
    QRect rect2 = b->geometry();

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
    // Il faut envoyer un signal
    return  !(right1 < left2 || left1 > right2 || bottom1 < top2 || top1 > bottom2);
}
