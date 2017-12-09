//
// Created by Yulia Lizneva on 2017-10-02.
//
//klassdefenition

#include "Song.h"

Song::Song(string titel, string artist, int speltid)
{
    this->titel = titel;
    this->artist = artist;
    this->speltid = speltid;

}

Song::Song()
{
    this->titel ="?";
    this->artist ="?";
    this->speltid =-1;
}


string Song::getTitel() const
{
    return this->titel;
}

string Song::getArtist() const
{
    return this->artist;
}

int Song::getSpeltid() const
{
    return this->speltid;
}

void Song::setArtist(string artist)
{
    this->artist=artist;
}
void Song::setTitel(string titel)
{
    this->titel=titel;
}
void Song::setSpeltid(int speltid)
{
    this->speltid=speltid;
}

string Song::convertSpeltid() const
{

    string byAsString= to_string(this->speltid/60) +":"+ to_string(this->speltid%60);
    return byAsString;
}

string Song::toString() const
{

    string totalString = this->artist + " singing a song "+
            this->titel + " that lasts " + convertSpeltid() +" " ;
    return totalString;
}












