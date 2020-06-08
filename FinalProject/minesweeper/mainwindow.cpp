#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.cpp"

MainWindow::MainWindow(int w, int h, int num, bool c):
    ui(new Ui::MainWindow),
    width(w),
    height(h),
    numMines(num),
    cheat(c),
    started(false)
{
    srand(time(NULL));
    ui->setupUi(this);
    this->setWindowTitle("Minesweeper");
    for(int i = 0; i < height; ++i)
    {
        mines.push_back( std::vector<Cell>(width)  );
        for(int j = 0; j < width; ++j)
        {
            mines[  i][j] = 0;
            mines[i][j].setCoords(i,j);
            QObject::connect(&mines[i][j], &Cell::rightClicked, this, &MainWindow::flag);
            QObject::connect(&mines[i][j], &Cell::clear_this, this, &MainWindow::clear_neighbors);
            QObject::connect(&mines[i][j], &Cell::check_win, this, &MainWindow::check_game);

        }
    }
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
    if(started  == false)
    {
        bomb_gen(x,y);
        started = true;
    }
    update_bombs();
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

void MainWindow::check_game()
{
    std::cout << "checking" << std::endl;
    bool win = true;
    for(int i = 0; i < width; ++i)
        for(int j = 0; j < height; ++j)
            if(mines[i][j] != -1 && !mines[i][j].cleared)
                win = false;
    bool lose = false;
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            if(mines[i][j] == -1 && mines[i][j].cleared)
                lose = true;
        }
    }
    if(win || lose)
    {
        QWidget *wdg = new QWidget();
        QVBoxLayout* vertical_lay = new QVBoxLayout();
        QLabel* win_lose = new QLabel();
        QFont font = win_lose->font();
        if(win)
        {
            win_lose->setText("You Win!!!");
            font.setPointSize(30);
        }
        if(lose)
        {
             win_lose->setText("You Lose, better luck next time. ");
             font.setPointSize(22);
        }
        win_lose->setFont(font);
        win_lose->setAlignment(Qt::AlignCenter);
        vertical_lay->addWidget(win_lose);

        QLabel* credits = new QLabel();
        credits->setText("Thanks for playing.\
Made by Zoeb J. and Rohith K for PIC10C Class.");
        credits->setAlignment(Qt::AlignCenter);
        vertical_lay->addWidget(credits);

        wdg->setLayout(vertical_lay);
        wdg->show();
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
        if(mines[x][y] != -1 &&
                (!(x == x_clear && y == y_clear) &&
                !(x == x_clear-1 && y == y_clear+1) &&
                !(x == x_clear-1 && y == y_clear) &&
                !(x == x_clear-1 && y == y_clear-1) &&
                !(x == x_clear+1 && y == y_clear+1) &&
                !(x == x_clear+1 && y == y_clear) &&
                !(x == x_clear+1 && y == y_clear-1) &&
                !(x == x_clear && y == y_clear+1) &&
                !(x == x_clear && y == y_clear-1))
                )
        {
            mines[x][y] = -1;
            placeMine(x,y);
            counter++;
        }
    }
    std::cout << "bombs generated..." << x_clear << " " << y_clear << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

