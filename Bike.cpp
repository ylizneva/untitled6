//
// Created by Yulia Lizneva on 2017-11-19.
//

#include "Bike.h"
#include <sstream>
#include "Vehicle.h"


Bike::Bike(string balans, int wheels, string fuel, int motor, string brand)
:Vehicle(wheels, fuel, motor, brand)
{
    this->balansPedals=balans;

}
Bike::~Bike()
{

}
string Bike::getBalans() const
{
    return this->balansPedals;
}
Bike::Bike(const Bike &original)
:Vehicle(original)
{
    this->balansPedals=original.balansPedals;
}
void Bike::operator=(const Bike &original)
{
    Vehicle::operator=(original);
    this->balansPedals=original.balansPedals;
}
int Bike::getNr() const
{
    return this->nrOf;
}
string Bike::toStringSpecific() const
{
    stringstream out;
    out<<"Balanspedals model is "<<this->balansPedals;
    return out.str();
}

