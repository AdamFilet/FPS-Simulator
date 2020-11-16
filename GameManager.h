#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Team.h"
#include "weapon.h"
#include "config.h"
#include "fight.h"

class GameManager
{
private:
	std::vector<Fight> _fights;
	Team _team1;
	Team _team2;

	int32_t _team1Score = 0;
	int32_t _team2Score = 0;
	int32_t _roundCount = 0;
	bool _isPlanted = false;
	bool _isDefused = false;
	int32_t _fightsSincePlanted = 0;

private:
	void handleExtraPlayers(Team team, std::vector<Player> eligibleFighters);
	void addTeam1Score();
	void addTeam2Score();
	void nextRound();

public:
	GameManager();

	bool IsRoundOver();

	void Matchmake();

	void SimulateRound();

	void Teams();

	bool IsGameOver();

	int Score();

	void PrintScore();

	void SwitchSides();

	bool IsPlanted();

	bool IsDefused();

	void ResetRound();

	void StartFights();

	void BombPlanted();

	void BombDefused();
};