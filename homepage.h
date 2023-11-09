#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

#include "soundhandler.h"
#include "page.h"

namespace Ui
{
    class HomePage;
}

class HomePage : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    void initializePage() override;
    void setState(bool isActive) override;
    void stopSound();
    ~HomePage();

private:
    Ui::HomePage *ui;
    bool isActive;
};

#endif // HOMEPAGE_H
