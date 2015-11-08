#include <iostream>
#include <string>
#include <stdlib.h>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	Game game = Game("game.txt");
	//pin-self kill pin-enenmy
	//pin-self add name
	
	if (argv[2] == "login")
	{
		int p = atoi(argv[1]);
		for (int i = 0; i < game.getPlayerList().size(); ++i)
		{
			if (p == (*game.getPlayerList().at(i)).getPin())
			{
				cout << (*(*game.getPlayerList().at(i)).getTarget()).getName() << endl;

			}
		}
	}
	else if (argv[2] == "add")
	{
		string name = argv[3];
		Player* p = new Player(name, true, 0, game.randomGen());
		game.addPlayer(p);

		
	}
	else if (argv[2] == "kill")
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

	/*switch(argv[2]) {
		case static_cast<char*>("new"):
			 Register this player
		game.addPlayer(new string(argv[3]),"",1,0,randPin());
			break;
		case static_cast<char*>("login"):
			 Cout the player's target
	
			break;
		case static_cast<char*>("kill"):
			 argv[1] is the killer's pin
			 argv[2] is the target's pin
			break;
		default:
			 Something went horribly wrong...
			return -1;*/
	//}
	
	
	
	// cout << "Welcome to Assassins Game Manager" << endl;
	// cout << "Please Pin" << endl;
	// string gameName;
	// cin >> gameName;
	return 0;
	}
	
	

