//
// Created by Yulia Lizneva on 2017-11-09.
//

#include "CarRegister.h"
#include <iostream>

using namespace std;



int menu()
{
    int choice=-1;
    cout<<"1. Add car \n"
        <<"2. Show all \n"
        <<"3. Change prices\n"
        <<"4. Remove car\n"
        <<"5. Find car\n"
        <<"6. Save to file\n"
        <<"7. Read file\n"
        <<"8. Clear all"<<endl;
    cin>>choice; cin.ignore();

    return choice;
}


void deleteEverything(CarRegister &notes)
{
    notes.ClearAll();
}




void addOne(CarRegister &notes, string name, string regNr, int miles, int price)
{
    cout<<"Name:\n";
    getline(cin, name);
    cout<<"Reg number:\n";
    getline(cin, regNr);
    cout<<"Miles:\n";
    cin>>miles; cin.ignore();
    cout<<"Price:\n";
    cin>>price; cin.ignore();

    notes.addCar(name, regNr, miles, price);
}
void showAll(const CarRegister &notes)
{

    string *str = nullptr;
    str= new string[notes.getNrOfCars()];

    notes.getAsStrings(str);
    for(int i=0; i<notes.getNrOfCars(); i++)
    {
        cout<<str[i]<<endl;
    }
}

void changePrices(CarRegister &notes)
{
    int pro=-1;
    cout<<"Enter %\n";
    cin>>pro; cin.ignore();
    notes.changePrice(pro);

}


int findOne(CarRegister &notes, string regNr)
{
    string *str= nullptr;
    str=new string[notes.getNrOfCars()];
    cout<<"Reg number: \n";
    getline(cin, regNr);
    notes.findCar(regNr);
    notes.getAsStringsByRegNr(str, regNr);

    for(int i=0; i<notes.getNrOfCars(); i++)
    {
        cout<<str[i]<<endl;
    }
}

void deleteOne(CarRegister &notes, string regNr)
{
    cout<<"Enter a reg number of a car you want to remove:\n";
    getline(cin, regNr);

    int pos= notes.findCar(regNr);
    notes.RemoveCar(pos);
}



int main()
{
    CarRegister notes(10);
    string name, regNr;
    int miles, price;
    int choice=-1;

    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                addOne(notes, name, regNr, miles, price);
                break;
            }
            case 2:
            {
                showAll(notes);
                break;
            }
            case 3:
            {
                changePrices(notes);
                break;
            }
            case 4:
            {
                deleteOne(notes, regNr);
                break;
            }
            case 5:
            {
                findOne(notes, regNr);
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                deleteEverything(notes);
                break;
            }
        }
    }






    return 0;
}