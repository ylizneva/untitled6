//
// Created by Yulia Lizneva on 2017-12-04.
//

#include "MediaHandlerr.h"

using namespace std;


MediaHandlerr::MediaHandlerr()
{
    this->currentNrOfMedias=0;
    for(int i=0; i<this->CAP; i++)
    {
        medias[i]= nullptr;
    }
}

MediaHandlerr::~MediaHandlerr()
{
    this->freeMemory();
}

void MediaHandlerr::makeCopy(const MediaHandlerr& original)
{
    this->currentNrOfMedias=original.currentNrOfMedias;


    Book* bookPtr = nullptr;
    Movie* moviePtr = nullptr;

    for(int i=0; i<this->currentNrOfMedias; i++)
    {
/*
        bookPtr = dynamic_cast<Book*>(original.medias[i]);
        if(bookPtr != nullptr)
        {
            // this->medias[i]= original.medias[i]; - yttlig kopiering, INTE OK!!!!
            this->medias[i]= new Book(*bookPtr);
        }
        // pss film
        moviePtr = dynamic_cast<Movie*>(original.medias[i]);
        if(moviePtr != nullptr)
        {
            this->medias[i] = new Movie(*moviePtr);
        }
        */

        this->medias[i]=original.medias[i]->clone();
    }

}



void MediaHandlerr::freeMemory()
{
    for(int i=0; i<this->currentNrOfMedias; i++)
    {
        delete this->medias[i];
    }

}
MediaHandlerr::MediaHandlerr(const MediaHandlerr& original) //copy construktor
{
    this->currentNrOfMedias=original.currentNrOfMedias;


    Book* bookPtr = nullptr;
    Movie* moviePtr = nullptr;

    for(int i=0; i<this->currentNrOfMedias; i++)
    {
        this->medias[i] = original.medias[i]->clone();
    }




}
MediaHandlerr& MediaHandlerr::operator=(const MediaHandlerr& original) // skulle clone anropas??
{
    if(this != &original) // kontroll av self-assigmnet( självtilldelnig)
    {

        this->freeMemory();
        this->makeCopy(original);


        //kopiera från original till this(se copy construktor)
    }
    return *this; // varför & ska vara med?
}
void MediaHandlerr::addBook(string titel, string author, int year)
{
    if(this->currentNrOfMedias<MediaHandlerr::CAP)
    {
        this->medias[this->currentNrOfMedias++]= new Book(titel, author, year);
    }

}

void MediaHandlerr::addMovie(string titel, int year, int playtime, string mainActor)
{
    if(this->currentNrOfMedias<MediaHandlerr::CAP)
    {
        this->medias[this->currentNrOfMedias++] = new Movie(titel, year, playtime, mainActor);
    }

}


void MediaHandlerr::getAllMediasAsString(string arr[], int capOfArr) const // Fråga Betty
{

    if(capOfArr<this->currentNrOfMedias)
    {
        for(int i=0; i<this->currentNrOfMedias; i++)
        {
            arr[i]= medias[i]->toString();
        }
    }

}

int MediaHandlerr::nrOfBooks() const
{
    int nrOfBooks=0;
    for(int i=0; i<currentNrOfMedias; i++)
    {
        if(dynamic_cast<Book*>(this->medias[i]) != nullptr)
        {
            nrOfBooks++;
        }
    }
    return nrOfBooks;
}

int MediaHandlerr::nrOfMovies() const
{
    int nrOfMovies=0;
    for(int i=0; i<this->currentNrOfMedias; i++)
    {
        if(dynamic_cast<Movie*>(this->medias[i]) != nullptr)
        {
            nrOfMovies++;
        }
    }
    return nrOfMovies;
}
void MediaHandlerr::getAllTitelsOfAuthir(string theAuthor, string arr[], int capOfArr, int& nrOfTitels) const
{
    Book* bookPtr = nullptr;
    for(int i=0; i<this->currentNrOfMedias; i++)
    {
        bookPtr = dynamic_cast<Book*>(medias[i]);

            if(bookPtr != nullptr && bookPtr->getAuthor()==theAuthor)
            {
                arr[nrOfTitels++]=medias[i]->getTitel();
            }

    }
}
int MediaHandlerr::longestPlayTime() const
{
    int longest = 0;
    Movie* moviePtr = nullptr;
    for(int i=0; i<currentNrOfMedias; i++)
    {
        moviePtr= dynamic_cast<Movie*>(medias[i]);
        if(moviePtr != nullptr)
        {
           if(longest<moviePtr->getPlaytime())
           {
               longest=moviePtr->getPlaytime();
           }
        }
    }
    return longest;
}

int MediaHandlerr::getNrOfAllMedias() const
{
    return this->currentNrOfMedias;
}

void MediaHandlerr::getAllBookasString(string arr[], int capOfArr) const
{
    int counter =0;
    for(int i=0; i<this->currentNrOfMedias; i++)
    {
        if(dynamic_cast<Book*>(medias[i]) != nullptr)
        {
            arr[counter++]= this->medias[i]->toString();
        }
    }
}
void MediaHandlerr::getAllMoviesString(string arr[], int capOfArr) const
{
    int counter=0;
    for(int i=0; i<this->currentNrOfMedias; i++)
    {
        if(dynamic_cast<Movie*>(medias[i]) != nullptr)
        {
            arr[counter++]= this->medias[i]->toString();
        }
    }

}