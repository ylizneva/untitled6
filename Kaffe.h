//
// Created by Yulia Lizneva on 2017-10-17.
//

#ifndef UNTITLED6_KAFFE_H
#define UNTITLED6_KAFFE_H

#include <string>
using namespace std;

class Kaffe
{

private:

    string coffeeBrand;
    string type;
    double buyPrice;
    double salePrice;


public:
    Kaffe(string coffeeBrand, string type, double buyPrice, double salePrice);
    Kaffe();
    Kaffe(string coffeeBrand, string type);
    ~Kaffe();


    double getMargin() const;
    string getCoffeeBrand() const;
    string getType() const;
    double getBuyPrice() const;
    double getSalePrice() const;

    void setSaleKaffe(double procent);
    string toString() const;

    bool operator<(const Kaffe &otherKaffe) const;
    bool operator==(const Kaffe &otheKaffe) const;








};


#endif //UNTITLED6_KAFFE_H
