#pragma once
#include <fstream>
#include <iostream>
#include "Weapon.h"

class Character :
    public Weapon
{
public:
	Character(std::string n, int bR, int cR, int pR, int chR, int balR, int envR, int flR, int enR, int shR, int acR, int maR, int grp, int m, int strR, int dexR, int i, int ath, int acr, int c, int ev, int per, int ap, weaponID weapon1, weaponID weapon2, weaponID weapon3);
	Character(std::string n, int bR, int cR, int pR, int chR, int balR, int envR, int flR, int enR, int shR, int acR, int maR, int grp, int m, int strR, int dexR, int i, int ath, int acr, int c, int ev, int per, int ap);
	Character();
	Weapon w1;
	Weapon w2;
	Weapon w3;
	Weapon w4;
	Weapon w5;
	std::string getChName();
	int initiativeRoll = 0;
	void setID(std::string n);
	void setName(std::string n);
	void setVocation(int num, std::string voc);
	void writeToFileNPC();
	void writeToCharacterFile();
	void writeToEncounterFile(std::string encounter);

	int getWoundLevel();
	int getWoundLevel(bodyPrt bp);
	int getResistance(damageType dt);
	int getSkillLevel(skill s);
	int getTrueSkillLevel(skill s);
	std::string getName();
	bool getActed();
	void wound(int damage, damageType dt);
	void heal();
	void heal(bodyPrt bp, int level);
	void act();
	void replenishAction();
	void takeDamage(damageType dt, int damage);
	void displayInfo();
	void setWeapon(weaponID& w, weaponID nw);
	weaponID getWeapon(int num);
	int diceRoll(int level);
	std::string getAction();
	void setAction(std::string action);
	int rollSkill(skill s, std::vector<Character>& combatants);
	int rollSkill(std::vector<Character>& combatants);
	int rollAttack(int& dmg, damageType& dmgType);
	int rollAttack(int& dmg, damageType& dmgType, const range& r);
	void reloadWeapon();
	void setSpecialSkill(int skillNum, std::string skillName, int skillLevel);
	int getSpecialSkillLevel(int skillNum);
	void setBodyPart(bodyPrt bP, int wL, int bR, int cR, int pR, int chR, int baR, int eR, int fR, int enR, int sR, int aR, int mR, int aP);
	int evade();
	void characterCreate(std::vector<Weapon>& weapons);
	void setSkill(skill s, int l);
	void setWoundLevel(int l, bodyPrt bP);
	void setArmorPenalty(int l);
	void setArmor(std::vector<Armor>& a);
	void resetArmor();
	void replaceOrRemoveWeapon(std::vector<Weapon>& weapons);
	void setSpareAmmo();
	void changeSkills();
	void setResistances();
	void rollInitiative();
	int getInitiative();
	void setNPC();
	bool getNPC();
	bool getAlive();
	void knockOut();
	void revive();
	

private:
	std::string vocation1;
	std::string vocation2;
	std::string vocation3;
	std::string name = "";
	std::string currentAction = "";

	bool acted = false;
	bool isNPC = false;
	
	bool alive = true;

	int defaultLevel = 4;

	int woundLevel = 0;
	int bluntResistance = 0;
	int cutResistance = 0;
	int pierceResistance = 0;
	int chopResistance = 0;
	int ballisticResistance = 0;
	int environmentalResistance = 0;
	int flameResistance = 0;
	int energyResistance = 0;
	int shockResistance = 0;
	int acidResistance = 0;
	int magicalResistance = 0;
	int armorPenalty = 0;

	int grapple = defaultLevel;
	int melee = defaultLevel;
	int strenghtRanged = defaultLevel;
	int dexRanged = defaultLevel;
	int initiative = defaultLevel;
	int athletics = defaultLevel;
	int acrobatics = defaultLevel;
	int constitution = defaultLevel;
	int evasion = defaultLevel;

	int perception_Investigation = defaultLevel;
	int tactics_Command = defaultLevel;
	int artillery = defaultLevel;
	int strength = defaultLevel;
	int ride_Pilot = defaultLevel;
	int stealth_SlightofHand = defaultLevel;
	int persuasion_Deception = defaultLevel;
	int charm_Seduction = defaultLevel;
	int intimidation = defaultLevel;
	int fortitude_Tolerence = defaultLevel;
	int navigation = defaultLevel;
	int survival = defaultLevel;
	int technology = defaultLevel;
	int engineering = defaultLevel;
	int medicine = defaultLevel;
	int calculation_Mathematics = defaultLevel;
	int memory = defaultLevel;
	int languages_linguistics = defaultLevel;

	int sketching_Painting = defaultLevel;
	int sculpting_Carving = defaultLevel;
	int sewing_Weaving_Knitting = defaultLevel;
	int oratory_Performance = defaultLevel;
	int writing_Composition = defaultLevel;
	int dance = defaultLevel;
	int music_Composition = defaultLevel;
	int music_InstrumentalPerformance = defaultLevel;
	int music_VocalPerformance = defaultLevel;

	struct specialSkill
	{
		std::string skillName = "";
		int skillLevel = 0;
	};

	struct bodyPart
	{
		std::string partName = "";
		int woundLevel = 0;
		int bluntResistance = 0;
		int cutResistance = 0;
		int pierceResistance = 0;
		int chopResistance = 0;
		int ballisticResistance = 0;
		int environmentalResistance = 0;
		int flameResistance = 0;
		int energyResistance = 0;
		int shockResistance = 0;
		int acidResistance = 0;
		int magicalResistance = 0;
		int armorPenalty = 0;
	};

	specialSkill ss1, ss2, ss3, ss4, ss5;

	bodyPart head, neck, rightArm, leftArm, chest, gut, rightLeg, leftLeg;
	
};

