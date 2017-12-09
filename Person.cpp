//
// Created by Yulia Lizneva on 2017-11-15.
//

#include "Person.h"
#include <sstream>

using namespace std;
Person::Person()
{
    this->name=" ";
    this->mail=" ";
}
Person::Person(string name, string mail)
{
    this->name=name;
    this->mail=mail;
}
Person::~Person()
{

}

Person::Person(const Person &originalObjekt)
{
    this->name=originalObjekt.name;
    this->mail=originalObjekt.mail;

}


void Person::operator=(const Person &originalObjekt)
{
    this->name=originalObjekt.name;
    this->mail=originalObjekt.mail;
}
void Person::setName(const string name)
{
    this->name=name;
}
void Person::setMail(const string mail)
{
    this->mail=mail;
}

string Person::getName() const
{
    return this->name;
}
string Person::getMail() const
{
    return this->mail;
}

string Person::toString() const
{
    stringstream out;
    out<<"Name: "<<this->name<<"\n Email: "<<this->mail<<"\n"<<toStringSpecific(); //vi har gjort en rent virtual funktion
    return out.str();
}
