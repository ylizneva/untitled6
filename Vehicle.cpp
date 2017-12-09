//
// Created by Yulia Lizneva on 2017-11-19.
//

#include "Vehicle.h"
#include <sstream>


Vehicle::Vehicle(int motor, string brand)
{
    this->wheels=0;
    this->fuel="";
    this->motor=motor;
    this->brand=brand;
}


Vehicle::Vehicle(int wheels, string fuel, int motor, string brand)
{
    this->wheels=wheels;
    this->fuel=fuel;
    this->motor=motor;
    this->brand=brand;
}
Vehicle::Vehicle()
{
    this->wheels=0;
    this->fuel="";
    this->motor=0;
    this->brand="";
}
Vehicle::~Vehicle()
{

}

Vehicle::Vehicle(const Vehicle &original)
{
    this->wheels=original.wheels;
    this->fuel=original.fuel;
    this->motor=original.motor;
    this->brand=original.brand;
}
void Vehicle::operator=(const Vehicle &original)
{
    this->wheels=original.wheels;
    this->fuel=original.fuel;
    this->motor=original.motor;
    this->brand=original.brand;
}

string Vehicle::getFuel() const
{
    return this->fuel;
}
string Vehicle::getBrand() const
{
    return this->brand;
}
int Vehicle::getMotor() const
{
    return this->motor;
}
int Vehicle::getWheels() const
{
    return this->wheels;
}

void Vehicle::setFuel()
{
    this->fuel=fuel;
}
void Vehicle::setBrand()
{
    this->brand=brand;
}
void Vehicle::setMotor()
{
    this->motor=motor;
}
void Vehicle::setWheels()
{
    this->wheels=wheels;
}

string Vehicle::toString() const
{
    stringstream out;
    out<<"The model "<<this->brand<<" has "<<this->wheels<<" wheels. "<<"\n Motor is "<<this->motor<<
         " Works on "<<this->fuel<<toStringSpecific()<<endl;
    return out.str();
}
//pure virt funktion
bool Vehicle::operator==(const Vehicle &original)
{
    bool isEqual = false;
    if(this->brand==original.brand &&this->motor==original.motor)
    {
        isEqual= true;
    }
    return isEqual;
}