//
// Created by Yulia Lizneva on 2017-11-19.
//

#ifndef UNTITLED6_VEHICLEREALREGISTER_H
#define UNTITLED6_VEHICLEREALREGISTER_H

#include "Vehicle.h"
#include "Bike.h"
#include "CarVSmc.h"


class VehicleRegister
{
private:
    int year;
    string owner;
    int cap;
    int nrOfFordons;
    Vehicle* *vehicles;

    //hjälpFunktioner
    void initiate(int from =0);
    void expend();
    void makeCopy(const VehicleRegister &original);
    void freeMemory();

public:
    VehicleRegister(int cap=10);
    VehicleRegister(const VehicleRegister &original);

    VehicleRegister& operator=(const VehicleRegister &original);
    //bool operator==(const VehicleRegister &original);

    //void operator=(const VehicleRegister &original);

    virtual~VehicleRegister();

    //int findOne(const Vehicle &vehicle, int motor, string brand) const;
    bool addCar( string airbag, int wheels, string fuel, int motor, string brand);
    bool addBike(string balans, int wheels, string fuel, int motor, string brand);
    bool deleteCar( string airbag, int wheels, string fuel, int motor, string brand);

    string getOwner() const;
    int getNrOfall() const;
    void showAll(string arr[], int n);
    void readFile(string fileName);
    void saveOnFile(string fileName);
    void getSortedByYaerAsString(string arr[], int n);
    void clearAll();
    string toString();


};


#endif //UNTITLED6_VEHICLEREALREGISTER_H
