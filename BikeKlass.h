//
// Created by Yulia Lizneva on 2017-11-20.
//

#ifndef UNTITLED6_BIKEKLASS_H
#define UNTITLED6_BIKEKLASS_H

#include <string>
using namespace std;

class BikeKlass
{
private:
    string colour;
    string make;
    int nrOfGears;

public:
    BikeKlass(string colour, string make, int nrOf);
    ~BikeKlass();
    BikeKlass();
    string toString() const;
    bool operator==(BikeKlass &original);

    string getColour() const;
    string getMake() const;
    int getGears() const;

};


#endif //UNTITLED6_BIKEKLASS_H
