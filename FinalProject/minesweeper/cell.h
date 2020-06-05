#ifndef CELL_H
#define CELL_H

#include <QStackedWidget>
#include <iostream>
#include <QPushButton>
#include <QLabel>

class Cell : public QStackedWidget
{
    Q_OBJECT
public:
    Cell();

    //operators
    void operator+=(int rhs);
    bool operator==(int rhs);
    bool operator!=(int rhs);
    void operator=(int rhs);

    //getters and setters
    int getNumber();
    int getX();
    int getY();
    void setCoords(int x, int y);

    void update_label(); //update from initialization values (all zeroes)

public slots:
    void clear(); //runs when the button of the cell clicked

signals:
    void clear_this(int x, int y); //signal emitted from clear to pass on coordinates

private:
    int number;
    int x_pos;
    int y_pos;

    QPushButton* button;
    QLabel* under;
};

#endif // CELL_H
