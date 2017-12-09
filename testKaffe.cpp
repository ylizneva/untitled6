//
// Created by Yulia Lizneva on 2017-10-17.
//

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "Kaffe.h"


void addCoffee(Kaffe kaffeArray[], int &nrOfSorts);
int findByName(Kaffe kaffeArray[], string name, string type, int nrOf);
void showAllInfo(Kaffe kaffeArray[], int nrOfSorts);
void showPurPrice(Kaffe kaffeArray[], int nrOf);
bool isChanged(Kaffe kaffeArray[], int nrOf);
void showPriceUnder(Kaffe kaffeArray[], int nrOf);
void showExpensive(Kaffe kaffeArray[], int nrOf);
bool isDeleted(Kaffe kaffeArray[], int &nrOf);
bool isAllDeleted(Kaffe kaffeArray[], string name, int &nrOf);
void sorted(Kaffe kaffeArray[], int nrOf);
void saveInFile(Kaffe kaffeArray[], string filename, int nrOf);
void readFrom(Kaffe kaffeArray[], string fileName, int &nrOf, int cap);

int menu()
{
    int choice=0;
    cout<<"1. Add a coffeebrand "<<endl
        <<"2.Show all information all brands" <<endl
        <<"3. Show the purchase price för selected brand" <<endl
        <<"4. Change the prices"<<endl
        <<"5. Show brands and types av coffee under specific purchase price "<<endl
        <<"6. Show info about the most expensive coffee" <<endl
        <<"7. Delete a coffeebrand by its name and type "<<endl
        <<"8. Delete all the coffeebrands by specific name  "<<endl
        <<"9. Show sorted coffee by its margin "<<endl
        <<"10. Save all the new information in the text file "<<endl
        <<"11. Show  info from the file "<<endl;
    cin>>choice;
    cin.ignore();
return choice;

}

void addCoffee(Kaffe kaffeArray[], int &nrOfSorts)
{

    string brand ="?";
    string type ="=";
    double purPrice=-1;
    double selPrice=-1;

    cout<<"Brand: "<<endl;
    getline(cin, brand);
    cout<<"Type: "<<endl;
    getline(cin, type);
    cout<<"Purchaice price: "<<endl;
    cin>>purPrice;
    cin.ignore();
    cout<<"Price for sale: "<<endl;
    cin>>selPrice;
    cin.ignore();


   int pos = findByName(kaffeArray, brand, type, nrOfSorts);

        if(pos==-1)
        {
            kaffeArray[nrOfSorts]= Kaffe(brand, type, purPrice, selPrice);
            cout<<"Saved!"<<endl;
            nrOfSorts++;
        }
    else
        {
            cout<<"This coffeebrand is already exist"<<endl;
        }

}



int findByName(Kaffe kaffeArray[], string name, string type, int nrOf)
{
    int pos=-1;
    Kaffe temp(name, type);
    for(int i=0; i<nrOf; i++)
    {
        if(kaffeArray[i]==temp)
        {
            pos=i;
        }
    }
    return pos;
}




void showAllInfo(Kaffe kaffeArray[], int nrOfSorts)
{


    for(int i=0; i<nrOfSorts; i++)
    {
       cout<< kaffeArray[i].toString()<<endl;


    }


}

bool isChanged(Kaffe kaffeArray[], int nrOf)
{
    bool ischanged = false;
    int procents=0;

    cout<<"How many %: "<<endl;
    cin>>procents;
    cin.ignore();

    for(int i=0; i<nrOf; i++)
    {
        kaffeArray[i].setSaleKaffe(procents);
        ischanged=true;
        cout<<"The new price for "<<kaffeArray[i].getCoffeeBrand()<<" is "<<kaffeArray[i].getSalePrice()<<endl;
    }
return ischanged;
}




void showPurPrice(Kaffe kaffeArray[], int nrOf)
{
    string brand ="+";
    string type ="+";
    cout<<"Prices for which coffeebrand would you like to see: "<<endl;
    getline(cin, brand);
    cout<<"Type: "<<endl;
    getline(cin, type);
    int pos = findByName(kaffeArray, brand, type, nrOf);

    if(pos!=-1)
    {
        cout<<kaffeArray[pos].getBuyPrice()<<endl;
    }
    else
    {
      cout<<"Not found"<<endl;
    }

}

void showPriceUnder(Kaffe kaffeArray[], int nrOf)
{
    int price =0;
    cout<<"Show all the prices under: "<<endl;
    cin>>price;

    cout<<"All the purchase prices which under "<<price<<" are: "<<endl;
    for(int i=0; i<nrOf; i++)
    {
        if(kaffeArray[i].getBuyPrice()<price)
        {
            cout<<kaffeArray[i].getCoffeeBrand()
                <<" "<<kaffeArray[i].getType()<<" - " <<kaffeArray[i].getBuyPrice()<<endl;
        }

    }


}

void showExpensive(Kaffe kaffeArray[], int nrOf)
{
    int posOfLargest =0;

    for(int i=1; i<nrOf; i++)
    {

        if(kaffeArray[posOfLargest].getBuyPrice()<kaffeArray[i].getBuyPrice())
        {
            posOfLargest=i;
        }
    }

    cout<<kaffeArray[posOfLargest].toString()<<endl;
}

bool isDeleted(Kaffe kaffeArray[], int &nrOf)
{
    bool isDone= false;
    string name ="?";
    string type ="?";
    cout<<"Brand of the coffee you want to delete: "<<endl;
    getline(cin, name);
    cout<<"Type: "<<endl;
    getline(cin, type);

    int pos=findByName(kaffeArray, name, type, nrOf);

    if(pos!=-1)
    {
        kaffeArray[pos] = kaffeArray[--nrOf];

        isDone = true;
        cout<<"Done!"<<endl;
    }
    return isDone;
}

bool isAllDeleted(Kaffe kaffeArray[], string name, int &nrOf)
{
    bool isOk = false;
    cout<<"What coffeebrand you want to delete: "<<endl;
    getline(cin, name);
    int pos=-1;

    for(int i=0; i<nrOf; i++)
    {
        if(kaffeArray[i].getCoffeeBrand()==name)
        {
            pos=i;
            kaffeArray[pos]=kaffeArray[--nrOf];
            isOk = true;
            cout<<"Deleted!"<<endl;
        }
    }
        return isOk;
}

void sorted(Kaffe kaffeArray[], int nrOf)
{
    int posOfLargest = 0;

    Kaffe temp;
    for(int i=0; i<nrOf; i++)
    {
        posOfLargest=i;
        for(int h=i+1; h<nrOf; h++)
        {
            if(kaffeArray[h].getMargin()<kaffeArray[posOfLargest].getMargin())
            {
                posOfLargest=h;
            }
        }

        temp = kaffeArray[posOfLargest];
        kaffeArray[posOfLargest]= kaffeArray[i];
        kaffeArray[i]=temp;

    }



}

void saveInFile(Kaffe kaffeArray[], string filename, int nrOf)
{
    ofstream out;
    out.open(filename, ios::app);

    out<<nrOf<<endl;
    for(int i=0; i<nrOf; i++)
    {
        out<<kaffeArray[i].toString()<<endl;
    }

    out.close();

}

void readFrom(Kaffe kaffeArray[], string fileName, int &nrOf, int cap)
{

    string name ="=";
    string type ="?";
    double Pprice =0;
    double Sprice = 0;
    int counter;

    ifstream in;
    in.open(fileName);

    if(in.is_open())
    {
        in>>counter;
        in.ignore();


        for(int i=0; i<counter && i<cap; i++)
        {
            getline(in, name);
            getline(in, type);
            in>>Pprice;
            in.ignore();
            in>>Sprice;
            in.ignore();

            kaffeArray[counter] = Kaffe(name, type, Pprice, Sprice);


        }
        nrOf=counter;


        in.close();
    }


}



int main()
{

    int cap=10;
    Kaffe *kaffeArray = nullptr;
    kaffeArray = new Kaffe[cap];




    int nrOfSorts =0;
    string name ="=";
    int userchoice= -1;



    cap=cap+10;
    Kaffe *temp = new Kaffe[cap];

    for(int i=0; i<cap; i++)
    {
        temp[i]=kaffeArray[i];
    }

        delete[] kaffeArray;
        kaffeArray=temp;




    while(userchoice!=0)
    {
        userchoice=menu();
       switch(userchoice)
       {

           case 1:
           {
               //system("cls");
               addCoffee(kaffeArray, nrOfSorts);
               break;
           }
           case 2:
           {
                showAllInfo(kaffeArray, nrOfSorts);
               break;
           }

           case 3:
           {
               showPurPrice(kaffeArray, nrOfSorts);
               break;
           }
           case 4:
           {
               isChanged(kaffeArray, nrOfSorts);
               break;
           }

           case 5:
           {
              showPriceUnder(kaffeArray, nrOfSorts);
               break;
           }
           case 6:
           {
               showExpensive(kaffeArray, nrOfSorts);
               break;
           }
           case 7:
           {
               isDeleted(kaffeArray, nrOfSorts);
               break;
           }
           case 8:
           {
               isAllDeleted(kaffeArray, name, nrOfSorts);
               break;
           }
           case 9:
           {
               sorted(kaffeArray, nrOfSorts);
               showAllInfo(kaffeArray, nrOfSorts);

               break;
           }
           case 10:
           {
               saveInFile(kaffeArray, "/Users/yulializneva/CLionProjects/untitled6/kaffe.txt", nrOfSorts);
               break;
           }
           case 11:
           {
               readFrom(kaffeArray, "/Users/yulializneva/CLionProjects/untitled6/kaffe.txt", nrOfSorts, cap);
               break;
           }
           default:
           {
               cout<<"Wrong choice"<<endl;
           }

       }

    }


    delete[] kaffeArray;


    return 0;
}