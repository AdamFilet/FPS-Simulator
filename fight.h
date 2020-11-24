#pragma once
#include "Team.h"
#include "weapon.h"
#include "Player.h"

class Fight
{
private:
	std::vector<Player*> _attackers;
	std::vector<Player*> _defenders;
	class GameManager* _gameManager;


public:
	Fight(Player& one, Player& two, GameManager* gameManager);

	void AddAttacker(Player& newAttacker);

	void AddDefender(Player& newDefender);

	int32_t FighterCount();

	void StartFight();

private:
	void handleFight(Player& attacker, Player& defender);
	void plantBomb(Player& planter);
	void defuseBomb(Player& defuser);
	void oneSidedFight(Player& fighter, Player& defuserOrPlanter);

};