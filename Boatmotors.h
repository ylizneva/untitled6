//
// Created by Yulia Lizneva on 2017-11-01.
//

#ifndef UNTITLED6_BOATMOTORS_H
#define UNTITLED6_BOATMOTORS_H

#include <string>

using namespace std;


class Boatmotors
{

private:
    string brand;
    int volume;
    int year;
    string serieNumber;


public:
    Boatmotors(string brand, int volume, int year, string serieNumber);
    Boatmotors();
    ~Boatmotors();


    string getBrand() const;
    int getVolume() const;
    int getYear() const;
    string getSerieNumber() const;
    Boatmotors& operator=(const Boatmotors &other);
    void setBrand(string brand);
    void setVolym(int vol);
    void setYear(int year);
    bool operator==(const Boatmotors &other) const;

    string toString() const;








};


#endif //UNTITLED6_BOATMOTORS_H
