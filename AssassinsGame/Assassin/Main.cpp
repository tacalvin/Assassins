#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	Game game = Game("game.txt");
	//pin-self kill pin-enenmy
	//pin-self add name
	cout << argv[0] << endl;
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << argv[3] << endl;
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
	
	

