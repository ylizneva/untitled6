//
// Created by Yulia Lizneva on 2017-11-03.
//

#include "DVDoCDandraFil.h"
#include <iostream>
using namespace std;

DVDoCDandraFil::DVDoCDandraFil(int space, string name, int playtime, int year)
{
    for(int i=0; i<maxNrOf; i++)
    {
        this->dvds[i]=DVDoCD(space, name, playtime, year);
    }
    this->freeSpace=50;
}


DVDoCDandraFil::DVDoCDandraFil(string name, int year)
{
   for(int i=0; i<maxNrOf; i++)
   {
       this->dvds[i]=DVDoCD(name, year);
   }
    this->freeSpace=50;
}


DVDoCDandraFil::DVDoCDandraFil()
{
    for(int i=0; i<maxNrOf; i++)
    {
        this->dvds[i]=DVDoCD();
    }
    this->freeSpace=50;
}
DVDoCDandraFil::~DVDoCDandraFil()
{

}

int DVDoCDandraFil::findOne(string name, int year)
{

    int pos=-1;
    DVDoCD temp= DVDoCD(name, year);
    for(int i=0; i<nrOf; i++)
    {
        if(dvds[i]==temp)
        {
            pos=i;

        }
    }
    return pos;
}

int DVDoCDandraFil::getFreeSpace(int space, string name, int playtime, int year)
{
   return this->freeSpace;
}

bool DVDoCDandraFil::saveAmovie(int space, string name, int playtime, int year)
{
    bool isDone =false;
    DVDoCD temp =DVDoCD (space, name, playtime, year);

    int pos= findOne(name, year);
    if(pos==-1 && space<freeSpace)
    {
       dvds[nrOf++]=temp;
        isDone=true;
        cout<<"Saved"<<endl;
        this->freeSpace-=space;
    }
    else
    {
        cout<<"Not saved"<<endl;
    }
    return isDone;
}
bool DVDoCDandraFil::deleteAmovie(int space, string name, int playtime, int year)
{
    bool isDone = false;
    DVDoCD temp = DVDoCD(space, name, playtime, year);
    int pos = findOne(name, year);
    if (pos != -1)
    {
        dvds[pos] = dvds[--nrOf];
        isDone = true;
        this->freeSpace+=space;
    }
    return isDone;
}

void DVDoCDandraFil::showAll() const
{
    for(int i=0; i<nrOf; i++)
    {
        cout<<dvds[i].toString()<<endl;
    }


}

bool DVDoCDandraFil::showSome(string arr[], int n, int space, string name, int playtime, int year)
{
    bool isOk = false;
    int pos=-1;
    DVDoCD temp = DVDoCD(space, name, playtime, year);
    for(int i=0; i<n; i++)
    {
        if(dvds[i]==temp)
        {
            isOk=true;
            pos=i;

        }
    }
    if(pos!=-1)
    {
        arr[0]=dvds[pos].toString();
    }
    return isOk;
}


bool DVDoCDandraFil::changeSomething(int space, int nSpace, string name, string nName, int nPT, int year, int NY)
{
    bool isChanged = false;
    DVDoCD temp = DVDoCD(name, year);
    int pos=findOne(name, year);
    if(pos!=-1)
    {
        dvds[pos]=DVDoCD(nSpace, nName, nPT, NY);
        isChanged=true;
    }

    return isChanged;
}

void DVDoCDandraFil::sortAllbySpace()
{
    int posOfSm=-1;
    DVDoCD temp;
    for(int i=0; i<nrOf; i++)
    {
        posOfSm=i;

        for(int h=i+1; h<nrOf; h++)
        {

            if(dvds[h]<dvds[i])
            {
                posOfSm=h;




            }
        }
        temp=dvds[posOfSm];
        dvds[posOfSm]=dvds[i];
        dvds[i]=temp;

    }


}

void DVDoCDandraFil::sortAllbyName()
{
    int pos=-1;
    DVDoCD temp;
    for(int i=0; i<nrOf; i++)
    {
        pos=i;
        for(int h=i+1; h<nrOf; h++)
        {
            if(dvds[h]<dvds[i])
            {
                pos=h;
            }
        }


        temp=dvds[pos];
        dvds[pos]=dvds[i];
        dvds[i]=temp;
    }

}














