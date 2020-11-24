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
    uint32_t _kills;
    uint32_t _assist;
    uint32_t _death;
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
    void Assisted();
    void ResetRoundDamage();
    void IncrementDamageDone(int32_t damage);

    /* Player Stat Getters */
    int GetScore();
    int GetCurrentHealth();
    int GetInitialHealth();
    int GetPriorityLevel();
    int GetSkillLevel();

    /* Weapon Getters */
    WeaponsTypes GetPlayerWeapon();
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
    int GetTotalGameDamage();
    int GetRoundDamage();

    /* Checkers */
    bool IsAlive();
    bool IsDead();
    bool IsAttacking();
    bool HasDefuser();

    /* Uncategorizable with current names */
};