#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    ~ClickableLabel();

signals:
    void clicked();  // Signal emit when label is clicked with left button

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // CLICKABLELABEL_H
