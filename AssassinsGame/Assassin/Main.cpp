#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	Game game = Game("game.txt");
	//pin-self kill pin-enenmy
	//pin-self add name
	
	string arg = argv[2];
	if (arg == "start")
	{
		game.targetSetup();
		cout << "Works" << endl;
		ofstream started;
		started.open("started.txt");
		started << "Game started" << endl;
		started.close();
	}
	else if (arg == "login")
	{
		ifstream start("started");
		if (!start.fail())
		{
			int p = atoi(argv[1]);
			for (int i = 0; i < game.getPlayerList().size(); ++i)
			{
				if (p == (*game.getPlayerList().at(i)).getPin())
				{
					if ((*game.getPlayerList().at(i)).getTarget() != nullptr)
						cout << (*(*game.getPlayerList().at(i)).getTarget()).getName() << endl;

					else
						cout << "Game has not started" << endl;

				}
			}
		}
		else
	
			cout << "Game has not started" << endl;
	}
	else if (arg == "add")
	{
		string name = argv[3];
		cout << "reached" << endl;
		int pin = game.randomGen();
		cout << "reached" << endl;
		cout << pin << endl;
		cout << "reached" << endl;
		Player* p = new Player(name, true, 0, pin);
		cout << "reached" << endl;
		game.addPlayer(p);
		cout << "reached" << endl;

		
	}
	
	else if (arg == "kill")
	{
		int p = atoi(argv[1]);
		for (int i = 0; i < game.getPlayerList().size(); ++i)
		{
			if (p == (*game.getPlayerList().at(i)).getPin())
			{
				Player* target = (*game.getPlayerList().at(i)).getTarget();
				(*game.getPlayerList().at(i)).kill(p, target);

			}
		}
	}



	
	return 0;
}
