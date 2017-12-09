//
// Created by Yulia Lizneva on 2017-11-16.
//

#ifndef UNTITLED6_CIRCLE_H
#define UNTITLED6_CIRCLE_H


#include "GeometriskaFigurer.h"

class Circle: public GeometriskaFigurer
{
private:
    int radien;

public:
    Circle(int X, int Y, int R);
    virtual~Circle();


    Circle(const Circle &original);
    void operator=(Circle &original);

    int area() const;
    int omkrets() const;

    string toStringSpecefik() const;







};


#endif //UNTITLED6_CIRCLE_H
