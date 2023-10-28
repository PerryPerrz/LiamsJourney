#include "clickablelabel.h"

#include <QDebug>
#include <QWindow>
#include <QPoint>

ClickableLabel::ClickableLabel(QWidget *parent,  bool moveable,  QString restriction) : QLabel(parent), m_moveable(moveable), m_restriction(restriction)
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
    //QLabel::mouseReleaseEvent(event);
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
    //QLabel::mousePressEvent(event);
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

    if (QString::compare(this->m_restriction, QString("none")) == 0) {
        QPoint mousePos = this->mapToGlobal(event->pos());
        this->move(mousePos - firstPosOnDragAndDrop);

    } else if (QString::compare(this->m_restriction, QString("x")) == 0) {
        const QPoint mousePos = this->mapToGlobal(event->pos());
        int posX = qBound(135, mousePos.x() - firstPosOnDragAndDrop.x(), 210);
        QPoint newPos = QPoint(posX , this->geometry().y());
        this->move(newPos);
    }

    emit moved();
}

/**
 * @brief Set a movement restriction by default "none" cne be "x" for horizontal deplacement only
 *  and "y" for vertical deplacement only
* @param rest
 */
void ClickableLabel::setRestriction(const QString &rest) {
    this->m_restriction = rest;
}

