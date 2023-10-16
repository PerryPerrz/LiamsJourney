#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

class ClickableLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(bool moveable READ isMoveable WRITE setMoveable)

public:
    explicit ClickableLabel(QWidget *parent = nullptr, bool moveable = false);
    ~ClickableLabel();
    bool isMoveable() const;
    void setMoveable(const bool &nm);

signals:
    void clicked();  // Signal emit when label is clicked with left button

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
    QPoint  firstPosOnDragAndDrop;
};

#endif // CLICKABLELABEL_H
