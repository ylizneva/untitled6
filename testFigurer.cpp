//
// Created by Yulia Lizneva on 2017-11-16.
//

#include "GeometriskaFigurer.h"
#include "Triangel.h"
#include "Circle.h"
#include <iostream>

using namespace std;
int main()
{
    GeometriskaFigurer *f1= new Triangel(2,3, 10, 20);
    cout<<f1->toString();

    GeometriskaFigurer *f2 = new Circle(5,6,20);
    cout<<f2->toString();


    return 0;
}