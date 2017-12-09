//
// Created by Yulia Lizneva on 2017-12-08.
//

#include "Box.h"
Box::Box(int width, int height)
{
    this->width=width;
    this->height=height;
}

Box::~Box()
{

}



int Box::getWidth() const
{
    return this->width;
}

int Box::getHeight() const
{
    return this->height;
}