//
// Created by Yulia Lizneva on 2017-11-01.
//

#ifndef UNTITLED6_FRIENDS_H
#define UNTITLED6_FRIENDS_H


#include <string>
#include "Date.h"

using namespace std;

class Friend
{
private:
    string name;
    Date dateOfBirth;
public:
    Friend();
    Friend(string name, int year, int month, int day);
    ~Friend();

    string getName() const;
    Date getDate() const;

    bool operator==(const Friend& other) const;

    // Based on the date of birth
    bool operator< (const Friend &other) const;

    string toString() const;
};



#endif //UNTITLED6_FRIENDS_H
