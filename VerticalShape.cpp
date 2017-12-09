//
// Created by Yulia Lizneva on 2017-12-09.
//

#include "VerticalShape.h"

VerticalShape::VerticalShape(int yDirectionint, int x, int width, int height, int step)
:Shape(step)
{
    this->yDirection=yDirection;
}
VerticalShape::~VerticalShape()
{

}

void VerticalShape::changeDirection()
{
    this->yDirection*=-1;
}
string VerticalShape::getDirectionAsString() const
{
    string out;
    if(yDirection<0)
    {
        out = UP ;
    }
    if(yDirection>0)
    {
        out= DOWN;
    }

    return out;
}
string VerticalShape::startString() const
{
    return "Vertical: ";
}
void VerticalShape::move()
{
    if(yDirection>0)
    {
        this->changeCoord(0, -this->getStep());
    }
    else
    {
        this->changeCoord(0, this->getStep());
    }
}

