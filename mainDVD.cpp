//
// Created by Yulia Lizneva on 2017-11-04.
//


#include <iostream>
#include "DVDoCDandraFil.h"

using namespace std;

int menu()
{
    int choice=-1;
    cout<<"1. Add a movie\n"
        <<"2. Delete a movie\n"
        <<"3. Search for a movie\n"
        <<"4. Check the memory\n"
        <<"5. Sort all the movies by space\n"
        <<"6. Sort all the movies by name\n"
        <<"7. Show all the movies\n"
        <<"8. Change something\n"
        <<"9. Save in text file\n"
        <<"10. Read from file\n";
    cin>>choice; cin.ignore();
    return choice;
}

void readFromFile(DVDoCDandraFil &disk, string file)
{

}





void changes(DVDoCDandraFil &disk, int nSpace, string name, string nName, int nPT, int year, int NY)
{
    int space=0;


    cout<<"Which movie would you like to change: \n Name: \n";
    getline(cin, name);
    cout<<"Year:\n";
    cin>>year; cin.ignore();


    cout<<"Enter the new parameters. \n Name: \n";
    getline(cin, nName);
    cout<<"Year:\n";
    cin>>NY; cin.ignore();
    cout<<"Playtime:\n";
    cin>>nPT; cin.ignore();
    cout<<"Space:\n";
    cin>>nSpace; cin.ignore();

    disk.changeSomething(space, nSpace, name, nName, nPT, year, NY);

}

void showAll(DVDoCDandraFil disk)
{

    disk.showAll();
}

void sortbyName(DVDoCDandraFil &disk)
{
    disk.sortAllbyName();
    disk.showAll();
}

void sortTheSpace(DVDoCDandraFil &disk)
{
    disk.sortAllbySpace();
    disk.showAll();

}
void addOne(DVDoCDandraFil &disk, int space, string name, int playtime, int year)
{
    cout<<"Name of a movie:\n";
    getline(cin, name);
    cout<<"Which year:\n";
    cin>>year; cin.ignore();
    cout<<"Enter playtime:\n";
    cin>>playtime; cin.ignore();
    cout<<"How many mg is the movie:\n";
    cin>>space; cin.ignore();
    disk.saveAmovie(space, name, playtime, year);

}

void deleteOne(DVDoCDandraFil &disk, int space, string name, int playtime, int year)
{
    cout<<"Name of a movie:\n";
    getline(cin, name);
    cout<<"Which year:\n";
    cin>>year; cin.ignore();
    cout<<"Enter playtime:\n";
    cin>>playtime; cin.ignore();
    cout<<"How many mg is the movie:\n";
    cin>>space; cin.ignore();
    disk.deleteAmovie(space, name, playtime, year);
}

void findOne(DVDoCDandraFil disk, int space, string name, int playtime, int year)
{
    cout<<"Name of a movie:\n";
    getline(cin, name);
    cout<<"Which year:\n";
    cin>>year; cin.ignore();
    cout<<"Enter playtime:\n";
    cin>>playtime; cin.ignore();
    cout<<"How many mg is the movie:\n";
    cin>>space; cin.ignore();
    string arr[10];
    disk.showSome(arr, 10, space, name, playtime, year);
    cout<<arr[0]<<endl;

}
void checkTheMemory(DVDoCDandraFil &disk, int space, string name, int playtime, int year)
{
   cout<<disk.getFreeSpace(space, name, playtime, year)<<endl;
}

int main()
{

    DVDoCDandraFil disk;
    int choice=-1;
    int space, play, year;
    string name="=";
    string nName="=";
    int nPT, NY;

    while(choice!=0)
    {
        choice=menu();
        switch(choice)
        {
            case 1:
            {
                addOne(disk, space, name, play, year);
                break;
            }
            case 2:
            {
                deleteOne(disk, space, name, play, year);
                break;
            }
            case 3:
            {
                findOne(disk, space, name, play, year);
                break;
            }
            case 4:
            {
                checkTheMemory(disk, space, name, play, year);
                break;
            }
            case 5:
            {
                sortTheSpace(disk);
                break;
            }
            case 6:
            {
                sortbyName(disk);
                break;
            }
            case 7:
            {
                showAll(disk);
                break;
            }
            case 8:
            {
                changes(disk, space, name, nName, nPT, year, NY);
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
        }
    }


    return 0;
}