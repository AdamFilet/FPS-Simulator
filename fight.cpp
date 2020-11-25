#include "fight.h"
#include "GameManager.h"

Fight::Fight(Player& one, Player& two, GameManager* gameManager)
{
	_gameManager = gameManager;
	if (one.IsAttacking())
	{
		_attackers.push_back(&one);
		_defenders.push_back(&two);
	}
	else
	{
		_defenders.push_back(&two);
		_attackers.push_back(&one);
	}
}

int32_t Fight::FighterCount()
{
	return _attackers.size() + _defenders.size();
}

void Fight::AddAttacker(Player& NewAttacker)
{
	_attackers.push_back(&NewAttacker);
}

void Fight::AddDefender(Player& NewDefender)
{
	_defenders.push_back(&NewDefender);
}

void Fight::StartFight()
{
	int32_t numOfAttackers = _attackers.size();
	int32_t numOfDefenders = _defenders.size();

	if (numOfAttackers < numOfDefenders) 
	{
		Player& attacker = *_attackers.at(0);
		Player& defender = *_defenders.at(0);
		Player& defuser = *_defenders.at(1);
			
		int32_t chanceToFindDefuser = rand() % 100;

		if (chanceToFindDefuser <= CHANCE_TO_FIND_DEFUSER)
		{
			oneSidedFight(attacker, defuser);
			handleFight(attacker, defender);
			if (_gameManager->IsPlanted() && !defuser.IsDead())
			{
				defuseBomb(defuser);
			}
		}
		else
		{
			handleFight(attacker, defender);
			if (_gameManager->IsPlanted() && !defuser.IsDead())
			{
				defuseBomb(defuser);
			}
		}
	}
	else if (numOfDefenders < numOfAttackers)
	{
		Player& attacker = *_attackers.at(0); 
		Player& planter = *_attackers.at(1);
		Player& defender = *_defenders.at(0);

		int32_t chanceToFindPlanter = rand() % 100;

		if (chanceToFindPlanter <= CHANCE_TO_FIND_PLANTER)
		{
			oneSidedFight(defender, planter);
			handleFight(attacker, defender);
			if (!_gameManager->IsPlanted() && !planter.IsDead()) 
			{
				plantBomb(planter);
			}
		}
		else
		{
			handleFight(attacker, defender);
			if (!_gameManager->IsPlanted() && !planter.IsDead())
			{
				plantBomb(planter);
			}
		}

	}
	else
	{
		Player& defender = *_defenders.at(0);
		Player& attacker = *_attackers.at(0);
		handleFight(attacker, defender);
	}
}

void Fight::handleFight(Player& attacker, Player& defender) 
{
	while (attacker.IsAlive() && defender.IsAlive())
	{
		int32_t attackerAmmo = attacker.GetCurrentAmmo();
		int32_t attackerAccuracy = attacker.GetPlayerWeaponAccuracy();
		int32_t attackerChanceShootFirst = rand() % 100;

		int32_t defenderAmmo = defender.GetCurrentAmmo();
		int32_t defenderAccuracy = defender.GetPlayerWeaponAccuracy();

		if (attackerChanceShootFirst <= CHANCE_TO_SHOOT_FIRST && attackerAmmo != 0)
		{
			int32_t bulletsToShoot = 3;
			if (attackerAmmo < bulletsToShoot)
			{
				bulletsToShoot = attackerAmmo;
			}

			if (defenderAmmo == 0 && attackerAmmo > 0)
			{
				bulletsToShoot = attackerAmmo;
			} 

			for (int i = bulletsToShoot; i > 0; i--)
			{
				int32_t attackerDamange = attacker.GetPlayerWeaponDamage();
				int32_t randomizeAttackerAccuracy = rand() % 100;

				if (randomizeAttackerAccuracy <= attackerAccuracy)
				{
					defender.DamageHealth(attackerDamange);
					attacker.IncrementDamageDone(attackerDamange);
				}
				attacker.ShotBullet();
				if (defender.IsDead())
				{
					std::cout << "[T" << attacker.IsAttacking() << "] " << attacker.GetName();
					std::cout << "  Killed ------> " << "[T" << defender.IsAttacking();
					std::cout << "] " << defender.GetName() << std::endl;
					defender.IncrementDeaths();
					attacker.TriggeredKill();
					break;
				}
			}
		}
		else if(attackerChanceShootFirst >= CHANCE_TO_SHOOT_FIRST && defenderAmmo != 0) 
		{
			int32_t bulletsToShoot = 3;
			if (defenderAmmo <= bulletsToShoot)
			{
				bulletsToShoot = defenderAmmo;
			}

			if (attackerAmmo == 0 && 0 < defenderAmmo)
			{
				bulletsToShoot = defenderAmmo;
			}

			for (int i = bulletsToShoot; i > 0; i--)
			{
				int32_t defenderDamage = defender.GetPlayerWeaponDamage(); 
				int32_t randomizeDefenderAccuracy = rand() % 100;	
				if (randomizeDefenderAccuracy <= defenderAccuracy)
				{
					attacker.DamageHealth(defenderDamage); 
					defender.IncrementDamageDone(defenderDamage);
				}
				defender.ShotBullet();
				if (attacker.IsDead())
				{
					std::cout << "[T" << defender.IsAttacking() << "] " << defender.GetName();
					std::cout << "  Killed ------> " << "[T" << attacker.IsAttacking();
					std::cout << "] " << attacker.GetName() << std::endl;
					attacker.IncrementDeaths();
					defender.TriggeredKill(); 
					break;
				}
			}
		}
		else if(defenderAmmo == 0 && attackerAmmo == 0)
		{
			break;
		}
	}
}

void Fight::plantBomb(Player& planter)
{
	int32_t chanceToPlant = rand() % 100;
	if (chanceToPlant <= CHANCE_TO_PLANT_BOMB)
	{
		std::cout << "[T" << planter.IsAttacking() << "] " << planter.GetName() << " Planted bomb!" << std::endl;
		planter.IncrementPlants();
		_gameManager->BombPlanted();
	}
}

void Fight::defuseBomb(Player& defuser)
{
	int32_t chanceToDefuse = rand() % 100;
	if (chanceToDefuse <= CHANCE_TO_DEFUSE_BOMB)
	{
		std::cout << defuser.GetName() << " Defused bomb!" << std::endl;
		defuser.IncrementDefuses();
		_gameManager->BombDefused();
	}
}

void Fight::oneSidedFight(Player& fighter, Player& defuserOrPlanter)
{
	int32_t fighterAccuracy = fighter.GetPlayerWeaponAccuracy();

	while (fighter.GetCurrentAmmo() != 0)
	{
		int32_t randomizeAccuracy = rand() % 100;
		int32_t fighterDamage = fighter.GetPlayerWeaponDamage();
		if (randomizeAccuracy <= fighterAccuracy)
		{
			defuserOrPlanter.DamageHealth(fighterDamage);
			fighter.IncrementDamageDone(fighterDamage);
		}
		fighter.ShotBullet();
		if(defuserOrPlanter.IsDead())
		{
			std::cout << "[T" << fighter.IsAttacking() << "] " << fighter.GetName();
			std::cout << "  Killed ------> " << "[T" << defuserOrPlanter.IsAttacking();
			std::cout << "] " << defuserOrPlanter.GetName() << std::endl;
			fighter.TriggeredKill();
			defuserOrPlanter.IncrementDeaths();
			break;
		}
	}
}