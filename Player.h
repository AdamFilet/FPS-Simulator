#pragma once
#include <iostream>
#include "weapon.h"

class Player
{
private:
    class Team* _team;

    Weapon _weapon;
    uint32_t _magazineCapacity;
    int32_t _initialHealth;
    int32_t _currentHealth;
    int32_t _skill;
    int32_t _priority;
    int32_t _score;
    uint32_t _totalDeaths;
    uint32_t _totalKills;
    uint32_t _roundKills;
    uint32_t _roundDeaths;
    uint32_t _amountOfPlants;
    uint32_t _amountOfDefuses;
    std::string _name;
    uint32_t _totalGameDamage;
    uint32_t _totalRoundDamage;

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
    void ResetRoundDamage();
    void IncrementDamageDone(int32_t damage);
    void ResetRoundKillsAndDeaths();

    /* Player Stat Getters */
    int32_t GetScore();
    int32_t GetCurrentHealth();
    int32_t GetInitialHealth();
    int32_t GetPriorityLevel();
    int32_t GetSkillLevel();

    /* Weapon Getters */
    std::string GetPlayerWeapon();
    int32_t GetPlayerWeaponAccuracy();
    int32_t GetPlayerWeaponDamage();
    int32_t GetCurrentAmmo();

    /* Stat Getters */
    int32_t GetBulletShots();
    int32_t GetBulletHits();
    int32_t GetTotalKills();
    int32_t GetTotalDeaths();
    int32_t GetPlants();
    int32_t GetDefuses();
    std::string GetName();
    int32_t GetTotalGameDamage();
    int32_t GetRoundDamage();
    int32_t GetRoundKills();
    int32_t GetRoundDeaths();

    /* Checkers */
    bool IsAlive();
    bool IsDead();
    bool IsAttacking();
    bool HasDefuser();
};