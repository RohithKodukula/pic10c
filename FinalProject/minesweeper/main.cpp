#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(8,8,30);
    w.bomb_gen();
    w.printboard();
    w.show();
    return a.exec();
}

//zoeb's random comment to test git stuff
//test
