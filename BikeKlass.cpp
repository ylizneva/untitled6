//
// Created by Yulia Lizneva on 2017-11-20.
//

#include "BikeKlass.h"
#include <sstream>

BikeKlass::BikeKlass(string colour, string make, int nrOf)
{
    this->colour=colour;
    this->make=make;
    this->nrOfGears=nrOf;
}
BikeKlass::~BikeKlass()
{

}
BikeKlass::BikeKlass()
{
    this->colour="";
    this->make="";
    this->nrOfGears=0;
}
string BikeKlass::toString() const
{
    stringstream out;
    out<<"Bike has "<<this->colour<<" colour, made by "<<this->make<<" nrOf gears is "<<
          this->nrOfGears<<endl;
    return out.str();
}

bool BikeKlass::operator==(BikeKlass &original)
{
    bool isEqual= false;

    if(this->colour==original.colour &&
    this->make==original.make &&
    this->nrOfGears==original.nrOfGears)
    {
        isEqual=true;
    }
    return isEqual;

}

string BikeKlass::getColour() const
{
    return this->colour;
}
string BikeKlass::getMake() const
{
    return this->make;
}
int BikeKlass::getGears() const
{
    return this->nrOfGears;
}
