#include "Attack.h"

Attack::Attack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB)
{
	name = n;
	dt = dmgType;
	baseDamage = baseDmg;
	damageModifier = dmgModifier;
	grappleBonus = grappleB;
	meleeBonus = meleeB;
	shortRangeBonus = -20;
	mediumRangeBonus = -20;
	longRangeBonus = -20;
	rangeAttackType;
}

Attack::Attack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB, int shortRangeB, int mediumRangeB, int longRangeB, skill rangeType)
{
	name = n;
	dt = dmgType;
	baseDamage = baseDmg;
	damageModifier = dmgModifier;
	grappleBonus = grappleB;
	meleeBonus = meleeB;
	shortRangeBonus = shortRangeB;
	mediumRangeBonus = mediumRangeB;
	longRangeBonus = longRangeB;
	rangeAttackType = rangeType;
}

Attack::Attack()
{
	name = "";
	dt = damageType::blunt;
	baseDamage = 4;
	damageModifier = 0;
	grappleBonus = 2;
	meleeBonus = 1;
}


void Attack::setAttack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB)
{
	name = n;
	dt = dmgType;
	baseDamage = baseDmg;
	damageModifier = dmgModifier;
	grappleBonus = grappleB;
	meleeBonus = meleeB;
	shortRangeBonus = -20;
	mediumRangeBonus = -20;
	longRangeBonus = -20;
	rangeAttackType;
}

void Attack::setAttack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB, int shortRangeB, int mediumRangeB, int longRangeB, skill rangeType)
{
	name = n;
	dt = dmgType;
	baseDamage = baseDmg;
	damageModifier = dmgModifier;
	grappleBonus = grappleB;
	meleeBonus = meleeB;
	shortRangeBonus = shortRangeB;
	mediumRangeBonus = mediumRangeB;
	longRangeBonus = longRangeB;
	rangeAttackType = rangeType;
}

void Attack::setAttack()
{
	name = "";
}

std::string Attack::getName()
{
	return name;
}

int Attack::getBaseDamage()
{
	return baseDamage;
}

int Attack::getDamageModifier()
{
	return damageModifier;
}

int Attack::getGrappleBonus()
{
	return grappleBonus;
}

int Attack::getMeleeBonus()
{
	return meleeBonus;
}

int Attack::getShortRangeBonus()
{
	return shortRangeBonus;
}

int Attack::getMediumRangeBonus()
{
	return mediumRangeBonus;
}

int Attack::getLongRangeBonus()
{
	return longRangeBonus;
}

skill Attack::getRangeAttackType()
{
	return rangeAttackType;
}

damageType Attack::getDamageType()
{
	return dt;
}

void Attack::writeToFile()
{
	std::ofstream inFile;
	inFile.open("Weapons.txt", std::ios::app);

	inFile << name << '\n';
	inFile << static_cast<int>(dt) << '\n';
	inFile << baseDamage << '\n';
	inFile << damageModifier << '\n';
	inFile << grappleBonus << '\n';
	inFile << meleeBonus << '\n';
	inFile << shortRangeBonus << '\n';
	inFile << mediumRangeBonus << '\n';
	inFile << longRangeBonus << '\n';
	inFile << static_cast<int>(rangeAttackType) << '\n';
	
	inFile.close();

}

void Attack::writeToFileNPC()
{
	std::ofstream inFile;
	inFile.open("NPC.txt", std::ios::app);

	inFile << name << '\n';
	inFile << static_cast<int>(dt) << '\n';
	inFile << baseDamage << '\n';
	inFile << damageModifier << '\n';
	inFile << grappleBonus << '\n';
	inFile << meleeBonus << '\n';
	inFile << shortRangeBonus << '\n';
	inFile << mediumRangeBonus << '\n';
	inFile << longRangeBonus << '\n';
	inFile << static_cast<int>(rangeAttackType) << '\n';

	inFile.close();

}

void Attack::writeToCharacterFile()
{
	std::ofstream inFile;
	inFile.open("Character.txt", std::ios::app);

	inFile << name << '\n';
	inFile << static_cast<int>(dt) << '\n';
	inFile << baseDamage << '\n';
	inFile << damageModifier << '\n';
	inFile << grappleBonus << '\n';
	inFile << meleeBonus << '\n';
	inFile << shortRangeBonus << '\n';
	inFile << mediumRangeBonus << '\n';
	inFile << longRangeBonus << '\n';
	inFile << static_cast<int>(rangeAttackType) << '\n';

	inFile.close();
}

void Attack::writeToEncounterFile(std::string encounter)
{
	std::ofstream inFile;
	inFile.open(encounter + ".txt", std::ios::app);

	inFile << name << '\n';
	inFile << static_cast<int>(dt) << '\n';
	inFile << baseDamage << '\n';
	inFile << damageModifier << '\n';
	inFile << grappleBonus << '\n';
	inFile << meleeBonus << '\n';
	inFile << shortRangeBonus << '\n';
	inFile << mediumRangeBonus << '\n';
	inFile << longRangeBonus << '\n';
	inFile << static_cast<int>(rangeAttackType) << '\n';

	inFile.close();
}

