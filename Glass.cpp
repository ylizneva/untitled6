//
// Created by Yulia Lizneva on 2017-10-19.
//

#include "Glass.h"
#include <string>

using namespace std;

Glass::Glass(string name, int points, int quantity)
{
    this->name=name;
    this->points=points;
    this->quantity=quantity;
}

Glass::~Glass()
{

}

string Glass::getName() const
{
    return this->name;
}

int Glass::getQuantity() const
{
    return this-> quantity;
}

void Glass::addPoints(int ppoints)
{
    this->points+=ppoints;
    this->quantity++;
}


double Glass::getAverage() const
{
    return this->points/this->quantity;
}

bool Glass::operator==(const Glass &otherOne)
{
    bool isEqual = false;
    if(this->name==otherOne.name)
    {
        isEqual=true;
    }
    return isEqual;
}
bool Glass::operator>(const Glass &otherOne)
{
    bool isBigger=false;
    if(this->getAverage()>otherOne.getAverage())
    {
        isBigger=true;
    }
    return isBigger;
}

string Glass::toString() const
{
    return "The icecream "+ name + "has been rated "+ to_string(quantity)
            + " times. The average point is" + to_string(getAverage());
}
