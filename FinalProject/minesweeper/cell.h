#ifndef CELL_H
#define CELL_H

#include <QStackedWidget>

class Cell : public QStackedWidget
{
public:
    Cell();
    void operator+=(int rhs);
    bool operator==(int rhs);
    bool operator!=(int rhs);
    void operator=(int rhs);
    int getNumber();

private:
    int number;
};

#endif // CELL_H
