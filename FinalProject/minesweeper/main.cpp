#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(8,8,10, false);
    w.show();
    return a.exec();
}

//zoeb's random comment to test git stuff
//test
