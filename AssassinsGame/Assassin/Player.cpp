#include "Player.h"



Player::Player( bool status, int kills, int pin)
{
	
	(*this).status = status;
	(*this).kills = kills;
	(*this).pin = pin;
}

bool Player::getStatus()
{
	return status;
}

int Player::getPin()
{
	return pin;
}

int Player::getKills()
{
	return kills;
}

Player * Player::getTarget()
{
	return target;
}

Player * Player::getKiller()
{
	return killer;
}

void Player::addAssassins(Player* killer, Player* target)
{
	
	(*this).target = target;
	(*this).killer = killer;
}

Player* Player::die(int playerpin, Player* actingkiller)
{
	if (pin == playerpin && (*this).getKiller() == actingkiller)
	{
		(*this).status = false;
		
		cout << "Player Killed" << endl;
		return (*this).getTarget();
	}

	else
		cout << "error invalid kill" << endl;
}

void Player::kill(int pin, Player* killer, Player* target)
{	
	
	if ((*killer).getStatus())
	{
		cout << "Checking kill" << endl;
		(*target).die(pin, killer);
		
	}
}



