//
// Created by Yulia Lizneva on 2017-12-08.
//

#ifndef UNTITLED6_SHAPE_H
#define UNTITLED6_SHAPE_H

#include "Shape.h"
#include "Coord.h"
#include "Box.h"
#include <string>

using namespace std;

const string UP;
const string DOWN;
const string LEFT;
const string RIGHT;




class Shape
{
private:
    int step;

public:

    Shape(int step=0, int width=0, int height=0, int xPos=0, int yPos=0);
    virtual~Shape();

    Shape(Shape &original);

    Coord *coord;
    Box *box;

    void changeCoord(int xChange, int yChange);
    void changeStep(int change);

    int getStep() const;
    bool intersectWith(const Shape& otherShape);

    string toString() const;

    virtual void changeDirection() const =0;
    virtual string getDirectionAsString() const=0;
    virtual string startString() const=0;
    virtual void move() const=0;



};


#endif //UNTITLED6_SHAPE_H
