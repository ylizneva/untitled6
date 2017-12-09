//
// Created by Yulia Lizneva on 2017-11-01.
//

#include <iostream>
#include <string>
#include "FriendBook.h"

using namespace std;


int main()
{




    FriendBook f1 = FriendBook(2);







    f1.addFriend("Anna", 1942, 10, 20);
    bool add = f1.addFriend("Anna", 1942, 10, 20);


    cout << endl << "Did anna add again: " << add;



    cout << endl << "Printing whole friendbook" << endl;
    cout << f1.toString();

    string friends[10];
    f1.getFriendsAsString(friends, 10);

    f1.addFriend("Bob", 1994, 3, 3);

    cout << endl;
    for (int i = 0; i < 1; i++)
    {
        cout << endl << friends[i];
    }

    f1.saveOnFile("/Users/yulializneva/CLionProjects/untitled6/names.txt");
    f1.readFromFile("/Users/yulializneva/CLionProjects/untitled6/names.txt");

    cout << f1.toString();
    cout << endl;
    return 0;
}
