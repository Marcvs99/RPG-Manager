#pragma once
#include <string>
#include "Enums.h"
#include "Attack.h"


class Weapon
{
protected:
	std::string weaponName = "";
	int maxLoaded = 0;
	int loadedAmmo = 0;
	int spareAmmo = 0;
	int ammoPerShot = 0;
	weaponID weaponNum = weaponID::knife;
	
public:
	Attack a1, a2, a3, a4;
	Weapon(weaponID weapon);
	Weapon();
	Weapon(std::string name, int maxL, int loaded, int spare, int perShot);
	std::string getName();
	weaponID getWeapon();
	int getMaxAmmo();
	int getLoadedAmmo();
	int getSpareAmmo();
	void spendAmmo(int ammo);
	void reloadAll();
	void reloadOne();
	void setWeapon(weaponID weapon);
	int getAmmoPerShot();
	void writeToFile();
	void writeToNPCFile();
	void writeToCharacterFile();
	void writeToEncounterFile(std::string encounter);
	void setSpareAmmo(int ammo);
	
	
	
	
	
};

