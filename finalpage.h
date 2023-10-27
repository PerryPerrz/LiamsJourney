#ifndef FINALPAGE_H
#define FINALPAGE_H

#include <QWidget>

namespace Ui {
class FinalPage;
}

class FinalPage : public QWidget
{
    Q_OBJECT

public:
    explicit FinalPage(QWidget *parent = 0);
    ~FinalPage();

private:
    Ui::FinalPage *ui;
};

#endif // FINALPAGE_H
