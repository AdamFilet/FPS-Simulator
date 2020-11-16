#pragma once
#include <iostream>
#include "weapon.h"

class Player
{
private:
    class Team* _team;

    Weapon _weapon;
    uint32_t _magazineCapacity = _weapon.InitialCapacity();
    int32_t _initialHealth = 100;
    int32_t _currentHealth = 100;
    int32_t _skill = 0;
    int32_t _priority = 0;
    int32_t _score = 0;
    uint32_t _kills = 0;
    uint32_t _assist = 0;
    uint32_t _death = 0;
    uint32_t _amountOfPlants = 0;
    uint32_t _amountOfDefuses = 0;
    std::string _name;

public:

    Player(std::string name, class Team* team);

    /* Logic Functions */
    void DamageHealth(int32_t damage);
    void ShotBullet();
    void IncrementDeaths();
    void ResetAmmo();
    void ResetHealth();
    void IncrementPlants();
    void IncrementDefuses();
    void TriggeredKill();
    void Assisted();

    /* Player Stat Getters */
    int GetScore();
    int GetCurrentHealth();
    int GetInitialHealth();
    int GetPriorityLevel();
    int GetSkillLevel();

    /* Weapon Getters */
    int GetPlayerWeapon();
    int GetPlayerWeaponAccuracy();
    int GetPlayerWeaponDamage();
    int GetCurrentAmmo();

    /* Stat Getters */
    int GetBulletShots();
    int GetBulletHits();
    int GetKills();
    int GetAssist();
    int GetDeath();
    int GetPlants();
    int GetDefuses();
    std::string GetName();

    /* Checkers */
    bool IsAlive();
    bool IsDead();
    bool IsAttacking();
    bool HasDefuser();

    /* Uncategorizable with current names */
};