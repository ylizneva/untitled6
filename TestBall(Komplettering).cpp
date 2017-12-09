//
// Created by Yulia Lizneva on 2017-10-06.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Ball.h"
#include <cmath>

using namespace std;

void readFile(Ball ballArray[], int &nrOfBalls, string fileName, int capacity);
void addBall(Ball ballArray[], int &nrOfBalls, int newSpeed);
void ShowAll(Ball ballArray[], int nrOfBalls, int time);
int findBall(Ball ballArray[], int speedX, int nrOfBalls);
bool deleteBall(Ball ballArray[], int &nrOfBalls);
void sortBalls(Ball ballArray[], int nrOfBalls);


int main()
{
    int capacity =4;
    Ball *ballArray = nullptr;
    ballArray = new Ball[capacity];
    int nrOfBalls = 0;
    int time=0;



    readFile(ballArray, nrOfBalls, "/Balls.txt", capacity);

    capacity=capacity+3;
    Ball *tempBallArray = new Ball [capacity];

    for(int i=0; i<nrOfBalls; i++)
    {
        tempBallArray[i] = ballArray[i];

    }


    delete[] ballArray;

    ballArray=tempBallArray;



    addBall(ballArray, nrOfBalls, 3);
    addBall(ballArray, nrOfBalls, 10);

    ShowAll(ballArray, nrOfBalls, time);

    deleteBall(ballArray, nrOfBalls);
    ShowAll(ballArray, nrOfBalls, time);


    sortBalls(ballArray, nrOfBalls);
    ShowAll(ballArray, nrOfBalls, time);

    delete[] ballArray;

    return 0;
}



  void readFile(Ball ballArray[], int &nrOfBalls, string fileName, int capacity)
  {

      int speedX = -1;
      ifstream in;

    in.open(fileName);

      if(in.is_open())
      {
          in>>nrOfBalls;
          in.ignore();
      }

    for(int i=0; i<capacity; i++)
    {
        in>>speedX;
        in.ignore();
        ballArray[i]= Ball(speedX);


    }
      in.close();
  }




void addBall(Ball ballArray[], int &nrOfBalls, int newSpeed)
{


   int pos =findBall(ballArray, newSpeed, nrOfBalls);


       if(pos==-1)
       {
           ballArray[nrOfBalls]= Ball(newSpeed);
           nrOfBalls++;
           cout <<"New ball with hastighet "<<newSpeed<< " has been added!"<<endl;

       }

        else
        {
            cout <<"New ball with hastighet " << newSpeed << " is already exist and will not be added."<<endl;
        }


}


void ShowAll(Ball ballArray[], int nrOfBalls, int time)
{
    cout<<"Enter time: ";
    cin>>time;
    cin.ignore();

    for(int i=0; i<nrOfBalls; i++)
    {

        if(ballArray[i].getSpeedX()!=-1)
        {
            cout<<ballArray[i].toString(time)<<" "<<endl;
        }

    }


}
int findBall(Ball ballArray[], int speedX, int nrOfBalls)
{
    int pos=-1;
    Ball temp(speedX);

    for(int i=0; i<nrOfBalls; i++)
    {
        if(ballArray[i]==temp)
        {
            pos=i;
        }
    }
    return pos;
}




bool deleteBall(Ball ballArray[], int &nrOfBalls)
{
    int speedNew = -1;
    bool didRemove = false;

    cout<<"Enter speed of the ball you want to remove: ";
    cin>>speedNew;
    cin.ignore();
    int temp = findBall(ballArray, speedNew, nrOfBalls);

    if(temp!=-1)
    {
        ballArray[temp]= ballArray[--nrOfBalls];
        ballArray[nrOfBalls]=-1;
        didRemove = true;
        cout<<"Your ball has been removed!"<<endl;
    }
    else
        cout<<"This ball is not exist"<<endl;


    return didRemove;
}



void sortBalls(Ball ballArray[], int nrOfBalls)
{
    int posOfSmallest =0;
    Ball tempBall(0);
    for(int i=0; i<nrOfBalls; i++)
    {
        posOfSmallest = i;
        for(int h=i+1; h < nrOfBalls; h++)
        {
            if(ballArray[posOfSmallest]>ballArray[h])
            {
              posOfSmallest = h;

            }

        }
        tempBall=ballArray[i];
        ballArray[i]=ballArray[posOfSmallest];
        ballArray[posOfSmallest]=tempBall;

    }

}








void readCoffeeFromTxtFile(Coffee *&coffees, int &nrOfCoffees, int &cap, string fileName)
{

    string brand, type;
    double storePrice, costomerPrice;
    int	fileNr;
    ifstream in;
    in.open(fileName);

    in >> fileNr; in.ignore();


    for (int i = nrOfCoffees; i < nrOfCoffees+fileNr; i++)
    {

        /*if (cap <= nrOfCoffees)
        {
            expandArray(coffees, nrOfCoffees, cap);
        }*/

        getline(in, brand);

        getline(in, type);

        in >> storePrice; in.ignore();

        in >> costomerPrice; in.ignore();

        coffees[i]=Coffee(brand, type, storePrice, costomerPrice);
    }

    nrOfCoffees += fileNr;

    in.close();

}

void expandArray(Coffee *&coffees, int nrOfCoffees, int &cap)
{
    if (cap != 0)
    {
        cap *= 2;
    }
    else
    {
        cap = 5;
    }

    Coffee *tempCoffees = new Coffee[cap];
    for (int i = 0; i < nrOfCoffees; i++)
    {

        tempCoffees[i] = coffees[i];

    }

    delete[] coffees;

    coffees = tempCoffees;

    tempCoffees = nullptr;

}