//
// Created by Yulia Lizneva on 2017-10-17.
//

#include "Kaffe.h"
#include <string>
#include <cmath>

using namespace std;


Kaffe::Kaffe(string coffeeBrand, string type, double buyPrice, double salePrice)
{
    this->coffeeBrand=coffeeBrand;
    this->type=type;
    this->buyPrice=buyPrice;
    this->salePrice=salePrice;


}

Kaffe::Kaffe(string coffeeBrand, string type)
{
    this->coffeeBrand=coffeeBrand;
    this->type=type;
    this->buyPrice=0;
    this->salePrice=0;


}

Kaffe::Kaffe()
{
    this->coffeeBrand="?";
    this->type="?";
    this->buyPrice=0;
    this->salePrice=0;


}

Kaffe::~Kaffe()
{

}

string Kaffe::getCoffeeBrand() const
{
   return this->coffeeBrand;
}

string Kaffe::getType() const
{
    return this->type;
}

double Kaffe::getBuyPrice() const
{
    return this->buyPrice;
}

double Kaffe::getSalePrice() const
{
    return this->salePrice;
}

void Kaffe::setSaleKaffe(double procent)
{
    this->salePrice= (procent/100 +1)*salePrice;
}

double Kaffe::getMargin() const
{
    return this->salePrice-this->buyPrice;
}



bool Kaffe::operator<(const Kaffe &otherKaffe) const
{

    bool isBigger = false;
    if(this->getMargin() < otherKaffe.getMargin())
    {
        isBigger = true;
    }
    return isBigger;

}

bool Kaffe::operator==(const Kaffe &otherKaffe) const
{
    bool isEqual = false;
    if(this->coffeeBrand==otherKaffe.coffeeBrand && this->type==otherKaffe.type)
    {
        isEqual=true;
    }
    return isEqual;
}

string Kaffe::toString() const
{
    return coffeeBrand +" " + type + " " + to_string(salePrice) + " " + to_string(buyPrice) + " margin is " + to_string(getMargin());
}
