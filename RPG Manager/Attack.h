#pragma once
#include <string>
#include "Enums.h"
#include <fstream>

class Attack
{
	std::string name;
	damageType dt;
	int baseDamage;
	int damageModifier;
	int grappleBonus;
	int meleeBonus;
	int shortRangeBonus;
	int mediumRangeBonus;
	int longRangeBonus;
	skill rangeAttackType;
public:
	Attack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB);
	Attack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB, int shortRangeB, int mediumRangeB, int longRangeB, skill rangeType);
	Attack();
	/*void inflictDamage(Creature* target);
	int grappleAttack(Creature* attacker);
	int meleeAttack(Creature* attacker);*/
	std::string getName();
	void setAttack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB);
	void setAttack(std::string n, damageType dmgType, int baseDmg, int dmgModifier, int grappleB, int meleeB, int shortRangeB, int mediumRangeB, int longRangeB, skill rangeType);
	void setAttack();
	int getBaseDamage();
	int getDamageModifier();
	int getGrappleBonus();
	int getMeleeBonus();
	int getShortRangeBonus();
	int getMediumRangeBonus();
	int getLongRangeBonus();
	skill getRangeAttackType();
	damageType getDamageType();
	void writeToFile();
	void writeToFileNPC();
	void writeToCharacterFile();
	void writeToEncounterFile(std::string encounter);
};

