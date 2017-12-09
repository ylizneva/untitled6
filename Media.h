//
// Created by Yulia Lizneva on 2017-11-27.
//

#ifndef UNTITLED6_MEDIA_H
#define UNTITLED6_MEDIA_H

#include <string>

using namespace std;

class Media
{
private:


    string titel;
    int year;

public:

    Media(string titel="", int year=0);
    Media(const Media &original); //inplimenterat av oss


    virtual Media* clone() const=0; // skapa en kopia o returnera adressen till denna(som en pekare)


    virtual~Media();

    int getYear() const;
    string getTitel() const;

    void setYear(const int year);
    void setTitel(const string titel);



    string toString() const; // ska inte överskuggas
    // virtual medför sen bindning, dynamic byndning.
    // Dvs objektets datatyp avgör vilken av dem överskuggade versionerna av funktion som sja användas
    //
    // om inte virt är det tidig bindning(static) dvs variablens datatyp avgör vilken av dem
    // överskuggade versionerna av funktion som ska användas
    virtual string toStringSpecific() const =0; // rent virt som måste defineras i subklasser
};


#endif //UNTITLED6_MEDIA_H
