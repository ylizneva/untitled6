//
// Created by Yulia Lizneva on 2017-12-08.
//

#include "Coord.h"
Coord::Coord(int xPos, int yPos)
{
    this->xPos=xPos;
    this->yPos=yPos;
}
Coord::~Coord()
{

}


int Coord::getXPos() const
{
    return this->xPos;
}
int Coord::getYPos() const
{
    return this->yPos;
}

void Coord::changeXPos(const int change)
{
    this->xPos+=change;
}
void Coord::changeYPos(const int change)
{
    this->yPos+=change;
}

