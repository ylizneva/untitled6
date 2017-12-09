//
// Created by Yulia Lizneva on 2017-11-08.
//

#include "Car.h"
#include <sstream>
Car::Car()
{
    this->model="";
    this->regNr="";
    this->nrOfMiles=0;
    this->price=0;
}
Car::Car(const string model, const string regNr, const int nrOfMiles, const double price)
{
    this->model=model;
    this->regNr=regNr;
    this->nrOfMiles=nrOfMiles;
    this->price=price;
}
Car::~Car()
{

}


//skriver ut en bils egenskaper
string Car::toStringCar() const
{
    stringstream out;
    out<<this->model<<"\t"<<this->regNr<<" with mileage "<<this->nrOfMiles<<" Costs €"<<this->price<<endl;
    return out.str();

}

//getfunktioner
string Car::getModel() const
{
    return this->model;
}
string Car::getRegNr()const
{
    return this->regNr;
}
double Car::getPrice() const
{
    return this->price;
}
int Car::getMiles() const
{
    return this->nrOfMiles;
}

//set-funktioner
void Car::setModel(const string model)
{
    this->model=model;
}
void Car::setRegNr(const string regNr)
{
    this->regNr=regNr;
}
void Car::setNrOfMiles(const int nrOfMiles)
{
    this->nrOfMiles=nrOfMiles;
}
void Car::setPrice(const double price)
{
    this->price=price;
}