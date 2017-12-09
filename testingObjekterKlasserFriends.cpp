//
// Created by Yulia Lizneva on 2017-10-02.
//

#include <iostream>
#include <string>
#include "ObjekterKlasserFriends.h"

using namespace std;

int main()
{
    ObjekterKlasserFriends favoriteFriend("Alexander", 1973, "alex@bth.se");

    {
        ObjekterKlasserFriends friend2("Batman", 1992, "bat@man.com" );
// när körningen lämnar blocket körs destruktorn för friend2
    }

/*
    //mata in uppgifter för en vän och skapa ett vän-objekt för dessa

    string aName;
    int aBY;
    string anEmail;

    cout<<"Name: ";
    getline(cin, aName);

    cout<<"BY: ";
    cin>>aBY;

    cout<<"email: ";
    cin>>anEmail;
    cin.ignore();

    ObjekterKlasserFriends aFriend(aName, aBY, anEmail);

    cout<<"My favorite friend's name's "<<favoriteFriend.getName()<<endl;
cout<<"My other's friend name's "<<aFriend.getName()<<endl;

    if(favoriteFriend.getName()==aFriend.getName())
    {
        cout<<"Friends has same names"<<endl;
    }
    else
    {
        cout<<"Friends has different names"<<endl;
    }
    //avgör om vännerna har samma namn eller ej och skriv ut resultat

    cout<<"My favorite frind was born at "<<favoriteFriend.getby()<<endl;
    cout<<"His email is "<<favoriteFriend.getemail()<<endl;

    cout<<"Year of birth of another one is: "<<aFriend.getby()<<endl;
    cout<<"His email is "<<aFriend.getemail()<<endl;


    cout<<"Give another name to your fav friend ";
    getline(cin, aName);

    favoriteFriend.setName(aName);

    cout<<endl;
    cout<<favoriteFriend.getName()<<" is "<<favoriteFriend.age(2017)<<" år i år"<<endl;
    cout<<aFriend.getName()<<" is "<<aFriend.age(2017)<<" år i år"<<endl;

cout<<endl<<endl<<"Anrop av toString() för de båda objekten"<<endl;

    cout<<favoriteFriend.toString()<<endl
        <<aFriend.toString()<<endl;
*/

    return 0;
}
