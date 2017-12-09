//
// Created by Yulia Lizneva on 2017-11-02.
//

#include <iostream>
#include "Motors.h"
#include "Boatmotors.h"

using namespace std;

int menu()
{
    int choice=0;
    cout<<"1.Add one \n"
        <<"2.Search one\n"
        <<"3.Show all\n"
        <<"4.Change something\n"
        <<"5.Delete one\n";
    cin>>choice; cin.ignore();
    return choice;
}


void deleteOne(Motors &motors, string brand, int vol, int year, string serie)
{
    cout<<"Enter the parameters of an engine you would like to delete\n"
        <<"Brand: \n";
    cin>>brand; cin.ignore();
    cout<<"Volume:\n";
    cin>>vol; cin.ignore();
    cout<<"Year: \n";
    cin>>year; cin.ignore();
    cout<<"Serie number: \n";
    cin>>serie; cin.ignore();

    motors.deleteOne(brand, vol, year, serie);
}


void isChanged(Motors &motors, string brand, int vol, int year, string serie)
{
    string nName="=";
    int nVal, nYear;
    cout<<"Enter parameters of an engine you want to change.\n Brand:\n";
    cin>>brand; cin.ignore();
    cout<<"Volume:\n";
    cin>>vol; cin.ignore();
    cout<<"Year:\n";
    cin>>year; cin.ignore();
    cout<<"Serie number:\n";
    cin>>serie; cin.ignore();

    cout<<"Enter the new parameters:\n";
    cout<<"Name: \n";
    cin>>nName; cin.ignore();
    cout<<"Volume: \n";
    cin>>nVal; cin.ignore();
    cout<<"Year:\n";
    cin>>nYear; cin.ignore();

    motors.changeBrand(brand, nName, vol, nVal, year, nYear, serie);
}


void addOne(Motors &motors, string brand, int vol, int year, string serie)
{
    cout<<"Brand:\n";
    cin>>brand;
    cout<<"Volume:\n";
    cin>>vol; cin.ignore();
    cout<<"Year:\n";
    cin>>year; cin.ignore();
    cout<<"Serienumber\n";
    cin>>serie;

    motors.addOne(brand, vol, year, serie);

}

void searchOne(Motors &motors, string brand, int vol, int year, string serie)
{

    cout<<"Brand:\n";
    getline(cin, brand);
    cout<<"Volume:\n";
    cin>>vol; cin.ignore();
    cout<<"Year:\n";
    cin>>year; cin.ignore();
    cout<<"Serienumber\n";
    getline(cin, serie);

    string arr[10];
    motors.showSomething(arr, 10, brand, vol, year, serie);
    cout<<arr[0]<<endl;

}

void showAll(Motors &motors)
{
    motors.showAll();

}

int main()
{
    string brand, serie;
    int vol=0;
    int year=0;



    Motors motors;



    int choice=0;
    while(choice!=-1)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                addOne(motors, brand, vol, year, serie);
                break;
            }
            case 2:
            {
                searchOne(motors,brand, vol, year, serie);
                break;
            }
            case 3:
            {

                showAll(motors);
                break;
            }
            case 4:
            {
                isChanged(motors, brand, vol, year, serie);
                break;
            }
            case 5:
            {
                deleteOne(motors, brand, vol, year, serie);
                break;
            }
        }
    }






    return 0;
}