//
// Created by Yulia Lizneva on 2017-11-10.
//

#include "Protocol.h"
#include <sstream>




Protocol::Protocol(string playersName)
{
    this->playersName=playersName;
    this->total=0;

}



Protocol::Protocol()
{

    this->playersName="";
    this->total=0;

}

Protocol::~Protocol()
{

}

bool Protocol::addResult(int diceValue, int result)
{
    bool isAdded=false;
    if(this->results[diceValue-1]<=0)
    {
        this->results[diceValue-1]=result;
        this->total+=result;
        isAdded=true;
    }

    return isAdded;
}


string Protocol::getPlayerName() const
{
    return this->playersName;
}

int Protocol::getSum() const
{
    return this->total;
}

bool Protocol::isFilled() const
{
    bool isFilled=true;
    for(int i=0; i<CAP; i++)
    {
        if(results[i]<=0)
        {
            isFilled=false;
        }
    }
    return isFilled;
}
string Protocol::toString() const
{
    stringstream out;
    out<<this->playersName<<" got \n";
    for(int i=0; i<CAP; i++)
    {
        out<<i+1<<" : "<<this->results[i]<<"\n";
    }
    out<<"Total :"<<this->total<<endl;
    return out.str();
}