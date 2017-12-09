//
// Created by Yulia Lizneva on 2017-11-19.
//

#include "VehicleRegister.h"
#include "Vehicle.h"


void VehicleRegister::initiate(int from)
{
   for(int i=from; i<this->cap; i++)
   {
       this->vehicles[i]= nullptr;

   }

}
void VehicleRegister::expend()
{
    this->cap+=10;
    Vehicle**temp1= new Vehicle*[this->cap];

    for(int i=0; i<this->nrOfFordons; i++)
    {
        temp1[i]=this->vehicles[i];

    }
    delete[] this->vehicles;

    this->vehicles=temp1;


    this->initiate(this->nrOfFordons);

}
void VehicleRegister::makeCopy(const VehicleRegister &original)
{
    this->cap=original.cap;
    this->nrOfFordons=original.nrOfFordons;

    this->vehicles= new Vehicle*[original.cap];



    for(int i=0; i<original.nrOfFordons; i++)
    {
        if( dynamic_cast<CarVSmc*>(original.vehicles[i])!= nullptr)
        {
            //dynamic_cast<CarVSmc*>(original.vehicles[i]);
           this->vehicles[i]= new CarVSmc(*dynamic_cast<CarVSmc*>(original.vehicles[i]));

        }
        if(dynamic_cast<Bike*>(original.vehicles[i])!= nullptr)
        {
            //dynamic_cast<Bike*>(original.vehicles[i]);
        }

    }

}
void VehicleRegister::freeMemory()
{
    for(int i=0; i<this->nrOfFordons; i++)
    {
        if(this->vehicles[i]!= nullptr)
        {
            delete this->vehicles[i];

        }
    }
    delete[] this->vehicles;

}
VehicleRegister::VehicleRegister(int cap)
{
    this->cap=cap;
    this->nrOfFordons=0;
    this->owner="";
    this->year=0;
    this->vehicles= new Vehicle*[this->cap];
    this->initiate(0);
}
VehicleRegister::VehicleRegister(const VehicleRegister &original) //copy konstruktor
{
    this->makeCopy(original);

}

//skillnaden mellan dem??
// behövs det? eller räcker det med ****VehicleRegister& VehicleRegister::operator=(const VehicleRegister &original)
/*void VehicleRegister::operator=(const VehicleRegister &original)
{
    Vehicle::operator=(original);
    this->cap=original.cap;
    this->nrOfFordons=original.nrOfFordons;
    this->owner=original.owner;
    this->year=original.year;
}*/
VehicleRegister::~VehicleRegister()
{
    this->freeMemory();

}

VehicleRegister& VehicleRegister::operator=(const VehicleRegister &original)
{
    if(this !=&original)
    {
        this->freeMemory();
        this->makeCopy(original);
    }
    return *this;
}


/*int VehicleRegister::findOne(const Vehicle &vehicle, int motor, string brand) const
{
    //ska det finnas findFUnktion i varje sub.klass??
    //string *str=nullptr;
    //str = new Vehicle [vehicle];
    int pos=-1;

    for(int i=0; i<nrOfFordons; i++)
    {
        if(*this->vehicles[i]->getBrand()==)
        {
            pos=i;
        }

    }
    return pos;*/

bool VehicleRegister::addCar( string airbag, int wheels, string fuel, int motor, string brand)
{

    bool isOk=false;


    for(int i=0; i<this->nrOfFordons; i++)
    {
        if (this->vehicles[i]->getBrand() != brand && this->vehicles[i]->getMotor() != motor)
            if(this->nrOfFordons==this->cap)
            {
                this->expend();

                this->vehicles[nrOfFordons++] = new CarVSmc(airbag, wheels, fuel, motor, brand);
                isOk = true;
            }
    }

    return isOk;

}


bool VehicleRegister::addBike( string balans, int wheels, string fuel, int motor, string brand)
{

    bool isOk = false;
    for (int i = 0; i < this->nrOfFordons; i++)
    {

        if (this->vehicles[i]->getBrand() != brand && this->vehicles[i]->getMotor() != motor)
        {
            if (this->nrOfFordons == this->cap)
            {
                this->expend();
                this->vehicles[nrOfFordons++] = new Bike(balans, wheels, fuel, motor, brand);
                isOk = true;
            }
        }

    }
    return isOk;
}


bool VehicleRegister::deleteCar( string airbag, int wheels, string fuel, int motor, string brand)
{

    bool isDone= false;

    int pos=-1;
    CarVSmc temp= CarVSmc(airbag, wheels, fuel, motor, brand);
        for(int i=0; i<this->nrOfFordons; i++)
        {
            if(*this->vehicles[i]==temp)
            {
                pos=i;
                delete this->vehicles[pos];
                this->vehicles[pos]=vehicles[--this->nrOfFordons];
                isDone=true;
            }
        }

    return isDone;
}

string VehicleRegister::getOwner() const
{
    return this->owner;
}
int VehicleRegister::getNrOfall() const
{
    return this->nrOfFordons;

}
void showAll(string arr[], int n);
void readFile(string fileName);
void saveOnFile(string fileName);
void getSortedByYaerAsString(string arr[], int n);
void clearAll();
string toString();
