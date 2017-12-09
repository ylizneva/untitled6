//
// Created by Yulia Lizneva on 2017-12-04.
//

#include "MyVector.h"
#include <iostream>
#include <string>

using namespace std;




int main()
{

    MyVector<int> intVector; // ett nyVector-obkekt som hanterar heltal

    MyVector<string> stringVector(5); // cap=5

    intVector.addLast(10);

    intVector.addLast(30);
    intVector.addLast(3);

    for(int i=12; i<20; i++)
    {
        intVector.addLast(i);
        cout<<"Sist i IntVectorn finns "<<intVector.getLast()<<endl;
    }








    return 0;
}