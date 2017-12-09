//
// Created by Yulia Lizneva on 2017-10-19.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Glass.h"

using namespace std;

int findOne(Glass isArray[], string name, int nrOf);
void addPoints(Glass isArray[], int nrOf);
void showAll(Glass isArray[], int nrOf);
void addOne(Glass isArray[], int &nrOf);


int menu()
{
    int choice=0;
    cout<<"1.Add one more icecream"<<endl
        <<"2.Show all"<<endl
        <<"3.Add points"<<endl
        <<"4.Show all info with more than _ participants "<<endl
        <<"5.Delete som icecream"<<endl
        <<"6.Show the icecream with the highest average points(quantity of participents needed)"<<endl
        <<"7. Delete a particular sort of icecream which average points are less than"<<endl
        <<"8.Sort by the average"<<endl
        <<"9.Save all the info to the text File"<<endl
        <<"10. Read the txt file"<<endl;
    cin>>choice;
    cin.ignore();

    return choice;
}

int findOne(Glass isArray[], string name, int nrOf)
{
    Glass temp(name);
    int pos=-1;
    for(int i=0; i<nrOf; i++)
    {
        if(isArray[i]==temp)
        {
            pos=i;
            cout<<i<<endl;
        }
    }
    return pos;
}

void addPoints(Glass isArray[], int nrOf)
{
    string name ="0";
    int points=0;
    cout<<"Which icecream you want to rate: "<<endl;
    getline(cin, name);
    cout<<"Rate from 1 to 10 "<<endl;
    cin>>points;
    int pos= findOne(isArray, name, nrOf);
cout<<pos<<endl;
    if(pos!=-1)
    {
        isArray[pos].addPoints(points);
    }
    else
    {
        cout<<"This one is not exists"<<endl;
    }

}

void showAll(Glass isArray[], int nrOf)
{
    for(int i=0; i<nrOf; i++)
    {
        cout<<isArray[i].toString()<<endl;
    }
}


void addOne(Glass isArray[], int &nrOf)
{
    string name = "=";
    cout<<"Name:"<<endl;
    getline(cin, name);


   int pos=findOne(isArray, name, nrOf);
   if(pos==-1)
   {
       isArray[nrOf]=Glass(name);
       nrOf++;
       cout<<"Done!"<<endl;
   }
    else
   {
       cout<<"This one is already exists"<<endl;
   }

}




int main()
{
    int cap=20;
    Glass *isArray = nullptr;
    isArray = new Glass[cap];

    int choice=-1;
    int nrOf=0;
    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                addOne(isArray, nrOf);
                break;
            }
            case 2:
            {
                showAll(isArray, nrOf);
                break;
            }

            case 3:
            {
                addPoints(isArray, nrOf);

                break;
            }
            case 4:
            {

            }




        }



    }


    return 0;
}