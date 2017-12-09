//
// Created by Yulia Lizneva on 2017-10-18.
//

#include "Cleaning.h"
#include <string>

using namespace std;

Cleaning::Cleaning(string type, double price, double payOff)
{
    this->type=type;
    this->price=price;
    this->payOff=payOff;
}

Cleaning::Cleaning()
{
    this->type="+";
    this->price=0;
    this->payOff=0;
}
Cleaning::~Cleaning()
{

}

string Cleaning::getType() const
{
    return this->type;
}

double Cleaning::getPrice() const
{
    return this->price;
}

double Cleaning:: getPayOff() const
{
    return this->payOff;
}

double Cleaning:: getMargin() const
{
    return this->price-this->payOff;
}




void Cleaning::setPrice(int procent)
{
    this->price=price*(procent/100+1);
}

void Cleaning::setSallary(int procent)
{
    this->payOff=(procent/100+1)*payOff;
}

bool Cleaning::operator==(const Cleaning &otherOne) const
{
    bool isEqual = false;
    if(this->type==otherOne.type && this->price==otherOne.price)
    {
        isEqual=true;
    }
    return isEqual;
}






bool Cleaning::operator<(const Cleaning &otheOne) const
{
    bool isLess = false;
    if(this->getMargin()<otheOne.getMargin())
    {
        isLess=true;
    }
    return isLess;

}

string Cleaning::toString() const
{
    return type + " will cost " + to_string(price) + "€ for a customer. You will pay for this"
    + to_string(payOff) + " as salary. Total you'll earn "+ to_string(getMargin());
}














