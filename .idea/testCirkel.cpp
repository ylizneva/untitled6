//
// Created by Yulia Lizneva on 2017-10-09.
//

#include <string>
#include <cmath>
#include <string>
#include <iostream>
#include "CIrkel.h"

using namespace std;

//prototypes

void showAll(CIrkel cirArray[], int nrOfCirkles);
void countTheArea(CIrkel cirArray[], int nrOfCirkles, int cap);
void countCircumference(CIrkel cirArray[], int nrOfCirkles, int cap);
void addCirkle(CIrkel cirArray[], int &nrOfCirkles, int cap);
bool deleteCirkel(CIrkel cirArray[], int &nrOfCirkles);
int findCirkel(CIrkel cirArray[], int nrOfCirkles, const CIrkel cirToFind);

void moveCirkles(CIrkel cirArray[], int nrOfCirkles);




int main()
{
    int radius = 0;
    int cap=0;
    int X =0;
    int Y =0;
    int nrOfCirkles =0;
    int expandSize=0;
    CIrkel *temp = nullptr;


    cout<<"Enter the capacity for an array: "<<endl;
    cin>>cap;
    cin.ignore();

    CIrkel *cirArray = nullptr;
    cirArray = new CIrkel[cap];





    addCirkle(cirArray, nrOfCirkles, cap);

    showAll(cirArray, nrOfCirkles);

    moveCirkles(cirArray, nrOfCirkles);

    //mata in extraplatser i arrayen(expandera)

    cout<<"How many extra places ";
    cin>>expandSize;
    cin.ignore();

    temp = new CIrkel[cap+expandSize];

    for(int i=0; i<nrOfCirkles; i++)
    {
        temp[i]=cirArray[i];
    }

    delete[] cirArray;

    cirArray=temp;
    temp= nullptr;
    cap+= expandSize;



    cout<<"Enter R, X and Y for a circle: "<<endl;
    cin>>radius;
    cin.ignore();
    cin>>X;
    cin.ignore();
    cin>>Y;
    cin.ignore();



    CIrkel aCirkle(radius, X, Y);
    int pos = findCirkel(cirArray, nrOfCirkles, aCirkle);


    showAll(cirArray, nrOfCirkles);
    return 0;

}


void addCirkle(CIrkel cirArray[], int &nrOfCirkles, int cap)
{
    int radien =0;
    int nrOf =1;

    cout<<"How many circles do you want: "<<endl;
    cin>>nrOfCirkles;
    cin.ignore();

    while(nrOfCirkles>cap)
    {
        cout<<"Too many, try smthng less"<<endl;
    }

   for(int i=0; i<nrOfCirkles; i++)
   {
       cout<<"Enter the radius for circle "<< nrOf++<<endl;
       cin>>radien;
       cin.ignore();
       cout<<radien<<endl;
       cirArray[i] = CIrkel(radien);
   }


}
void showAll(CIrkel cirArray[], int nrOfCirkles)
{
    cout<<"Here's all the circles: "<<endl;
    for(int i=0; i<nrOfCirkles; i++)
    {
        cout<<cirArray[i].toString()<<endl;
    }

}

void moveCirkles(CIrkel cirArray[], int nrOfCirkles)
{
    int X =0;
    int Y =0;
    for(int i=0; i<nrOfCirkles; i++)
    {
        cout<<"X: ";
        cin>>X;
        cin.ignore();

        cout<<"Y: ";
        cin>>Y;
        cin.ignore();
        cirArray[i].move(X, Y);

    }

}


int findCirkel(CIrkel cirArray[], int nrOfCirkles, const CIrkel &cirToFind)
{

    int pos=-1;

    for(int i=0; i<nrOfCirkles && pos==-1; i++)
    {
        if(cirArray[i] == cirToFind)
        {
            pos=i;
        }
    }
return pos;
}