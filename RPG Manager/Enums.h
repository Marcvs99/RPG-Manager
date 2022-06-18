#pragma once
#include <vector>
#include<iomanip>
#include <cstdio>
//special data types used across the program

enum class damageType { blunt, cut, pierce, chop, ballistic, environmental, flame, energy, shock, acid, magical };

enum class range { grappleR, meleeR, shortR, mediumR, longR };

enum class skill { S_grapple, S_melee, S_strenghtRanged, S_dexRanged, S_initiative, S_athletics, S_Acrobatics, S_constitution, S_evasion, S_perception_Investigation,
S_tactics_Command, S_artillery, S_strength, S_ride_Pilot, S_stealth_SlightofHand, S_persuasion_Deception, S_charm_Seduction, S_intimidation, S_fortitude_Tolerence,
S_navigation, S_survival, S_technology, S_engineering, S_medicine, S_calculation_Mathematics, S_memory, S_languages_linguistics, S_sketching_Painting, S_sculpting_Carving,
S_sewing_Weaving_Knitting, S_oratory_Performance, S_writing_Composition, S_dance, S_music_Composition, S_music_InstrumentalPerformance, S_music_VocalPerformance, other};

enum class weaponID { fist, knife, sword, spear, bow, crossbow, pistol, rifle, other};

enum class bodyPrt {head, neck, rightArm, leftArm, chest, gut, rightLeg, leftLeg, all};

bool isInteger(const std::string& s);
int getIntInput();



struct Armor
{
	std::string type;
	
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
