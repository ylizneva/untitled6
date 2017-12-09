//
// Created by Yulia Lizneva on 2017-11-19.
//

#include "CarVSmc.h"
#include <sstream>


CarVSmc::CarVSmc(string airbag, int wheels, string fuel, int motor, string brand)
:Vehicle(wheels, fuel, motor, brand)
{
    this->airbag=airbag;
}
CarVSmc::~CarVSmc()
{

}

CarVSmc::CarVSmc(const CarVSmc &origianal)
:Vehicle(origianal)
{
    this->airbag=origianal.airbag;
}
void CarVSmc::operator=(const CarVSmc &original)
{
    Vehicle::operator=(original);
    this->airbag=original.airbag;
}

string CarVSmc::getBag() const
{
    return this->airbag;
}
string CarVSmc::toStringSpecific() const
{
    stringstream out;
    out<<"The airbag model is"<<this->airbag<<endl;
    return out.str();

}