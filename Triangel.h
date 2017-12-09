//
// Created by Yulia Lizneva on 2017-11-16.
//

#ifndef UNTITLED6_TRIANGEL_H
#define UNTITLED6_TRIANGEL_H

#include "GeometriskaFigurer.h"

class Triangel:public GeometriskaFigurer
{

private:
    int lenghtA;
    int lenghtB;

public:

    Triangel(int X, int Y, int lA, int lB);
    virtual~Triangel();

    Triangel(const Triangel &original);
    void operator=(const Triangel &original);

    int getLenghtA() const;
    int getLenghtB() const;

    int area() const;
    int omkrest() const;

    virtual string toStringSpecefik() const;







};


#endif //UNTITLED6_TRIANGEL_H
