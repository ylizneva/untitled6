//
// Created by Yulia Lizneva on 2017-11-01.
//

#include "Friend.h"
#include <string>


using namespace std;

Friend::Friend()
//:Date()
{

}
Friend::Friend(string name, int year, int month, int day)
//:Date(year, month, day)
{
    this->name=name;
    this->dateOfBirth=Date(year, month, day);

}
Friend::~Friend()
{

}

string Friend::getName() const
{
    return this->name;
}
Date Friend::getDate() const
{
    return this->dateOfBirth;
}

bool Friend::operator== (const Friend& other) const
{
    return (this->name==other.name &&this->dateOfBirth==other.dateOfBirth);
}

// Based on the date of birth
bool Friend::operator< (const Friend &other) const
{
    return (this->dateOfBirth<other.dateOfBirth);
}

string Friend::toString() const
{
   return name + this->dateOfBirth.toString();
}