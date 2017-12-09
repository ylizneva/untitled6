//
// Created by Yulia Lizneva on 2017-11-08.
//
#pragma once

#include <string>

using namespace std;

class Car
{
private:
    string model;
    string regNr;
    int nrOfMiles;
    double price;



public:

    Car();
    Car(const string model, const string regNr, const int nrOfMiles, const double price);
    ~Car();


    //skriver ut en bils egenskaper
    string toStringCar() const;

    //getfunktioner
    string getModel() const;
    string getRegNr()const;
    double getPrice() const;
    int getMiles() const;

    //set-funktioner
    void setModel(const string model);
    void setRegNr(const string regNr);
    void setNrOfMiles(const int nrOfMiles);
    void setPrice(const double price);



};

