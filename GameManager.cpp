#include <iostream> 
#include "GameManager.h" 

GameManager::GameManager() :_team1(PLAYERS_PER_TEAM, true), _team2(PLAYERS_PER_TEAM, false)
{
	_team1Score = 0;
	_team2Score = 0;
	_roundCount = 0;
	_isPlanted = false;
	_isDefused = false;
	_fightsSincePlanted = 0;
}

void GameManager::nextRound()
{

}

bool GameManager::IsRoundOver() // Check why the round isnt over after all the defenders are dead 
{
	if (_team1.IsTeamDead())
	{
		_team2Score++;
		std::cout << "Team 1 is all dead" << std::endl;
		return true;
	}

	if (_team2.IsTeamDead())
	{
		_team1Score++;
		std::cout << "Team 2 is all dead" << std::endl;
		return true;
	}

	if (_fightsSincePlanted == DEFUSE_TIME)
	{
		if (!_team1.IsAttacking())
		{
			_team1Score++;
			std::cout << "Team 1 has planted" << std::endl;
			return true;
		}
		else
		{
			_team2Score++;
			std::cout << "Team 2 has planted" << std::endl;
			return true;
		}
	}

	if (_isDefused)
	{
		if (_team1.IsAttacking())
		{
			_team1Score++;
			std::cout << "Team 1 has defused" << std::endl;
			return true;
		}
		else
		{
			_team2Score++;
			std::cout << "Team 2 has defused" << std::endl;
			return true;
		}
	}
	return false;
}

void GameManager::Matchmake()
{
	std::vector<Player*> eligibleFighters1 = _team1.GetEligiblePlayers();
	std::vector<Player*> eligibleFighters2 = _team2.GetEligiblePlayers();

	while (eligibleFighters1.size() != 0 && eligibleFighters2.size() != 0)
	{
		int32_t i = rand() % eligibleFighters1.size();
		int32_t i2 = rand() % eligibleFighters2.size(); // Problems occurs here
		Player* p1 = eligibleFighters1.at(i);
		Player* p2 = eligibleFighters2.at(i2);

		Fight tempFight = Fight(*p1, *p2, this);
		_fights.push_back(tempFight);

		eligibleFighters1.erase(eligibleFighters1.begin() + i);
		eligibleFighters2.erase(eligibleFighters2.begin() + i2);

	}

	//TODO: Team might need to be referenced  
	handleExtraPlayers(_team1, eligibleFighters1);
	handleExtraPlayers(_team2, eligibleFighters2);
	_roundCount++;
}

bool GameManager::IsPlanted()
{
	return _isPlanted;
}

bool GameManager::IsDefused()
{
	return _isDefused;
}

void GameManager::BombPlanted()
{
	_isPlanted = true;
}

void GameManager::BombDefused()
{
	_isDefused = true;
}

void GameManager::ResetRound()
{
	_fightsSincePlanted = 0;
	_isDefused = false;
	_isPlanted = false;

	_team1.ResetHealth();
	_team2.ResetHealth();
	_team1.ResetRoundDamage();
	_team2.ResetRoundDamage();
}

void GameManager::handleExtraPlayers(Team& team, std::vector<Player*> eligibleFighters)
{
	for (Player* currentFighter : eligibleFighters)
	{
		for (Fight& currentFight : _fights)
		{
			if (currentFight.FighterCount() == 2)
			{
				int32_t chanceOfMatch = rand() % 100;
				if (chanceOfMatch <= CHANCE_TO_JOIN_EXISTING_MATCH)
				{
					if (team.IsAttacking())
					{
						currentFight.AddAttacker(*currentFighter);
					}
					else
					{
						currentFight.AddDefender(*currentFighter);
					}
					break;
				}
			}
		}
	}
}

void GameManager::SimulateRound()
{
	ResetRound();
	while (!IsRoundOver())
	{
		Matchmake();
		StartFights();
		if (_isPlanted)
		{
			_fightsSincePlanted++;
		}
	}
}

void GameManager::StartFights()
{
	_team1.ResetAmmo();
	_team2.ResetAmmo();
	for (Fight& fight : _fights)
	{
		fight.StartFight();
	}
}

void GameManager::Teams()
{

}

bool GameManager::IsGameOver()
{
	return _team1Score == 16 || _team2Score == 16;
}

int GameManager::Score()
{

	return 0;
}

void GameManager::PrintScore()
{
	std::cout << "Team 1 score: " << _team1Score << std::endl;
	std::cout << "Team 2 score: " << _team2Score << std::endl;
	std::cout << std::endl;
}

void GameManager::SwitchSides()
{
	_team1.SwitchSide();
	_team2.SwitchSide();
}

void GameManager::addTeam1Score()
{
	_team1Score++;
}

void GameManager::addTeam2Score()
{
	_team2Score++;
}

void GameManager::PrintStats()
{
	std::cout << 
}

void GameManager::PrintRoundStats()
{

}