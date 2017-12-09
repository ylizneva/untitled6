//
// Created by Yulia Lizneva on 2017-11-27.
//

#ifndef UNTITLED6_BOOK_H
#define UNTITLED6_BOOK_H

#include "Media.h"

class Book:public Media
{
private:
    string author;

public:
    Book(string titel="",string author="",  int year=0);
    Book(const Book &original);
    ~Book();

    Book* clone() const;

    string getAuthor() const;
    void setAuthor(const string author);


    //string toString() const;
    string toStringSpecific() const;



};


#endif //UNTITLED6_BOOK_H
