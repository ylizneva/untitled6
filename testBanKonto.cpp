//
// Created by Yulia Lizneva on 2017-10-10.
//

#include <iostream>
#include <string>
#include "BankKonto.h"


void SkapaKonto(BankKonto bankArray[], int &nrOfKonto, int cap);
int findAkund(BankKonto bankArray[], string aCodos, string aName, int nrOf);
void depasito(BankKonto bankArray[], int nrOfKonto);
bool getOut(BankKonto bankArray[], int nrOfKonto);
void ShowAll(BankKonto bankArray[], int nrOfKonto);
bool changeCode(BankKonto bankArray[], int nrOfKonto, string aCode);

int menu()
{
    int userChoice =-1;
    cout<<"1. Create en account"<<endl
    <<"2. Make deposits on the account"<<endl
    <<"3. Make withdrawals from an account"<<endl
    <<"4. View account statements for an account"<<endl
    <<"5. Change the code for an account"<<endl
    <<"6. Exit"<<endl;
    cin>>userChoice;
    cin.ignore();
    return userChoice;
}

void SkapaKonto(BankKonto bankArray[], int &nrOfKonto, int cap)
{
    string name ="?";
    string code ="-";

    cout<<"Name and surname: "<<endl;
    getline(cin, name);


    cout<<"Enter password: "<<endl;
    cin>>code;
    cin.ignore();

    for(int i=0; i<nrOfKonto; i++)
    {


            if(bankArray[i].checkCode(code))
            {

                cout<<"Pls change your password, someone else is already have it."<<endl;
                cout<<"Enter another password: "<<endl;
                cin>>code;
                cin.ignore();

            }
    }



   bankArray[nrOfKonto].getCountNr();
   bankArray[nrOfKonto] = BankKonto(name, code);
    nrOfKonto++;

}



void depasito(BankKonto bankArray[], int nrOfKonto)
{
    int money=0;
    string code = "?";
    string name;
    cout<<"What's your name: "<<endl;
    getline(cin, name);
    cout<<"Enter your password: "<<endl;
    cin>>code;
    cin.ignore();

    int pos=findAkund(bankArray, code, name, nrOfKonto);


    if(pos!=-1)
    {
        cout<<"How much would you like to depose: "<<endl;
        cin>>money;

        bankArray[pos].deposit(money);
        cout<<bankArray[pos].toString()<<endl;
    }
    else
    {
        cout<<"Wrong name or password."<<endl;
    }


}





int findAkund(BankKonto bankArray[], string aCodos, string aName, int nrOf)
{

    int pos=-1;

    for(int i=0; i<nrOf; i++)
    {
        if(bankArray[i].checkCode(aCodos) && bankArray[i].checkName(aName))
        {
                pos=i;

        }
    }
    return pos;

}



bool getOut(BankKonto bankArray[], int nrOfKonto)
{
    int pengar =0;
    bool isGood = false;
    string code ="?";
    string name= "?";
    cout<<"What's your name: "<<endl;
    getline(cin, name);
    cout<<"Whats your code: "<<endl;
    getline(cin, code);

    int pos=findAkund(bankArray, code, name, nrOfKonto);


    cout<<"How much: "<<endl;
    cin>>pengar;

    if(pos!=-1 && bankArray[pos].getBalance()>pengar)
    {

        bankArray[pos].withdraw(pengar);
        cout<<bankArray[pos].toString()<<endl;
        isGood=true;
    }

    if(pos!=-1 && bankArray[pos].getBalance()<pengar)
    {
     cout<<"You have not enough money on your account."<<endl;
    }
    else
    {
        cout<<"You're not a costumire."<<endl;
    }
 return isGood;

}


void ShowAll(BankKonto bankArray[], int nrOfKonto)
{
    string code ="0";
    string name ="?";
    cout<<"What's your name: "<<endl;
    getline(cin, name);
    cout<<"Enter your password: "<<endl;
    getline(cin, code);
    int pos=findAkund(bankArray, code, name, nrOfKonto);

    if(pos!=-1)
    {
        bankArray[pos].getTransaktioner();
    }


}

bool changeCode(BankKonto bankArray[], int nrOfKonto, string aCode)
{
    bool isDone = false;
    string name ="?";
    string pas="0";



    cout<<"What's your name: "<<endl;
    getline(cin, name);
    cout<<"Enter the old password: "<<endl;
    getline(cin, aCode);



        int pos=findAkund(bankArray, aCode, name, nrOfKonto);



        if(pos!=-1)
        {
            cout<<"Enter a new password: "<<endl;
            cin>>pas;
            cin.ignore();
            bankArray[pos].changeCode(aCode,pas);
            isDone = true;

        }
        else
        {
        cout<<"Wrong password."<<endl;
        }


    return isDone;

}


int main()
{
    string aCode="=";

    int cap=10;
    BankKonto *bankArray= nullptr;
    bankArray = new BankKonto[cap];

    int nrOfKonto =0;

    int choice =-1;

    while(choice!=0)
    {
        choice=menu();

    switch (choice)
    {
        case 1:
        {
            SkapaKonto(bankArray, nrOfKonto, cap);
            break;
        }
        case 2:
        {
            depasito(bankArray,nrOfKonto);
            break;
        }
        case 3:
        {
            getOut(bankArray, nrOfKonto);
            break;
        }

        case 4:
        {
            ShowAll(bankArray, nrOfKonto);
            break;
        }
        case 5:
        {
            changeCode(bankArray, nrOfKonto, aCode);
            break;
        }
        case 6:
        {
            cout<<"Thank you and good bye!"<<endl;
            break;
        }
        default:
        {
            cout<<"Wrong number."<<endl;
            break;
        }

    }

    }

return 0;

}