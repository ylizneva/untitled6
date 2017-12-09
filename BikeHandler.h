//
// Created by Yulia Lizneva on 2017-11-20.
//

#ifndef UNTITLED6_BIKEHANDLER_H
#define UNTITLED6_BIKEHANDLER_H

#include "BikeKlass.h"


class BikeHandler
{
private:
    BikeKlass* *bikes;
    int nrOfBikes;
    int cap;

public:
    BikeHandler(int cap=10);
    ~BikeHandler();

    void makeCopy(const BikeHandler &original);
    void initiate(int from=0);
    void freeMemory();
    //BikeHandler(const BikeHandler &original);
    //void operator=(const BikeHandler &original); alternativ
    BikeHandler& operator=(const BikeHandler &original);
    void expand();
    bool addBike(string colour, string make, int nrOfGears);

    void getAllBikesAsStrings(string str[], int n) const;
    int gerNrOfBikes() const;

};


#endif //UNTITLED6_BIKEHANDLER_H
