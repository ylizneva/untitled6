//
// Created by Yulia Lizneva on 2017-11-03.
//

#ifndef UNTITLED6_DVDOCD_H
#define UNTITLED6_DVDOCD_H

#include <string>
using namespace std;


class DVDoCD
{

private:
    string name;
    int space;
    int playtime;
    int year;


public:
    DVDoCD(int space, string name, int playtime, int year);
    DVDoCD(string name, int year);
    DVDoCD();
    ~DVDoCD();



    string getName() const;
    int getTime() const;
    int getYear() const;



    DVDoCD& operator=(const DVDoCD &other);
    bool operator ==(const DVDoCD &other) const;
    bool operator <(const DVDoCD &other) const;
    bool operator <(const DVDoCD &other) const;


    string toString() const;





};


#endif //UNTITLED6_DVDOCD_H
