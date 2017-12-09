//
// Created by Yulia Lizneva on 2017-10-18.
//

#include <iostream>
#include <string>
#include "Cleaning.h"

using namespace std;

void addNewOne(Cleaning cleanArray[], int &nrOf);
void showAll(Cleaning cleanArray[], int nrOf);
void sortByAlpha(Cleaning cleanArray[], int nrOf);
void sortMargin(Cleaning cleanArray[], int nrOf);




int menu()
{
    int choice=0;
    cout<<"1. Add a new type of cleaning"<<endl
        <<"2. Show all"<<endl
        <<"3. Sort by alphabet"<<endl
        <<"4. Sort cleaning by its margin"<<endl
        <<"5. Change salary"<<endl
        <<"6. Change prices"<<endl
        <<"7. Show the most expensive one"<<endl
        <<"8. Delete some type of cleaning"<<endl
        <<"9. Save all the info in the textFile"<<endl;
    cin>>choice;
    cin.ignore();

return choice;
}

void addNewOne(Cleaning cleanArray[], int &nrOf)
{
    string type="=";
    double price =0;
    double payOff =0;

    cout<<"What type of cleaning would you like to add: "<<endl;
    getline(cin, type);
    cout<<"Whats a price: "<<endl;
    cin>>price;
    cin.ignore();
    cout<<"How much will you pay for sallary: "<<endl;
    cin>>payOff;
    cin.ignore();

    cleanArray[nrOf] = Cleaning(type, price, payOff);
    nrOf++;

}
void showAll(Cleaning cleanArray[], int nrOf)
{
    for(int i=0; i<nrOf; i++)
    {
        cout<<cleanArray[i].toString()<<endl;
    }

}

void sortByAlpha(Cleaning cleanArray[], int nrOf)
{

    int posOfSmallets =0;
    Cleaning temp;

    for(int i=0; i<nrOf; i++)
    {
        posOfSmallets=i;

        for(int h=i+1; h<nrOf; h++)
        {
            if(cleanArray[h].getType()<cleanArray[posOfSmallets].getType())
            {
                posOfSmallets=h;
            }

        }

        temp=cleanArray[posOfSmallets];
        cleanArray[posOfSmallets]=cleanArray[i];
        cleanArray[i]=temp;

    }


}

void sortMargin(Cleaning cleanArray[], int nrOf)
{
    int pos=0;
    Cleaning temp;
    for(int i=0; i<nrOf; i++)
    {
        pos=i;

        for(int h=i+1; h<nrOf; h++)
        {
            if(cleanArray[h].getMargin()<cleanArray[pos].getMargin())
            {
                pos=h;
            }
        }

        temp=cleanArray[pos];
        cleanArray[pos]=cleanArray[i];
        cleanArray[i]=temp;
    }

}




int main()
{
    int cap =10;
    Cleaning *cleanArray= nullptr;
    cleanArray = new Cleaning[cap];
    int nrOf;

    int choice=-1;

    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                addNewOne(cleanArray, nrOf);
                break;

            }
            case 2:
            {
                showAll(cleanArray, nrOf);
                break;
            }
            case 3:
            {
                sortByAlpha(cleanArray,nrOf);
                showAll(cleanArray, nrOf);
                break;

            }
            case 4:
            {
                sortMargin(cleanArray, nrOf);
                showAll(cleanArray, nrOf);
                break;
            }



        }




    }







    return 0;
}
