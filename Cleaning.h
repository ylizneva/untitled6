//
// Created by Yulia Lizneva on 2017-10-18.
//
#ifndef CLEANING_H
#define CLEANING_H

#include <string>
using namespace std;

class Cleaning
{

private:
    double price;
    string type;
    double payOff;


public:

    Cleaning(string type, double price, double payOff);
    Cleaning();
    ~Cleaning();


    double getPrice() const;
    string getType() const;
    double getPayOff() const;

    double getMargin() const;
    void setPrice(int procent);
    void setSallary(int procent);

    bool operator==(const Cleaning &otherOne) const;
    bool operator<(const Cleaning &otheOne) const;
    string toString() const;



};




#endif