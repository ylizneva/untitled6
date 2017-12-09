//
// Created by Yulia Lizneva on 2017-11-20.
//

#include "BikeHandler.h"

BikeHandler::BikeHandler(int cap)
{
    this->nrOfBikes=0;
    this->cap=cap;
    this->bikes= new BikeKlass*[this->cap];

}
BikeHandler::~BikeHandler()
{
    for(int i=0; i<this->nrOfBikes; i++)
    {
        delete this->bikes[i];
    }
    delete[]this->bikes;

}

/*BikeHandler::BikeHandler(const BikeHandler &original)
{
    this->cap=original.cap;
    this->nrOfBikes=original.nrOfBikes;
    this->bikes= new BikeKlass*[this->cap];
    for(int i=0; i<this->nrOfBikes; i++)
    {
        this->bikes[i] = new BikeKlass(*original.bikes[i]);
    }
}
 */
//void operator=(const BikeHandler &original); alternativ
BikeHandler& BikeHandler::operator=(const BikeHandler &original)
{
    if(this !=&original)
    {
        this->freeMemory();
        this->makeCopy(original);
    }
    return *this;
}
void BikeHandler::expand()
{
    this->cap+=10;
    BikeKlass**temp= new BikeKlass*[this->cap];
    for(int i=0; i<this->nrOfBikes; i++)
    {
        temp[i]=this->bikes[i];
    }
    delete[] this->bikes;
    this->bikes=temp;
    temp= nullptr;
    this->initiate(0);
}

void BikeHandler::freeMemory()
{
  for(int i=0; i<this->nrOfBikes; i++)
  {
      if(bikes[i]!= nullptr)
      {
          delete this->bikes[i];
      }
  }
    delete[] this->bikes;
}


void BikeHandler::initiate(int from)
{
    for(int i=from; i<this->nrOfBikes; i++)
    {
        this->bikes[i]= nullptr;
    }

}

void BikeHandler::makeCopy(const BikeHandler &original)
{
    this->nrOfBikes=original.nrOfBikes;
    this->cap=original.cap;

    this->bikes=new BikeKlass*[original.cap];
    for(int i=0; i<original.nrOfBikes; i++)
    {
        this->bikes[i]=new BikeKlass(*original.bikes[i]);
    }
    this->initiate(this->nrOfBikes);

}




bool BikeHandler::addBike(string colour, string make, int nrOfGears)
{
    bool isDone= false;
    BikeKlass* temp = new BikeKlass(colour, make, nrOfGears);
    for(int i=0; i<this->nrOfBikes && !isDone; i++)
    {
        if(*this->bikes[i]==*temp)
        {
            isDone=true;
        }

    }
    if(!isDone)
    {
        if(this->nrOfBikes==this->cap)
        {
            this->expand();
        }
        this->bikes[this->nrOfBikes++]=temp;
    }
    else
    {
        delete temp;
    }
   return !isDone;
}

void BikeHandler::getAllBikesAsStrings(string str[], int n) const
{
    //förutsätter att cap är tillräcklig
    for(int i=0; i<this->nrOfBikes; i++)
    {
        str[i]=this->bikes[i]->toString();
    }
}
int BikeHandler::gerNrOfBikes() const
{
    return this->nrOfBikes;
}