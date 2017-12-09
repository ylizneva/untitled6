//
// Created by Yulia Lizneva on 2017-11-15.
//

#include "Employee.h"
#include <sstream>

Employee::Employee(string name, string mail, string dep)
:Person(name, mail)
{
    this->dep=dep;
}
Employee::~Employee()
{

}

Employee::Employee(const Employee &originalObjekt)
:Person(originalObjekt)
{
    this->dep=originalObjekt.dep;
}

void Employee::operator=(const Employee &originalObjekt)
{
    Person::operator=(originalObjekt);
    this->dep=originalObjekt.dep;
}
void Employee::setDep(const string dep)
{
    this->dep=dep;
}
string Employee::getDep(const string dep)
{
    return this->dep;
}
/*string Employee::toString() const
{
    stringstream out;
    out<<Person::toString()<<endl;
    out<<"Department: "<<this->dep;
}*/

string Employee::toStringSpecific() const
{
    stringstream out;
    out<<"Department: "<<this->dep<<endl;
    return out.str();
}