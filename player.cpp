#include "Player.h"
#include "Team.h"

Player::Player(std::string name, Team* team) 
{
	_magazineCapacity = _weapon.InitialCapacity();
	_initialHealth = 100;
	_currentHealth = 100;
	_skill = 0;
	_priority = 0;
	_score = 0;
	_totalKills = 0;
	_totalDeaths = 0;
	_roundKills = 0;
	_roundDeaths = 0;
	_amountOfPlants = 0;
	_amountOfDefuses = 0;
	_name = name;
	_team = team;
	_totalRoundDamage = 0;
	_totalGameDamage = 0;
}

std::string Player::GetName()
{
	return _name;
}

bool Player::IsAttacking()
{
	return _team->IsAttacking();
}

int32_t Player::GetInitialHealth()
{
	return _initialHealth;
}

int32_t Player::GetCurrentHealth()
{
	return _currentHealth;
}

void Player::DamageHealth(int32_t damage)
{
	_currentHealth -= damage;
	if (_currentHealth < 0)
	{
		_currentHealth = 0;
	}
}

int32_t Player::GetSkillLevel()
{
	_skill = rand() % 5 + 1;
	return _skill;
}

int32_t Player::GetPriorityLevel()
{
	_priority = rand() % 10 + 1;
	return _priority;
}

int32_t Player::GetScore()
{
	return _score;
}

int32_t Player::GetCurrentAmmo()
{
	return _weapon.GetAmmo();
}

std::string Player::GetPlayerWeapon()
{
	return _weapon.GetWeaponName();
}

int32_t Player::GetPlayerWeaponAccuracy()
{
	return _weapon.GetWeaponAccuracy();
}

int32_t Player::GetPlayerWeaponDamage()
{
	int32_t weaponDamageAdjust = rand() % RANDOM_DAMAGE_ADJUST;
	return _weapon.GetWeaponDamage() - weaponDamageAdjust;
}

int32_t Player::GetBulletShots()
{
	return _magazineCapacity - GetCurrentAmmo();
}

void Player::ShotBullet()
{
	_weapon.ShotingBullets();
}

int32_t Player::GetBulletHits()
{

	return 0;
}

void Player::TriggeredKill()
{
	_score += 100;
	_totalKills++;
	_roundKills++;
}

void Player::ResetRoundKillsAndDeaths()
{
	_roundKills = 0;
	_roundDeaths = 0;
}

bool Player::IsAlive()
{
	if (_currentHealth <= 0)
	{
		return false;
	}
	return true;
}

bool Player::IsDead()
{
	return !IsAlive(); 
}

void Player::IncrementDeaths()
{
	_roundDeaths++;
	_totalDeaths++;
}

void Player::ResetRoundDamage()
{
	_totalRoundDamage = 0;
}

void Player::IncrementDamageDone(int32_t damage)
{
	_totalGameDamage += damage;
	_totalRoundDamage += damage;
}

int32_t Player::GetTotalKills()
{
	return _totalKills;
}


int32_t Player::GetTotalDeaths()
{
	return _totalDeaths;
}

bool Player::HasDefuser()
{
	return true;
}

void Player::ResetAmmo()
{
	_weapon.ResetAmmo();
}

void Player::ResetHealth()
{
	_currentHealth = _initialHealth;
}

void Player::IncrementPlants()
{
	_score += 100;
	_amountOfPlants++;
}

void Player::IncrementDefuses()
{
	_score += 100;
	_amountOfDefuses++;
}

int32_t Player::GetPlants()
{
	return _amountOfPlants;
}

int32_t Player::GetDefuses()
{
	return _amountOfDefuses;
}

int32_t Player::GetTotalGameDamage()
{
	return _totalGameDamage;
}

int32_t Player::GetRoundDamage()
{
	return _totalRoundDamage;
}

int32_t Player::GetRoundKills()
{
	return _roundKills;
}

int32_t Player::GetRoundDeaths()
{
	return _roundDeaths;
}
