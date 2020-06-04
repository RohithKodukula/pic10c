#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int w, int h, int num):
    width(w),
    height(h),
    numMines(num),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    for(int i = 0; i < width; ++i)
    {
        mines.push_back( std::vector<int>(height) );
    }
}

void MainWindow::bomb_gen()
{
    for(int i = 0; i < numMines; ++i)
    {
        int x = rand() % height;
        int y = rand() % width;
        std::cout << x << " " << y << " " << RAND_MAX;
    }
}

void MainWindow::printboard()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

