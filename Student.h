//
// Created by Yulia Lizneva on 2017-11-15.
//

#ifndef UNTITLED6_STUDENT_H
#define UNTITLED6_STUDENT_H


#include "Person.h"

class Student :public Person
{

private:
    int regNr;


public:
    Student(string name="?", string mail="+", int regNr=0);//ok att använda default i konstruktör
    virtual~Student();

    Student(const Student &originalObjekt);

    void operator=(const Student &originalObjekt);

    void setRegNr(const int regNr);
    int getRegNr(const int regNr);
    //string toString() const;

    virtual string toStringSpecific() const; //överskuggat
};


#endif //UNTITLED6_STUDENT_H
