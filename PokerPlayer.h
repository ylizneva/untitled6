//
// Created by Yulia Lizneva on 2017-10-22.
//

#ifndef UNTITLED6_POKERPLAYER_H
#define UNTITLED6_POKERPLAYER_H
#include <string>
using namespace std;

class PokerPlayer
{
private:
    string name;
    int result[5] ={};

public:
    PokerPlayer(string name);
    PokerPlayer();
    ~PokerPlayer();

    string getName() const;
    int getSum() const;

    bool operator==(const PokerPlayer &otherOne) const;
    bool operator<(const PokerPlayer &otherOne) const;
    bool operator>(const PokerPlayer &otherOne) const;
    string toString() const;
    int getResult() const;


};


#endif //UNTITLED6_POKERPLAYER_H
