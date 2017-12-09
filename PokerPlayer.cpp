//
// Created by Yulia Lizneva on 2017-10-22.
//

#include "PokerPlayer.h"
#include <ctime>
#include <cstdlib>
using namespace std;


PokerPlayer::PokerPlayer(string name)
{

    this->name=name;
    for(int i=0; i<5; i++)
    {
        this->result[i]=rand()%101-60;
    }
}
PokerPlayer::PokerPlayer()
{
    this->name="";
    for(int i=0; i<5; i++)
    {
        this->result[i]=0;
    }
}

PokerPlayer::~PokerPlayer()
{

}

string PokerPlayer::getName() const
{
    return this->name;
}

int PokerPlayer::getResult() const
{
    int bla;
    for(int i=0; i<5; i++)
    {
        bla=result[i];
    }
    return bla;
}

int PokerPlayer::getSum() const
{

    int sum=0;
    for(int i=0; i<5; i++)

    sum+=this->result[i];

    return sum;
}
bool PokerPlayer::operator==(const PokerPlayer &otherOne) const
{
    bool isEqual = false;
    if(this->name == otherOne.name)
    {
        isEqual=true;
    }
    return isEqual;
}
bool PokerPlayer::operator<(const PokerPlayer &otherOne) const
{
    bool isBigger=false;


        if(this->getSum()<otherOne.getSum())
        {
            isBigger = true;
        }

    return isBigger;
}
bool PokerPlayer::operator>(const PokerPlayer &otherOne) const
{
    bool isSmaller= false;
    if(this->getSum()<otherOne.getSum())
    {
        isSmaller=true;
    }
    return isSmaller;
}

string PokerPlayer::toString() const
{

    string runder = "The player "+ name+"\n";
    for(int i=0; i<5; i++)
    {
        runder+= " for the #"+ to_string(i+1) +" round "+
                "got result " + to_string(result[i])+":- \n";
    }


       return runder;

}