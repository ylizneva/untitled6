//
// Created by Yulia Lizneva on 2017-11-15.
//

#include "Student.h"
#include <sstream>

using namespace std;

Student::Student(string name, string mail, int regNr)
:Person(name, mail)//kallar på
{
    this->regNr=regNr;
}
Student::~Student()
{

}

Student::Student(const Student &originalObjekt)
:Person(originalObjekt)
{
    this->regNr=originalObjekt.regNr;
}

void Student::operator=(const Student &originalObjekt)
{
    Person::operator=(originalObjekt);
    this->regNr=originalObjekt.regNr;
}

void Student::setRegNr(const int regNr)
{
    this->regNr=regNr;
}
int Student::getRegNr(const int regNr)
{
    return this->regNr;
}
/*string Student::toString() const
{
    stringstream out;
    out<<Person::toString()<<endl;
    out<<"RegNr: "<<this->regNr<<endl;
    return out.str();

}*/
string Student::toStringSpecific() const
{
        stringstream out;
    out<<"Medelmsnummer: "<<this->regNr<<endl;
    return out.str();
}