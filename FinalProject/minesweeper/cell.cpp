#include "cell.h"

Cell::Cell() :
    number(0)
{

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
