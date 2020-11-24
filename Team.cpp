#include "Team.h"
// Going to prolly need references for this
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

bool Team::IsTeamDead() 
{
	for (Player& player: _players)
	{
		if (player.IsAlive())
		{
			return false; 
		}
	}
	return true;
}

std::vector<Player*> Team::GetEligiblePlayers()
{
	std::vector<Player*> EligiblePlayers;
	for (Player& tempPlayer : _players)
	{
		if (tempPlayer.IsAlive())
		{
			EligiblePlayers.push_back(&tempPlayer);
		}
	}
	return EligiblePlayers;
}

std::vector<Player>& Team::GetAllPlayers()
{
	return _players;
}

void Team::ResetAmmo()
{
	for (Player& player : _players)
	{
		player.ResetAmmo();
	}
}

void Team::ResetRoundDamage()
{
	for (Player& player : _players)
	{
		player.ResetRoundDamage();
	}
}

void Team::ResetHealth()
{
	for (Player& player : _players)
	{
		player.ResetHealth();
	}
}

std::vector<std::string> Team::GetTeamsWeapons()
{
	std::vector<std::string> playersWeapons;
	for (int i = 0; i < _players.size(); i++)
	{
		WeaponsTypes weapon = _players.at(i).GetPlayerWeapon();
		if (weapon == 0)
		{
			playersWeapons.push_back("R4C");
		}
		else if (weapon == 1)
		{
			playersWeapons.push_back("L85A2");
		}
		else if (weapon == 2)
		{
			playersWeapons.push_back("MPX");
		}
		else if (weapon == 3)
		{
			playersWeapons.push_back("K1A");
		}
		else if (weapon == 4)
		{
			playersWeapons.push_back("GP41");
		}
	}
	return playersWeapons; 
}

std::vector<std::string> Team::GetPlayersNames()
{
	std::vector<std::string> playerNames;
	for (Player& playerName: _players)
	{
		playerNames.push_back(playerName.GetName());
	}
	return playerNames;
}

std::vector<int32_t> Team::GetPlayersDeaths()
{
	std::vector<int32_t> playersDeaths;
	for (Player& playerDeath : _players)
	{
		playersDeaths.push_back(playerDeath.GetDeath());
	}
	return playersDeaths;
}

std::vector<int32_t> Team::GetPlayersKills()
{
	std::vector<int32_t> playerKills;
	for (Player& playerKill : _players)
	{
		playerKills.push_back(playerKill.GetKills());
	}
	return playerKills;
}

std::vector<int32_t> Team::GetPlayersRoundDamage()
{
	std::vector<int32_t> playersDamage;
	for (Player& playerDamage: _players)
	{
		playersDamage.push_back(playerDamage.GetRoundDamage());
	}
	return playersDamage;
}

std::vector<int32_t> Team::GetPlayersTotalDamage()
{
	std::vector<int32_t> playersDamage;
	for (Player& playerDamage : _players)
	{
		playersDamage.push_back(playerDamage.GetTotalGameDamage());
	}
	return playersDamage;
}