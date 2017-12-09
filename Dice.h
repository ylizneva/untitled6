//
// Created by Yulia Lizneva on 2017-11-10.
//

#ifndef UNTITLED6_DICE_H
#define UNTITLED6_DICE_H


class Dice
{

private:
    int value;
    int sides;


public:
    Dice(int sides=6);
    ~Dice();
    void toss();
    int getCurrentValue() const;




};


#endif //UNTITLED6_DICE_H
