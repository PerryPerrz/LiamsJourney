#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCursor cursor(QPixmap(":/images/main_cursor.png"));
    QApplication::setOverrideCursor(cursor);

    MainWindow w;
    w.show();

    return a.exec();
}
