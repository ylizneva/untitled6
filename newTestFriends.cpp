//
// Created by Yulia Lizneva on 2017-10-04.
//
#include "ObjekterKlasserFriends.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string aName;

    int by;
    string email;

    ObjekterKlasserFriends bestFriend("Vlex", 1996, "alex@nah.com");

    cout<<"Name: "<<endl;
    getline(cin, aName);

    cout<<"Year of birth: ";
    cin>>by;
    cin.ignore();

    cout<<"email: "<<endl;
    getline(cin, email);

    ObjekterKlasserFriends someFriend(aName, by, email);
    /*
    ObjekterKlasserFriends aFriend; //anrop av default konstroktor


    cout<<"Name: ";
    getline(cin, aName);


  aFriend.setName(aName);

    if(bestFriend.getName()==aFriend.getName())
    {
        cout<<"Same names"<<endl;
    }
    */




    if(bestFriend == someFriend)
    {
        cout<<"Du har matat in samma person, try again!";
    }
if(bestFriend<someFriend)
{
    cout<<"bestFriend är mindre än someFriend";
}

}
