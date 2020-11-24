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
	_kills = 0;
	_assist = 0;
	_death = 0;
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

int Player::GetInitialHealth()
{
	return _initialHealth;
}

int Player::GetCurrentHealth()
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

int Player::GetSkillLevel()
{
	_skill = rand() % 5 + 1;
	return _skill;
}

int Player::GetPriorityLevel()
{
	_priority = rand() % 10 + 1;
	return _priority;
}

int Player::GetScore()
{
	return _score;
}

int Player::GetCurrentAmmo()
{
	return _weapon.GetAmmo();
}

WeaponsTypes Player::GetPlayerWeapon()
{
	return _weapon.GetWeapon();
}

int Player::GetPlayerWeaponAccuracy()
{
	return _weapon.GetWeaponAccuracy();
}

int Player::GetPlayerWeaponDamage()
{
	int32_t weaponDamageAdjust = rand() % RANDOM_DAMAGE_ADJUST;
	return _weapon.GetWeaponDamage() - weaponDamageAdjust;
}

int Player::GetBulletShots()
{
	return _magazineCapacity - GetCurrentAmmo();
}

void Player::ShotBullet()
{
	_weapon.ShotingBullets();
}

int Player::GetBulletHits()
{

	return 0;
}

void Player::TriggeredKill()
{
	_score += 100;
	_kills++;
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
	_death++;
}

void Player::Assisted()
{
	_score += 50;
	_assist++;
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

int Player::GetKills()
{
	return _kills;
}

int Player::GetAssist()
{
	return _assist;
}

int Player::GetDeath()
{
	return _death;
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

int Player::GetPlants()
{
	return _amountOfPlants;
}

int Player::GetDefuses()
{
	return _amountOfDefuses;
}

int Player::GetTotalGameDamage()
{
	return _totalGameDamage;
}

int Player::GetRoundDamage()
{
	return _totalRoundDamage;
}