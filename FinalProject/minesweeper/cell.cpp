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
    under->setStyleSheet( styleSheet().append(QString("margin: 0; padding: 0;")) );
    under->setStyleSheet( styleSheet().append(QString("QLabel {border: 1px solid gray;}")));
    QObject::connect(button, &QPushButton::clicked, this, &Cell::clear);

    addWidget(button);
    addWidget(under);
}

void Cell::operator+=(int rhs)
{ number += rhs; }

bool Cell::operator==(int rhs)
{ return number == rhs; }

bool Cell::operator!=(int rhs)
{ return number != rhs; }

void Cell::operator=(int rhs)
{ number = rhs; }

int Cell::getNumber()
{  return number; }

int Cell::getX()
{ return x_pos; }

int Cell::getY()
{ return y_pos; }

void Cell::setCoords(int x, int y)
{
    x_pos = x;
    y_pos = y;
}

void Cell::clear()
{
    if(currentIndex() == 0)
        this->setCurrentIndex(1);
    else
        this->setCurrentIndex(0);
    emit clear_this(getX(), getY());
}

void Cell::update_label()
{
    under->setText(QString::number(getNumber()));
    switch(getNumber()){
        case 0 : under->setText(""); break;
        case -1 : under->setText("💣"); under->setStyleSheet("QLabel {color : black;}"); break;
        case 1 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : blue;}"))); break;
        case 2 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : green;}"))); break;
        case 3 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : red;}"))); break;
        case 4 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : purple;}"))); break;
        case 5 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : maroon;}"))); break;
    }
}
