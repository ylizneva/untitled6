//
// Created by Yulia Lizneva on 2017-11-27.
//

#ifndef UNTITLED6_MOVIE_H
#define UNTITLED6_MOVIE_H

#include "Media.h"

class Movie: public Media
{
private:
    int playtime;
    string mainActor;

public:
    Movie(string titel="", int year=0, int playtime=0, string mainActor="");

    Movie* clone() const;



    int getPlaytime() const;
    string getMainActor() const;

    void setPlaytime(const int playtime);
    void setMainActor(const string mainActor);

    string toStringSpecific() const;


};


#endif //UNTITLED6_MOVIE_H
