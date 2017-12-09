//
// Created by Yulia Lizneva on 2017-11-08.
//

#include "CarRegister.h"
#include <fstream>


void CarRegister::initiate(int from)
{
    for(int i=from; i<this->nrOfCars; i++)
    {
        this->cars[i]= nullptr;
    }
}//s‰tter toma platser i arrayn till nullptr

void CarRegister::makeCopy(const CarRegister &originalObjekt)
{
   this->Capacity=originalObjekt.Capacity;
    this->nrOfCars=originalObjekt.nrOfCars;

    this->cars= new Car*[originalObjekt.Capacity];

    for(int i=0; i<originalObjekt.nrOfCars; i++)
    {
        this->cars[i]= new Car(*originalObjekt.cars[i]);
    }
    this->initiate(this->nrOfCars);
}



void CarRegister::expand()
{
   this->Capacity+=10;

    Car* *temp = new Car*[this->Capacity];
    for(int i=0; i<this->nrOfCars; i++)
    {
        temp[i]=this->cars[i];
    }
    delete[] this->cars;
    this->cars=temp;
    temp=NULL;

    this->initiate(this->nrOfCars);

}//expanderar arrayn
void CarRegister::freeMemory()
{
   for(int i=0; i<this->nrOfCars; i++)
   {
       if(cars[i]!= nullptr)
       {
           delete this->cars[i];
       }
   }

    delete [] this->cars;

}//raderar arrayn


CarRegister::CarRegister(int Capacity)
{
    this->nrOfCars=0;
    this->Capacity=Capacity;
    this->cars= new Car*[this->Capacity];
    this->initiate(0);

}//konstruktor


/*CarRegister::CarRegister(const CarRegister &originalObjekt)
{
    this->makeCopy(originalObjekt);
}//copy constructor*/


CarRegister& CarRegister::operator=(const CarRegister &originalObject)
{
    if( this != &originalObject)
    {
        this->freeMemory();
        this->makeCopy(originalObject);
    }

    return *this;
}//assignment constructor



CarRegister::~CarRegister()
{
    this->freeMemory();
    this->nrOfCars=0;
}//Destructor

//l‰gg till bil
void CarRegister::addCar(const string name, const string regNr, const int nrOfMiles, const double price)
{
    if(findCar(regNr)==-1)
    {
        if(this->nrOfCars==this->Capacity)
        {
            this->expand();
        }
        this->cars[nrOfCars++]= new Car(name, regNr, nrOfMiles, price);
    }
}

//retunerar antal bilar
int CarRegister::getNrOfCars()const
{
    return this->nrOfCars;
}

//fˆr att fÂ alla bilar egensakper som str‰ngar
void CarRegister::getAsStrings(string str[]) const
{
    for(int i=0; i<this->nrOfCars; i++)
    {
        str[i]=cars[i]->toStringCar();
    }

    (*cars[0]) < (*cars[1]); //sortering med bool
    cars[i]->getPrice();//sortering manuellt
}

//fˆr att fÂ egenskaper fˆr alla bilar inom ett prisintervall som str‰ngar
void CarRegister::getAsStringsByPrice(string str[], double min, double max) const
{
    int counter=0;
    for(int i=0; i<this->nrOfCars; i++)
    {
        if(cars[i]->getPrice()>min && cars[i]->getPrice()<max)
        {
            str[counter++]= cars[i]->toStringCar();
        }
    }
}
void CarRegister::getAsStringsByRegNr(string str[], string regNr) const
{

    for(int i=0; i<this->nrOfCars; i++)
    {

        if(cars[i]->getRegNr()==regNr)
            str[i]=cars[i]->toStringCar();

    }
}

//fˆr att fÂ egenskaper fˆr alla bilar inom ett intervall av kˆrda mil som str‰ngar
void CarRegister::getAsStringsByMiles(string str[], int min, int max) const
{
    int counter =0;
    for(int i=0; i<this->nrOfCars; i++)
    {
        if(cars[i]->getMiles()<max &&cars[i]->getMiles()>min)
        {
            str[counter++]=cars[i]->toStringCar();
        }
    }
}

//‰ndrar pris
void CarRegister::changePrice(const double percent/*, const double maxLimit*/)
{
    double priset,konst;
    konst = (percent/100)+1;


    for(int i=0; i<this->nrOfCars; i++)
    {
        priset = cars[i]->getPrice()*konst;
        cars[i]->setPrice(priset);
    }
}

//tar bort en bil
void CarRegister::RemoveCar(const int pos)
{
    if(pos!=-1)
    {
        delete this->cars[pos];
        cars[pos]=cars[--nrOfCars];
    }
}

//retunerar positionen fˆr en bil
int CarRegister::findCar(const string regNr)  const
{
    int pos=-1;
    for(int i=0; i<this->nrOfCars; i++)
    {
        if(this->cars[i]->getRegNr()==regNr)
        {
            pos=i;
        }
    }
    return pos;
}

//rensar allt innehÂll i arrayn
void CarRegister::ClearAll()
{
    this->nrOfCars=0;
}

//retunerar kapaciteten fˆr arrayn (fˆr test)
int CarRegister::getCapacity() const
{
    return this->Capacity;
}

// sparar till fil
void CarRegister::saveToFile(const string FileName) const
{
    ofstream out;
    out.open(FileName);

    out<<this->nrOfCars<<endl;
    for(int i=0; i<this->nrOfCars; i++)
    {
        out<<cars[i]->toStringCar()<<endl;
    }
    out.close();
}

//l‰ser frÂn fil
void CarRegister::readFromFile(const string FileName)
{
    int counter, miles, price;
    string name, regNr;

    ifstream in;
    in.open(FileName);

    if(in.is_open())
    {
        in>>counter; in.ignore();

        for(int i=0; i<counter; i++)
        {
            getline(in, name);
            getline(in, regNr);
            in>>miles; in.ignore();
            in>>price; in.ignore();

           cars[counter]= new Car(name, regNr, miles, price);
        }
        nrOfCars+=counter;
    }
    in.close();
}
