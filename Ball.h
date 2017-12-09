//
// Created by Yulia Lizneva on 2017-10-06.
//

#ifndef BALL_H
#define BALL_H

#include <string>
using namespace std;

const double aceleration =9.82;
class Ball
{

private:
    int speedX;


public:

    Ball(int speedX);
    ~Ball();
    Ball();

    int getSpeedX() const;
    double getSpeedY(int travelTime) const;
    double getResultant(int travelTIme) const;




    bool operator==(const Ball &otherball) const;
    bool operator >(const Ball &otherball) const;

    string toString(int travelTime) const;










};


#endif //UNTITLED6_BALL_H
