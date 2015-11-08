#include "Game.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<ctime>
using namespace std;




Game::Game(string sessionName)
{
	srand(time(0));

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


void Game::loadSession(string sessionName, int flag)
{
	//if flag == 1 game has started therefore text files have targets and killers

	ifstream game(sessionName);
	if (flag == 0)
	{
		while (!game.eof())
		{
			string name;
			getline(game, name, ',');

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

			Player* p = new Player(name, /*email,*/ stat, kil, piN);
			PlayerList.push_back(p);
		}
	}

	if (flag == 1)
	{
		while (!game.eof())
		{
			string name;
			getline(game, name, ',');

			string status;
			getline(game, status, ',');
			string pin;
			getline(game, pin, ',');
			string kills;
			getline(game, kills, ',');
			string killPin;
			getline(game, killPin, ',');
			string targPin;
			getline(game, targPin, ',');

			std::string::size_type sz;   // alias of size_t

			int kil = atoi(kills.c_str());
			int piN = atoi(pin.c_str());
			int kpin = atoi(killPin.c_str());
			int tpin = atoi(targPin.c_str());
			bool stat = false;
			if (status == "true")
				stat = true;

			Player* p = new Player(name, /*email,*/ stat, kil, piN);
			for (int i = 0; i < PlayerList.size(); ++i)
			{
				if (kpin == (*(*PlayerList.at(i)).getKiller()).getPin())
				{
					for (int j = 0; i < PlayerList.size(); ++j)
					{
						if (tpin == (*(*PlayerList.at(i)).getTarget()).getPin())
						{
							(*p).addAssassins(PlayerList.at(i), PlayerList.at(j));
							break;
						}
					}
					if ((*p).getKiller != nullptr || (*p).getTarget() != nullptr)
						break;
				}
			}
			
			PlayerList.push_back(p);
		}
	}
}

void Game::addPlayer(Player* pl)
{
	PlayerList.push_back((pl));
	
}

vector<Player*> Game::getPlayerList()
{
	return PlayerList;
}

int Game::randomGen()
{
	int pid = rand() % (9999 - 1000) + 1000;
	for (int i = 0; i < PlayerList.size(); ++i)
	{
		if (pid == (*PlayerList.at(i)).getPin())
		{
			pid = rand() % (9999 - 1000) + 1000;
			i = 0;
		}
	}
	return pid;
}


Game::~Game()
{
	cout << "Program Terminated" << endl;
	ifstream game("game.txt");
	
	if (!game.fail())
	{
		ofstream outfile;
		outfile.open("game.txt");
		for (int i = 0; i < PlayerList.size(); ++i)
		{
			outfile << (*PlayerList.at(i)).getName() << ",";
			if ((*PlayerList.at(i)).getStatus())
				outfile << "true" << ",";
			else
				outfile << "false" << ",";
			outfile << (*PlayerList.at(i)).getPin() << ",";
			outfile << (*PlayerList.at(i)).getKills() << ",";

			outfile << (*(*PlayerList.at(i)).getKiller()).getPin() << ",";
			outfile << (*(*PlayerList.at(i)).getTarget()).getPin() << ",";
			//killer then target

		}
		outfile.close();
	}

}

void Game::targetSetup()
{
	vector<bool> set = *new vector < bool>(PlayerList.size());

	for (int i = 0; i < PlayerList.size(); ++i)
	{
		if (i != 0 && i != PlayerList.size())
		(*PlayerList.at(i)).addAssassins(PlayerList.at(i - 1), PlayerList.at(i + 1));

		else if(i==0)
			(*PlayerList.at(i)).addAssassins(PlayerList.at(PlayerList.size()-1), PlayerList.at(i + 1));
		else if(i == PlayerList.size()-1)
			(*PlayerList.at(i)).addAssassins(PlayerList.at(PlayerList.size() - 2), PlayerList.at(0));
	}

}
