//
// Created by Yulia Lizneva on 2017-11-10.
//

#ifndef UNTITLED6_YATZEE_H
#define UNTITLED6_YATZEE_H

#include "Protocol.h"
#include "Dice.h"


class Yatzee
{
    static const int nrOfDices=5;

private:

    int nrOfPlayers;
    int maxNrOfPlayers;
    Protocol* *protocl;
    Dice dices[nrOfDices];
    int curentPlayer;


    void initiate(int from =0);
    void expend();
    void freeMemory();
    void makeCopy(const Yatzee &originalObjekt);

public:

    Yatzee(int players =5);
    Yatzee(const Yatzee &originalObjekt);
    Yatzee& operator=(const Yatzee &originalObjekt);
    ~Yatzee();


    int findPlayer(const string name) const;
    void addPlayer(const string name);
    string protocolInfoOfCurrentPlayer() const;
    int getNrOfPlayers() const;
    void toss(int diceValue);
    void toss();
    string infoOfLatestToss() const;
    bool addResult(int diceValue);
    string nameOfCurrentPlayer() const;
    void nextPlayersTurn();
    bool allPlayersDone() const;




};


#endif //UNTITLED6_YATZEE_H
