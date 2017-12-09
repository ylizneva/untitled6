//
// Created by Yulia Lizneva on 2017-12-09.
//

#ifndef UNTITLED6_VERTICALSHAPE_H
#define UNTITLED6_VERTICALSHAPE_H
#include "Shape.h"

class VerticalShape: public Shape
{
private:
    int yDirection;

public:
    VerticalShape(int yDirection=0, int x=0, int width=0, int height=0, int step=0);
    ~VerticalShape();

    void changeDirection();
    string getDirectionAsString() const;
    string startString() const;
    void move();


};


#endif //UNTITLED6_VERTICALSHAPE_H
