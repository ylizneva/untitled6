//
// Created by Yulia Lizneva on 2017-11-01.
//

#include "Motors.h"
#include <string>
#include <iostream>

using namespace std;

Motors::Motors(string brand, int volume, int year, string serieNr)
{
    for (int i = 0; i < maxNrOf; ++i)
    {
        this->motors[i]=Boatmotors(brand, volume, year, serieNr);

    }

}
Motors::Motors()
{
    this->motors[nrOf]=Boatmotors();

}
Motors::~Motors()
{

}

int Motors::findOne(string brand, int volume, int year, string serieNr) const
{
    int pos=-1;
    Boatmotors temp= Boatmotors(brand, volume, year, serieNr);
    for(int i=0; i<nrOf; i++)
    {
        if(motors[i]==temp)
        {
            pos=i;
        }

    }

    return pos;
}
bool Motors::addOne(string brand, int volume, int year, string serieNr)
{
    bool isDone = false;

    Boatmotors temp = Boatmotors(brand, volume, year, serieNr);

    int pos=findOne(brand, volume, year, serieNr);

        if(nrOf<maxNrOf && pos==-1)
        {
            motors[nrOf++] = temp;
            isDone = true;
        }
    return isDone;
}


bool Motors::deleteOne(string brand, int volume, int year, string serieNr)
{
    bool isDone = false;
    Boatmotors temp= Boatmotors(brand, volume, year, serieNr);
    int pos= findOne(brand, volume, year, serieNr);
    if(pos!=-1)
    {
        motors[pos]=motors[--nrOf];
        isDone = true;
    }
    return isDone;
}

void Motors::showAll() const
{

    for(int i=0; i<nrOf; i++)
    {
        cout<< motors[i].toString();
    }


}

bool Motors::showSomething(string arr[], int n, string brand, int volume, int year, string serieNr)
{
    bool isFound = false;
    int pos=-1;
    Boatmotors temp= Boatmotors(brand, volume, year, serieNr);
    for(int i=0; i<nrOf; i++)
    {
        if(motors[i]==temp)
        {
            pos=i;
            isFound=true;
        }

    }
    if(pos!=-1)
    {
        arr[0]=motors[pos].toString();
    }
    return isFound;
}


/*void Motors::saveAsString(string arr[], int n)
{
    for (int i = 0; i <n ; i++)
    {
        arr[i]=motors[i].toString();
    }
}
*/
bool Motors::changeBrand(string brand, string newBrand, int vol, int NewV, int year, int newY, string serieNr)
{
    bool isDone = false;

    int pos= findOne(brand, vol, year, serieNr);
    Boatmotors temp= Boatmotors(newBrand, NewV, newY, serieNr);
    if(pos!=-1)
    {
        motors[pos]=temp;
        isDone = true;
    }


    return isDone;
}

