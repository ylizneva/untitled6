//
// Created by Yulia Lizneva on 2017-10-02.
//Gör dessutom en klass som beskriver en låt. Klassens namn ska vara Song. Data/info ska vara titel, speltid
//  samt artist. Det ska vara möjligt att få title, få speltid, få artist, ändra titel,
// ändra speltid, ändra artist samt att få all data som en sträng (toString()-funktionen). Default-konstuktor
// och en konstruktorn som har parametrar för titel, speltid och artist ska finnas.

//Gör ett testprogram som testar din klass Song genom att skapa Song-objekt och anropa funktioner för dessa.
//
#ifndef UNTITLED6_SONG_H
#define UNTITLED6_SONG_H

#include <string>

using namespace std;

class Song
{

private:
    string titel;
    int speltid;
    string artist;
    string convertSpeltid;

public:

    Song(string titel, string artist, int speltid);
    Song();

    string getTitel() const;
    string getArtist() const;
    int getSpeltid() const;

    void setTitel(string titel);
    void setArtist(string artist);
    void setSpeltid(int speltid);


    string toString() const;



};


#endif //UNTITLED6_SONG_H
