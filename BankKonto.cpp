//
// Created by Yulia Lizneva on 2017-10-10.
//

#include "BankKonto.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

BankKonto::BankKonto(string nameOwner, string code)
{
    srand(time(0));
    this->nameOwner=nameOwner;
    this->code=code;
    this->countNr=rand()%89999+10000;
    this->balance=0;
    this->transaktioner = new int [10];

}



BankKonto::BankKonto()
{
    this->nameOwner="-";
    this->code="?";
    this->countNr=rand()%89999+10000;
    this->balance=0;
    this->transaktioner=new int [10];
}
BankKonto::~BankKonto()
{
    delete[]transaktioner;
}

void BankKonto::getTransaktioner()
{

    for(int i=0; i<10 && this->transaktioner[i]!=0; i++)
    {
        cout<<"transaktioner "<< i <<" "<<this->transaktioner[i]<<endl;
    }
}

void BankKonto::enterTrans(int amount)
{
    int counter =0;
    while(this->transaktioner[counter]!=0)
    {
        counter++;
    }

    transaktioner[counter] = amount;

}



string BankKonto::getNameOwner() const
{
    return this->nameOwner;
}

int BankKonto::getBalance() const
{

    return this->balance;
}

int BankKonto::getCountNr() const
{

    return this->countNr;
}

void BankKonto::setNameOwner(string nameOwner)
{
    this->nameOwner=nameOwner;
}


bool BankKonto::checkCode(string code) const
{
    bool isEqual = false;
    if(this->code==code)
    {
        isEqual=true;
    }
    return isEqual;
}

bool BankKonto::checkName(string name) const
{
    bool isGood = false;
    if(this->nameOwner==name)
    {
        isGood=true;
    }
    return isGood;
}


bool BankKonto::changeCode(string oldCode, string newCode)
{
    bool isOk = false;
    if(code==oldCode)
    {
        this->code=newCode;
        isOk=true;
    }
    return isOk;
}

void BankKonto::deposit(int amount)
{

    this->enterTrans(amount);
    this->balance+=amount;
}

bool BankKonto::withdraw(int amount)
{

    bool isGood = false;

    if(balance>=amount)
    {
        this->balance-=amount;
        isGood=true;
        amount=amount-amount*2;
        this->enterTrans(amount);
    }


    return isGood;
}

/*bool BankKonto::operator==(const BankKonto &otherKund) const
{
    bool isExist = false;
    if(this->code==otherKund.code)
    {
        isExist =true;
    }
    return isExist;
}
*/
string BankKonto::toString() const
{

   return this->getNameOwner()+ " have countNr " + to_string(this->countNr) + " with balance "
   + to_string(this->balance);


}