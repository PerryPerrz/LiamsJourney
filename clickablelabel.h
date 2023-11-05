#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include <QString>

class ClickableLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(bool moveable READ isMoveable WRITE setMoveable)

public:
    explicit ClickableLabel(QWidget *parent = nullptr, bool moveable = false, QString restriction = "none");
    ~ClickableLabel();
    bool isMoveable() const;
    void setMoveable(const bool &nm);
    void setRestriction(const QString &rest);

signals:
    void clicked(); // Signal emit when label is clicked with left button
    void moved();   // Signal emit when label is moved
    void stopDragAndDrop();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    // Fuctions
    void dragAndDrop(QMouseEvent *event);

    // Attributes
    bool m_moveable;
    bool doDragAndDrop;
    QPoint firstPosOnDragAndDrop;
    QString m_restriction;
};

#endif // CLICKABLELABEL_H
