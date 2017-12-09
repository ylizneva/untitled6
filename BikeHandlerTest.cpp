//
// Created by Yulia Lizneva on 2017-11-20.
//

#include <iostream>
#include "BikeHandler.h"

using namespace std;


void test(BikeHandler &bh)
{
    bh.addBike("red", "cresent", 12);

}


int main()
{
    BikeHandler bikeHand(4);
    bikeHand.addBike("yellow", "monark", 7);
    test(bikeHand);

    string bikes[4];
    bikeHand.getAllBikesAsStrings(bikes, 5);
    cout<<bikes[1]<<"*****"<<bikes[2];
    return 0;
}