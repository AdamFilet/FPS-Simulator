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

void Team::ResetRoundKillsAndDeaths()
{
	for (Player& player : _players)
	{
		player.ResetRoundKillsAndDeaths();
	}
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
		playersDeaths.push_back(playerDeath.GetTotalDeaths());
	}
	return playersDeaths;
}

std::vector<int32_t> Team::GetPlayersKills()
{
	std::vector<int32_t> playerKills;
	for (Player& playerKill : _players)
	{
		playerKills.push_back(playerKill.GetTotalKills());
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

std::vector<int32_t> Team::GetPlayersScore()
{
	std::vector<int32_t> playerScores;
	for (Player& playerScore : _players)
	{
		playerScores.push_back(playerScore.GetScore());
	}
	return playerScores;
}

std::vector<int32_t> Team::GetPlayersPlants()
{
	std::vector<int32_t> playerPlants;
	for (Player& playerPlant : _players)
	{
		playerPlants.push_back(playerPlant.GetPlants());
	}
	return playerPlants;
}

std::vector<int32_t> Team::GetPlayDefuses()
{
	std::vector<int32_t> playerDefuses;
	for (Player& playerDefuse : _players)
	{
		playerDefuses.push_back(playerDefuse.GetDefuses());
	}
	return playerDefuses;
}

std::vector<int32_t> Team::GetPlayerRoundKill()
{
	std::vector<int32_t> playerKills;
	for (Player& playerKill : _players)
	{
		playerKills.push_back(playerKill.GetRoundKills());
	}
	return playerKills;
}

std::vector<int32_t> Team::GetPlayerRounDeaths()
{
	std::vector<int32_t> playerDeaths;
	for (Player& playerDeath : _players)
	{
		playerDeaths.push_back(playerDeath.GetRoundDeaths());
	}
	return playerDeaths;
}
