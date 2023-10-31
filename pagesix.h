#ifndef PAGESIX_H
#define PAGESIX_H

#include "page.h"

#include <QWidget>

namespace Ui {
class PageSix;
}

class PageSix : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit PageSix(QWidget *parent = 0);
    void initializePage() override;
    ~PageSix();

public slots:
    void onSpoonMouve();
    void onDragAndDropStopped();

private:
    Ui::PageSix *ui;
    bool isEnter;
    int jarState;
    bool done;
};

#endif // PAGESIX_H
