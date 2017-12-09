//
// Created by Yulia Lizneva on 2017-10-06.
//

#include "Ball.h"
#include <cmath>

Ball::Ball(int speedX)
{
    this->speedX = speedX;

}

Ball::Ball()
{
    this->speedX =-1;

}
Ball::~Ball()
{

}

int Ball::getSpeedX() const
{
    return this->speedX;
}

double Ball::getSpeedY(int travelTime) const
{
    return travelTime*aceleration;

}

double Ball::getResultant(int travelTime) const
{
    return sqrt((this->speedX*this->speedX)+(this->getSpeedY(travelTime)*this->getSpeedY(travelTime)));

}


bool Ball::operator==(const Ball &otherBall) const
{
    bool isEqual = false;
    if(this->speedX == otherBall.speedX)
    {
        isEqual=true;
    }
    return isEqual;
}

bool Ball::operator>(const Ball &otherball) const
{
    bool isBigger = false;
    if(this->speedX > otherball.speedX)
    {
        isBigger=true;
    }
    return isBigger;
}

string Ball::toString(int travelTime) const
{
    string byAsStringX = to_string(this->speedX);
    string byAsStringY = to_string(this->getSpeedY(travelTime));
    string byAsStringTot = to_string(this->getResultant(travelTime));

    string totalString = byAsStringX + "m/s is the horizontal speed, "+
    byAsStringY + "m/s is the vertical speed, and " + byAsStringTot
    + "m/s is the total speed of the ball.";
    return totalString;

}