#pragma once
#include <iostream>
#include <string>

enum WeaponsTypes
{
	R4C,
	L85A2,
	MPX,
	K1A,
	GP41,
	END
};

class Weapon
{
private:
	WeaponsTypes _weaponType;
	uint32_t _initialCapacity;
	uint32_t _ammo;
	uint32_t _damage;
	uint32_t _accuracy;
public:
	Weapon();
	
	std::string GetWeaponName();

	void ShotingBullets();

	int32_t GetWeaponAccuracy();

	int32_t GetWeaponDamage();

	bool IsShooting(int bulletsShot);

	uint32_t InitialCapacity();

	uint32_t GetAmmo();

	void ResetAmmo();
};
