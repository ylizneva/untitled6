//
// Created by Yulia Lizneva on 2017-11-19.
//

#ifndef UNTITLED6_CARVSMC_H
#define UNTITLED6_CARVSMC_H

#include "Vehicle.h"


class CarVSmc:public Vehicle
{
private:
    string airbag;

public:
    CarVSmc(string airbag="", int wheels=0, string fuel="", int motor=0, string brand="" );
    virtual~CarVSmc();

    CarVSmc(const CarVSmc &origianal);
    void operator=(const CarVSmc &original);

    string getBag() const;
    string toStringSpecific() const;

};


#endif //UNTITLED6_CARVSMC_H
