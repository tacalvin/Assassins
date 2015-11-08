#include "Game.h"
#include <fstream>

using namespace std;




Game::Game(string sessionName)
{
	ifstream game(sessionName + ".txt");
	if(game.fail())
	{
	cout<<"Error Game does not exist please contact system admin"<<endl
	return -1;

	
	}
	loadSession(string sessionName);
}

string Game::createSession(string sessionName)
{	
	return sessionName;
}

//
bool Game::loadSession(string sessionName)
{
	ifstream game(sessionName + ".txt");
	while(
	return false;
}

bool Game::addPlayer(Player pl)
{
	return false;
}


Game::~Game()
{
}
