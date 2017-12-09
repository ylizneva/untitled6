//
// Created by Yulia Lizneva on 2017-10-23.
//

#include <iostream>
#include <fstream>
#include "Account.h"

using namespace std;
int menu();
int findOne(Account theArray[], string name, int pass, int nrOf);
void addOne(Account theArray[], int &nrOf);
int deposito(Account theArray[], int nrOf);
bool withdraw(Account theArray[], int nrOf);
bool deleteOne(Account theArray[], int &nrOf);
void sortByBalance(Account theArray[], int nrOf);
void showTransaktions(Account theArray[], int nrOf);
void showAll(Account theArray[], int nrOf);
void writeToFile(Account theArray[], string fileName, int nrOf);
void readFile(Account theArray[], string fileName, int &nrOf);




int main()
{
    srand(time(0));
    int cap=10;
    int nrOf=0;
    Account *theArray = nullptr;
    theArray = new Account[cap];

    cap*=2;
    Account *temp= nullptr;
    temp=new Account[cap];

    for(int i=0; i<nrOf; i++)
    {
       temp[i]=theArray[i];
    }


    delete[] theArray;
    theArray=temp;
    temp= nullptr;

    int choice=-1;
    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                addOne(theArray, nrOf);
                break;
            }
            case 2:
            {
                deposito(theArray,nrOf);
                break;
            }
            case 3:
            {
                withdraw(theArray, nrOf);
                break;
            }
            case 4:
            {
                deleteOne(theArray, nrOf);
                showAll(theArray, nrOf);
                break;
            }
            case 5:
            {
                sortByBalance(theArray, nrOf);
                break;
            }
            case 6:
            {
                showTransaktions(theArray, nrOf);
                break;
            }
            case 7:
            {
                writeToFile(theArray, "/Users/yulializneva/CLionProjects/untitled6/names.txt", nrOf);

            }
            case 8:
            {
                readFile(theArray, "/Users/yulializneva/CLionProjects/untitled6/names.txt", nrOf);
                showAll(theArray, nrOf);
            }







        }
    }



    delete[] theArray;
    return 0;
}
void showAll(Account theArray[], int nrOf)
{
    for(int i=0; i<nrOf; i++)
    {
        cout<<theArray[i].getName()
        <<" "<<theArray[i].getKontoNr()<<endl;
    }
}

int findOne(Account theArray[], string name, int pass, int nrOf)
{
    int pos=-1;
    Account temp(name, pass);
    for(int i=0; i<nrOf; i++)
    {
        if(theArray[i]==temp)
        {
            pos=i;
        }
    }
    return pos;
}
void addOne(Account theArray[], int &nrOf)
{
    srand(time(0));
    string name="+";
    int pass =0;
    cout<<"Name and surname: "<<endl;
    getline(cin, name);
    cout<<"Password:"<<endl;
    cin>>pass;
    int pos=findOne(theArray,name, pass, nrOf);
    if(pos==-1)
    {
        theArray[nrOf]= Account(name, pass);
        theArray[nrOf].getKontoNr();
        nrOf++;
    }
    else
    {
        cout<<"already exists"<<endl;
    }


    for(int i=0; i<nrOf; i++)
    {
        cout<<theArray[i].getName()<<" created an account #"
            <<theArray[i].getKontoNr()<<endl;

    }
}

int deposito(Account theArray[], int nrOf)
{
    string name="0";
    int pass=0;
    int pengar =0;
    cout<<"Your name and surname:"<<endl;
    getline(cin, name);
    cout<<"Password: "<<endl;
    cin>>pass;

    int pos=findOne(theArray, name, pass, nrOf);
    if(pos!=-1)
    {
        cout<<"How much:"<<endl;
        cin>>pengar;
        theArray[pos].makeDeposito(pengar);


        cout<<theArray[pos].getName()<<" account #"
            <<theArray[pos].getKontoNr()<<" just deposed "<<pengar
            <<"\nThe balance is "<<theArray[pos].getBAlance()<< endl;


    }
    else
    {
        cout<<"Wrong name or password"<<endl;
    }






}
bool withdraw(Account theArray[], int nrOf)
{
    bool isDone=false;
    string name="+";
    int pass=0;
    int money=0;
    cout<<"Enter your name"<<endl;
    getline(cin, name);
    cout<<"Password:"<<endl;
    cin>>pass;

    int pos=findOne(theArray, name, pass, nrOf);
    if(pos!=-1)
    {
        cout<<"How much:"<<endl;
        cin>>money;

        if(theArray[pos].getBAlance()>=money)
        {
            theArray[pos].withdraw(money);
            isDone=true;
            cout<<theArray[pos].getName()<<" account #"
                <<theArray[pos].getKontoNr()<<" just took out "<<money
                <<"\nThe balance is "<<theArray[pos].getBAlance()<< endl;

        }
        else
        {
            cout<<"Not enough on the balance."<<endl;
        }

    }
    else
    {
        cout<<"Not found"<<endl;
    }
    return isDone;
}
bool deleteOne(Account theArray[], int &nrOf)
{
    string name="=";
    int pass =0;
    bool isDone=false;
    cout<<"Name to delete:"<<endl;
    getline(cin, name);
    cout<<"Password:"<<endl;
    cin>>pass;

    int pos=findOne(theArray, name, pass, nrOf);
    if(pos!=-1)
    {
        theArray[pos]=theArray[--nrOf];
        isDone=true;

    }

    return isDone;
}
void sortByBalance(Account theArray[], int nrOf)
{
    int posOfSmallest =0;
    Account temp;
    for(int i=0; i<nrOf; i++)
    {
        posOfSmallest=0;
        for(int h=i+1; h<nrOf; h++)
        {
            if(theArray[h].getBAlance()<theArray[posOfSmallest].getBAlance())
            {
                posOfSmallest=h;
            }
        }

        temp=theArray[posOfSmallest];
        theArray[posOfSmallest]=theArray[i];
        theArray[i]=temp;
        cout<<theArray[i].getName()<<" "<<theArray[i].getBAlance()<<endl;
    }

}

void showTransaktions(Account theArray[], int nrOf)
{
    string name="+";
    int pass=0;
    cout<<"Name:"<<endl;
    getline(cin, name);
    cout<<"Password:"<<endl;
    cin>>pass;
    cin.ignore();

    int pos=findOne(theArray, name, pass, nrOf);
    if(pos!=-1)
    {
        theArray[pos].getTransaktions();
    }

}


void writeToFile(Account theArray[], string fileName, int nrOf)
{
  ofstream out;
    out.open(fileName);
    out<<nrOf<<endl;

    for(int i=0; i<nrOf; i++)
    {
       out<<theArray[i].getName()<<endl;
        out<<theArray[i].getPAssword()<<endl;
    }
    out.close();
}

void readFile(Account theArray[], string fileName, int &nrOf)
{
    int bla;
    string name="";
    int pass=0;

    ifstream in;
    in.open(fileName);

    if(in.is_open())
    {
        in>>bla; in.ignore();
        nrOf+=bla;
        for(int i=0; i<nrOf; i++)
        {
            in>>name; in.ignore();
            in>>pass; in.ignore();

            theArray[i]=Account(name, pass);
        }
    }
    in.close();

}


int menu()
{
    srand(time(0));
    int choice=-1;
    cout<<"1. Create account\n"
        <<"2. Deposit \n"
        <<"3. Get out \n"
        <<"4. Delete one\n"
        <<"5. Sort by balance \n"
        <<"6. Show history \n"
        <<"7. Save in file\n"
        <<"8. Read from file\n"
        <<"9 Change password\n"
        <<"10. Show all the klients\n"
        <<"11. Show the richest client\n";
    cin>>choice;
    cin.ignore();

    return choice;

}