//
// Created by Yulia Lizneva on 2017-10-09.
//
//definitioner

#include "CIrkel.h"

CIrkel::CIrkel(int X, int Y, int radius)
{
    this->X =X;
    this ->Y=Y;
    this ->radius = radius;
}



CIrkel::CIrkel(int radius)
{
    this->radius=radius;
    this->Y =0;
    this->X =0;
}
CIrkel::CIrkel()
{
    this->radius=0;
}

CIrkel::~CIrkel()
{
    //tom eftersom ingen dynamisk allokering sker för medlemsvariabler
}

int CIrkel::getX() const
{
    return this->X;
}

int CIrkel::getY() const
{
    return this->Y;
}
double CIrkel::area() const
{
    return PI*this->radius*this->radius;
}

double CIrkel::circumference() const
{
    return 2*PI*this->radius;
}

void CIrkel::move(int X, int Y)
{
    this->Y = Y;
    this->X = X;
}

int CIrkel::getRadius() const
{
    return this->radius;
}

void CIrkel::setRadius(int radius)
{
    if(radius>=0)
    {
        this->radius = radius;
    }
}

bool CIrkel::operator==(const CIrkel &otherCirkel) const
{
 bool isEqual = false;

    if(this->radius==otherCirkel.radius && this->X ==otherCirkel.X && this->Y==otherCirkel.Y)
    {
        isEqual = true;
    }


    return isEqual;

}

bool CIrkel::operator!=(const CIrkel &otherCirkel) const
{
    bool isNotEqual = false;
    if(this->radius!=otherCirkel.radius || this->X !=otherCirkel.X || this->Y!=otherCirkel.Y)
    {
        isNotEqual = true;
    }

    return isNotEqual;
}



string CIrkel::toString() const
{
    string byAsStringX = to_string(this-> X);
    string byAsStringY = to_string(this->Y);
    string byAsStringR = to_string(this->radius);
    string byAsStringArea = to_string(this->area());
    string byAsStringCirk = to_string(this ->circumference());

    string totalString = "The circle with centre (" + byAsStringX + ":" + byAsStringY + ")" +
    " with radius "+ byAsStringR + " mm., has an area " + byAsStringArea +
    " and circumferemce "+ byAsStringCirk + ". ";

return totalString;
}
