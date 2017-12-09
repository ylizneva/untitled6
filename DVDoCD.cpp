//
// Created by Yulia Lizneva on 2017-11-03.
//

#include "DVDoCD.h"
#include <sstream>

DVDoCD::DVDoCD(int space, string name, int playtime, int year)
{
    this->name=name;
    this->playtime=playtime;
    this->year=year;
    this->space=space;


}

DVDoCD::DVDoCD(string name, int year)
{
    this->name=name;
    this->year=year;
}





DVDoCD::DVDoCD()
{
    this->name="";
    this->playtime=0;
    this->year=0;
    this->space=0;


}
DVDoCD::~DVDoCD()
{

}

string DVDoCD::getName() const
{
    return this->name;
}
int DVDoCD::getTime() const
{
    return this->playtime;
}
int DVDoCD::getYear() const
{
    return this->year;
}


DVDoCD& DVDoCD::operator=(const DVDoCD &other)
{

    this->year=other.year;
    this->playtime=other.playtime;
    this->name=other.name;
    this->space=other.space;

    return *this;
}
bool DVDoCD::operator ==(const DVDoCD &other) const
{
    bool isEqual = false;
    if(this->name==other.name)
    {
        isEqual=true;
    }
    return isEqual;
}
bool DVDoCD::operator <(const DVDoCD &other) const
{
    bool isBigger=false;
    if(this->space<other.space)
    {
        isBigger=true;
    }
    return isBigger;
}
bool DVDoCD::operator <(const DVDoCD &other) const
{
    return(this->name<other.name);
}


string DVDoCD::toString() const
{
    stringstream out;
    out<<this->name<<" from "<<this->year<<" lasts "
       <<this->playtime<<" and takes "<<this->space<<" MG\n";

    return out.str();

}