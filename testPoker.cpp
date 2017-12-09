//
// Created by Yulia Lizneva on 2017-10-22.
//

#include <iostream>
#include "PokerPlayer.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int menu();
void readFile(PokerPlayer theArray[], string filename, int &nrOf);
void showAllTheNames(PokerPlayer theArray[], int nrOf);
int findOne(PokerPlayer theArray[], string name, int nrOf);
void addOne(PokerPlayer theArray[], int &nrOf);
void play5times(PokerPlayer theArray[], int nrOf);
void showTheBestOne(PokerPlayer theArray[], int nrOf);
void showTheWorstOne(PokerPlayer theArray[], int nrOf);
bool deleteOne(PokerPlayer theArray[], int &nrOf);
void sortBySumman(PokerPlayer theArray[], int nrOf);
void saveInFile(PokerPlayer theArray[], string filename, int nrOf);

int main()
{
    srand(time(0));

    int nrOf =0;
    int cap=6;
    PokerPlayer *theArray= nullptr;
    theArray = new PokerPlayer[cap];

    cap*=2;

    PokerPlayer *temp = nullptr;
    temp = new PokerPlayer[cap];

    for(int i=0; i<nrOf; i++)
    {
        temp[i]=theArray[i];
    }

    delete[] theArray;

    theArray= temp;

    temp = nullptr;






    int choice=-1;

    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                readFile(theArray, "/Users/yulializneva/CLionProjects/untitled6/names.txt", nrOf);
                showAllTheNames(theArray, nrOf);
                break;
            }
            case 2:
            {
                showAllTheNames(theArray, nrOf);
                break;
            }
            case 3:
            {
                addOne(theArray, nrOf);
                showAllTheNames(theArray, nrOf);
                break;
            }
            case 4:
            {

                play5times(theArray, nrOf);
                break;
            }
            case 5:
            {
                showTheBestOne(theArray, nrOf);
                showTheWorstOne(theArray, nrOf);
                break;
            }
            case 6:
            {
                deleteOne(theArray, nrOf);
                break;
            }
            case 7:
            {
                sortBySumman(theArray, nrOf);
                break;
            }
            case 8:
            {
                saveInFile(theArray, "/Users/yulializneva/CLionProjects/untitled6/names.txt", nrOf);
            }



        }
    }


    delete[] theArray;


    return 0;
}


void saveInFile(PokerPlayer theArray[], string filename, int nrOf)
{
    ofstream out;
    out.open(filename);

    out<<nrOf<<endl;
    for(int i=0; i<nrOf; i++)
    {
        out<<theArray[i].getName()<<endl;
        out<<theArray[i].toString()<<endl;
    }
    out.close();
}

void sortBySumman(PokerPlayer theArray[], int nrOf)
{
   int posOfSmallest=0;
    PokerPlayer temp;
    for(int i=0; i<nrOf; i++)
    {
        posOfSmallest=i;

        for(int h=i+1; h<nrOf; h++)
        {
            if(theArray[h].getSum()<theArray[posOfSmallest].getSum())
            {
                posOfSmallest=h;
            }
        }
        temp=theArray[posOfSmallest];
        theArray[posOfSmallest]=theArray[i];
        theArray[i]=temp;

        cout<<theArray[i].getName()<<" got "<<theArray[i].getSum()<<endl;

    }


}

void showTheWorstOne(PokerPlayer theArray[], int nrOf)
{
    int posOfSmallest=0;
    for(int i=0; i<nrOf; i++)
    {
        if(theArray[posOfSmallest].getSum()>theArray[i].getSum())
        {
            posOfSmallest=i;
        }
    }
    cout<<theArray[posOfSmallest].getName()<<" got the worst result "<<theArray[posOfSmallest].getSum()<<endl;
}

bool deleteOne(PokerPlayer theArray[], int &nrOf)
{
    bool deleted=false;
    string name="+";
    cout<<"Which one would you like to delete: "<<endl;
    getline(cin, name);

    int pos=findOne(theArray, name, nrOf);

    if(pos!=-1)
    {
        theArray[pos]=theArray[--nrOf];
        deleted=true;
        cout<<"Done"<<endl;
    }
    else
    {
        cout<<"This one is not on the list"<<endl;
    }
    return deleted;

}

void showAllTheNames(PokerPlayer theArray[], int nrOf)
{
    for(int i=0; i<nrOf; i++)
    {
        cout<<theArray[i].getName()<<endl;
    }
}

int findOne(PokerPlayer theArray[], string name, int nrOf)
{
    int pos=-1;
    PokerPlayer temp(name);
    for(int i=0; i<nrOf; i++)
    {
        if(theArray[i]==temp)
        {
            pos=i;
        }
    }
    return pos;
}

void addOne(PokerPlayer theArray[], int &nrOf)
{
    string name ="=";
    cout<<"Name of a new player:"<<endl;
    getline(cin, name);
    int pos= findOne(theArray, name, nrOf);
    if(pos==-1)
    {
        theArray[nrOf]=PokerPlayer(name);
        nrOf++;
    }
    else
    {
        cout<<"This person is already exists"<<endl;
    }

}

void play5times(PokerPlayer theArray[], int nrOf)
{

    for(int i=0; i<nrOf; i++)
    {
        cout<<theArray[i].toString()<<endl;
    }
}


void showTheBestOne(PokerPlayer theArray[], int nrOf)
{
    int posOfLargest=0;
    for(int i=0; i<nrOf; i++)
    if(theArray[posOfLargest].getSum()<theArray[i].getSum())
    {
        posOfLargest=i;

    }
    cout<<theArray[posOfLargest].getName()<<" got the best result "<<theArray[posOfLargest].getSum()<<endl;
}
int menu()
{
    int choice=0;
    cout<<"1. Read file"<<endl
        <<"2. Show all"<<endl
        <<"3. Add one more player"<<endl
        <<"4. Play 5 times and show"<<endl
        <<"5. Show a player with best and a worst result"<<endl
        <<"?. "<<endl
        <<"6. Delete one"<<endl
        <<"7. Sort by the result"<<endl
        << "8. Save in text"<<endl;
    cin>>choice;
    cin.ignore();

    return choice;
}

void readFile(PokerPlayer theArray[], string filename, int &nrOf)
{
    int nrs;
    string names="0";

   ifstream in;
    in.open(filename);

    if(in.is_open())
    {
       in>>nrs; in.ignore();
        nrOf+=nrs;
        for (int i = 0; i < nrOf; i++)
        {
            getline(in, names);
            theArray[i]=PokerPlayer(names);
        }

    }
    in.close();
}