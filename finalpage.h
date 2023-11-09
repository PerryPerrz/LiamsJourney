#ifndef FINALPAGE_H
#define FINALPAGE_H

#include "page.h"

#include <QWidget>

namespace Ui
{
    class FinalPage;
}

class FinalPage : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit FinalPage(QWidget *parent = 0);
    void initializePage() override;
     void setState(bool isActive) override;
     void stopSound();
    ~FinalPage();

private:
    Ui::FinalPage *ui;
    bool isActive;
};

#endif // FINALPAGE_H
