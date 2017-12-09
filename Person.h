//
// Created by Yulia Lizneva on 2017-11-15.
//

#ifndef UNTITLED6_PERSON_H
#define UNTITLED6_PERSON_H

#include <string>
using namespace std;

class Person
{
private:
    string name;
    string mail;

public:
    Person();//default o konstruktorn måste vara separat i en basklass
    Person(string name, string mail);
    virtual~Person();

    Person(const Person &originalObjekt);

    void operator=(const Person &originalObjekt);
    void setName(const string name);
    void setMail(const string mail);

    string getName() const;
    string getMail() const;

    string toString() const;

// pure virtual funktions

virtual string toStringSpecific() const =0; //0 eftersom det är rent, student o empl def detta funktionen. =0 bara i basklassen
};


#endif //UNTITLED6_PERSON_H
