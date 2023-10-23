#include "clickablelabel.h"

#include <QDebug>
#include <QWindow>
#include <QPoint>

ClickableLabel::ClickableLabel(QWidget *parent,  bool moveable) : QLabel(parent), m_moveable(moveable)
{
    doDragAndDrop = false;
}

ClickableLabel::~ClickableLabel()
{
}

bool ClickableLabel::isMoveable() const {
    return m_moveable;
}

void ClickableLabel::setMoveable(const bool &nm) {
    m_moveable = nm;
}

/**
 * @brief Redefining the mouse release event in order to emit a signal when the
 * label is clicked and start the drag and drop event if the label is moveable
 * @param event
 */
void ClickableLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked();
        if (m_moveable) {
            doDragAndDrop = false;
            emit(stopDragAndDrop());
        }
    }
    QLabel::mouseReleaseEvent(event);
}

/**
 * @brief Redefine the mouse press event in order to stop the drag & drop event when
 * the clic is release
 * @param event
 */
void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (m_moveable) {
            doDragAndDrop = true;
            firstPosOnDragAndDrop = event->pos();
        }
    }
    QLabel::mousePressEvent(event);
}

 void ClickableLabel::mouseMoveEvent(QMouseEvent *event) {

     if (doDragAndDrop) {
         if (event->buttons() & Qt::LeftButton)
             {
             //qDebug() << "===> It's working";
                 dragAndDrop(event);
             }
     }
     QLabel::mouseMoveEvent(event);
 }

 /**
 * @brief Fonction qui effectue le drag an drop
 * @param event
 */
void ClickableLabel::dragAndDrop(QMouseEvent *event) {
    QPoint mousePos = this->mapToGlobal(event->pos());
    this->move(mousePos - firstPosOnDragAndDrop);

    //Emit the objectMoved signal with the new position
    emit moved();
}
