//
// Created by Yulia Lizneva on 2017-11-10.
//

#ifndef UNTITLED6_PROTOCOLCOLUMN_H
#define UNTITLED6_PROTOCOLCOLUMN_H


#include <string>

using namespace std;

const int CAP=6;

class Protocol
{

private:
    int results[CAP]={};
    int total;
    string playersName;


public:

    Protocol();
    ~Protocol();
    Protocol(string playersName);

    bool addResult(int diceValue, int result);
    string getPlayerName() const;
    int getSum() const;
    bool isFilled() const;
    string toString() const;


};


#endif //UNTITLED6_PROTOCOLCOLUMN_H
