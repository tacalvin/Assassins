#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Player.h"
using namespace std;
class Game
{
	public:
	Game(string);
	string createSession(string sessionName);
	bool loadSession(string sessionName);
	bool addPlayer(Player pl);
	~Game();

	private:
	vector<Player> PlayerList;
};

