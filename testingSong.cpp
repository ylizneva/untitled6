//
// Created by Yulia Lizneva on 2017-10-02.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"

using namespace std;

const int CAP=10;

//prototypes
int addSong(Song art[], int nrOf);
void changeSong(Song art[], int nrOf);
int findSong(string findSong, Song art[], int &nrOf);
int counter(Song art[], int nrOf);



int menu()
{
    int choice=0;
    cout<<"1. Add a song"<<endl
        <<"2. Change something"<<endl
        <<"3. Show the list"<<endl
        <<"4.Finish"<<endl;
    cin>>choice;
    cin.ignore();
    return choice;
}

int addSong(Song art[], int nrOf)
{
    string titel;
    string artist;
    int speltid;


    cout<<"Titel: ";
    getline(cin, titel);

    cout<<"Arist: ";
    getline(cin, artist);

    cout<<"Playtime: ";
    cin>>speltid;
    cin.ignore();


    art[nrOf]=Song(titel, artist, speltid);
    nrOf++;
    return nrOf;
}

int findSong(string songToFind, Song art[],  int &nrOf)
{

    int pos = -1;
    for(int i=0; i<nrOf && pos==-1; i++)
    {
        if(art[i].getTitel()==songToFind)
        {
            pos=i;
        }
    }
return pos;
}


void changeSong(Song art[], int nrOf)
{
    string tmp;
    string aTitel, bTitel;
    string aArtist;
    int aSpeltid;
    string svar;


    cout<<"Enter titel of a song you want to change: "<<endl;
    getline(cin, aTitel);


    int pos= findSong(aTitel, art, nrOf);
    cout<<aTitel;

    cout << "What you want to change(titel/artist/playtime: " << endl;
    cin >> svar;
    cin.ignore();


    if (svar == "titel")
            {
                cout << "Enter the new titel: " << endl;
                getline(cin, bTitel);
                art[pos].setTitel(bTitel);

            }
            if (svar == "artist")
            {

                cout << "Enter the new artists name: " << endl;
                getline(cin, aArtist);
                art[pos].setArtist(aArtist);

            }
            if (svar == "playtime")
            {

                cout << "Enter the new playtime: " << endl;
                cin >> aSpeltid;
                art[pos].setSpeltid(aSpeltid);
            }
        }


void showAll(Song art[], int nrOf)
{
    for(int i=0; i<nrOf; i++)
    {
        cout<<art[i].toString()<<" ";
    }

}

int main()
{
    Song art[CAP];
    int choice;
    int nrOfSongs =0;

    while(choice!=3)
    {
        choice=menu();
        switch(choice)
        {
            {
                case 1:
                    nrOfSongs= addSong(art, nrOfSongs);
                break;
            }

            case 2:
            {
                changeSong(art, nrOfSongs);
                break;
            }

            case 3:
            {
               showAll(art, nrOfSongs);
                break;
            }
            case 4:
            {
                cout<<"Thank you and goodbye";
                break;
            }
            default:
            {
                cout<<"Wrong choice";
                break;
            }


        }


    }






    return 0;
}