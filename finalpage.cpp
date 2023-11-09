#include "finalpage.h"
#include "ui_finalpage.h"
#include "mainwindow.h"
#include "clickablelabel.h"

#include <QLabel>

FinalPage::FinalPage(QWidget *parent) : QWidget(parent),
                                        ui(new Ui::FinalPage)
{
    ui->setupUi(this);

    ClickableLabel *exitButton = this->findChild<ClickableLabel *>("exitButton");
    connect(exitButton, &ClickableLabel::clicked,
            dynamic_cast<MainWindow *>(this->parent()),
            &MainWindow::close);
}

FinalPage::~FinalPage()
{
    delete ui;
}

void FinalPage::initializePage()
{
}

void FinalPage::setState(bool isActive) {
    this->isActive = isActive;
}
