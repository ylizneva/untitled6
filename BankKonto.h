//
// Created by Yulia Lizneva on 2017-10-10.
//

#ifndef UNTITLED6_BANKKONTO_H
#define UNTITLED6_BANKKONTO_H

#include <string>
using namespace std;


class BankKonto
{

private:

    string nameOwner;
    string code;
    int countNr;
    int balance;
    int *transaktioner = nullptr;



public:

    BankKonto(string nameOwner, string code);
    BankKonto();
    ~BankKonto();

    string getNameOwner() const;

    int getCountNr() const;
    int getBalance() const;

    void setNameOwner(string nameOwner);
    void getTransaktioner();
    void enterTrans(int amount);


    bool checkCode(string code) const;
    bool checkName(string name) const;
    bool changeCode(string oldCode, string newCode);

    void deposit(int amount);
    bool withdraw(int amount);
    //bool operator==(const BankKonto &otherKund) const;


    string toString() const;




};


#endif //UNTITLED6_BANKKONTO_H
