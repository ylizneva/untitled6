//
// Created by Yulia Lizneva on 2017-11-01.
//

#include "Boatmotors.h"
#include <sstream>
Boatmotors::Boatmotors(string brand, int volume, int year, string serieNumber)
{
    this->brand=brand;
    this->volume=volume;
    this->year=year;
    this->serieNumber=serieNumber;
}
Boatmotors::Boatmotors()
{
    this->brand="";
    this->volume=0;
    this->year=0;
    this->serieNumber="";
}
Boatmotors::~Boatmotors()
{

}


string Boatmotors::getBrand() const
{
    return this->brand;
}
int Boatmotors::getVolume() const
{
    return this->volume;
}
int Boatmotors::getYear() const
{
    return this->year;
}
string Boatmotors::getSerieNumber() const
{
    return this->serieNumber;
}

void Boatmotors::setBrand(string brand)
{
    this->brand=brand;
}
void Boatmotors::setVolym(int vol)
{
    this->volume=vol;
}
void Boatmotors::setYear(int year)
{
    this->year=year;
}
bool Boatmotors::operator==(const Boatmotors &other) const
{
    bool isEqual = false;
    if(this->brand==other.brand &&this->serieNumber==other.serieNumber &&this->year==other.year &&this->volume==other.volume)
    {
        isEqual=true;
    }
    return isEqual;
}

string Boatmotors::toString() const
{
    stringstream out;
    out<<this->brand<<" "<<this->volume<<" hk from "<<this->year<<" with series number "<<this->serieNumber<<endl;
    return out.str();
}

Boatmotors& Boatmotors::operator=(const Boatmotors &other)
{
    this->volume=other.volume;
    this->year=other.year;
    this->brand=other.brand;
    this->serieNumber=other.serieNumber;

    return *this;

}