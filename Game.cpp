//
// Created by Yulia Lizneva on 2017-11-12.
//

#include "Yatzee.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int nrOfPlayers=0;
	string name="";
    int dice=-1;


    //Skapa ett Yatzee-objekt baserat pÂ nrOfPlayers
	cout << "How many players? ";
	cin >> nrOfPlayers; cin.ignore();

    Yatzee game(nrOfPlayers);


    //LÂt anv‰ndaren mata in namnen pÂ spelarna och l‰gg till spelarna till Yatzee-objektet
	for(int i=0; i<nrOfPlayers; i++)
    {
        cout<<i+1<<" name: "<<endl;
        getline(cin, name);
        game.addPlayer(name);

    }


	//SÂ l‰nge som inte alla spelare har spelat klart

    while(!game.allPlayersDone())
    {
        bool isDone = false;
        //Presentera protokollet fˆr aktuell spelare
       cout<<game.protocolInfoOfCurrentPlayer()<<endl;
        //Kasta en omgÂng t‰rningar
        game.toss();

        //Upprepa 2 gÂnger
        for(int i=0; i<2; i++)
        {


        //Visa t‰rningarnas utfall
       cout<< game.infoOfLatestToss()<<endl;


        //LÂt anv‰ndaren mata in vilket t‰rningsv‰rde som ska sparas
        cout<<"Choose dice value:"<<endl;
        cin>>dice; cin.ignore();
        //Kasta alla ˆvriga t‰rningar
        game.toss(dice);


        }

        //Visa t‰rningarnas utfall
        cout<<game.infoOfLatestToss()<<endl;

        //LÂt anv‰ndaren mata in vilket t‰rningsv‰rde resultatet ska sparas pÂ
        cout<<"Which result do you wanna save: "<<endl;
        cin>>dice; cin.ignore();

        isDone = game.addResult(dice);



//SÂ l‰nge som t‰rningsv‰rdet redan ‰r ifyllt

        while(!isDone)
        {
            //LÂt anv‰ndaren mata in vilket t‰rningsv‰rde resultatet ska sparas pÂ
            cout<<"You have already selected this value, choose another one: "<<endl;
            cin>>dice; cin.ignore();
            if(game.addResult(dice))
            {
                isDone=true;

            }

        }


		//Presentera protokollkolumnen fˆr aktuell spelare

        cout<<game.protocolInfoOfCurrentPlayer()<<endl;

		//N‰sta spelares tur
        game.nextPlayersTurn();
    }
		//Rensa sk‰rmen och pausa
    //system("cls");
   // system("pause");

	//Presentera protokollkolumnen och totalsumman fˆr varje spelare
    for(int i=0; i<nrOfPlayers; i++)
    {
        game.nextPlayersTurn();
        cout<<game.protocolInfoOfCurrentPlayer()<<endl;
    }

    //system("pause");
	return 0;
}