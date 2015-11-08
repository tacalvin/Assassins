#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	Game game = new Game("game.txt");
	//pin-self kill pin-enenmy
	//pin-self add name

	switch(argv[2]) {
		case "new":
			// Register this player
		game.addPlayer(argv[3],"",1,0,randPin());
			break;
		case "login":
			// Cout the player's target
	
			break;
		case "kill":
			// argv[1] is the killer's pin
			// argv[2] is the target's pin
			break;
		case default:
			// Something went horribly wrong...
			return -1;
	}
	
	
	
	// cout << "Welcome to Assassins Game Manager" << endl;
	// cout << "Please Pin" << endl;
	// string gameName;
	// cin >> gameName;
	return 0;
	}
	
	
}
