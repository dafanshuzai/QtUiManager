#include "mainwindow.h"
#include <QApplication>
#include "dbutil.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DbUtil::initTable();
    MainWindow w;
    w.show();

    return a.exec();
}