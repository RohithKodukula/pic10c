#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(3,3,1);
    w.bomb_gen(0,0);
    w.show();
    return a.exec();
}

//zoeb's random comment to test git stuff
//test
