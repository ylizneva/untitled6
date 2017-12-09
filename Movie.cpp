//
// Created by Yulia Lizneva on 2017-11-27.
//

#include "Movie.h"
#include <sstream>


Movie::Movie(string titel, int year, int playtime, string mainActor)
:Media(titel, year)
{
    this->playtime=playtime;
    this->mainActor=mainActor;
}

Movie* Movie::clone() const
{
    return new Movie(*this);
}



int Movie::getPlaytime() const
{
    return this->playtime;
}
string Movie::getMainActor() const
{
    return this->mainActor;
}

void Movie::setPlaytime(const int playtime)
{
    this->playtime=playtime;
}
void Movie::setMainActor(const string mainActor)
{
    this->mainActor=mainActor;
}

string Movie::toStringSpecific() const
{
    stringstream out;
    out<<"Playtime: "<<this->playtime<<endl;
    return out.str();
}