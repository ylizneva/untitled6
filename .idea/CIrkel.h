//
// Created by Yulia Lizneva on 2017-10-09.
//

#ifndef UNTITLED6_CIRKEL_H
#define UNTITLED6_CIRKEL_H

#include <string>

using namespace std;
const double PI = 3.14159;
class CIrkel
{


private:
    int radius;
    int X;
    int Y;


public:

    CIrkel(int X, int Y, int radius);
    CIrkel(int radius);
    ~CIrkel();
    CIrkel();

    bool operator ==(const CIrkel &otherCirkel) const;

    bool operator !=(const CIrkel &otherCirkel) const;

    int getX() const;
    int getY() const;


    double area() const;
    double circumference() const;

    int getRadius() const;
    void setRadius(int radius);

    void move(int X, int Y);

    string toString() const;











};


#endif //UNTITLED6_CIRKEL_H
