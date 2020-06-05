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
    button->setFont(font);
    under->setAlignment(Qt::AlignCenter);
    under->setStyleSheet( styleSheet().append(QString("margin: 0; padding: 0;")) );
    under->setStyleSheet( styleSheet().append(QString("border: 1px solid gray;")));
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

void Cell::update_label(bool cheat)
{
    under->setText(QString::number(getNumber()));
    switch(getNumber()){
        case 0 : under->setText("");  under->setStyleSheet("QLabel {color : red; border: 1px solid gray;}"); break;
        case -1 :
            under->setText("💣");
            under->setStyleSheet("QLabel {color : black; border: 1px solid gray;}");
            if(cheat)
            {
                button->setText("🚩");
                button->setStyleSheet("QLabel {color : red;}");
            }
            break;
        case 1 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : blue; border: 1px solid gray;}"))); break;
        case 2 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : green; border: 1px solid gray;}"))); break;
        case 3 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : red; border: 1px solid gray;}"))); break;
        case 4 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : purple; border: 1px solid gray;}"))); break;
        case 5 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : maroon; border: 1px solid gray;}"))); break;
        case 6 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : turquoise; border: 1px solid gray;}"))); break;
        case 7 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : black; border: 1px solid gray;}"))); break;
        case 8 : under->setStyleSheet( styleSheet().append(QString("QLabel {color : gray; border: 1px solid gray;}"))); break;
    }
}
