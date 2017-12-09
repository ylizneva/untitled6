//
// Created by Yulia Lizneva on 2017-12-09.
//

#include "HorisontalShape.h"
#include "sstream"

HorisontalShape::HorisontalShape(int xDirection, int y, int width, int height, int step)
:Shape(step)
{
    this->xDirection=xDirection;
}
HorisontalShape::~HorisontalShape()
{

}

void HorisontalShape::changeDirection()
{
    this->xDirection*=-1;
}
string HorisontalShape::getDirectionAsString() const
{
    string out;
    if(xDirection<0)
    {
        out = LEFT ;
    }
    if(xDirection>0)
    {
        out= RIGHT;
    }

    return out;

}
string HorisontalShape::startString() const
{
    return "Horisontal: ";
}
void HorisontalShape::move()
{
    if(xDirection>0)
    {
        this->changeCoord(this->getStep(), 0);
    }
    else
    {
        this->changeCoord(-this->getStep(), 0);
    }
}