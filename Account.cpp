//
// Created by Yulia Lizneva on 2017-10-23.
//

#include "Account.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


Account::Account(string name, int password)
{
    this->name=name;
    this->balance=0;
    this->kontoNr=rand()%101+599;
    this->password=password;
    for(int i=0; i<10; i++)
        this->transaktions[i] =0;
}
Account::Account()
{
    this->name="";
    this->kontoNr=0;
    this->password=0;
    this->balance=0;
    for(int i=0; i<10; i++)
        this->transaktions[i] =0;

}
Account::~Account()
{

}
void Account::getTransaktions()
{

    for(int i=0; i<10 && this->transaktions[i]!=0; i++)
    {
        cout<<"transaktions "<<this->transaktions[i]<<endl;
    }


}

void Account::fyllTransaktions(int amount)
{
    int counter=0;

    while(this->transaktions[counter]!=0)
    {
       counter++;
    }
    transaktions[counter]=amount;

}

string Account::getName() const
{
    return this->name;
}
int Account::getKontoNr() const
{
    return this->kontoNr;
}
int Account::getPAssword() const
{
    return this->password;
}
double Account::getBAlance() const
{

    return this->balance;
}

void Account::setPassword(int pass)
{
    this->password=pass;
}
void Account::makeDeposito(int money)
{
    this->fyllTransaktions(money);
    this->balance+=money;



}
bool Account::withdraw(int money)
{

    bool isOk;
    if(this->balance>=money)
    {
        this->balance-=money;
        isOk=true;
        this->fyllTransaktions(-money);
    }
    return isOk;
}

bool Account::operator==(const Account &otherOne) const
{
    bool isEqual=false;
    if(this->name==otherOne.name && this->password==otherOne.password)
    {
        isEqual=true;
    }
    return isEqual;
}
bool Account::operator<(const Account &otherOne) const
{
    bool isBigger=false;
    if(this->balance<otherOne.balance)
    {
        isBigger=true;
    }
    return isBigger;
}



string Account::toString() const
{
    string all = name + " accountNr ";
    for(int i=0; i<10; i++)
    all+=to_string(kontoNr) +"\n"+ " "+ to_string(i+1)+
         to_string(transaktions[i]);
    return all;
}