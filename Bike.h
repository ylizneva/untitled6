//
// Created by Yulia Lizneva on 2017-11-19.
//

#ifndef UNTITLED6_BIKE_H
#define UNTITLED6_BIKE_H

#include <string>
#include "Vehicle.h"

using namespace std;

class Bike:public Vehicle
{

private:
    string balansPedals;
    int nrOf;


public:
    Bike(string balans="", int wheels=0, string fuel="", int motor=0, string brand="");
    virtual~Bike();

    Bike(const Bike &original);
    void operator=(const Bike &original);

    int getNr() const;

    string getBalans() const;

    string toStringSpecific() const;




};


#endif //UNTITLED6_BIKE_H
