#include "Weapon.h"

Weapon::Weapon()
{
	weaponName = "";
	maxLoaded = 0;
	loadedAmmo = 0;
	spareAmmo = 0;
	weaponNum = weaponID::knife;
}

Weapon::Weapon(std::string name, int maxL, int loaded, int spare, int perShot)
{
	weaponName = name;
	maxLoaded = maxL;
	loadedAmmo = loaded;
	spareAmmo = spare;
	ammoPerShot = perShot;
}

Weapon::Weapon(weaponID weapon)
{
	maxLoaded = 0;
	loadedAmmo = 0;
	spareAmmo = 0;
	weaponNum = weapon;
	switch (weapon)
	{
	case weaponID::knife:
	{
		weaponNum = weaponID::knife;
		weaponName = "Knife";
		a1.setAttack("slash", damageType::cut, 4, 1, 0, 1);
		a2.setAttack("jab", damageType::pierce, 4, 1, 0, 1);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::sword:
	{
		weaponNum = weaponID::sword;
		weaponName = "Sword";
		a1.setAttack("slash", damageType::cut, 4, 1, -3, 2);
		a2.setAttack("jab", damageType::pierce, 4, 1, -6, 2);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::spear:
	{
		weaponNum = weaponID::spear;
		weaponName = "Spear";
		a1.setAttack("jab", damageType::pierce, 4, 1, -20, 3);
		a2.setAttack();
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::bow:
	{
		weaponNum = weaponID::bow;
		weaponName = "Bow";
		maxLoaded = 1;
		loadedAmmo = 1;
		ammoPerShot = 1;
		spareAmmo = 10;
		a1.setAttack("shoot", damageType::pierce, 2, 3, -20, -2, 1, 2, 1, skill::S_strenghtRanged);
		a2.setAttack();
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::crossbow:
	{
		weaponNum = weaponID::crossbow;
		weaponName = "Crossbow";
		maxLoaded = 1;
		loadedAmmo = 1;
		ammoPerShot = 1;
		spareAmmo = 10;
		a1.setAttack("shoot", damageType::pierce, 2, 3, -20, 0, 3, 3, 2, skill::S_dexRanged);
		a2.setAttack();
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::pistol:
	{
		weaponNum = weaponID::pistol;
		weaponName = "Pistol";
		maxLoaded = 15;
		loadedAmmo = 15;
		ammoPerShot = 1;
		spareAmmo = 15;
		a1.setAttack("shoot", damageType::ballistic, 2, 3, -1, 3, 3, 2, 0, skill::S_dexRanged);
		a2.setAttack("Bludgeon", damageType::blunt, 4, 1, 0, 0);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::rifle:
	{
		weaponNum = weaponID::rifle;
		weaponName = "Rifle";
		maxLoaded = 20;
		loadedAmmo = 20;
		ammoPerShot = 1;
		spareAmmo = 20;
		a1.setAttack("shoot", damageType::ballistic, 2, 3, -20, 0, 3, 3, 2, skill::S_dexRanged);
		a2.setAttack("Bludgeon", damageType::blunt, 4, 1, -20, 2);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	default:
	{
		weaponName = "Claw";
		a1.setAttack("slash", damageType::cut, 4, 1, 0, 1);
		a2.setAttack("jab", damageType::pierce, 4, 1, 0, 1);
		a3.setAttack();
		a4.setAttack();
	}
	}
}

void Weapon::setWeapon(weaponID weapon)
{
	maxLoaded = 1;
	loadedAmmo = 1;
	spareAmmo = 0;
	ammoPerShot = 1;
	weaponNum = weapon;
	

	switch (weapon)
	{
	case weaponID::knife:
	{
		weaponNum = weaponID::knife;
		weaponName = "Knife";
		a1.setAttack("slash", damageType::cut, 4, 1, 0, 1);
		a2.setAttack("jab", damageType::pierce, 4, 1, 0, 1);
		a3.setAttack("Throw", damageType::pierce, 4, 1, -20, -1, 1, -3, -6, skill::S_strenghtRanged);
		a4.setAttack();
		break;
	}
	case weaponID::sword:
	{
		weaponNum = weaponID::sword;
		weaponName = "Sword";
		a1.setAttack("slash", damageType::cut, 4, 1, -3, 2);
		a2.setAttack("jab", damageType::pierce, 4, 1, -6, 2);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::spear:
	{
		weaponNum = weaponID::spear;
		weaponName = "Spear";
		a1.setAttack("jab", damageType::pierce, 4, 1, -20, 3);
		a2.setAttack("Throw", damageType::pierce, 4, 1, -20, -1, 0, 1, -3, skill::S_strenghtRanged);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::bow:
	{
		weaponNum = weaponID::bow;
		weaponName = "Bow";
		maxLoaded = 1;
		loadedAmmo = 1;
		ammoPerShot = 1;
		spareAmmo = 10;
		a1.setAttack("shoot", damageType::pierce, 2, 3, -20, -2, 1, 2, 1, skill::S_strenghtRanged);
		a2.setAttack();
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::crossbow:
	{
		weaponNum = weaponID::crossbow;
		weaponName = "Crossbow";
		maxLoaded = 1;
		loadedAmmo = 1;
		ammoPerShot = 1;
		spareAmmo = 10;
		a1.setAttack("shoot", damageType::pierce, 2, 3, -20, 0, 3, 3, 2, skill::S_dexRanged);
		a2.setAttack();
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::pistol:
	{
		weaponNum = weaponID::pistol;
		weaponName = "Pistol";
		maxLoaded = 15;
		loadedAmmo = 15;
		ammoPerShot = 1;
		spareAmmo = 15;
		a1.setAttack("shoot", damageType::ballistic, 2, 3, -1, 3, 3, 2, 0, skill::S_dexRanged);
		a2.setAttack("Bludgeon", damageType::blunt, 4, 1, 0, 0);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	case weaponID::rifle:
	{
		weaponNum = weaponID::rifle;
		weaponName = "Rifle";
		maxLoaded = 20;
		loadedAmmo = 20;
		ammoPerShot = 1;
		spareAmmo = 20;
		a1.setAttack("shoot", damageType::ballistic, 2, 3, -20, 0, 3, 3, 2, skill::S_dexRanged);
		a2.setAttack("Bludgeon", damageType::blunt, 4, 1, -20, 2);
		a3.setAttack();
		a4.setAttack();
		break;
	}
	default:
	{
		weaponName = "Claw";
		a1.setAttack("slash", damageType::cut, 4, 1, 0, 1);
		a2.setAttack("jab", damageType::pierce, 4, 1, 0, 1);
		a3.setAttack();
		a4.setAttack();
	}
	}
}

std::string Weapon::getName()
{
	return weaponName;
}

weaponID Weapon::getWeapon()
{
	return weaponNum;
}

int Weapon::getMaxAmmo()
{
	return maxLoaded;
}

int Weapon::getLoadedAmmo()
{
	return loadedAmmo;
}

int Weapon::getSpareAmmo()
{
	return spareAmmo;
}

void Weapon::spendAmmo(int ammo)
{
	loadedAmmo -= ammo;
}

int Weapon::getAmmoPerShot()
{
	return ammoPerShot;
}

void Weapon::reloadAll()
{
	if (spareAmmo >= maxLoaded)
	{
		spareAmmo -= maxLoaded - loadedAmmo;
		loadedAmmo = maxLoaded;
	}
	else
	{
		loadedAmmo += spareAmmo;
		spareAmmo = 0;
	}
}

void Weapon::reloadOne()
{
	if (spareAmmo > 0 && (loadedAmmo != maxLoaded))
	{
		loadedAmmo ++;
		spareAmmo--;
	}
}

void Weapon::writeToFile()
{
	std::ofstream inFile;
	inFile.open("Weapons.txt", std::ios::app);

	inFile << weaponName << '\n';
	inFile << maxLoaded << '\n';
	inFile << loadedAmmo << '\n';
	inFile << spareAmmo << '\n';
	inFile << ammoPerShot << '\n';

	inFile.close();

	a1.writeToFile();
	a2.writeToFile();
	a3.writeToFile();
	a4.writeToFile();
}

void Weapon::writeToNPCFile()
{
	std::ofstream inFile;
	inFile.open("NPC.txt", std::ios::app);

	inFile << weaponName << '\n';
	inFile << maxLoaded << '\n';
	inFile << loadedAmmo << '\n';
	inFile << spareAmmo << '\n';
	inFile << ammoPerShot << '\n';

	inFile.close();

	a1.writeToFileNPC();
	a2.writeToFileNPC();
	a3.writeToFileNPC();
	a4.writeToFileNPC();
	
}

void Weapon::writeToCharacterFile()
{
	std::ofstream inFile;
	inFile.open("Character.txt", std::ios::app);

	inFile << weaponName << '\n';
	inFile << maxLoaded << '\n';
	inFile << loadedAmmo << '\n';
	inFile << spareAmmo << '\n';
	inFile << ammoPerShot << '\n';

	inFile.close();

	a1.writeToCharacterFile();
	a2.writeToCharacterFile();
	a3.writeToCharacterFile();
	a4.writeToCharacterFile();
}

void Weapon::writeToEncounterFile(std::string encounter)
{
	std::ofstream inFile;
	inFile.open(encounter + ".txt", std::ios::app);

	inFile << weaponName << '\n';
	inFile << maxLoaded << '\n';
	inFile << loadedAmmo << '\n';
	inFile << spareAmmo << '\n';
	inFile << ammoPerShot << '\n';

	inFile.close();

	a1.writeToEncounterFile(encounter);
	a2.writeToEncounterFile(encounter);
	a3.writeToEncounterFile(encounter);
	a4.writeToEncounterFile(encounter);
}

void Weapon::setSpareAmmo(int ammo)
{
	spareAmmo = ammo;
}
