//
// Created by Yulia Lizneva on 2017-11-03.
//

#ifndef UNTITLED6_DVDOCDANDRAFIL_H
#define UNTITLED6_DVDOCDANDRAFIL_H

#include "DVDoCD.h"


class DVDoCDandraFil
{

private:
    static const int maxNrOf = 10;
    int nrOf =0;
    DVDoCD dvds[maxNrOf];
    static const int volume = 50;
    int freeSpace=50;


public:
    DVDoCDandraFil(int space, string name, int playtime, int year);
    DVDoCDandraFil(string name, int year);
    DVDoCDandraFil();
    ~DVDoCDandraFil();

    void sortAllbySpace();
    void sortAllbyName();
    int getFreeSpace(int space, string name, int playtime, int year);
    bool saveAmovie(int space, string name, int playtime, int year);
    bool deleteAmovie(int space, string name, int playtime, int year);
    int findOne(string name, int year);
    void showAll() const;
    bool showSome(string arr[], int n, int space, string name, int playtime, int year);
    bool changeSomething(int space, int nSpace, string name, string nName, int nPT, int year, int NY);






};


#endif //UNTITLED6_DVDOCDANDRAFIL_H
