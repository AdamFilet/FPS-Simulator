#include "weapon.h"

Weapon::Weapon()
{
	_initialCapacity = 0;
	_ammo = 0;
	_damage = 0;
	_accuracy = 0;
	_weaponType = (WeaponsTypes) (rand() % 5);

	if (_weaponType == R4C)
	{
		_ammo = 31;
		_damage = 32;
		_accuracy = 59;
		_initialCapacity = 31;
	}
	else if (_weaponType == L85A2)
	{
		_ammo = 31;
		_damage = 47;
		_accuracy = 63;
		_initialCapacity = 31;
	}
	else if (_weaponType == MPX)
	{
		_ammo = 31;
		_damage = 26;
		_accuracy = 74;
		_initialCapacity = 31;
	}
	else if (_weaponType == K1A)
	{
		_ammo = 31;
		_damage = 36;
		_accuracy = 60;
		_initialCapacity = 31;
	}
	else if (_weaponType == GP41)
	{
		_ammo = 100;
		_damage = 30;
		_accuracy = 30;
		_initialCapacity = 100;
	}

}


WeaponsTypes Weapon::GetWeapon()
{
	return _weaponType;
}

int32_t Weapon::GetWeaponAccuracy()
{
	return _accuracy;
}

int32_t Weapon::GetWeaponDamage()
{
	return _damage;
}

bool Weapon::IsShooting(int bulletsShot)
{

	for (int i = 0; i < bulletsShot; i++)
	{
		_ammo--;
	}
	return true;
}

void Weapon::ShotingBullets()
{
	_ammo--;
}

uint32_t Weapon::GetAmmo()
{
	return _ammo;
}

 uint32_t Weapon::InitialCapacity()
{
	return _initialCapacity;
}

 void Weapon::ResetAmmo()
 {
	 _ammo = _initialCapacity;
 }