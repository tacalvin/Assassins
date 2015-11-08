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
	void loadSession(string sessionName);
	void addPlayer(Player pl);
	~Game();

	private:
	vector<Player*> PlayerList;
};

