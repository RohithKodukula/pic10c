#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <QGridLayout>

#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //width, height, and number of bombs on the board
    MainWindow(int w, int h, int num, bool cheat = false);
    ~MainWindow();

    void update_bombs(); //update from initialization values (all zeroes)
    void bomb_gen(int x_clear, int y_clear); //randomly generate without putting on
                                             //existing bombs or x_clear y_clear coord

    void placeMine(int x, int y); //places bomb and updates neighbors

    void clear_neighbors(int x, int y); //clear neighbors too if they have 0 neighbors

private:
    Ui::MainWindow *ui;
    QGridLayout* layout;

    int width;
    int height;
    int numMines;
    bool cheat;
    std::vector<std::vector<Cell>> mines; //double vector of all the cell

};
#endif // MAINWINDOW_H
