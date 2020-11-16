#include "Team.h"

Team::Team(int playerCount, bool isAttacking)
{
	_isAttacking = isAttacking;
	
	for (int i = 0; i < playerCount; i++)
	{
		std::string name = "Player " + std::to_string(i);
		_players.push_back(Player(name, this));
	}
}

bool Team::IsAttacking()
{
	return _isAttacking; 
}

bool Team::IsDefending()
{
	return !_isAttacking;
}

void Team::SwitchSide()
{
	_isAttacking = !_isAttacking;
}

bool Team::IsTeamDead() // No one is every dying, unknown why
{
	for (int i = 0; i < _players.size(); i++)
	{
		Player player = _players.at(i);
		if (player.IsAlive())
		{
			return false; 
		}
	}
	return true;
}

std::vector<Player> Team::GetEligiblePlayers()
{
	std::vector<Player> EligiblePlayers;
	for (int i = 0; i < _players.size(); i++)
	{
		Player temp = _players.at(i);
		if (temp.IsAlive())
		{
			EligiblePlayers.push_back(temp);
		}
	}
	return EligiblePlayers;
}

std::vector<Player> Team::GetAllPlayers()
{
	return _players;
}

void Team::ResetAmmo()
{
	for (int i = 0; i < _players.size(); i++)
	{
		_players.at(i).ResetAmmo();
	}
}

void Team::ResetHealth()
{
	for (int i = 0; i < _players.size(); i++)
	{
		_players.at(i).ResetHealth();
	}
}

std::vector<int32_t> Team::GetTeamsWeapons()
{
	std::vector<int32_t> playersWeapons;
	for (int i = 0; i < _players.size(); i++)
	{
		int32_t weapon = _players.at(i).GetPlayerWeapon();
		playersWeapons.push_back(weapon);
	}
	return playersWeapons; // Dont know if this will work, maybe because each weapon is just a value
}


