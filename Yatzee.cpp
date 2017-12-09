//
// Created by Yulia Lizneva on 2017-11-10.
//

#include "Yatzee.h"
#include "Dice.h"
#include "Protocol.h"
#include <sstream>
using namespace std;

void Yatzee::initiate(int from)
{
    for(int i=from; i<this->maxNrOfPlayers; i++)
    {
        this->protocl[i]= nullptr;
    }
}

void Yatzee::expend()
{
    this->maxNrOfPlayers+=10;
    Protocol* *temp = new Protocol*[this->maxNrOfPlayers];
    for(int i =0; i<this->nrOfPlayers; i++)
    {
        temp[i]=this->protocl[i];
    }

    delete[] this->protocl;
    this->protocl=temp;
    temp=NULL;
    this->initiate(this->nrOfPlayers);


}
void Yatzee::freeMemory()
{
    for(int i=0; i<this->nrOfPlayers; i++)
    {
        if(this->protocl[i]!= nullptr)
        {
            delete this->protocl[i];
        }
    }

    delete [] this->protocl;
}

void Yatzee::makeCopy(const Yatzee &originalObjekt)
{
    this->maxNrOfPlayers=originalObjekt.maxNrOfPlayers;
    this->nrOfPlayers=originalObjekt.nrOfPlayers;
    this->protocl= new Protocol*[originalObjekt.maxNrOfPlayers];
    for(int i=0; i<originalObjekt.nrOfPlayers; i++)
    {
        this->protocl[i]=new Protocol(*originalObjekt.protocl[i]);
    }
    this->initiate(this->nrOfPlayers);
}


Yatzee::Yatzee(int players)
{
    this->maxNrOfPlayers=players;
    this->protocl= new Protocol*[this->maxNrOfPlayers];
    this->curentPlayer=0;
    this->nrOfPlayers=0;
    this->initiate(0);
}

Yatzee::Yatzee(const Yatzee &originalObjekt)
{
    this->makeCopy(originalObjekt);
}
Yatzee& Yatzee::operator=(const Yatzee &originalObjekt)
{
    if(this != &originalObjekt)
    {
        this->freeMemory();
        this->makeCopy(originalObjekt);
    }
    return *this;
}
Yatzee::~Yatzee()
{
    this->freeMemory();
    this->nrOfPlayers=0;
}
int Yatzee::findPlayer(const string name) const
{
    int pos=-1;
    for(int i=0; i<this->nrOfPlayers; i++)
    {
        if(this->protocl[i]->getPlayerName()==name)
        {
            pos=i;
        }
    }
    return pos;
}
void Yatzee::addPlayer(const string name)
{
    if(findPlayer(name)==-1)
    {
        if(this->nrOfPlayers==this->maxNrOfPlayers)
        {
            this->expend();
        }

        this->protocl[this->nrOfPlayers++]=new Protocol(name);
    }
}


string Yatzee::protocolInfoOfCurrentPlayer() const
{
    return this->protocl[curentPlayer]->toString();
}



int Yatzee::getNrOfPlayers() const
{
    return this->nrOfPlayers;
}

void Yatzee::toss(int diceValue)
{

        for(int i=0; i<this->nrOfDices; i++)
        {
           if(dices[i].getCurrentValue()!=diceValue)
           {
               dices[i].toss();
           }
        }
}

string Yatzee::infoOfLatestToss() const
{
    stringstream out;

    for(int i=0; i<this->nrOfDices; i++)
    {
        out<< "Dice "<<i+1<< " : "<< this->dices[i].getCurrentValue()<<" , ";
    }

    return out.str();
}
bool Yatzee::addResult(int diceValue)
{
    bool isAdded=false;
    int resultat=0;

    for(int i=0; i<this->nrOfDices; i++)
    {
        if(diceValue==this->dices[i].getCurrentValue())
        {
            resultat+=this->dices[i].getCurrentValue();

        }

    }
    if(this->protocl[curentPlayer]->addResult(diceValue, resultat))
    {
        isAdded=true;
    }

    return isAdded;
}

string Yatzee::nameOfCurrentPlayer() const
{
    return this->protocl[curentPlayer]->getPlayerName();
}
void Yatzee::nextPlayersTurn()
{
  if(this->curentPlayer<this->nrOfPlayers-1)
  {
      this->curentPlayer++;
  }
    else
  {
      this->curentPlayer=0;
  }

}
bool Yatzee::allPlayersDone() const
{
    bool isDone=false;
    for(int i=0; i<this->nrOfPlayers; i++)
    {
        if(protocl[i]->isFilled())
        {
            isDone=true;
        }
    }
    return isDone;
}

void Yatzee::toss()
{
    for(int i=0; i<this->nrOfDices; i++)
    {
        dices[i].toss();
    }
}