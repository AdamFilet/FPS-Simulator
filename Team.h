#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "config.h"
#include <string>
#include "weapon.h"

class Team
{
private:
	std::vector<Player> _players;
	bool _isAttacking;

public:
	Team(int playerCount, bool isAttacking);

	void SwitchSide();

	bool IsAttacking();

	bool IsDefending();
	
	bool IsTeamDead();

	std::vector<Player*> GetEligiblePlayers();

	std::vector<Player>& GetAllPlayers();

	void ResetAmmo();

	void ResetRoundDamage();

	void ResetHealth();

	void ResetRoundKillsAndDeaths();

	std::vector<std::string> GetTeamsWeapons();

	std::vector<std::string> GetPlayersNames();

	std::vector<int32_t> GetPlayersDeaths();

	std::vector<int32_t> GetPlayersKills();

	std::vector<int32_t> GetPlayerRoundKill();

	std::vector<int32_t> GetPlayerRounDeaths();

	std::vector<int32_t> GetPlayersRoundDamage();

	std::vector<int32_t> GetPlayersTotalDamage();
	
	std::vector<int32_t> GetPlayersScore();

	std::vector<int32_t> GetPlayersPlants();

	std::vector<int32_t> GetPlayDefuses();
};