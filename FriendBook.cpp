//
// Created by Yulia Lizneva on 2017-11-01.
//

#include "FriendBook.h"
#include <fstream>
#include <sstream>

using namespace std;




/*FriendBook::FriendBook(string owner, int year)
{

    this->owner=owner;
    this->year=year;
}


FriendBook::FriendBook()
{

    this->owner="";
    this->year=0;
}

 */


// Adds a friend to the internal array based on the parameters, but only if there is room in the internal array and the friend to be added does not already exist in the friendbook
bool FriendBook::addFriend(string name, int year, int month, int day)
{
    bool isDone=false;


    if(existFriend(name, year, month, day)==-1)
    {
        if(this->nrOfFriends==this->cap)
        {
            this->expend();
        }

        this->friends[nrOfFriends++]=new Friend(name, year, month, day);
        isDone =true;
    }



    /*Friend temp = Friend(name, year, month, day);

    int pos=existFriend(name, year, month, day);

        if (nrOfFriends < maxNrOfFriends && pos==-1 )
        {
            friends[nrOfFriends++]=temp;
            isDone=true;
        }
*/

    return isDone;
}

// Removes a friend specified by the parameters from the internal array if it exists in the friendbook
bool FriendBook::removeFriend(string name, int year, int month, int day)
{
    bool isDone = false;
    int pos=-1;
    Friend temp = Friend(name, year, month, day);
    for(int i=0; i<nrOfFriends; i++)
    {
        if(*this->friends[i]==temp)
        {
            pos =i;
            delete this->friends[pos];
            this->friends[pos] =friends[--nrOfFriends];
            isDone = true;

        }
    }
    return isDone;
}

// Searches through the internal array to see if a friend matching the parameters can be found and returns the index if it finds one, otherwise returns -1
int FriendBook::existFriend(string name, int year, int month, int day) const
{
    int pos=-1;
    Friend temp = Friend(name, year, month, day);
    for(int i=0; i<nrOfFriends; i++)
    {
        if(*this->friends[i]==temp)
        {
            pos=i;
        }
    }
    return pos;
}

// Fills arr with the toString information of all the internally stored friends with the indicated year, but will not fill more spots than indicated by the n parameter
void FriendBook::getNameAndAgeAsStringsOfFriends(string arr[], int n, int year) const
{
    int counter =0;
    for(int i=0; i<n && i<nrOfFriends; i++)
    {
        if(this->friends[i]->getDate().getYear()==year)
        {
            arr[counter++] = friends[i]->toString();
        }
    }
}

// Returns the number of friends currently in the friendbook
int FriendBook::getNrOfFriends() const
{
    return this->nrOfFriends;
}

// Get and set functions for the friendbooks owner and year
string FriendBook::getOwner() const
{
    return this->owner;
}
void FriendBook::setOwner(string owner)
{
    this->owner=owner;
}
int FriendBook::getYear() const
{
   return this->year;
}
void FriendBook::setYear(int year)
{
    this->year=year;
}

// Clears the friendbook
void FriendBook::clear()
{
    nrOfFriends=0;

}

// Fills arr with the toString information of all the internally stored friends, but will not fill more spots than indicated by the n parameter
void FriendBook::getFriendsAsString(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i]=this->friends[i]->toString();
    }
}

// Saves all the friends currently in the friendbook to a file with a given filename
void FriendBook::saveOnFile(string filename) const
{
    ofstream out;
    out.open(filename);

    out<<nrOfFriends<<endl;
    for(int i=0; i<nrOfFriends; i++)
    {
        out<<friends[i]->getName()<<endl;
        out<<friends[i]->getDate().getYear()<<endl;
        out<<friends[i]->getDate().getMonth()<<endl;
        out<<friends[i]->getDate().getDay()<<endl;
    }

    out.close();
}

// Reads the file given by the filename and fills the friendbook with friends based on the data in the file
void FriendBook::readFromFile(string filename)
{
    int nrOf;
    string name;
    int year, month, day;
    ifstream in;
    in.open(filename);
    if(in.is_open())
    {
        in>>nrOf; in.ignore();
        nrOfFriends+=nrOf;

        for(int i=0; i<nrOfFriends; i++)
        {
            getline(in, name);
            in>>year; in.ignore();
            in>>month; in.ignore();
            in>>day; in.ignore();

            *this->friends[i]= Friend(name, year, month, day);
        }

    }
    in.close();
}

// Fills arr with the toString information of all the internally stored friends in a sorted order, but will not fill more spots than indicated by the n parameter
// The member function require <operator for Friend
// Should not change the internal order of the Friends
void FriendBook::getFriendsAsStringsSorted(string arr[], int n)
{
    int smallestPos=-1;
    Friend* temp;



    for(int i=0; i<nrOfFriends; i++)
    {
        smallestPos=i;
        for(int h=i+1; h<nrOfFriends; h++)
        {
            if(friends[h]<friends[smallestPos])
            {
                smallestPos=h;
            }
        }

        temp=friends[smallestPos];
        friends[smallestPos]=friends[i];
        friends[i]=temp;


    }


    for(int i=0; i<n; i++)
    {
        arr[i]=friends[i]->toString();
    }


    for(int i=0; i<nrOfFriends; i++)
    cout<<this->friends[i]->getName() << "\t"
       << this->friends[i]->getDate().getYear()
       <<"\t"<<this->friends[i]->getDate().getMonth()<<"\t"<<this->friends[i]->getDate().getDay()<<endl;
    //return out.str();
}

// Returns all the information in the friendbook as a string
string FriendBook::toString()
{
    string sum;
    for(int i=0; i<nrOfFriends; i++)
    {
        sum += friends[i]->toString() +"\n";
    }

    return sum;
}





void FriendBook::initiate(int from)
{
    for(int i=from; i<this->cap; i++)
    {
        this->friends[i]= nullptr;
    }
}



void FriendBook::expend()
{
    this->cap+=10;
    Friend* *temp=new Friend*[this->cap];

    for(int i=0; i<this->nrOfFriends; i++)
    {
        temp[i]=this->friends[i];
    }

    delete[] this->friends;
    this->friends=temp;
    temp = NULL;

    this->initiate(this->nrOfFriends);

}


void FriendBook::freeMemory()
{
    for(int i=0; i<this->nrOfFriends; i++)
    {
        if(this->friends[i]!= nullptr)
        {
            delete this->friends[i];
        }
    }

    delete[]this->friends;
}


void FriendBook::makeCopy(const FriendBook &originalObjekt)
{
    this->cap=originalObjekt.cap;
    this->nrOfFriends=originalObjekt.nrOfFriends;

    this->friends=new Friend*[originalObjekt.cap];

    for(int i=0; i<originalObjekt.nrOfFriends; i++)
    {
        this->friends[i]=new Friend(*originalObjekt.friends[i]);
    }

    this->initiate(this->nrOfFriends);
}

FriendBook::FriendBook(int cap) // konstruktor
{
    this->nrOfFriends=0;
    this->cap=cap;
    this->friends= new Friend*[this->cap];
    this->owner="";
    this->year=0;
    this->initiate(0);
}

FriendBook::FriendBook(const FriendBook &originalObjekt) //copy konstruktor
{
    this->makeCopy(originalObjekt);
}


FriendBook& FriendBook::operator=(const FriendBook &originalObjekt)
{
    if(this != &originalObjekt)
    {
        this->freeMemory();
        this->makeCopy(originalObjekt);
    }

    return *this;
}


FriendBook::~FriendBook()
{
    this->freeMemory();
    this->nrOfFriends=0;
}
















