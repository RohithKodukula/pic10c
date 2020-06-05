#include "cell.h"

Cell::Cell() :
    number(0),
    x_pos(0),
    y_pos(0),
    button(new QPushButton()),
    under(new QLabel())
{
    button->setStyleSheet("height: 50px; width: 50px; font-size: 50px;");
    under->setText(QString::number(getNumber()));
    QFont font = under->font();
    font.setPointSize(30);
    under->setFont(font);
    under->setAlignment(Qt::AlignCenter);
    QObject::connect(button, &QPushButton::clicked, button, &QPushButton::deleteLater);

    addWidget(button);
    addWidget(under);
}

void Cell::operator+=(int rhs)
{
    number += rhs;
}

bool Cell::operator==(int rhs)
{
    return number == rhs;
}

bool Cell::operator!=(int rhs)
{
    return number != rhs;
}

void Cell::operator=(int rhs)
{
    number = rhs;
}

int Cell::getNumber()
{
    return number;
}

int Cell::getX()
{
    return x_pos;
}

int Cell::getY()
{
    return y_pos;
}

void Cell::setCoords(int x, int y)
{
    x_pos = x;
    y_pos = y;
}

void Cell::flip()
{
    if(currentIndex() == 0)
        this->setCurrentIndex(1);
    else
        this->setCurrentIndex(0);
}

void Cell::update_label()
{
    under->setText(QString::number(getNumber()));
}
