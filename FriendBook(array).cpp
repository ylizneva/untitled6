//
// Created by Yulia Lizneva on 2017-10-02.
//

#include <iostream>
#include <string>
#include <fstream>
#include "ObjekterKlasserFriends.h"


using namespace std;

const int CAP=15;

//prototypes
int manu();
int findFriends(string nameToFind, ObjekterKlasserFriends friends[], int nrOfFriends);
void addFriend(ObjekterKlasserFriends friends[], int &nrOfFriends, int capacity);
void showAll(ObjekterKlasserFriends Friends[], int nrOfFriends);

bool deleteFriend(ObjekterKlasserFriends friends[], int &nrOfFriends);

void readFromFile(ObjekterKlasserFriends friends[], string fileName, int &nrOfFriends, int capacity);

void writeToFile(ObjekterKlasserFriends friends[], string fileName, int nrOfFriends);


void showEmail(ObjekterKlasserFriends friends[], int nrOfFriends);

void showAllFriendsMoreThan(ObjekterKlasserFriends friends[], int nrOfFriends);

void showTheYoungest(ObjekterKlasserFriends friends[], int nrOfFriends);
void showAverage(ObjekterKlasserFriends friends[], int nrOfFriends);
//selektionsort

void sortOnName(ObjekterKlasserFriends friends[], int nrOfFriends);




int menu()
{

    int userChoice=0;
    cout<<"1. Add a friend"<<endl
        <<"2. Show friends"<<endl
        <<"3. Delete a friend"<<endl
        <<"4. Show email"<<endl
        <<"5. Show older than:.."<<endl
        <<"6. Show youngest"<<endl
        <<"7. Show the average age"<<endl
         <<"Sort all the names by alfabet"<<endl
        <<"0. Finish"<<endl;
    cin>>userChoice;
    cin.ignore();
    return userChoice;
}


void addFriend(ObjekterKlasserFriends Friends[], int &nrOfFriends, int capacity)
{
    string aName ="?";
    string aMail= "?";
    int by =-1;


    cout << "Friend's name: " <<endl;
    getline(cin, aName);
    cout << "Birth date: " << endl;
    cin >> by;
    cin.ignore();
    cout << "email: " << endl;
    cin >> aMail;
    cin.ignore();
    Friends[nrOfFriends] = ObjekterKlasserFriends(aName, by, aMail);
    nrOfFriends++;

}

int findFriends(string nameToFind, ObjekterKlasserFriends Friends[], int nrOfFriends)

{
    int temp=-1;

        for (int i = 0; i < nrOfFriends && temp==-1; i++)
        {
            if (Friends[i].getName() == nameToFind)
            {
                temp = i;
            }
        }
        return temp;
}


bool deleteFriend(ObjekterKlasserFriends Friends[], int &nrOfFriends)
{
    string aName ="J";
    int temp = -1;
    bool didRemove = false;

    cout << "What's name you want to delete: ";
    getline(cin, aName);


    temp=findFriends(aName, Friends, nrOfFriends);
         if(temp!=-1)
         {
             Friends[temp]= Friends[--nrOfFriends];
             didRemove= true;
         }

        cout<<"Completed!"<<endl;


    return didRemove;
}



void showAll(ObjekterKlasserFriends Friends[], int nrOfFriends)
{

    for (int i = 0; i < nrOfFriends; i++)
    {

        cout<<Friends[i].toString()<<" ";
        cout<<"and "<< Friends[i].age(2017)<<" years old"<<endl;

    }


}




void readFromFile(ObjekterKlasserFriends Friends[], string fileName, int &nrOfFriends, int capacity)
{
    //öppna filen
    ifstream in;
    in.open(fileName);

    string theName;
    int by;
    string email;
    int counter = nrOfFriends;
    if(in.is_open())
    {
        in>>nrOfFriends;
        in.ignore();

    for(int i=0; i<nrOfFriends && i<capacity; i++)
    {
        //om antalet > kapacitetn sätt antalet till kapasiteten

        getline(in, theName);
        in>>by;
        in.ignore();
        getline(in, email);

        Friends[counter] = ObjekterKlasserFriends(theName, by, email);
        counter++;

        //om antalet större än kapaciteten då sätt antalet till kapaciteten
    }
        //bygg ett objekt genom att använda konstruktor o placera objektet på aktuel pos i arrayen

        in.close();
    }

    nrOfFriends=counter;
}

void writeToFile(ObjekterKlasserFriends Friends[], string fileName, int nrOfFriends)
{

    ofstream out;
    out.open(fileName);

    out<<nrOfFriends<<endl;
    for(int i=0; i<nrOfFriends; i++)
    {
        out<<Friends[i].getName()<<endl;
        out<<Friends[i].getby()<<endl;
        out<<Friends[i].getemail()<<endl;
    }



    out.close();

}

void sortOnName(ObjekterKlasserFriends Friends[], int nrOfFriends)
{
    string tmp ="?";

    for(int i=0; i<nrOfFriends; i++)
    {
        if(Friends[i].getName()<tmp)
        {

        }
    }

}
void showEmail(ObjekterKlasserFriends Friends[], int nrOfFriends)
{
    string theName ="?";
    int pos = -1;
    cout<<"Enter a name in the order to see email: "<<endl;
    getline(cin, theName);

    for(int i=0; i<nrOfFriends; i++)
    {
        if(Friends[i].getName()==theName)
        {
            pos=i;
        }
    }

    cout<<Friends[pos].getemail()<<" ";

}



   int main()
   {
       int nrOfFriends =0;
       ObjekterKlasserFriends Friends[CAP];


       int choice = -1;


       while(choice!=0)
       {
           choice = menu();
           switch (choice)
           {
               case 1:
               {
                   addFriend(Friends, nrOfFriends,CAP);

                   break;
               }
               case 2:
               {
                   readFromFile(Friends, "/Users/yulializneva/CLionProjects/untitled6/friends.txt", nrOfFriends, CAP);
                   showAll(Friends, nrOfFriends);


                   break;
               }
               case 3:
               {
                   nrOfFriends = deleteFriend(Friends, nrOfFriends);
                   break;
               }

               case 4:
               {
                   readFromFile(Friends, "/Users/yulializneva/CLionProjects/untitled6/friends.txt", nrOfFriends, CAP);
                   showEmail(Friends, nrOfFriends);
                   break;
               }

               case 0:
               {
                   cout << "Thank you and goodbye" << endl;
                   break;
               }
               default:
               {
                   cout << "Not valid choice. Try again." << endl;
               }

                }
            }

       writeToFile(Friends, "/Users/yulializneva/CLionProjects/untitled6/friends.txt", nrOfFriends);
            return 0;

    }





