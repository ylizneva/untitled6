//
// Created by Yulia Lizneva on 2017-11-01.
//

#include "Date.h"
#include <string>
#include <sstream>

using namespace std;

Date::Date()
{
    this->day=0;
    this->month=0;
    this->year=0;

}
Date::Date(int year, int month, int day)
{
    this->day=day;
    this->month=month;
    this->year=year;
}
Date::~Date()
{

}

int Date::getYear() const
{
    return this->year;
}
int Date::getMonth() const
{
    return this->month;
}
int Date::getDay() const
{
    return this->day;
}

bool Date::operator==(const Date &other) const
{
    bool isEqual = false;
    if(this->day==other.day && this->month==other.month && this->year==other.year)
    {
        isEqual=true;
    }
    return isEqual;
}
bool Date::operator< (const Date& other) const
{
    bool isBigger = false;
    if(this->year<other.year || this->month<other.month || this->day<other.day)
    {
        isBigger=true;
    }
    return isBigger;

}
Date& Date::operator= (const Date& other)
{
    this->year=other.year;
    this->month=other.month;
    this->day=other.day;

    return *this;
}

string Date::toString() const
{
    stringstream out;
   out<<this->year<< "\t"<< this->month <<" \t"<<this->day;
    return out.str();
}
















