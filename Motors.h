//
// Created by Yulia Lizneva on 2017-11-01.
//

#ifndef UNTITLED6_MOTORS_H
#define UNTITLED6_MOTORS_H


#include "Boatmotors.h"

class Motors
{
private:

    int nrOf=0;
    static const int maxNrOf=10;
    Boatmotors motors[maxNrOf];

public:
    Motors(string brand, int volume, int year, string serieNr);
    Motors();
    ~Motors();

    bool showSomething(string arr[], int n, string brand, int volume, int year, string serieNr);
    int findOne(string brand, int volume, int year, string serieNr) const;
    bool addOne(string brand, int volume, int year, string serieNr);
    void showAll() const;
    bool deleteOne(string brand, int volume, int year, string serieNr);
    void saveAsString(string arr[], int n);
    bool changeBrand(string brand, string newBrand, int vol, int NewV, int year, int newY, string serieNr);
};


#endif //UNTITLED6_MOTORS_H
