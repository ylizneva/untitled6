//
// Created by Yulia Lizneva on 2017-10-02.
//

#ifndef UNTITLED6_OBJEKTERKLASSERFRIENDS_H
#define UNTITLED6_OBJEKTERKLASSERFRIENDS_H

#include <string>

using namespace std;

//klassdeklaratuion
class ObjekterKlasserFriends
{

    //innebär att det inte är tillgängligt utanför objektet
private:

    //medlemsvariabler, infor som varje Friend-objekt kommer att innehålla men ha sitt eget värde på i
    string name;
    int by;
    string email;

public:
    //innebär att det är tillgängligt utanför objektet
//konstruktorer har till uppgift att skapa objekt, har alltid samma namn som klassen
    ObjekterKlasserFriends(string name, int by, string email);

    ObjekterKlasserFriends(); //default konstarktor, tom parameterlista

    ~ObjekterKlasserFriends(); //destruktor

    // operator överlagning
    bool operator== (const ObjekterKlasserFriends &otherFriend) const; //anropande objekt jämför sig med parameter
    bool operator <(const ObjekterKlasserFriends &otherFriend) const;




    //medlemsfunktioner(konstant medelmfunktion), funktioner som "tillhör" objektet
    //anropas genom punktnotation

    string getName() const; //const innebär att funktionen ej ändrar innehållet i objektet
    //get-funktion för namnet
    int getby() const;
    string getemail() const;

    void setName(string name); //set-funktion för namnet för att ändra det

    int age(int year) const; //berättar och returnerar åldern vid året som ges av year

    string toString() const; //sätter ihop en sträng med info/data som returneras

};


#endif //UNTITLED6_OBJEKTERKLASSERFRIENDS_H
