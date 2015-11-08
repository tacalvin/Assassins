#pragma once
#include<iostream>
#include<string>
using namespace std;


class Player
{
	private:
	string name;
	string email;
	bool status;
	int kills;
	int pin;
	Player* target;
	Player* killer;
	Player* self = this;

	public:
	Player(string name, string email, bool status, int kills, int pin);
	bool getStatus();
	int getPin();
	int getKills();
	Player* getTarget();
	Player* getKiller();
	void addAssassins(Player* killer, Player* target);
	void kill(int pin, Player* killer, Player* target);
	Player* die(int pin, Player* killer);
	


};


