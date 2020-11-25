#include <iostream> 
#include "GameManager.h" 

GameManager::GameManager() :_team1(PLAYERS_PER_TEAM, true), _team2(PLAYERS_PER_TEAM, false)
{
	_team1Score = 0;
	_team2Score = 0;
	_roundCount = 0;
	_isPlanted = false;
	_isDefused = false;
	t1Won = false;
	t2Won = false;
	_fightsSincePlanted = 0;
}

bool GameManager::IsRoundOver() // Check why the round isnt over after all the defenders are dead 
{
	if (_team1.IsTeamDead())
	{
		_team2Score++;
		t2Won = true;
		return true;
	}

	if (_team2.IsTeamDead())
	{
		_team1Score++;
		t1Won = true;
		return true;
	}

	if (_fightsSincePlanted == DEFUSE_TIME)
	{
		if (!_team1.IsAttacking())
		{
			_team1Score++;
			t1Won = true;
			return true;
		}
		else
		{
			_team2Score++;
			t2Won = true;
			return true;
		}
	}

	if (_isDefused)
	{
		if (_team1.IsAttacking())
		{
			_team1Score++;
			t1Won = true;
			return true;
		}
		else
		{
			_team2Score++;
			t2Won = true;
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
	t1Won = false;
	t2Won = false;
	_team1.ResetHealth();
	_team2.ResetHealth();
	_team1.ResetRoundDamage();
	_team2.ResetRoundDamage();
	_team1.ResetRoundKillsAndDeaths();
	_team2.ResetRoundKillsAndDeaths();
	
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
	std::cout << "Round Feed" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (Fight& fight : _fights)
	{
		fight.StartFight();
	}
	
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
	std::cout << std::endl;
	std::cout << std::setw(5) << "Name" << std::setw(15) << "Score" << std::setw(15) << "Weapon";
	std::cout << std::setw(15) << "Kills" << std::setw(15) << "Deaths" << std::setw(15) << "Damage";
	std::cout << std::setw(15) << "Plants" << std::setw(15) << "Defuses" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "TEAM 1" << std::endl;
	for (Player& player : _team1.GetAllPlayers())
	{
		std::cout << std::setw(5) << player.GetName() << ": ";
		std::cout << std::setw(10) << player.GetScore();
		std::cout << std::setw(14) << player.GetPlayerWeapon();
		std::cout << std::setw(14) << player.GetTotalKills();
		std::cout << std::setw(14) << player.GetTotalDeaths();
		std::cout << std::setw(16) << player.GetTotalGameDamage();
		std::cout << std::setw(15) << player.GetPlants();
		std::cout << std::setw(15) << player.GetDefuses() << std::endl;	
	}
	std::cout << std::endl;
	std::cout << "TEAM 2" << std::endl;
	for (Player& player : _team2.GetAllPlayers())
	{
		std::cout << std::setw(5) << player.GetName() << ": ";
		std::cout << std::setw(10) << player.GetScore();
		std::cout << std::setw(14) << player.GetPlayerWeapon();
		std::cout << std::setw(14) << player.GetTotalKills();
		std::cout << std::setw(14) << player.GetTotalDeaths();
		std::cout << std::setw(16) << player.GetTotalGameDamage();
		std::cout << std::setw(15) << player.GetPlants();
		std::cout << std::setw(15) << player.GetDefuses() << std::endl;
	}
	std::cout << std::endl;
}

//Killfeed by saying who killed who in plant
void GameManager::PrintRoundStats() 
{
	std::cout << std::endl;
	std::cout << std::setw(5) << "Name" << std::setw(15) << "Kills" << std::setw(15);
	std::cout << "Deaths" << std::setw(15) << "Damage" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "TEAM 1" << std::endl;
	for (Player& player: _team1.GetAllPlayers())
	{
		std::cout << std::setw(5) << player.GetName() << ": ";
		std::cout << std::setw(7) << player.GetRoundKills();
		std::cout << std::setw(12) << player.GetRoundDeaths();
		std::cout << std::setw(17) << player.GetRoundDamage() << std::endl;

	}
	std::cout << std::endl;
	std::cout << "TEAM 2" << std::endl;
	for (Player& player : _team2.GetAllPlayers())
	{
		std::cout << std::setw(5) << player.GetName() << ": ";
		std::cout << std::setw(7) << player.GetRoundKills();
		std::cout << std::setw(12) << player.GetRoundDeaths();
		std::cout << std::setw(17) << player.GetRoundDamage() << std::endl;
	}
	if (t1Won)
	{
		std::cout << "TEAM 1 WON!" << std::endl;
	}
	if (t2Won)
	{
		std::cout << "TEAM 2 WON!" << std::endl;
	}
	std::cout << std::endl;
}
