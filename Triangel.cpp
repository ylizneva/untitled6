//
// Created by Yulia Lizneva on 2017-11-16.
//

#include "Triangel.h"
#include <sstream>


Triangel::Triangel(int X, int Y, int lA, int lB)
:GeometriskaFigurer(X, Y)
{
    this->lenghtA=lA;
    this->lenghtB=lB;
}
Triangel::~Triangel()
{

}

Triangel::Triangel(const Triangel &original)
:GeometriskaFigurer(original)
{
    this->lenghtA=original.lenghtA;
    this->lenghtB=original.lenghtB;
}
void Triangel::operator=(const Triangel &original)

{
    GeometriskaFigurer::operator=(original);
    this->lenghtA=original.lenghtA;
    this->lenghtB=original.lenghtB;
}

int Triangel::getLenghtA() const
{
    return this->lenghtA;
}
int Triangel::getLenghtB() const
{
    return this->lenghtB;
}

int Triangel::area() const
{
    return this->lenghtA*this->lenghtB;
}
int Triangel::omkrest() const
{
    return this->lenghtA+this->lenghtB;
}

string Triangel::toStringSpecefik() const
{
    stringstream out;
    out<<"Area is "<<this->area()<<" Omkrets is "<<this->omkrest()<<endl;
    return out.str();
}

