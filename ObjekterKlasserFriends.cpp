//
// Created by Yulia Lizneva on 2017-10-02.
//
//klassdefenition

#include "ObjekterKlasserFriends.h"
#include <iostream>

// ObjekterKlasserFriends är klassen
// :: - scope operator, när vi går IN i klassen
//ObjekterKlasserFriends (parameterlista) är konstruktorn som ska defineras
ObjekterKlasserFriends::ObjekterKlasserFriends(string name, int by, string email)
{
    // placera parametrarnas innehåll i medlemsvariablerna

    //this -> innebär att vi går in i objektet
    this->name = name;
    this->by = by;
    this->email = email;

}

ObjekterKlasserFriends::ObjekterKlasserFriends()
{
    this->name ="?";
    this->by=-1;
    this->email ="?";
}

ObjekterKlasserFriends:: ~ ObjekterKlasserFriends()
{
    //cout<<"Destroering av "<<this->name<<" , "
    // <<this->by<<" , "<<this->email<<" , ";
}


bool ObjekterKlasserFriends::operator==(const ObjekterKlasserFriends &otherFriend) const
{
    bool isEqual = false;
    if(this->name == otherFriend.name && this->by == otherFriend.by && this->email == otherFriend.email)
    {
        isEqual = true;
    }
    return isEqual;
}

bool ObjekterKlasserFriends::operator<(const ObjekterKlasserFriends &otherFriend) const
{
    //baseras på namnet
    bool isLess = false;
    if(this->name <otherFriend.name)
    {
        isLess = true;
    }
    return isLess;

    //return this->name < otherFriend.name;


}

string ObjekterKlasserFriends::getName() const
{
    return this->name;

}

int ObjekterKlasserFriends::getby() const
{
    return this->by;
}

string ObjekterKlasserFriends::getemail() const
{
    return this->email;
}

void ObjekterKlasserFriends::setName(string name)
{
    this->name=name;
}
int ObjekterKlasserFriends::age(int year) const
{
    return year - this->by;


}


string ObjekterKlasserFriends::toString() const
{
string byAsString = to_string(this->by);//to string
    string totalString = this->name + " was born at "+ byAsString+
            " has en email " + this->email;
    return totalString;
}

