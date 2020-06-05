#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.cpp"

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
        mines.push_back( std::vector<Cell>(height)  );
        for(int j = 0; j < height; ++j)
        {
            mines[i][j] = 0;
        }
    }
    std::cout << "constructed window..." << std::endl;

    layout = new QGridLayout();
    QWidget* centralWidget = new QWidget();
    for(int i = 0; i < width; ++i)
    {
        mines.push_back( std::vector<Cell>(height)  );
        for(int j = 0; j < height; ++j)
        {
            //button that covers numbers/bombs
            QPushButton* button = new QPushButton(" ");
            button->setStyleSheet("height: 50px; width: 50px; font-size: 50px;");
            //text underneath with number/bomb
            QLabel* under = new QLabel(QString::number(mines[i][j].getNumber()));
            QFont font = under->font();
            font.setPointSize(30);
            under->setFont(font);
            under->setAlignment(Qt::AlignCenter);
            QObject::connect(button, &QPushButton::clicked, this, &MainWindow::clear);

            mines[i][j].addWidget(button);
            mines[i][j].addWidget(under);
            mines[i][j].setCurrentIndex(0);

            layout->addWidget(&mines[i][j], i, j);
        }

    }
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}

//clearing a clicked button (slot)
void MainWindow::clear()
{
    bomb_gen(0,0);
    std::cout << "clicked!" << std::endl;
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            mines[i][j].setCurrentIndex(1);
        }
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
        if(mines[x][y] != -1 && (x != x_clear && y != y_clear))
        {
            mines[x][y] = -1;
            placeMine(x,y);
            counter++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

