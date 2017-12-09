//
// Created by Yulia Lizneva on 2017-11-10.
//

#include "Dice.h"
#include <cstdlib>
#include <ctime>


using namespace std;


Dice::Dice(int sides)
{

    this->sides=sides;
    this->value=rand()%this->sides+1;

}
void Dice::toss()
{
    this->value=rand()%this->sides+1;
}
Dice::~Dice()
{

}


int Dice::getCurrentValue() const
{
  return this->value;
}
