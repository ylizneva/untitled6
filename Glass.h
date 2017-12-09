//
// Created by Yulia Lizneva on 2017-10-19.
//

#ifndef GLASS_H
#define GLASS_H

#include <string>

using namespace std;

class Glass
{
private:
    string name;
    int points;
    int quantity;

public:
    Glass(string name="", int points=0, int quantity =0);
    ~Glass();

    string getName() const;

    int getQuantity() const;

    void addPoints(int ppoints);

    double getAverage() const;

    bool operator==(const Glass &otherOne);
    bool operator>(const Glass &otherOne);

    string toString() const;






};

#endif
