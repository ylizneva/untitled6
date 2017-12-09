//
// Created by Yulia Lizneva on 2017-11-10.
//
//
/*
#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "swedish");
    srand(100);

    Dice aDice(12);
    Dice anotherDice(6);
    Dice aThirdDice(2);

    cout << "Fˆrv‰ntat resultat: 1 1 11 3 11 2 2 11 10 3";

    cout << endl << "Ditt resultat:      ";
    for (int i = 0; i < 10; i++)
    {
        aDice.toss();
        cout << aDice.getCurrentValue() << " ";
    }

    cout <<endl << "Tryck pÂ en tangent fˆr att forts‰tta: "<<endl;
    getchar();
    cout << "Fˆrv‰ntat resultat: 2 4 1 1 6 6 4 5 6 1";

    cout << endl << "Ditt resultat:      ";
    for (int i = 0; i < 10; i++)
    {
        anotherDice.toss();
        cout << anotherDice.getCurrentValue() << " ";
    }

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();
    cout << "Fˆrv‰ntat resultat: 1 2 2 1 2 2 2 1 1 1";

    cout << endl << "Ditt resultat:      ";
    for (int i = 0; i < 10; i++)
    {
        aThirdDice.toss();
        cout << aThirdDice.getCurrentValue() << " ";
    }

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: ";
    getchar();
    return 0;
}
*/


#include "Yatzee.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void testingCopyConstructor(Yatzee theYatzee)
{

    theYatzee.addPlayer("Stina");
    theYatzee.toss();

}

void showProtocols(Yatzee &theYatzee)
{
    for (int i = 0; i < theYatzee.getNrOfPlayers(); i++)
    {
        cout << theYatzee.protocolInfoOfCurrentPlayer() << endl;
        theYatzee.nextPlayersTurn();
        cout << endl;
    }
}

void testingTossing(Yatzee &theYatzee, int n = 3)
{
    int value = rand()%6+1;
    for (int round = 1; round <= n; round++)
    {
        theYatzee.toss();
        theYatzee.toss(value);
        theYatzee.toss(value);
        theYatzee.addResult(value);
        theYatzee.nextPlayersTurn();
        value = rand() % 6 + 1;
        theYatzee.toss();
        theYatzee.toss(value);
        theYatzee.toss(value);
        theYatzee.addResult(value);
        theYatzee.nextPlayersTurn();
        value = rand() % 6 + 1;
    }
}

int main()
{

    srand(100);
    Yatzee aYatzee;

    cout << "--------------------------------------------1----------------------------------------" << endl;

    cout << "Testar kopieringskonstruktorn pÂ objekt utan nÂgra protokoll" << endl;

    cout << "Fˆrv‰ntad utskrift:\nRune ska ha 2 po‰ng pÂ 1:or och 5 po‰ng pÂ 5:or samt summan 7"
        <<"\nLisa ska ha 8 po‰ng pÂ 2:or och 6 poˆng pÂ 6:or samt summan 14"<< endl;
    cout << "Fˆrv‰ntad utskrift:\n";
    cout << "Antalet spelare 2\n\nRune\nLisa\n\n"
         <<"Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =    7\n\n"
         <<"Lisa\n"
         << "1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     :  0\n6     :  6\n"
         << "-------------------\nSUM =   14\n" << endl;


    cout << endl << "Tryck pÂ en tangent för att forts‰tta: " << endl;
    getchar();

    cout <<endl << "Din utskrift: " << endl;
    testingCopyConstructor(aYatzee);



    aYatzee.addPlayer("Rune");
    aYatzee.addPlayer("Lisa");

    cout<<"Antalet spelare: " << aYatzee.getNrOfPlayers() << endl;
    cout << endl;
    for (int i = 0; i < aYatzee.getNrOfPlayers(); i++)
    {
        cout << aYatzee.nameOfCurrentPlayer() << endl;
        aYatzee.nextPlayersTurn();
    }

    cout << endl;

    testingTossing(aYatzee, 2);

    showProtocols(aYatzee);

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    cout << "--------------------------------------------2----------------------------------------" << endl;

    cout << "Testar kopieringskonstruktor pÂ objekt innehÂllande protokoll" << endl;

    cout << "Fˆrv‰ntad utskrift:\n";
    cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =    7\n\n"
         <<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
         << "-------------------\nSUM =   24\n" << endl;
    cout << "Rune\n1     :  2\n2     :   0\n3     : 15\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =   22\n\n"
         <<"Lisa\n1     :  2\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
         << "-------------------\nSUM =   26\n" << endl;


    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    cout << endl << "Din utskrift: " << endl;

    testingCopyConstructor(aYatzee);

    Yatzee xYatzee = aYatzee;
    testingTossing(xYatzee);
    testingTossing(aYatzee, 1);

    showProtocols(aYatzee);
    showProtocols(xYatzee);
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();
    system("cls");
    cout << "--------------------------------------------3----------------------------------------" << endl;

    cout << "Testar tilldelningsoperator mellan objekt som inte innehÂller protokoll och "
         << " objekt som innehÂller protokoll" << endl;

    cout << "Fˆrv‰ntad utskrift:\n";
    cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =    7\n\n"
         <<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
         << "-------------------\nSUM =   24\n" << endl;
    cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =    7\n\n"
         <<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
         << "-------------------\nSUM =   24\n" << endl;


    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    cout << "Din utskrift\n";
    Yatzee anotherYatzee;
    anotherYatzee = aYatzee;

    showProtocols(anotherYatzee);
    showProtocols(aYatzee);
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();
    system("cls");

    cout << "--------------------------------------------4----------------------------------------" << endl;

    cout << "Testar tilldelningsoperatorn mellan tvÂ objekt som innehÂller protokoll" << endl;

    cout << "Fˆrv‰ntad utskrift:\n";
    cout << "Rune\n1     :  2\n2     :  0\n3     :  9\n4     :  8\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =   24\n\n"
         <<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
         << "-------------------\nSUM =   24\n" << endl;
    cout << "Rune\n1     :  2\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =    7\n\n"
         <<"Lisa\n1     :  0\n2     :  8\n3     :  0\n4     :  0\n5     : 10\n6     :  6\n"
         << "-------------------\nSUM =   24\n" << endl;


    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    cout << "Din utskrift:\n";
    testingTossing(anotherYatzee, 4);

    showProtocols(anotherYatzee);
    showProtocols(aYatzee);
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();
    system("cls");

    cout << "--------------------------------------------5----------------------------------------" << endl;

    cout << "Testar tilldelningsoperatorn mellan objekt som innehÂller protokoll"
         << " och objekt som inte innehÂller protokoll" << endl;

    cout << "Fˆrv‰ntad utskrift:\n";
    cout << "Katarina\n1     :  0\n2     :  6\n3     :  9\n4     :  0\n5     :  0\n6     : 18\n"
         << "-------------------\nSUM =   33\n\n"
         <<"Charlotta\n1     :  0\n2     :  0\n3     :  6\n4     :  8\n5     : 10\n6     :  0\n"
         << "-------------------\nSUM =   24\n" << endl;



    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    cout << "Din utskrift\n";


    Yatzee aThirdYatzee;
    aYatzee = aThirdYatzee;

    aYatzee.addPlayer("Katarina");
    aYatzee.addPlayer("Charlotta");
    testingTossing(aYatzee,5);

    showProtocols(aYatzee);

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();
    system("cls");
    cout << "--------------------------------------------6----------------------------------------" << endl;

    cout << "Testar tilldelningsoperatorn mellan tvÂ objekt som inte innehÂller protokoll"<<endl;

    cout << "Fˆrv‰ntad utskrift:\n";
    cout << "Allan\n1     :  0\n2     :  0\n3     :  9\n4     :  0\n5     : 10\n6     :  0\n"
         << "-------------------\nSUM =   19\n\n"
         <<"Britta\n1     :  0\n2     :  6\n3     :  9\n4     :  0\n5     :  0\n6     :  0\n"
         << "-------------------\nSUM =   15\n" << endl;
    cout << "Herbert\n1     :  0\n2     :  6\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
         << "-------------------\nSUM =    6\n\n"
         <<"Hugo\n1     :  0\n2     :  4\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
         << "-------------------\nSUM =   4\n" << endl;
    cout << "Rut\n1     :  0\n2     :  0\n3     :  0\n4     :  0\n5     :  5\n6     :  0\n"
         << "-------------------\nSUM =    5\n\n"
         <<"Bertil\n1     :  0\n2     :  0\n3     :  0\n4     :  0\n5     :  0\n6     :  0\n"
         << "-------------------\nSUM =   0\n" << endl;

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    Yatzee bYatzee(3);
    Yatzee cYatzee;

    cYatzee = bYatzee;

    cYatzee.addPlayer("Allan");
    cYatzee.addPlayer("Britta");
    cYatzee.addPlayer("Herbert");

    testingTossing(cYatzee);
    bYatzee.addPlayer("Bertil");
    bYatzee.addPlayer("Hugo");
    bYatzee.addPlayer("Rut");
    testingTossing(bYatzee,2);

    showProtocols(cYatzee);
    showProtocols(bYatzee);

    cout << "------------------------------------------SLUT---------------------------------------" << endl;

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();
    return 0;
}


/*#include "Protocol.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "swedish");
    Protocol aProtocol("Kalle");
    aProtocol.addResult(1, 5);

    cout << "-------------------------------------------1-----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    cout << "Fˆrv‰ntat resultat: " << endl
         << "Kalle" << endl
         << "1     :  5" << endl
         << "2     :  0" << endl
         << "3     :  0" << endl
         << "4     :  0" << endl
         << "5     :  0" << endl
         << "6     :  0" << endl
         << "-------------------" << endl
         << "SUM =    5" << endl;



    cout << endl << "Ditt resultat: "<<endl;


    cout<< aProtocol.toString() << endl;

    cout << "-------------------------------------------2-----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    cout << "Fˆrv‰ntat resultat: " << endl
         << "Korrekt retur pÂ addResult(...)" << endl;
    cout << endl << "Ditt resultat: " << endl;
    if (!aProtocol.addResult(1, 3))
    {
        cout << "Korrekt retur pÂ addResult(...)" << endl;
    }
    else
    {
        cout << "FEL retur pÂ addResult(...)" << endl;
    }

    cout << "-------------------------------------------3-----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    cout << "Fˆrv‰ntat resultat: " << endl
         << "Kalle" << endl
         << "1     :  5" << endl
         << "2     :  0" << endl
         << "3     :  0" << endl
         << "4     :  0" << endl
         << "5     :  0" << endl
         << "6     :  0" << endl
         << "-------------------" << endl
         << "SUM =    5" << endl;



    cout << endl << "Ditt resultat: " << endl;


    cout << aProtocol.toString() << endl;
    cout << "-------------------------------------------4-----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    for (int i = 2; i <= 6; i++)
    {
        if (i != 4)
        {
            if (i % 2 == 0)
            {
                aProtocol.addResult(i, i * 3);
            }
            else
            {
                aProtocol.addResult(i, i * 2);
            }
            if (i == 5)
            {
                aProtocol.addResult(5, 25);
            }
        }
    }


    cout << "Fˆrv‰ntat resultat: " << endl
         << "Kalle" << endl
         << "1     :  5" << endl
         << "2     :  6" << endl
         << "3     :  6" << endl
         << "4     :  0" << endl
         << "5     : 10" << endl
         << "6     : 18" << endl
         << "-------------------" << endl
         << "SUM =   45" << endl;



    cout << endl << "Ditt resultat: " << endl;


    cout << aProtocol.toString() << endl;

    cout << "-------------------------------------------5-----------------------------------------------" << endl;

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    cout << "Fˆrv‰ntat resultat: " << endl
         << "Korrekt retur pÂ isFilled(...)" << endl;
    cout << endl << "Ditt resultat: " << endl;
    if (!aProtocol.isFilled())
    {
        cout << "Korrekt retur pÂ isFilled(...)" << endl;
    }
    else
    {
        cout << "FEL retur pÂ isFilled(...)" << endl;
    }

    cout << "-------------------------------------------6-----------------------------------------------" << endl;

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    cout << "Fˆrv‰ntat resultat: " << endl
         << "Korrekt retur pÂ getSum()" << endl;
    cout << endl << "Ditt resultat: " << endl;
    if (aProtocol.getSum() == 45)
    {
        cout << "Korrekt retur pÂ getSum()" << endl;
    }
    else
    {
        cout << "FEL retur pÂ getSum()" << endl;
    }

    cout << "-------------------------------------------7-----------------------------------------------" << endl;

    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    aProtocol.addResult(4, 20);
    cout << "Fˆrv‰ntat resultat: " << endl
         << "Kalle" << endl
         << "1     :  5" << endl
         << "2     :  6" << endl
         << "3     :  6" << endl
         << "4     : 20" << endl
         << "5     : 10" << endl
         << "6     : 18" << endl
         << "-------------------" << endl
         << "SUM =   65" << endl;



    cout << endl << "Ditt resultat: " << endl;


    cout << aProtocol.toString() << endl;

    cout << "-------------------------------------------8-----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    Protocol anotherProtocol("Pelle");
    anotherProtocol.addResult(6, 12);
    anotherProtocol.addResult(2, 0);
    anotherProtocol.addResult(1, 3);
    anotherProtocol.addResult(5, 10);
    anotherProtocol.addResult(3, 9);
    anotherProtocol.addResult(4, 20);


    cout << "Fˆrv‰ntat resultat: " << endl
         << "Korrekt retur pÂ isFilled()" << endl;
    cout << endl << "Ditt resultat: " << endl;

    if (anotherProtocol.isFilled())
    {
        cout << "Korrekt retur pÂ isFilled()" << endl;
    }
    else
    {
        cout << "FEL retur pÂ isFilled()" << endl;
    }

    cout << "-------------------------------------------9-----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();


    cout << "Fˆrv‰ntat resultat: " << endl
         << "Korrekt retur pÂ getSum()" << endl;
    cout << endl << "Ditt resultat: " << endl;

    if (aProtocol.getSum() > anotherProtocol.getSum())
    {
        cout << "Korrekt retur pÂ getSum()" << endl;
    }
    else
    {
        cout << "FEL retur pÂ getSum()" << endl;
    }

    cout << "-------------------------------------------10----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    cout << "Fˆrv‰ntat resultat: " << endl
         << "Korrekt retur pÂ getPlayerName()" << endl;
    cout << endl << "Ditt resultat: " << endl;

    if (aProtocol.getPlayerName() == "Kalle" && anotherProtocol.getPlayerName() == "Pelle")
    {
        cout << "Korrekt retur pÂ getPlayerName()" << endl;
    }
    else
    {
        cout << "FEL retur pÂ getPlayerName()" << endl;
    }

    cout << "-----------------------------------------SLUT----------------------------------------------" << endl;
    cout << endl << "Tryck pÂ en tangent fˆr att forts‰tta: " << endl;
    getchar();

    return 0;
}*/