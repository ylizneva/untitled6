//
// Created by Yulia Lizneva on 2017-11-27.
//

#include "Book.h"
#include "Movie.h"
#include "MediaHandlerr.h"

#include <iostream>

using namespace std;

int main()
{
    /*
    int cap=0;

    // användare matar in en cap
    // allokera en dynamisk array av denna cap i vilken både böcker o filmer ska placeras

    cout<<"Cap: "<<endl;
    cin>>cap; cin.ignore();

  //Media* *medias = new Media*[cap]; // dubbelpekare för att Media är en abstrakt klass


    // skapa en array av storlek 20(kommer ej att ändras) i vilken både böcker i filmer kan placeras

    //Media* mediar[20]; // ingen new, för att det är ett bestämt antal

    //Skapa 3 böcker o 2 filmer vilka placeras i arrayen

    medias[0]= new Book("Bla", "Bla", 2000);

    medias[1] = new Movie("Film", 2009, 123, "Jag");
    medias[2] = new Movie("Movie", 2001, 190, "Du");
    medias[3]= new Book("gla", "Bla", 2001);
    medias[4] = new Book("mla", "hla", 2002);



    int currentNrOfMedias = 5;
    cout<<"*******************************************"<<endl;
    //1. Presentera alla filmer o böcker i den ordning dem placerade i arrayen i samma ordning

    cout<<"Arayen innehåller följande medier"<<endl;
    for(int i=0; i<currentNrOfMedias; i++)
    {
        cout<<medias[i]->toString()<<endl;
    }

    cout<<"*******************************************"<<endl;
    //2.Presentera bara böcker
    cout<<"Bara böcker"<<endl;
    for(int i=0; i<currentNrOfMedias; i++)
    {
        //typ bestämmning
       if(dynamic_cast<Book*>(medias[i])!= nullptr) // om det är ett Book-objekt som nås via pekaren media[i]
       {
           //erhålls adressen till detta objekt.
           // och om det är inte ett Book-objekt erhålls istället nullptr
           cout<<medias[i]->toString()<<endl;
       }
    }
    string nåt="";
    string titel, actor, author;
    int pl, year;

    //3. lägger till en fill eller en bok
    cout<<"Bok eller en film(B/F)"<<endl;
    getline(cin, nåt);

    cout<<"Titel:\n";
        getline(cin, titel);

        cout<<"Year\n";
        cin>>year; cin.ignore();


    if(nåt=="B"|| nåt =="b")
    {

        cout<<"Author:\n";
        getline(cin, author);

        medias[currentNrOfMedias++]= new Book(titel, author, year);




    }
    else
    {
        cout<<"Actor\n";
        getline(cin, actor);
        cout<<"Playtime:\n";
        cin>>pl; cin.ignore();


        medias[currentNrOfMedias++]= new Movie(titel, year, pl, actor);
    }

    cout<<"*******************************************"<<endl;
    //4.
    cout<<" Bestäm antalet böcker resp antalet filmer"<<endl;
    int nrOfBooks=0;
    int nrOfMovies=0;

    for(int i=0; i<currentNrOfMedias; i++)
    {
        if(dynamic_cast<Book*>(medias[i])!= nullptr)
        {
            nrOfBooks++;


        }

        else
            nrOfMovies++;


        //om det är en bok på plats i
        // öka räknaren för analet böcker

        //annars öka räknaren för antalet filmer
    }
    cout<<"Books: "<<nrOfBooks<<endl;
    cout<<"Movies: "<<nrOfMovies<<endl;


    //skriv ut antalet böcker och antalet filmer
    cout<<"*******************************************"<<endl;
    //5. Presentera alla titlar av författaren Bla

    // identifiera om det är Book, om det är då reda ut en författare

    cout<<"*******************************************"<<endl;
    cout<<"Titlar på böcker som var skrivna av Bla"<<endl;
    Book* bookPtr = nullptr;
    for(int i=0; i<currentNrOfMedias; i++)
    {
        bookPtr = dynamic_cast<Book*>(medias[i]); // bookPtr innehåller adressen till varje position
        // levererar adressen till Book
        if(bookPtr!= nullptr)
        {
            // är författaren Bla?
            if(bookPtr->getAuthor()=="Bla")
            {
                cout<<medias[i]->getTitel();
            }
        }
    }

*/

    Media* mPtr = new Book("A", "a", 2015);
    Media* copuPtr = mPtr->clone();
    cout<<mPtr->toString()<<endl;
    cout<<copuPtr->toString()<<endl;

    Book* bPtr = new Book("B", "b", 2016);
    Book* copybPtr = bPtr->clone();


    delete mPtr;
    delete copuPtr;
    delete bPtr;





    return 0;
}