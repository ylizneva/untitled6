//
// Created by Yulia Lizneva on 2017-12-08.
//

#include "Shape.h"
#include <sstream>

Shape::Shape(int step, int width, int height, int xPos, int yPos)
{
    this->box = new Box(width, height);
    this->coord = new Coord(xPos, yPos);
    this->step=step;
}
Shape::~Shape()
{
    delete box;
    delete coord;
}


Shape::Shape(Shape &original)
{
    this->step=original.step;
    this->box = new Box(*original.box);
    this->coord = new Coord(*original.coord);
}


void Shape::changeCoord(int xChange, int yChange)
{
    this->coord->changeXPos(xChange);
    this->coord->changeYPos(yChange);
}
void Shape::changeStep(int change)
{
    this->step+=change;
}

int Shape::getStep() const
{
    return this->step;
}
bool Shape::intersectWith(const Shape& otherShape)
{
    bool crossing = false;
    int rectMaxWidth=coord->getXPos()+this->box->getWidth();
    int rectMinWidth= coord->getXPos();

    int otherRectMaxWidth=otherShape.coord->getXPos()+ otherShape.box->getWidth();
    int otherRectMinWidth=otherShape.coord->getXPos();


    int rectMaxHeight= coord->getYPos()+this->box->getHeight();
    int rectMinHeight = coord->getYPos();


    int otherRectMaxHeight=otherShape.coord->getYPos()+otherShape.box->getHeight();
    int otherRectMinHeight =otherShape.coord->getYPos();

    if(otherRectMinWidth<= rectMaxWidth || otherRectMaxHeight >= rectMinHeight
       || otherRectMaxWidth>= rectMinWidth || otherRectMinHeight<= rectMaxHeight)

    {
        crossing = true;
    }

    return crossing;
}

string Shape::toString() const
{
    stringstream out;
    out<<this->startString()<<"\nPosition:\n X:"<<this->coord->getXPos()<<" Y: "
       <<this->coord->getYPos()<<"\nDirection: "<<this->getDirectionAsString()
       <<"\nStep: "<<this->getStep()<<"\nWidth: "<<this->box->getWidth()<<"Height: "<<this->box->getHeight()<<endl;

    return out.str();
}

