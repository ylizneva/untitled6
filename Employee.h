//
// Created by Yulia Lizneva on 2017-11-15.
//

#ifndef UNTITLED6_EMPLOYEE_H
#define UNTITLED6_EMPLOYEE_H

#include "Person.h"

class Employee:public Person
{

private:
    string dep;

public:
    Employee(string name="?", string mail="=", string dep="+");
    virtual~Employee();

    Employee(const Employee &originalObjekt);

    void operator=(const Employee &originalObjekt);
    void setDep(const string dep);
    string getDep(const string dep);
    //string toString() const;

    virtual string toStringSpecific() const;

};


#endif //UNTITLED6_EMPLOYEE_H
