#pragma once
#include <iostream>

class Weapon
{
private:
	int32_t _weaponType;
	uint32_t _initialCapacity;
	uint32_t _ammo;
	uint32_t _damage;
	uint32_t _accuracy;
public:
	Weapon();
	
	int32_t GetWeapon();

	void ShotingBullets();

	int32_t GetWeaponAccuracy();

	int32_t GetWeaponDamage();

	bool IsShooting(int bulletsShot);

	uint32_t InitialCapacity();

	uint32_t GetAmmo();

	void ResetAmmo();
};
