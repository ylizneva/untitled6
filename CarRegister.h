//
// Created by Yulia Lizneva on 2017-11-08.
//

#pragma once
#include "Car.h"


class CarRegister
{
private:
    int nrOfCars;
    int Capacity;
    Car* *cars;

    //hj‰lpfunktioner
    void initiate(int from =0);	//s‰tter toma platser i arrayn till nullptr
    void expand();	//expanderar arrayn
    void freeMemory(); //raderar arrayn
    void makeCopy(const CarRegister &originalObjekt);

public:
    CarRegister(int Capacity =10); //konstruktor
    CarRegister(const CarRegister &originalObjekt); //copy constructor
    CarRegister& operator=(const CarRegister &originalObject); //assignment constructor
    ~CarRegister();	//Destructor

    //l‰gg till bil
    void addCar(const string name, const string regNr, const int nrOfMiles, const double price);

    //retunerar antal bilar
    int getNrOfCars()const;

    //fˆr att fÂ alla bilar egensakper som str‰ngar
    void getAsStrings(string str[]) const;

    //fˆr att fÂ egenskaper fˆr alla bilar inom ett prisintervall som str‰ngar
    void getAsStringsByPrice(string str[], double min, double max) const;

    //fˆr att fÂ egenskaper fˆr alla bilar inom ett intervall av kˆrda mil som str‰ngar
    void getAsStringsByMiles(string str[], int min, int max) const;

    void getAsStringsByRegNr(string str[], string regNr) const;
    //‰ndrar pris
    void changePrice(const double percent/*, const double maxLimit*/);

    //tar bort en bil
    void RemoveCar(const int pos);

    //retunerar positionen fˆr en bil
    int findCar(const string regNr) const;

    //rensar allt innehÂll i arrayn
    void ClearAll();

    //retunerar kapaciteten fˆr arrayn (fˆr test)
    int getCapacity() const;

    // sparar till fil
    void saveToFile(const string FileName) const;

    //l‰ser frÂn fil
    void readFromFile(const string FileName);


};

