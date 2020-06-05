#ifndef CELL_H
#define CELL_H

#include <QStackedWidget>
#include <iostream>
#include <QPushButton>
#include <QLabel>

class Cell : public QStackedWidget
{
public:
    Cell();
    void operator+=(int rhs);
    bool operator==(int rhs);
    bool operator!=(int rhs);
    void operator=(int rhs);
    int getNumber();

    int getX();
    int getY();
    void setCoords(int x, int y);

    void flip();
    void update_label();

private:
    int number;
    int x_pos;
    int y_pos;

    QPushButton* button;
    QLabel* under;
};

#endif // CELL_H
