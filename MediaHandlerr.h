//
// Created by Yulia Lizneva on 2017-12-04.
//

#ifndef UNTITLED6_MEDIAHANDLERR_H
#define UNTITLED6_MEDIAHANDLERR_H

#include "Media.h"
#include <string>
#include <iostream>
#include "Book.h"
#include "Movie.h"


using namespace std;
class MediaHandlerr
{

private:

    static const int CAP=20;
    Media* medias[CAP];
    int currentNrOfMedias;

    void freeMemory();
    void makeCopy(const MediaHandlerr& original);

public:
    MediaHandlerr();
    virtual~MediaHandlerr();
    MediaHandlerr(const MediaHandlerr& original);
    MediaHandlerr& operator=(const MediaHandlerr& original);


    void addBook(string titel, string author, int year);
    void addMovie(string titel, int year, int playtime, string mainActor);
    void getAllMediasAsString(string arr[], int capOfArr) const;

    int nrOfBooks() const;
    int nrOfMovies() const;
    void getAllTitelsOfAuthir(string theAuthor, string arr[], int capOfArr, int& nrOfTitels) const;
    int longestPlayTime() const;

    int getNrOfAllMedias() const;


    void getAllBookasString(string arr[], int capOfArr) const;
    void getAllMoviesString(string arr[], int capOfArr) const;


};


#endif //UNTITLED6_MEDIAHANDLERR_H
