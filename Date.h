//
// Created by Yulia Lizneva on 2017-11-01.
//

#ifndef UNTITLED6_DATE_H
#define UNTITLED6_DATE_H

#include <string>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int year, int month, int day);
    ~Date();

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    bool operator== (const Date& other) const;
    bool operator< (const Date& other) const;
    Date& operator= (const Date& other);

    string toString() const;
};



#endif //UNTITLED6_DATE_H
