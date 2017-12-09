//
// Created by Yulia Lizneva on 2017-11-19.
//

#include <iostream>
#include <string>
#include "VehicleRegister.h"
#include "Vehicle.h"


int menu()
{
    int choice = -1;
    cout << "1.Add\n"
         << "2.Show all\n"
         <<"3.Delete \n";
    cin>>choice; cin.ignore();
    return choice;

}


void addSomething(VehicleRegister &arr, int motor, string fuel, string brand)
{
    string name, airbag;
    int wheels;
    cout<<"Bike or car?\n";
    getline(cin, name);

    if(name=="car")
    {
        cout<<"Brand:\n";
        getline(cin, brand);
        cout<<"motor:\n";
        cin>>motor; cin.ignore();
        cout<<"airbag\n";
        getline(cin, airbag);
        arr.addCar(airbag, wheels, fuel, motor, brand);
    }
}






int main()
{

    VehicleRegister arr;
    int choice=-1;

    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {

                break;
            }

        }
    }











    return 0;
}