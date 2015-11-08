#include "Game.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;




Game::Game(string sessionName)
{
	ifstream game(sessionName);
	if(game.fail())
	{
		cout << "Error Game does not exist please contact system admin" << endl;
	
	}

	loadSession( sessionName);
}

string Game::createSession(string sessionName)
{	
	return sessionName;
}

//
void Game::loadSession(string sessionName)
{
	ifstream game(sessionName + ".txt");
	while (!game.eof())
	{
		string name;
		getline(game, name, ',');
		string email;
		getline(game, email, ',');
		string status;
		getline(game, status, ',');
		string pin;
		getline(game, pin, ',');
		string kills;
		getline(game, kills, ',');

		std::string::size_type sz;   // alias of size_t

		int kil = atoi(kills.c_str());
		int piN = atoi(pin.c_str());
		bool stat = false;
		if (status == "true")
			stat = true;
			
		Player* p = new Player(name, email, stat, kil, piN);
		PlayerList.push_back(p);
	}
	
}

void Game::addPlayer(Player pl)
{
	PlayerList.push_back((&pl));
	
}


Game::~Game()
{
}
