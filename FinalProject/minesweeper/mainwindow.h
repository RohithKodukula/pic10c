#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <QGridLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int w, int h, int num);
    ~MainWindow();

    void bomb_gen(int x_clear, int y_clear);
    void placeMine(int x, int y);

private:
    Ui::MainWindow *ui;
    QGridLayout* layout;

    int width;
    int height;
    int numMines;
    std::vector<std::vector<int>> mines;

};
#endif // MAINWINDOW_H
