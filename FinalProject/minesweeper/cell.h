#ifndef CELL_H
#define CELL_H

#include <QStackedWidget>
#include <iostream>

class Cell : public QStackedWidget
{
public:
    Cell();
    void operator+=(int rhs);
    bool operator==(int rhs);
    bool operator!=(int rhs);
    void operator=(int rhs);
    int getNumber();

public slots:
    void clear(int index);

private:
    int number;
};

#endif // CELL_H
