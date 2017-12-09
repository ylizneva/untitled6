//
// Created by Yulia Lizneva on 2017-11-27.
//

#include <iostream>
#include "Book.h"
#include "Movie.h"

using namespace std;


int main()
{

   //Media *m1 = new Media();
    Book *b1 = new Book("C++", "Gaddis", 2016);

    Movie *m2 = new Movie("Bla", 1990, 120, "Jag");

    Media *m10 = new Book("Java","Bla", 190);

    cout<<b1->toString()<<endl<<"*********"<<endl;
    cout<<m2->toString()<<endl<<"*********"<<endl;
    cout<<m10->toString()<<endl<<"*********"<<endl;

    delete b1;
    delete m2;
    delete m10;

    return 0;
}
