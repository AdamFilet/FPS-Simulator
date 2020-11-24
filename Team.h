#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "config.h"

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

	std::vector<int32_t> GetTeamsWeapons();
};