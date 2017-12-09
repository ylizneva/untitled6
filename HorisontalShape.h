//
// Created by Yulia Lizneva on 2017-12-09.
//

#ifndef UNTITLED6_HORISONTALSHAPE_H
#define UNTITLED6_HORISONTALSHAPE_H

#include "Shape.h"

class HorisontalShape :public Shape
{
private:
    int xDirection;

public:
    HorisontalShape(int xDirection=0, int y=0, int width=0, int height=0, int step=0);
    ~HorisontalShape();

    void changeDirection();
    string getDirectionAsString() const;
    string startString() const;
    void move();

};


#endif //UNTITLED6_HORISONTALSHAPE_H
