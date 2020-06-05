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

void Cell::clear(int index)
{
    std::cout << "there we are... " << index << std::endl;
}
