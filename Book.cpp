//
// Created by Yulia Lizneva on 2017-11-27.
//

#include "Book.h"
#include <sstream>

Book::Book(string titel, string author, int year)
    :Media(titel, year)
{
    this->author=author;
}
Book* Book::clone() const
{
    return new Book(*this);  // booken gör en kopia av sig själv genom att använda kopierings operaor
}




Book::Book(const Book &original) //varför använder vi det?
:Media(original)
{
    this->author=original.author;
}


Book::~Book()
{

}

string Book::getAuthor() const
{
    return this->author;
}
void Book::setAuthor(const string author)
{
    this->author=author;
}

string Book::toStringSpecific() const
{
    stringstream out;
    out<<"The author: "<<this->author;
    return out.str();
}

/*string Book::toString() const
{
    stringstream out;
     out<<Media::toString()<<this->author;
    return out.str();
}*/