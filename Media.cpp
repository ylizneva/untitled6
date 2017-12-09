//
// Created by Yulia Lizneva on 2017-11-27.
//

#include "Media.h"
#include <sstream>

// en abstrakt klass för att det innehåller minst en rent virt funktion
// det går ej att skapa objekt av denna klass

Media::Media(string titel, int year)
{
    this->titel=titel;
    this->year=year;
}

Media::Media(const Media &original)
{
    this->titel=original.titel;
    this->year=original.year;

}




Media::~Media()
{

}

int Media::getYear() const
{
    return this->year;
}

string Media::getTitel() const
{
    return this->titel;
}

void Media::setYear(const int year)
{
    this->year=year;
}
void Media::setTitel(const string titel)
{
    this->titel=titel;
}

string Media::toString() const
{
    stringstream out;
    out<<"The titel is "<<this->titel<<"\nYear:"<<this->year<<" \n"<<toStringSpecific()<<endl;
    return out.str();
    //anropet av toStringSpecific() styrs av vilken klasstyp objektet är av,
    // dvs är det en Bok så exekveras Book-klassens toStringSpecific().
    // Här den dynamiska bindningen sker
}
//string Media::toStringSpecific() const;