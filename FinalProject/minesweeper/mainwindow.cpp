#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.cpp"

MainWindow::MainWindow(int w, int h, int num, bool c):
    width(w),
    height(h),
    numMines(num),
    cheat(c),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    for(int i = 0; i < width; ++i)
    {
        mines.push_back( std::vector<Cell>(height)  );
        for(int j = 0; j < height; ++j)
        {
            mines[  i][j] = 0;
            mines[i][j].setCoords(i,j);
            QObject::connect(&mines[i][j], &Cell::rightClicked, this, &MainWindow::flag);
            QObject::connect(&mines[i][j], &Cell::clear_this, this, &MainWindow::clear_neighbors);

        }
    }
    bomb_gen(0,0);
    std::cout << "constructed window..." << std::endl;

    layout = new QGridLayout();
    layout->setSpacing(0);
    QWidget* centralWidget = new QWidget();
    for(int i = 0; i < width; ++i)
    {
        mines.push_back( std::vector<Cell>(height)  );
        for(int j = 0; j < height; ++j)
        {
            layout->addWidget(&mines[i][j], i, j);
            mines[i][j].setCurrentIndex(0);
        }
    }
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}

void MainWindow::flag(int x, int y)
{
    if(mines[x][y].button->text() == "🚩")
    {
        mines[x][y].button->setText("");
    }
    else
    {
        mines[x][y].button->setText("🚩");
    }
}

void MainWindow::clear_neighbors(int x, int y)
{
    std::cout << "clearing neigbors" << std::endl;
    //top left corner
    if(y == 0 && x == 0)
    {
        if(!mines[x][y+1].cleared)
            mines[x][y+1].clear();
        if(!mines[x+1][y].cleared)
            mines[x+1][y].clear();
        if(!mines[x+1][y+1].cleared)
            mines[x+1][y+1].clear();
        return;
    }
    //top right corner
    else if( y == (width - 1) && x == 0)
    {
        if(!mines[x][y-1].cleared)
            mines[x][y-1].clear();
        if(!mines[x+1][y-1].cleared)
            mines[x+1][y-1].clear();
        if(!mines[x+1][y].cleared)
            mines[x+1][y].clear();
        return;
    }
    //bottom right corner
    else if(y == (width - 1) && x == (height -1))
    {
        if(!mines[x][y-1].cleared)
            mines[x][y-1].clear();
        if(!mines[x-1][y-1].cleared)
            mines[x-1][y-1].clear();
        if(!mines[x-1][y].cleared)
            mines[x-1][y].clear();
        return;
    }
    //bottom left corner
    else if(y == 0 && x == (height -1))
    {
        if(!mines[x][y+1].cleared)
            mines[x][y+1].clear();
        if(!mines[x-1][y+1].cleared)
            mines[x-1][y+1].clear();
        if(!mines[x-1][y].cleared)
            mines[x-1][y].clear();
        return;
    }
    //right side
    else if(y == (width - 1) && x != 0)
    {
        if(!mines[x-1][y].cleared)
            mines[x-1][y].clear();
        if(!mines[x+1][y-1].cleared)
            mines[x+1][y-1].clear();
        if(!mines[x][y-1].cleared)
            mines[x][y-1].clear();
        if(!mines[x-1][y-1].cleared)
            mines[x-1][y-1].clear();
        if(!mines[x+1][y].cleared)
            mines[x+1][y].clear();
        return;
    }
    //left side
    else if(y == 0 && x != 0)
    {
        if(!mines[x+1][y].cleared)
            mines[x+1][y].clear();
        if(!mines[x-1][y].cleared)
            mines[x-1][y].clear();
        if(!mines[x+1][y+1].cleared)
            mines[x+1][y+1].clear();
        if(!mines[x][y+1].cleared)
            mines[x][y+1].clear();
        if(!mines[x-1][y+1].cleared)
            mines[x-1][y+1].clear();
        return;
    }
    //bottom side
    else if(y != 0 && x == (width - 1))
    {
        if(!mines[x][y-1].cleared)
            mines[x][y-1].clear();
        if(!mines[x][y+1].cleared)
            mines[x][y+1].clear();
        if(!mines[x-1][y-1].cleared)
            mines[x-1][y-1].clear();
        if(!mines[x-1][y].cleared)
            mines[x-1][y].clear();
        if(!mines[x-1][y+1].cleared)
            mines[x-1][y+1].clear();
        return;
    }
    //top side
    else if(y != 0 && x == 0)
    {
        if(!mines[x][y-1].cleared)
            mines[x][y-1].clear();
        if(!mines[x][y+1].cleared)
            mines[x][y+1].clear();
        if(!mines[x+1][y-1].cleared)
            mines[x+1][y-1].clear();
        if(!mines[x+1][y].cleared)
            mines[x+1][y].clear();
        if(!mines[x+1][y+1].cleared)
            mines[x+1][y+1].clear();
        return;
    }
    else
    {
        if(!mines[x-1][y].cleared)
            mines[x-1][y].clear();
        if(!mines[x-1][y-1].cleared)
            mines[x-1][y-1].clear();
        if(!mines[x][y-1].cleared)
            mines[x][y-1].clear();
        if(!mines[x+1][y-1].cleared)
            mines[x+1][y-1].clear();
        if(!mines[x+1][y].cleared)
            mines[x+1][y].clear();
        if(!mines[x-1][y+1].cleared)
            mines[x-1][y+1].clear();
        if(!mines[x][y+1].cleared)
            mines[x][y+1].clear();
        if(!mines[x+1][y+1].cleared)
            mines[x+1][y+1].clear();
        return;
    }
    update_bombs();
}

//handles incrementing neighboring cells on addition of bomb
void MainWindow::placeMine(int x, int y)
{
    //top left corner
    if(y == 0 && x == 0)
    {
        if(mines[x][y+1] != -1)
            mines[x][y+1] += 1;
        if(mines[x+1][y] != -1)
            mines[x+1][y] += 1;
        if(mines[x+1][y+1] != -1)
            mines[x+1][y+1] += 1;
    }
    //top right corner
    else if(y == (width - 1) && x == 0)
    {
        if(mines[x][y-1] != -1)
            mines[x][y-1] += 1;
        if(mines[x+1][y-1] != -1)
            mines[x+1][y-1] += 1;
        if(mines[x+1][y] != -1)
            mines[x+1][y] += 1;
    }
    //bottom right corner
    else if(y == (width - 1) && x == (height -1))
    {
        if(mines[x][y-1] != -1)
            mines[x][y-1] += 1;
        if(mines[x-1][y-1] != -1)
            mines[x-1][y-1] += 1;
        if(mines[x-1][y] != -1)
            mines[x-1][y] += 1;
    }
    //bottom left corner
    else if(y == 0 && x == (height -1))
    {
        if(mines[x][y+1] != -1)
            mines[x][y+1] += 1;
        if(mines[x-1][y+1] != -1)
            mines[x-1][y+1] += 1;
        if(mines[x-1][y] != -1)
            mines[x-1][y] += 1;
    }
    //right side
    else if(y == (width - 1) && x != 0)
    {
        if(mines[x-1][y] != -1)
            mines[x-1][y] += 1;
        if(mines[x+1][y-1] != -1)
            mines[x+1][y-1] += 1;
        if(mines[x][y-1] != -1)
            mines[x][y-1] += 1;
        if(mines[x-1][y-1] != -1)
            mines[x-1][y-1] += 1;
        if(mines[x+1][y] != -1)
            mines[x+1][y] += 1;
    }
    //left side
    else if(y == 0 && x != 0)
    {
        if(mines[x+1][y] != -1)
            mines[x+1][y] += 1;
        if(mines[x-1][y] != -1)
            mines[x-1][y] += 1;
        if(mines[x+1][y+1] != -1)
            mines[x+1][y+1] += 1;
        if(mines[x][y+1] != -1)
            mines[x][y+1] += 1;
        if(mines[x-1][y+1] != -1)
            mines[x-1][y+1] += 1;
    }
    //bottom side
    else if(y != 0 && x == (width - 1))
    {
        if(mines[x][y-1] != -1)
            mines[x][y-1] += 1;
        if(mines[x][y+1] != -1)
            mines[x][y+1] += 1;
        if(mines[x-1][y-1] != -1)
            mines[x-1][y-1] += 1;
        if(mines[x-1][y] != -1)
            mines[x-1][y] += 1;
        if(mines[x-1][y+1] != -1)
            mines[x-1][y+1] += 1;
    }
    //top side
    else if(y != 0 && x == 0)
    {
        if(mines[x][y-1] != -1)
            mines[x][y-1] += 1;
        if(mines[x][y+1] != -1)
            mines[x][y+1] += 1;
        if(mines[x+1][y-1] != -1)
            mines[x+1][y-1] += 1;
        if(mines[x+1][y] != -1)
            mines[x+1][y] += 1;
        if(mines[x+1][y+1] != -1)
            mines[x+1][y+1] += 1;
    }
    else
    {
        if(mines[x-1][y] != -1)
            mines[x-1][y] += 1;
        if(mines[x-1][y-1] != -1)
            mines[x-1][y-1] += 1;
        if(mines[x][y-1] != -1)
            mines[x][y-1] += 1;
        if(mines[x+1][y-1] != -1)
            mines[x+1][y-1] += 1;
        if(mines[x+1][y] != -1)
            mines[x+1][y] += 1;
        if(mines[x-1][y+1] != -1)
            mines[x-1][y+1] += 1;
        if(mines[x][y+1] != -1)
            mines[x][y+1] += 1;
        if(mines[x+1][y+1] != -1)
            mines[x+1][y+1] += 1;
    }
    update_bombs();
}

void MainWindow::update_bombs()
{
    for(int i = 0; i < width; ++i)
    {
        mines.push_back( std::vector<Cell>(height)  );
        for(int j = 0; j < height; ++j)
        {
            mines[i][j].update_label(cheat);
        }
    }
}

//adds bombs where they are allowed to be
void MainWindow::bomb_gen(int x_clear, int y_clear)
{
    int x;
    int y;
    int counter = 0;
    while(counter != numMines)
    {
        x = rand() % height;
        y = rand() % width;
        if(mines[x][y] != -1 && !(x == x_clear && y == y_clear))
        {
            mines[x][y] = -1;
            placeMine(x,y);
            counter++;
        }
    }
    std::cout << "this is bomb_gen" << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

