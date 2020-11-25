#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Team.h"
#include "weapon.h"
#include "config.h"
#include "fight.h"
#include <iomanip>

class GameManager
{
private:
	std::vector<Fight> _fights;
	Team _team1;
	Team _team2;
	int32_t _team1Score;
	int32_t _team2Score;
	int32_t _roundCount;
	bool _isPlanted;
	bool _isDefused;
	bool t1Won;
	bool t2Won;
	int32_t _fightsSincePlanted;


public:
	GameManager();

	bool IsRoundOver();

	void Matchmake();

	void SimulateRound();

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

	void PrintStats();

	void PrintRoundStats();

private:
	void handleExtraPlayers(Team& team, std::vector<Player*> eligibleFighters);
	void addTeam1Score();
	void addTeam2Score();

};