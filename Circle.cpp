//
// Created by Yulia Lizneva on 2017-11-16.
//

#include "Circle.h"
#include <iostream>
#include <sstream>

using namespace std;


Circle::Circle(int X, int Y, int R)
:GeometriskaFigurer(X, Y)
{
    this->radien=R;
}
Circle::~Circle()
{

}
Circle::Circle(const Circle &original)
:GeometriskaFigurer(original)
{
    this->radien=original.radien;
}
void Circle::operator=(Circle &original)
{
    GeometriskaFigurer::operator=(original);
    this->radien=original.radien;
}

int Circle::area() const
{
    return 3.1415*this->radien;
}
int Circle::omkrets() const
{
    return (3.1415*this->radien)/2;
}

string Circle::toStringSpecefik() const
{
    stringstream out;
    out<<"Area is "<<this->area()<<"Radien is "<<this->omkrets();
    return out.str();
}

