#include "pageseven.h"
#include "ui_pageseven.h"
#include "mainwindow.h"
#include "clickablelabel.h"
#include "utils.h"

#include <QLabel>

PageSeven::PageSeven(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSeven)
{
    ui->setupUi(this);

    ClickableLabel *spoon = this->findChild<ClickableLabel*>("spoon");
    spoon->setMoveable(true);

    connect(spoon, &ClickableLabel::moved, this, &PageSeven::onSpoonMoved);
    connect(spoon, &ClickableLabel::stopDragAndDrop, this, &PageSeven::onSpoonReleased);

    count = 0;
    done = false;
    isTriggered = false;
}

PageSeven::~PageSeven()
{
    delete ui;
}

void PageSeven::initializePage() {
}

void PageSeven::onSpoonMoved() {
    ClickableLabel *spoon = this->findChild<ClickableLabel*>("spoon");
    QLabel *honey = this->findChild<QLabel*>("honey");
    QLabel *counter = this->findChild<QLabel*>("counter");


    Utils utils = Utils();

    if (utils.areLabelsColliding(spoon, honey)) {
        dynamic_cast<MainWindow*>(this->parent()->parent())
                ->getHapticHandler()
                ->startEffect(HapticHandler::SCENE_7);
    } else {
        dynamic_cast<MainWindow*>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_7);
    }

    if (count < 10 && utils.areLabelsColliding(spoon, counter) && !isTriggered) {
        count++;
        isTriggered = true;
    } else if (count == 10 && !done && utils.areLabelsColliding(spoon, counter)) {
        dynamic_cast<MainWindow*>(this->parent()->parent())
                ->getHapticHandler()
                ->stopEffect(HapticHandler::SCENE_7);

        dynamic_cast<MainWindow*>(this->parent()->parent())
                ->nextPage();
        done = true;
    } else if (!utils.areLabelsColliding(spoon, counter)) {
        isTriggered = false;
    }
}

void PageSeven::onSpoonReleased() {
    dynamic_cast<MainWindow*>(this->parent()->parent())
            ->getHapticHandler()
            ->stopEffect(HapticHandler::SCENE_7);
}
