//
// Created by Yulia Lizneva on 2017-10-23.
//

#ifndef UNTITLED6_ACCOUNT_H
#define UNTITLED6_ACCOUNT_H

#include <string>
using namespace std;

class Account
{
private:
    string name;
    int kontoNr;
    int password;
    int transaktions[10]={};
    double balance;

public:
    Account(string name, int kontoNr, int password);
    Account();
    Account(string name, int password);
    ~Account();

    string getName() const;
    int getKontoNr() const;
    int getPAssword() const;
    double getBAlance() const;
    void fyllTransaktions(int antal);
    void getTransaktions();
    void setPassword(int pass);
    void makeDeposito(int money);
    bool withdraw(int money);
    bool operator==(const Account &otherOne) const;
    bool operator<(const Account &otherOne) const;
    string toString() const;





};


#endif //UNTITLED6_ACCOUNT_H
