#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int w, int h, int num);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int width;
    int height;
    int numMines;
    std::vector<std::vector<int>> mines;

    void bomb_gen();
    void printboard();
};
#endif // MAINWINDOW_H
