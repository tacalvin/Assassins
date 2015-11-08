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
	cout << "generate game" << endl;
	ifstream game(sessionName);
	if(game.fail())
	{
		cout << "Error Game does not exist please contact system admin" << endl;

	
	}
	else
	{
		ifstream started("started.txt");
		if (started.fail())
		{
			loadSession(sessionName, 0);
			cout << "generate game" << endl;
		}
		else
			loadSession(sessionName, 1);
	}

}

string Game::createSession(string sessionName)
{	
	return sessionName;
}


void Game::loadSession(string sessionName, int flag)
{
	//if flag == 1 game has started therefore text files have targets and killers

	ifstream game(sessionName);
	cout << flag << endl;
	if (flag == 0)
	{
		cout << "reached load" << endl;
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

	else if (flag == 1)
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
					if ((*p).getKiller() != nullptr || (*p).getTarget() != nullptr)
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
	ifstream game("started.txt");
	
	if (!game.fail())
	{
		cout << "Saving" << endl;
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
	else
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

				
				//killer then target

			}
			outfile.close();
		
	}

}

void Game::targetSetup()
{
	cout << PlayerList.size() << endl;
	for (int i = 0; i < PlayerList.size(); ++i)
	{
		if (i != 0 && i != PlayerList.size()-2)
		(*PlayerList.at(i)).addAssassins(PlayerList.at(i - 1), PlayerList.at(i + 1));

		else if(i==0)
			(*PlayerList.at(i)).addAssassins(PlayerList.at(PlayerList.size()-1), PlayerList.at(i + 1));
		else if(i == PlayerList.size()-1)
			(*PlayerList.at(i)).addAssassins(PlayerList.at(PlayerList.size() - 2), PlayerList.at(0));
	}

}
