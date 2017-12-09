//
// Created by Yulia Lizneva on 2017-11-19.
//

#ifndef UNTITLED6_VEHICLEREGISTER_H
#define UNTITLED6_VEHICLEREGISTER_H

#include <string>

using namespace std;

class Vehicle
{

private:
    string fuel;
    string brand;
    int motor;
    int wheels;


public:
    Vehicle(int wheels, string fuel, int motor, string brand);
    Vehicle(int motor, string brand);
    Vehicle();
    virtual~Vehicle();

    Vehicle(const Vehicle &original);
    void operator=(const Vehicle &original);

    bool operator==(const Vehicle &original);
    string getFuel() const;
    string getBrand() const;
    int getMotor() const;
    int getWheels() const;

    void setFuel();
    void setBrand();
    void setMotor();
    void setWheels();

    string toString() const;
    //pure virt funktion
    virtual string toStringSpecific() const =0;



};


#endif //UNTITLED6_VEHICLEREGISTER_H
