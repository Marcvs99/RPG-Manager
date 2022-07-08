// Marcus King
// 5/5/2022
// CIS 1202.501

// Description: This is a program that is meant to assist calculations and recordkeeping for roleplaying games.
// Right now it is set up to demonstrate some of the capabilities with an example combat scenario between two npcs (non player characters)

// To use follow the promts to customize your character, than select a weapon to use, and finally which opponent to face.

// The program will generate a simulated battle, logging each hit and miss, along with damage dealt until there is a winner.


#include <iostream>             // files
#include <string>
#include <fstream>

#include "Enums.h"
#include "Character.h"

void newNPCType(std::vector<Weapon>& weapons);
void loadNPCvector(std::vector<Character>& NPCvector);
void sortCharacterVector(std::vector<Character>& vector);
int vectorLookup(std::vector<Character>& vector, std::string creatureName, const int& l, const int& r);
int unsortedLookup(std::vector<Character>& vector, std::string creatureName);
void activateNPC(std::vector<Character>& NPCvector, std::vector<Character>& activeCharacterVector);
void killActiveCreature(std::vector<Character>& activeCharacterVector, const int& e);
void removeNPC(std::vector<Character>& activeCharacterVector);
void removeNPCType(std::vector<Character>& NPCvector);
void createNewWeaponType();
void loadWeaponVector(std::vector<Weapon>& WeaponVector);
void sortWeaponVector(std::vector<Weapon>& vector);
void deleteWeapon(std::vector<Weapon>& weaponVector);
void newCharacter(std::vector<Weapon>& weaponVector);
void loadCharacterVector(std::vector<Character>& Characters);
void saveCharacterChanges(std::vector<Character>& Characters);
void addNewArmor(std::vector<Armor>& ArmorVector);
void writeToArmorFile(const Armor& a);
void loadArmorVector(std::vector<Armor>& ArmorVector);
void sortArmorVector(std::vector<Armor>& ArmorVector);
void attackDefend(Character& attacker, Character& defender);
void chooseCombatants(std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants);
int combatEncounter(std::vector<std::string>& args, std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants,
	std::vector<Weapon>& weapons, std::vector<Armor>& armor, std::vector<std::string>& encounters, std::string& currentEncounter);
void getCommandInput(std::vector<std::string>& args);
int executeCommand(std::vector<std::string>& args, std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants, std::vector<Weapon>& weapons, std::vector<Armor>& armor, std::vector<std::string>& encounters, std::string& currentEncounter);
void deleteArmorType(std::vector<Armor>& armor);
void displayArmor(std::vector<Armor>& armor);
int armorLookup(std::vector<Armor>& vector, std::string armorName, const int& l, const int& r);
std::string damageTypeToString(damageType dt);
void displayWeapons(std::vector<Weapon>& weapons);
int weaponLookup(std::vector<Weapon>& vector, std::string weaponName, const int& l, const int& r);
void displayNPCs(std::vector<Character>& NPCs);
void deleteCharacter(std::vector<Character>& Characters);
void newEncounter(std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants, std::vector<std::string>& encounters);
void deleteEncounter(std::vector<std::string>& encounters);
void loadEncounters(std::vector<std::string>& encounters);
void getCombatants(std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<std::string>& names, std::vector<int>& nums);
void displayEncounters(std::vector<std::string>& encounters);
void sortEncounters(std::vector<std::string>& encounters);
int encounterLookup(std::vector<std::string>& vector, std::string encounter, const int& l, const int& r);
std::string getEncounter(std::vector<std::string>& encounters, std::string& currentEncounter);
void loadCombatants(std::string encounter, std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants);
skill stringToSkill(std::string& s);

int main()																					//main
{
	int escapeCode = 0;
	srand(time(NULL));		//seed random

	std::vector<std::string> args;

	std::vector<Character> NPCtypeVector;
	loadNPCvector(NPCtypeVector);
	
	std::vector<Character> playerCharacters;
	loadCharacterVector(playerCharacters);

	std::vector<Character> Combatants;

	std::vector<Weapon> WeaponVector;
	loadWeaponVector(WeaponVector);

	std::vector<Armor> ArmorVector;
	loadArmorVector(ArmorVector);

	std::vector <std::string> encounters;
	loadEncounters(encounters);

	std::string currentEncounter = "none";

	while (escapeCode < 3)
	{
		//main driver goes here
		
		std::cout << "Current encounter: " << currentEncounter << '\n';
		getCommandInput(args);
		escapeCode = executeCommand(args, playerCharacters, NPCtypeVector, Combatants, WeaponVector, ArmorVector, encounters, currentEncounter);

		if (escapeCode == 3)
		{
			std::cout << "Exit Program?" << '\n';
			std::cout << "1. Yes" << '\n';
			std::cout << "2. No" << '\n';
			int response = getIntInput();
			while (response < 1 || response > 2)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response == 2)
			{
				escapeCode = 0;
			}
		}
		
	}
	
	// done

	// Create function to allow user to specify new creature type
	// store user input in temp Character object
	// Write that data to a NPC file IN A CHARACTER CLASS METHOD
	// Read all NPC data from file into CreatureTypeVector	
	// Create sorting algorithm in function to sort Character vectors alphabetically by Character Name (include call within loadNPCvector function)
	// Create function to allow user to look up npctype
	// Create function to allow user to look up npctype and copy to CreatureVector
	// Give each active NPC unique name upon activation
	// Create function to delete Characters from active array
	// Allow user to delete NPC from active creature vector
	// Allow user to lookup NPC type and delete from vector, then re-write the file
	// CONVERT ALL USER CIN INPUT TO GETLINE
	// add weapons (slots) to NPCs
	// remove Creature Class
	// move Creature Methods to Character Class
	// create character method to return (rolled) result of skill + vocation + assists - wound penelalty
	// create character method to return (rolled) result of skill + vocation, + assists, + weapon.attack bonus - wound penalty (pass int dmg as &parameter and roll damage, pass damageType)
	// create character method to accept int value and increase wound level but apply resistance and constitution check
	// implement rest of attacks
	// implement rest of weapons
	// Allow NPCs to use rest of weapons
	// add throwing attacks to melee weapons
	// create Character.method to reload weapon
	// Implement rest of resistances
	// allow user to define new weapons and save to fil
	// load weapons into weapon vector and sort alphabetically
	// allow characters to copy weapons from weapon vector on creation
	// add "special skill" struct in Character class with user defined string "name" and an int "skillLevel"
	// add ~5 "special skill" objects to chacter class and methods to access/set them
	// allow user to access special skills from skillchecks and attack rolls etc.
	// add "bodyPart" struct (in Character class) with partName, woundLevel, resistances, etc.
	// give Characters bodyparts and ability to access member data
	// change takeDamage character method to apply damage to specified or random body part, as well as total wound level
	// add character method to return evasion + cover
	// create weapon method to write to character file
	// create character method to write data to character file (write name, all skills, special skills, resistances, wound level, armor penalty, bodyPart data, weapon data)
	// allow user to specify new Character and write to file
	// load characters from file to activeCharacters vector
	// overwrite character file on close to save changes
	// create armor struct vector for pieces of armor, save to and load from file
	// create character method that takes an armor struct as argument and increases resistances and armor penalty
	// create character method that resets resistances and armor penalty
	// create function to add or replace or delete a weapon from a character
	// create funtion to edit skills
	// create function to change spare ammo
	// create function to alter resistances
	// implement combat function that calls attack method, asks for target, processes attack or evade check, applies damage appropriately 
	// implement function to choose combatants and load them into a single character vector

	//to do:

	// add even more weapons
	// implement combat encounter function: get characters to include, roll initiative, order characters from lowest to highest initiative,
	//			get and dispaly actions for each character (as well as remaining actions, ammo, and wound level), reverse order, allow user to access actions 
	//			for each character in order and end turn. Allow user to remove characters after taking damage. Repeat until user terminates encounter
	// implement ability to save and delete text events, display them as list (Title only), choose from list or draw randomly
	// allow user to add new event decks (new files)
	// implement ability to save and load combat encounters
	// Implement Command interface
	// add perception/investigation to npc creation

	std::cout << "Save character changes?" << '\n';

	std::cout << "1. Yes" << '\n';
	std::cout << "2. No" << '\n';

	int response = getIntInput();

	while (response < 1 || response > 2)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	if (response == 1)
	{
		saveCharacterChanges(playerCharacters);
	}
	
	return 0;
}

int executeCommand(std::vector<std::string>& args, std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants, std::vector<Weapon>& weapons, 
	std::vector<Armor>& armor, std::vector<std::string>& encounters, std::string& currentEncounter)
{
	int escapeCode = 0;

	std::cout << '\n';

	if (args.size() > 0)
	{
		if (args[0] == "commands")
		{
			//display list of commands
			std::cout << "Displaying commands" << '\n' << '\n';
			std::cout << std::setfill('.') << std::setw(40) << std::left << "gameinfo" << "display info about the roleplay system and the program" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "endturn" << "ends current character's turn when in combat" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "endcombat" << "ends current combat encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "endprogram" << "exits the program" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "armor/new" << "create new armor type" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "armor/delete" << "delete an armor type" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "armor/display" << "display all armor types" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "armor/display/[name]" << "display specified armor type" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "weapon/new" << "create new weapon type" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "weapon/delete" << "delete an weapon type" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "weapon/display" << "display all weapon types" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "weapon/display/[name]" << "display specified weapon type" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "npc/new" << "create new npc type" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "npc/delete" << "delete an npc type" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "npc/display" << "display all npc types" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "npc/display/[name]" << "display specified npc type" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "character/new" << "create new character" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "character/delete" << "delete a character" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "character/display" << "display all characters" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "character/display/[name]" << "display specified character" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "encounter/new" << "specify new encounter to save to file" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "encounter/delete" << "delete a saved encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "encounter/display" << "display all saved encounters" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "encounter/load" << "load a saved encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "encounter/clear" << "clear all characters/npcs from current encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "encounter/displaycharacters" << "display all characters/npcs from current encounter" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "event/newdeck" << "create new event deck" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "event/deletedeck" << "delete an event deck" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "event/[deckname]/newevent" << "create new event in specified deck" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "event/[deckname]/deleteevent" << "delete an event in specified deck" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "event/[deckname]/seelist" << "display list of events in specified deck and choose one to display full details of" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "event/[deckname]/seelist" << "display random event from specified deck" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "edit/[charactername]/resistances" << "edit the specified character's resistances" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "edit/[charactername]/armor" << "edit the specified character's armor" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "edit/[charactername]/skills" << "edit the specified character's skills" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "edit/[charactername]/ammo" << "edit the specified character's ammo" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "edit/[charactername]/weapons" << "edit the specified character's weapons" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "combat" << "initiate combat with current encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "combat/[encountername]" << "initiate combat with specified encounter" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "kill" << "displays current characters in encounter and knocks selected character out (will be skipped in combat but can still be interacted with)" << '\n';
			std::cout << "NOTE: if in the combat helper, this command will automatically specify character who's turn it is unless otherwise specified" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "kill/[charactername]" << "knocks specified character out (will be skipped in combat but can still be interacted with)" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "revive" << "displays current characters in encounter and revives selected character (will not be skipped in combat)" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "revive/[charactername]" << "revives specified character (will not be skipped in combat)" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "activate/npc" << "displays npc types and adds specified amount of user selection to current encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "activate/character" << "displays characters and adds specified character to current encounter" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "remove" << "displays characters in current encounter and removes specified character" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "remove/[charactername]" << "removes specified character from current encounter" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "rollskill" << "displays characters in current encounter and rolls selected skill for selected character" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "rollskill/[charactername]" << "rolls selected skill for specified character" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "rollskill/[charactername]/[skill]" << "rolls specified skill for specified character" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "attack" << "displays characters in current encounter and resolves attack between two selected characters" << '\n';
			std::cout << "NOTE: if in the combat helper, this command will automatically specify character who's turn it is unless otherwise specified" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "attack/[attackername]" << "resolves attack between specified character and annother selected from current encounter" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "attack/[attackername]/[defendername]" << "resolves attack between specified characters" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "heal" << "displays characters in current encounter and restores health to selected body part" << '\n';
			std::cout << "NOTE: if in the combat helper, this command will automatically specify character who's turn it is unless otherwise specified" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "heal/[charactername]" << "heals specified character and selected body part" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "heal/[charactername]/[bodypart]" << "heals specified character and specified body part" << '\n';
			std::cout << "NOTE: body parts are: 'head' 'neck' 'rightarm' leftarm' 'chest' 'gut' 'rightleg' leftleg'" << '\n';
			std::cout << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "reload" << "displays characters in current encounter and restores ammo to selected weapon" << '\n';
			std::cout << "NOTE: if in the combat helper, this command will automatically specify character who's turn it is unless otherwise specified" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "reload/[charactername]" << "restores ammo to selected weapon of specified character" << '\n';
			std::cout << std::setfill('.') << std::setw(40) << "reload/[charactername]/[weaponname]" << "restores ammo to specified weapon of specified character" << '\n';
			std::cout << '\n';
		}
		else if (args[0] == "gameinfo")
		{
			//display menu for different chapters of game rules, get selection, and display to user
			std::cout << "Displaying game info" << '\n';
		}
		else if (args[0] == "endturn")
		{
			std::cout << "Ending turn" << '\n';
			escapeCode = 1;
		}
		else if (args[0] == "endcombat")
		{
			std::cout << "Ending combat" << '\n';
			escapeCode = 2;
			std::cout << '\n';
			std::cout << "Save changes to player characters?" << '\n';
			std::cout << "1. Yes" << '\n';
			std::cout << "2. No" << '\n';
			int response = getIntInput();
			while (response < 1 || response > 2)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}
			if (response == 1)
			{
				for (int i = 0; i < combatants.size(); i++)
				{
					if (combatants[i].getNPC() == false)
					{
						int test = vectorLookup(playerCharacters, combatants[i].getName(), 0, playerCharacters.size() - 1);
						if (test != -1)
						{
							playerCharacters[test] = combatants[i];
							saveCharacterChanges(playerCharacters);
						}
						else
						{
							playerCharacters.push_back(combatants[i]);
							saveCharacterChanges(playerCharacters);
						}
					}
				}
			}
		}
		else if (args[0] == "endprogram" || args[0] == "exit")
		{
			escapeCode = 3;
		}
		else if (args[0] == "armor")
		{
			if (args.size() > 1)
			{
				if (args[1] == "new")
				{
					addNewArmor(armor);
				}
				else if (args[1] == "delete")
				{
					deleteArmorType(armor);
				}
				else if (args[1] == "display")
				{
					if (args.size() > 2)
					{
						int result = armorLookup(armor, args[2], 0, armor.size() - 1);
						if (result > -1)
						{
							std::vector<Armor> a;
							a.push_back(armor[result]);
							displayArmor(a);
							a.clear();
						}
						else
						{
							std::cout << "Error: Armor type not found" << '\n';
						}
					}
					else
					{
						displayArmor(armor);
					}
				}
				else
				{
					std::cout << "Error: Unrecognized Command: '" << args[1] << "'" << '\n';
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
			
		}
		else if (args[0] == "weapon")
		{
			if (args.size() > 1)
			{
				if (args[1] == "new")
				{
					createNewWeaponType();
				}
				else if (args[1] == "delete")
				{
					deleteWeapon(weapons);
				}
				else if (args[1] == "display")
				{
					if (args.size() > 2)
					{
						int result = weaponLookup(weapons, args[2], 0, weapons.size() - 1);
						if (result > -1)
						{
							std::vector<Weapon> w;
							w.push_back(weapons[result]);
							displayWeapons(w);
							w.clear();
						}
						else
						{
							std::cout << "Error: weapon not found" << '\n';
						}
					}
					else
					{
						displayWeapons(weapons);
					}
				}
				else
				{
					std::cout << "Error: Unrecognized Command: '" << args[1] << "'" << '\n';
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "npc")
		{
			if (args.size() > 1)
			{
				if (args[1] == "new")
				{
					newNPCType(weapons);
					loadNPCvector(NPCs);
				}
				else if (args[1] == "delete")
				{
					removeNPCType(NPCs);
					loadNPCvector(NPCs);
				}
				else if (args[1] == "display")
				{
					if (args.size() > 2)
					{
						int result = vectorLookup(NPCs, args[2], 0, NPCs.size() - 1);
						if (result > -1)
						{
							std::vector<Character> c;
							c.push_back(NPCs[result]);
							displayNPCs(c);
							c.clear();
						}
						else
						{
							std::cout << "Error: npc not found" << '\n';
						}
					}
					else
					{
						displayNPCs(NPCs);
					}
				}
				else
				{
					std::cout << "Error: Unrecognized Command: '" << args[1] << "'" << '\n';
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "character")
		{
			if (args.size() > 1)
			{
				if (args[1] == "new")
				{
					newCharacter(weapons);
					loadCharacterVector(playerCharacters);
				}
				else if (args[1] == "delete")
				{
					deleteCharacter(playerCharacters);
					loadCharacterVector(playerCharacters);
				}
				else if (args[1] == "display")
				{
					if (args.size() > 2)
					{
						int result = vectorLookup(playerCharacters, args[2], 0, playerCharacters.size() - 1);
						if (result > -1)
						{
							std::vector<Character> c;
							c.push_back(playerCharacters[result]);
							displayNPCs(c);
							c.clear();
						}
						else
						{
							std::cout << "Error: npc not found" << '\n';
						}
					}
					else
					{
						displayNPCs(playerCharacters);
					}
				}
				else
				{
					std::cout << "Error: Unrecognized Command: '" << args[1] << "'" << '\n';
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "encounter")
		{
			if (args.size() > 1)
			{
				if (args[1] == "new")
				{
					//create new encounter and save to file
					newEncounter(playerCharacters, NPCs, combatants, encounters);
				}
				else if (args[1] == "delete")
				{
					// display encounters and remove user selection, then rewrite to file
					deleteEncounter(encounters);
				}
				else if (args[1] == "display")
				{
					// display encounters
					displayEncounters(encounters);
				}
				else if (args[1] == "load")
				{
					if (args.size() < 3)
					{
						// display encounters, get user selection, load selected encounter into combat vector, set currentEncounter to name of selection
						loadCombatants(getEncounter(encounters, currentEncounter), playerCharacters, NPCs, combatants);
					}
					else
					{
						// load encounter corresponding to args[2], set currentEncounter to name of selection
						int test = encounterLookup(encounters, args[2], 0, encounters.size() - 1);
						if (test != -1)
						{
							loadCombatants(encounters[test], playerCharacters, NPCs, combatants);
							currentEncounter = encounters[test];
						}
						else
						{
							std::cout << "Error: Encounter not found" << '\n';
						}
					}
				}
				else if (args[1] == "clear")
				{
					std::cout << "Save changes to player characters?" << '\n';
					std::cout << "1. Yes" << '\n';
					std::cout << "2. No" << '\n';
					int response = getIntInput();
					while (response < 1 || response > 2)
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}

					if (response == 1)
					{
						for (int i = 0; i < combatants.size(); i++)
						{
							if (combatants[i].getNPC() == false)
							{
								int test = vectorLookup(playerCharacters, combatants[i].getName(), 0, playerCharacters.size() - 1);
								if (test != -1)
								{
									playerCharacters[test] = combatants[i];
								}
							}
						}
						saveCharacterChanges(playerCharacters);
					}
					combatants.clear();
					currentEncounter = "none";
				}
				else if (args[1] == "displaycharacters")
				{
					//display all combatants
					for (int i = 0; i < combatants.size(); i++)
					{
						std::cout << combatants[i].getName() << '\n';
					}
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "event")
		{
			if (args[1] == "newdeck")
			{
				// create new deck and write to new file
			}
			else if (args[1] == "deletedeck")
			{
				// dispay event decks and delete user selection
			}
			else if (args.size() > 2)
			{
				if (args[2] == "newevent")
				{
					// find event deck that matches args[1] and add new event, then rewrite the deck to file
				}
				else if (args[2] == "deleteevent")
				{
					// find event deck that matches args[1], display events and delete user selection
				}
				else if (args[2] == "seelist")
				{
					// find event deck that matches args[1], display events, allow user to select from list, draw randomly, or go back
				}
				else if (args[2] == "drawrandom")
				{
					// find event deck that matches args[1], display random event from deck
				}
				else
				{
					// find event deck that matches args[1], search and display event matching args[2]
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "edit")
		{
			if (args.size() > 2)
			{
				if (args[2] == "resistances")
				{
					// search character vector for args[1], then allow user to edit resistances, then save changes to character vector and file
					int test = vectorLookup(playerCharacters, args[1], 0, playerCharacters.size() - 1);
					if (test > -1)
					{
						playerCharacters[test].setResistances();
					}
					else
					{
						test = vectorLookup(NPCs, args[1], 0, NPCs.size() - 1);
						if (test > -1)
						{
							NPCs[test].setResistances();
						}
						else
						{
							std::cout << "Error: character not found" << '\n';
						}
					}
				}
				else if (args[2] == "armor")
				{
					// search character vector for args[1], then allow user to edit armor, then save changes to character vector and file
					int test = vectorLookup(playerCharacters, args[1], 0, playerCharacters.size() - 1);
					if (test > -1)
					{
						playerCharacters[test].setArmor(armor);
					}
					else
					{
						test = vectorLookup(NPCs, args[1], 0, NPCs.size() - 1);
						if (test > -1)
						{
							NPCs[test].setArmor(armor);
						}
						else
						{
							std::cout << "Error: character not found" << '\n';
						}
					}
				}
				else if (args[2] == "skills")
				{
					// search character vector for args[1], then allow user to edit skills, then save changes to character vector and file
					int test = vectorLookup(playerCharacters, args[1], 0, playerCharacters.size() - 1);
					if (test > -1)
					{
						playerCharacters[test].changeSkills();
					}
					else
					{
						test = vectorLookup(NPCs, args[1], 0, NPCs.size() - 1);
						if (test > -1)
						{
							NPCs[test].changeSkills();
						}
						else
						{
							std::cout << "Error: character not found" << '\n';
						}
					}
				}
				else if (args[2] == "ammo")
				{
					// search character vector for args[1], then allow user to edit (spare) ammo, then save changes to character vector and file
					int test = vectorLookup(playerCharacters, args[1], 0, playerCharacters.size() - 1);
					if (test > -1)
					{
						playerCharacters[test].setSpareAmmo();
					}
					else
					{
						test = vectorLookup(NPCs, args[1], 0, NPCs.size() - 1);
						if (test > -1)
						{
							NPCs[test].setSpareAmmo();
						}
						else
						{
							std::cout << "Error: character not found" << '\n';
						}
					}
				}
				else if (args[2] == "weapons")
				{
					// search character vector for args[1], then allow user to edit weapons, then save changes to character vector and file
					int test = vectorLookup(playerCharacters, args[1], 0, playerCharacters.size() - 1);
					if (test > -1)
					{
						std::cout << "Choose weapon to replace" << '\n';
						int num = 1;
						
						std::cout << "0. None" << '\n';
						std::cout << "1. " << playerCharacters[test].w1.getName() << '\n';
						if (playerCharacters[test].w2.getName() != "")
						{
							std::cout << "2. " << playerCharacters[test].w2.getName() << '\n';
							if (playerCharacters[test].w3.getName() != "")
							{
								std::cout << "3. " << playerCharacters[test].w3.getName() << '\n';
								if (playerCharacters[test].w4.getName() != "")
								{
									std::cout << "4. " << playerCharacters[test].w4.getName() << '\n';
									std::cout << "5. " << playerCharacters[test].w5.getName() << '\n';
									num = 5;
								}
								else
								{
									std::cout << "4. " << playerCharacters[test].w2.getName() << '\n';
									num = 4;
								}
								
							}
							else
							{
								std::cout << "3. " << playerCharacters[test].w2.getName() << '\n';
								num = 3;
							}
							
						}
						else
						{
							std::cout << "2. " << playerCharacters[test].w2.getName() << '\n';
							num = 2;
						}
						

						int response = getIntInput();

						if (response < 0 || response > num)
						{
							std::cout << "Invalid Input" << '\n';
							response = getIntInput();
						}

						if (response > 0)
						{
							std::cout << "Choose weapon to replace selected weapon" << '\n';
							for (int i = 0; i < weapons.size(); i++)
							{
								std::cout << i + 1 << ". " << weapons[i].getName() << '\n';
							}

							int response2 = getIntInput();

							if (response2 < 1 || response > weapons.size())
							{
								std::cout << "Invalid Input" << '\n';
								response2 = getIntInput();
							}

							Weapon temp = weapons[response2 - 1];

							switch (response)
							{
								case 1:
								{
									playerCharacters[test].w1 = temp;
									break;
								}
								case 2:
								{
									playerCharacters[test].w2 = temp;
									break;
								}
								case 3:
								{
									playerCharacters[test].w3 = temp;
									break;
								}
								case 4:
								{
									playerCharacters[test].w4 = temp;
									break;
								}
								case 5:
								{
									playerCharacters[test].w5 = temp;
									break;
								}
							}
						}
						
					}
					else
					{
						test = vectorLookup(NPCs, args[1], 0, NPCs.size() - 1);
						if (test > -1)
						{
							std::cout << "Choose weapon to replace" << '\n';
							int num = 1;

							std::cout << "0. None" << '\n';
							std::cout << "1. " << NPCs[test].w1.getName() << '\n';
							if (NPCs[test].w2.getName() != "")
							{
								std::cout << "2. " << NPCs[test].w2.getName() << '\n';
								if (NPCs[test].w3.getName() != "")
								{
									std::cout << "3. " << NPCs[test].w3.getName() << '\n';
									if (NPCs[test].w4.getName() != "")
									{
										std::cout << "4. " << NPCs[test].w4.getName() << '\n';
										std::cout << "5. " << NPCs[test].w5.getName() << '\n';
										num = 5;
									}
									else
									{
										std::cout << "4. " << NPCs[test].w2.getName() << '\n';
										num = 4;
									}

								}
								else
								{
									std::cout << "3. " << NPCs[test].w2.getName() << '\n';
									num = 3;
								}

							}
							else
							{
								std::cout << "2. " << NPCs[test].w2.getName() << '\n';
								num = 2;
							}


							int response = getIntInput();

							if (response < 0 || response > num)
							{
								std::cout << "Invalid Input" << '\n';
								response = getIntInput();
							}

							if (response > 0)
							{
								std::cout << "Choose weapon to replace selected weapon" << '\n';
								for (int i = 0; i < weapons.size(); i++)
								{
									std::cout << i + 1 << ". " << weapons[i].getName() << '\n';
								}

								int response2 = getIntInput();

								if (response2 < 1 || response > weapons.size())
								{
									std::cout << "Invalid Input" << '\n';
									response2 = getIntInput();
								}

								Weapon temp = weapons[response2 - 1];

								switch (response)
								{
								case 1:
								{
									NPCs[test].w1 = temp;
									break;
								}
								case 2:
								{
									NPCs[test].w2 = temp;
									break;
								}
								case 3:
								{
									NPCs[test].w3 = temp;
									break;
								}
								case 4:
								{
									NPCs[test].w4 = temp;
									break;
								}
								case 5:
								{
									NPCs[test].w5 = temp;
									break;
								}
								}
							}

						}
						else
						{
							std::cout << "Error: character not found" << '\n';
						}
					}
				}
				else
				{
					std::cout << "Error: Unrecognized Command: '" << args[2] << "'" << '\n';
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "combat" && combatants.size() > 0)
		{
			if (args.size() < 2)
			{
				// launch combat
				escapeCode = combatEncounter(args, playerCharacters, NPCs, combatants, weapons, armor, encounters, currentEncounter);
			}
			else if (combatants.size() < 1)
			{
				std::cout << "Error: no characters are loaded in current encounter" << '\n';
			}
			else
			{
				// load encounter matching args[1], then launch combat
				int test = encounterLookup(encounters, args[1], 0, encounters.size() - 1);
				if (test != -1)
				{
					loadCombatants(encounters[test], playerCharacters, NPCs, combatants);
					currentEncounter = encounters[test];
					escapeCode = combatEncounter(args, playerCharacters, NPCs, combatants, weapons, armor, encounters, currentEncounter);
				}
				else
				{
					std::cout << "Error: Encounter not found" << '\n';
				}
			}
		}
		else if (args[0] == "kill")
		{
			if (args.size() < 2 && combatants.size() > 0)
			{
				// display combatants and set user selection.alive to false
				std::cout << "Select character to remove from combat (will be skipped in combat until revived)" << '\n';
				std::cout << "0. None" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
				}
				int response = getIntInput();
				while (response < 0 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}
				combatants[response - 1].knockOut();
			}
			else if (combatants.size() < 1)
			{
				std::cout << "Error: no characters are loaded in current encounter" << '\n';
			}
			else
			{
				// set combatant matching args[1] alive to false
				int test = unsortedLookup(combatants, args[1]);
				if (test != -1)
				{
					combatants[test].knockOut();
				}
				else
				{
					std::cout << "Combatant not found" << '\n';
				}
			}
		}
		else if (args[0] == "revive")
		{
		if (args.size() < 2 && combatants.size() > 0)
		{
			// display combatants and set user selection.alive to true
			std::cout << "Select character to revive" << '\n';
			std::cout << "0. None" << '\n';
			for (int i = 0; i < combatants.size(); i++)
			{
				std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
			}
			int response = getIntInput();
			while (response < 0 || response > combatants.size())
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}
			combatants[response - 1].revive();
		}
		else if (combatants.size() < 1)
		{
			std::cout << "Error: no characters are loaded in current encounter" << '\n';
		}
		else
		{
			// set combatant matching args[1] alive to true
			int test = unsortedLookup(combatants, args[1]);
			if (test != -1)
			{
				combatants[test].revive();
			}
			else
			{
				std::cout << "Combatant not found" << '\n';
			}
		}
		}
		else if (args[0] == "activate")
		{
			if (args.size() > 1)
			{
				if (args[1] == "npc")
				{
					activateNPC(NPCs, combatants);
				}
				else if (args[1] == "character")
				{
					// display characters, get user selection, and add to combatants
					std::cout << "Select character to add to current encounter" << '\n';
					std::cout << "0. None" << '\n';
					for (int i = 0; i < playerCharacters.size(); i++)
					{
						std::cout << i + 1 << ". " << playerCharacters[i].getName() << '\n';
					}
					int response = getIntInput();
					while (response < 0 || response > playerCharacters.size())
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}
					if (response != 0)
					{
						combatants.push_back(playerCharacters[response - 1]);
					}
				}
			}
			else
			{
				std::cout << "Error: Not enough arguments" << '\n';
			}
		}
		else if (args[0] == "remove")
		{
			if (args.size() < 2 && combatants.size() > 0)
			{
				//display combatants and remove user selection from vector
				std::cout << "Select character to remove from encounter:" << '\n';
				std::cout << "0. None" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
				}
				int response = getIntInput();
				while (response < 0 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}
				if (response != 0)
				{
					combatants.erase(combatants.begin() + (response - 1));
				}
			}
			else if (combatants.size() < 1)
			{
				std::cout << "Error: no characters are loaded in current encounter" << '\n';
			}
			else
			{
				// remove combatant matching args[1]
				int test = unsortedLookup(combatants, args[1]);
				if (test != -1)
				{
					combatants.erase(combatants.begin() + test);
				}
				else
				{
					std::cout << "Combatant not found" << '\n';
				}
			}
		}
		else if (args[0] == "rollskill")
		{
			if (args.size() < 2 && combatants.size() > 0)
			{
				// display all combatants, get user selection, call rollskill method
				std::cout << "Select character to roll skill:" << '\n';
				std::cout << "0. None" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
				}
				int response = getIntInput();
				while (response < 0 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}
				if (response != 0)
				{
					combatants[response - 1].rollSkill(combatants);
				}
			}
			else if (combatants.size() < 1)
			{
				std::cout << "Error: no characters are loaded in current encounter" << '\n';
			}
			else if (args.size() < 3)
			{
				// call rollskill method for character matching args[1]
				int test = unsortedLookup(combatants, args[1]);
				if (test != -1)
				{
					combatants[test].rollSkill(combatants);
				}
				else
				{
					std::cout << "Combatant not found" << '\n';
				}
			}
			else
			{
				// call rollskill method for character matching args[1], with skill matching args[2]
				int test = unsortedLookup(combatants, args[1]);
				if (test != -1)
				{
					skill s = stringToSkill(args[2]);
					if (s != skill::other)
					{
						combatants[test].rollSkill(s, combatants);
					}
					else
					{
						std::cout << "Error: Unkown Skill" << '\n';
					}
					
				}
				else
				{
					std::cout << "Combatant not found" << '\n';
				}
			}
		}
		else if (args[0] == "attack")
		{
			if (args.size() < 2 && combatants.size() > 1)
			{
				// display all combatants, get user selection for attacker, get user selection for defender, call attackDefend function
				int attacker = -1;
				int defender = -1;
				std::cout << "Select attacker:" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i << ". " << combatants[i].getName() << '\n';
				}
				int response = getIntInput();
				while (response < 0 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}
				attacker = response;

				std::cout << "Select defender:" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i << ". " << combatants[i].getName() << '\n';
				}
				response = getIntInput();
				while (response < 0 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}
				defender = response;
				attackDefend(combatants[attacker], combatants[defender]);
			}
			else if (combatants.size() < 2)
			{
				std::cout << "Error: not enough characters loaded in current encounter" << '\n';
			}
			else if (args.size() < 3)
			{
				// find combatant matching arg[1] (attacker), display all combatants, get user selection for defender, call attackDefend function
				int test = unsortedLookup(combatants, args[1]);
				if (test != -1)
				{
					std::cout << "Select defender:" << '\n';
					for (int i = 0; i < combatants.size(); i++)
					{
						std::cout << i << ". " << combatants[i].getName() << '\n';
					}
					int response = getIntInput();
					while (response < 0 || response > combatants.size() - 1)
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}
					int defender = response;
					attackDefend(combatants[test], combatants[defender]);
				}
				else
				{
					std::cout << "Attacker not found" << '\n';
				}
			}
			else
			{
				// find combatant matching arg[1] (attacker), args[2] (defender), call attackDefend function
				int test = unsortedLookup(combatants, args[1]);
				int test2 = unsortedLookup(combatants, args[2]);
				if (test != -1 && test2 != -1)
				{
					attackDefend(combatants[test], combatants[test2]);
				}
				else if(test == -1)
				{
					std::cout << "Attacker not found" << '\n';
				}
				else if (test2 == -1)
				{
					std::cout << "Defender not found" << '\n';
				}
			}
		}
		else if (args[0] == "heal")
		{
			if (args.size() < 2 && combatants.size() > 0)
			{
				// display all combatants, get user selection for character to heal, get user selection for body part, change wound level
				std::cout << "select combatant to heal:" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
				}

				int response = getIntInput();
				while (response < 1 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}

				std::cout << "select body part to heal:" << '\n';
				std::cout << "1. All/General Wound Level (" << combatants[response - 1].getWoundLevel() << '\n';
				std::cout << "2. Head (" << combatants[response - 1].getWoundLevel(bodyPrt::head) << '\n';
				std::cout << "3. Neck (" << combatants[response - 1].getWoundLevel(bodyPrt::neck) << '\n';
				std::cout << "4. Right Arm (" << combatants[response - 1].getWoundLevel(bodyPrt::rightArm) << '\n';
				std::cout << "5. Left Arm (" << combatants[response - 1].getWoundLevel(bodyPrt::leftArm) << '\n';
				std::cout << "6. Chest (" << combatants[response - 1].getWoundLevel(bodyPrt::chest) << '\n';
				std::cout << "7. Gut (" << combatants[response - 1].getWoundLevel(bodyPrt::gut) << '\n';
				std::cout << "8. Right Leg (" << combatants[response - 1].getWoundLevel(bodyPrt::rightLeg) << '\n';
				std::cout << "9. Left Leg (" << combatants[response - 1].getWoundLevel(bodyPrt::leftLeg) << '\n';

				int response2 = getIntInput();
				while (response2 < 0 || response2 > 9)
				{
					std::cout << "Invalid Input" << '\n';
					response2 = getIntInput();
				}

				if (response2 == 1)
				{
					response2 = 10;
				}

				std::cout << "Enter amount to heal (will subtract from wound level)" << '\n';

				int response3 = getIntInput();
				while (response3 > combatants[response - 1].getWoundLevel(static_cast<bodyPrt>(response2 - 2)))
				{
					response3 = combatants[response - 1].getWoundLevel(static_cast<bodyPrt>(response2 - 2));
				}

				if (response3 > 0)
				{
					int newLevel = combatants[response - 1].getWoundLevel(static_cast<bodyPrt>(response2 - 2)) - response3;
					combatants[response - 1].heal(static_cast<bodyPrt>(response2 - 2), newLevel);
				}
				
			}
			else if (combatants.size() < 1)
			{
				std::cout << "Error: no characters are loaded in current encounter" << '\n';
			}
			else if (args.size() < 3)
			{
				// find combatant matching arg[1], get user selection for body part, change wound level
				int test = unsortedLookup(combatants, args[1]);
				if (test > -1)
				{
					std::cout << "select body part to heal:" << '\n';
					std::cout << "1. All/General Wound Level (" << combatants[test].getWoundLevel() << '\n';
					std::cout << "2. Head (" << combatants[test].getWoundLevel(bodyPrt::head) << '\n';
					std::cout << "3. Neck (" << combatants[test].getWoundLevel(bodyPrt::neck) << '\n';
					std::cout << "4. Right Arm (" << combatants[test].getWoundLevel(bodyPrt::rightArm) << '\n';
					std::cout << "5. Left Arm (" << combatants[test].getWoundLevel(bodyPrt::leftArm) << '\n';
					std::cout << "6. Chest (" << combatants[test].getWoundLevel(bodyPrt::chest) << '\n';
					std::cout << "7. Gut (" << combatants[test].getWoundLevel(bodyPrt::gut) << '\n';
					std::cout << "8. Right Leg (" << combatants[test].getWoundLevel(bodyPrt::rightLeg) << '\n';
					std::cout << "9. Left Leg (" << combatants[test].getWoundLevel(bodyPrt::leftLeg) << '\n';

					int response2 = getIntInput();
					while (response2 < 0 || response2 > 9)
					{
						std::cout << "Invalid Input" << '\n';
						response2 = getIntInput();
					}

					if (response2 == 1)
					{
						response2 = 10;
					}

					std::cout << "Enter amount to heal (will subtract from wound level)" << '\n';

					int response3 = getIntInput();
					while (response3 > combatants[test].getWoundLevel(static_cast<bodyPrt>(response2 - 2)))
					{
						response3 = combatants[test].getWoundLevel(static_cast<bodyPrt>(response2 - 2));
					}

					if (response3 > 0)
					{
						int newLevel = combatants[test].getWoundLevel(static_cast<bodyPrt>(response2 - 2)) - response3;
						combatants[test].heal(static_cast<bodyPrt>(response2 - 2), newLevel);
					}
				}
				else
				{
					std::cout << "Error: could not find combatant: " << args[1] << '\n';
				}
			}
			else
			{
				// find combatant matching arg[1], body part = args[2], apply to wound level
				int test = unsortedLookup(combatants, args[1]);
				if (test > -1)
				{
					bodyPrt bp = bodyPrt::all;
					bool validbp = true;

					if (args[2] == "all")
					{
						bp = bodyPrt::all;
					}
					else if (args[2] == "head")
					{
						bp = bodyPrt::head;
					}
					else if (args[2] == "neck")
					{
						bp = bodyPrt::neck;
					}
					else if (args[2] == "rightArm")
					{
						bp = bodyPrt::rightArm;
					}
					else if (args[2] == "leftArm")
					{
						bp = bodyPrt::leftArm;
					}
					else if (args[2] == "chest")
					{
						bp = bodyPrt::chest;
					}
					else if (args[2] == "gut")
					{
						bp = bodyPrt::gut;
					}
					else if (args[2] == "rightLeg")
					{
						bp = bodyPrt::rightLeg;
					}
					else if (args[2] == "leftLeg")
					{
						bp = bodyPrt::leftLeg;
					}
					else
					{
						std::cout << "Error: Unknown body part" << '\n';
						validbp = false;
					}

					if (validbp == true)
					{
						int healLevel = 0;
						if (isInteger(args[3]) == true)
						{
							healLevel = std::stoi(args[3]);
						}
						else
						{
							std::cout << "Enter level to subtract from wound level" << '\n';
							int response = getIntInput();
							if (response > combatants[test].getWoundLevel(bp))
							{
								healLevel = combatants[test].getWoundLevel(bp);
							}
							else
							{
								healLevel = response;
							}

							int newLevel = combatants[test].getWoundLevel(bp) - healLevel;
							combatants[test].heal(bp, newLevel);
						}
					}
				}
				else
				{
					std::cout << "Error: could not find combatant: " << args[1] << '\n';
				}
			}
		}
		else if (args[0] == "reload")
		{
			if (args.size() < 2 && combatants.size() > 0)
			{
				// display all combatants, get user selection for character, get user selection weapon, reload weapon
				std::cout << "Choose character to reload:" << '\n';
				for (int i = 0; i < combatants.size(); i++)
				{
					std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
				}
				int response = getIntInput();
				while (response < 1 || response > combatants.size())
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}
				int numWeps = 0;
				std::cout << '\n' << "Choose Weapon to reload:" << '\n';
				if (combatants[response - 1].w1.getName() != "" && combatants[response - 1].w2.getName() != "" && combatants[response - 1].w3.getName() != ""
					&& combatants[response - 1].w4.getName() != "" && combatants[response - 1].w5.getName() != "")
				{
					std::cout << "1. " << combatants[response - 1].w1.getName() << '\n';
					std::cout << "2. " << combatants[response - 1].w2.getName() << '\n';
					std::cout << "3. " << combatants[response - 1].w3.getName() << '\n';
					std::cout << "4. " << combatants[response - 1].w4.getName() << '\n';
					std::cout << "5. " << combatants[response - 1].w5.getName() << '\n';
					numWeps = 5;
				}
				else if (combatants[response - 1].w1.getName() != "" && combatants[response - 1].w2.getName() != "" && combatants[response - 1].w3.getName() != ""
					&& combatants[response - 1].w4.getName() != "")
				{
					std::cout << "1. " << combatants[response - 1].w1.getName() << '\n';
					std::cout << "2. " << combatants[response - 1].w2.getName() << '\n';
					std::cout << "3. " << combatants[response - 1].w3.getName() << '\n';
					std::cout << "4. " << combatants[response - 1].w4.getName() << '\n';
					numWeps = 4;
				}
				else if (combatants[response - 1].w1.getName() != "" && combatants[response - 1].w2.getName() != "" && combatants[response - 1].w3.getName() != "")
				{
					std::cout << "1. " << combatants[response - 1].w1.getName() << '\n';
					std::cout << "2. " << combatants[response - 1].w2.getName() << '\n';
					std::cout << "3. " << combatants[response - 1].w3.getName() << '\n';
					numWeps = 3;
				}
				else if (combatants[response - 1].w1.getName() != "" && combatants[response - 1].w2.getName() != "")
				{
					std::cout << "1. " << combatants[response - 1].w1.getName() << '\n';
					std::cout << "2. " << combatants[response - 1].w2.getName() << '\n';
					numWeps = 2;
				}
				else
				{
					std::cout << "1. " << combatants[response - 1].w1.getName() << '\n';
					numWeps = 1;
				}

				int response2 = getIntInput();
				while (response2 < 1 || response2 > numWeps)
				{
					std::cout << "Invalid Input" << '\n';
					response2 = getIntInput();
				}

				switch (response2)
				{
					case 1:
					{
						combatants[response - 1].w1.reloadAll();
						break;
					}
					case 2:
					{
						combatants[response - 1].w2.reloadAll();
						break;
					}
					case 3:
					{
						combatants[response - 1].w3.reloadAll();
						break;
					}
					case 4:
					{
						combatants[response - 1].w4.reloadAll();
						break;
					}
					case 5:
					{
						combatants[response - 1].w5.reloadAll();
						break;
					}
				}
			}
			else if (combatants.size() < 1)
			{
				std::cout << "Error: no characters are loaded in current encounter" << '\n';
			}
			else if (args.size() < 3)
			{
				// find combatant matching arg[1], get user selection for weapon, reload weapon
				int test = unsortedLookup(combatants, args[1]);
				if (test > -1)
				{
					int numWeps = 0;
					std::cout << '\n' << "Choose Weapon to reload:" << '\n';
					if (combatants[test].w1.getName() != "" && combatants[test].w2.getName() != "" && combatants[test].w3.getName() != ""
						&& combatants[test].w4.getName() != "" && combatants[test].w5.getName() != "")
					{
						std::cout << "1. " << combatants[test].w1.getName() << '\n';
						std::cout << "2. " << combatants[test].w2.getName() << '\n';
						std::cout << "3. " << combatants[test].w3.getName() << '\n';
						std::cout << "4. " << combatants[test].w4.getName() << '\n';
						std::cout << "5. " << combatants[test].w5.getName() << '\n';
						numWeps = 5;
					}
					else if (combatants[test].w1.getName() != "" && combatants[test].w2.getName() != "" && combatants[test].w3.getName() != ""
						&& combatants[test].w4.getName() != "")
					{
						std::cout << "1. " << combatants[test].w1.getName() << '\n';
						std::cout << "2. " << combatants[test].w2.getName() << '\n';
						std::cout << "3. " << combatants[test].w3.getName() << '\n';
						std::cout << "4. " << combatants[test].w4.getName() << '\n';
						numWeps = 4;
					}
					else if (combatants[test].w1.getName() != "" && combatants[test].w2.getName() != "" && combatants[test].w3.getName() != "")
					{
						std::cout << "1. " << combatants[test].w1.getName() << '\n';
						std::cout << "2. " << combatants[test].w2.getName() << '\n';
						std::cout << "3. " << combatants[test].w3.getName() << '\n';
						numWeps = 3;
					}
					else if (combatants[test].w1.getName() != "" && combatants[test].w2.getName() != "")
					{
						std::cout << "1. " << combatants[test].w1.getName() << '\n';
						std::cout << "2. " << combatants[test].w2.getName() << '\n';
						numWeps = 2;
					}
					else
					{
						std::cout << "1. " << combatants[test].w1.getName() << '\n';
						numWeps = 1;
					}

					int response2 = getIntInput();
					while (response2 < 1 || response2 > numWeps)
					{
						std::cout << "Invalid Input" << '\n';
						response2 = getIntInput();
					}

					switch (response2)
					{
					case 1:
					{
						combatants[test].w1.reloadAll();
						break;
					}
					case 2:
					{
						combatants[test].w2.reloadAll();
						break;
					}
					case 3:
					{
						combatants[test].w3.reloadAll();
						break;
					}
					case 4:
					{
						combatants[test].w4.reloadAll();
						break;
					}
					case 5:
					{
						combatants[test].w5.reloadAll();
						break;
					}
					}
				}
				else
				{
					std::cout << "Error: combatant not found" << '\n';
				}
			}
			else
			{
				// find combatant matching arg[1], find weapon matching args[2], reload weapon
				int test = unsortedLookup(combatants, args[1]);
				if (test > -1)
				{
					if (args[1] == combatants[test].w1.getName())
					{
						combatants[test].w1.reloadAll();
					}
					else if (args[1] == combatants[test].w2.getName())
					{
						combatants[test].w2.reloadAll();
					}
					else if (args[1] == combatants[test].w3.getName())
					{
						combatants[test].w3.reloadAll();
					}
					else if (args[1] == combatants[test].w4.getName())
					{
						combatants[test].w4.reloadAll();
					}
					else if (args[1] == combatants[test].w5.getName())
					{
						combatants[test].w5.reloadAll();
					}
					else
					{
						std::cout << "Error: Weapon not found" << '\n';
					}
				}
				else
				{
					std::cout << "Error: combatant not found" << '\n';
				}
			}
		}
		else// first arg not recognized
		{
			std::cout << "Error: Unrecognized Command: '" <<  args[0] << "'" << '\n';
		}
	}

	std::cout << '\n';

	return escapeCode;
}

void getCommandInput(std::vector<std::string>& args)
{
	args.clear();
	
	std::string input;
	std::cout << "Enter command (type 'commands' for list of commands) ('endprogram' to exit program)" << '\n';

	std::getline(std::cin, input);

	int argNum = 0;
	args.push_back("");

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != '/')
		{
			args[argNum] += input[i];
		}
		else
		{
			argNum++;
			args.push_back("");
		}
	}

}

skill stringToSkill(std::string& s)
{
	if (s == "grapple")
	{
		return skill::S_grapple;
	}
	if (s == "melee")
	{
		return skill::S_melee;
	}
	if (s == "strenght ranged" || s == "ranged strength")
	{
		return skill::S_strenghtRanged;
	}
	if (s == "dex ranged" || s == "ranged dex")
	{
		return skill::S_dexRanged;
	}
	if (s == "initiative")
	{
		return skill::S_initiative;
	}
	if (s == "athletics")
	{
		return skill::S_athletics;
	}
	if (s == "acrobatics")
	{
		return skill::S_Acrobatics;
	}
	if (s == "constitution")
	{
		return skill::S_constitution;
	}
	if (s == "evasion")
	{
		return skill::S_evasion;
	}
	if (s == "perception" || s == "investigation")
	{
		return skill::S_perception_Investigation;
	}
	if (s == "tactics" || s == "command")
	{
		return skill::S_tactics_Command;
	}
	if (s == "artillery")
	{
		return skill::S_artillery;
	}
	if (s == "strength")
	{
		return skill::S_strength;
	}
	if (s == "ride" || s == "riding" || s == "pilot" || s == "piloting" || s == "ride pilot")
	{
		return skill::S_ride_Pilot;
	}
	if (s == "stealth" || s == "slight of hand")
	{
		return skill::S_stealth_SlightofHand;
	}
	if (s == "persuasion" || s == "deception")
	{
		return skill::S_persuasion_Deception;
	}
	if (s == "charm" || s == "seduction")
	{
		return skill::S_charm_Seduction;
	}
	if (s == "intimidation")
	{
		return skill::S_intimidation;
	}
	if (s == "fortitute" || s == "tolerence")
	{
		return skill::S_fortitude_Tolerence;
	}
	if (s == "navigation")
	{
		return skill::S_navigation;
	}
	if (s == "survival")
	{
		return skill::S_survival;
	}
	if (s == "technology")
	{
		return skill::S_technology;
	}
	if (s == "engineering")
	{
		return skill::S_engineering;
	}
	if (s == "medicine")
	{
		return skill::S_medicine;
	}
	if (s == "calculation" || s == "mathematics")
	{
		return skill::S_calculation_Mathematics;
	}
	if (s == "memory")
	{
		return skill::S_memory;
	}
	if (s == "language" || s == "linguistics")
	{
		return skill::S_languages_linguistics;
	}
	if (s == "sketching" || s == "painting")
	{
		return skill::S_sketching_Painting;
	}
	if (s == "sculpting" || s == "carving")
	{
		return skill::S_sculpting_Carving;
	}
	if (s == "sewing" || s == "weaving" || s == "knitting")
	{
		return skill::S_sewing_Weaving_Knitting;
	}
	if (s == "oratory" || s == "performance")
	{
		return skill::S_oratory_Performance;
	}
	if (s == "writing")
	{
		return skill::S_writing_Composition;
	}
	if (s == "dance")
	{
		return skill::S_dance;
	}
	if (s == "music composition")
	{
		return skill::S_music_Composition;
	}
	if (s == "instrumental performance")
	{
		return skill::S_music_InstrumentalPerformance;
	}
	if (s == "vocal performance")
	{
		return skill::S_music_VocalPerformance;
	}
	return skill::other;
}

void loadCombatants(std::string encounter, std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants)
{
	std::vector<std::string> names;
	std::vector<int> nums;
	std::string temp;
	std::ifstream inFile;

	if (encounter != "")
	{
		combatants.clear();
		inFile.open(encounter + ".txt");
		while (!inFile.eof())
		{
			std::getline(inFile, temp, '\n');
			if (temp != "")
			{
				names.push_back(temp);
				std::getline(inFile, temp, '\n');
				nums.push_back(std::stoi(temp));
			}
		}
		inFile.close();
		
		if (names.size() == nums.size())
		{
			int test = -1;
			for (int i = 0; i < names.size(); i++)
			{
				if (nums[i] == 0)
				{
					test = vectorLookup(playerCharacters, names[i], 0, playerCharacters.size() - 1);
					if ( test != -1)
					{
						combatants.push_back(playerCharacters[test]);
					}
				}
				else
				{
					test = vectorLookup(NPCs, names[i], 0, NPCs.size() - 1);
					if (test != -1)
					{
						for (int j = 0; j < nums[i]; j++)
						{
							combatants.push_back(NPCs[test]);
						}
					}
				}
			}
			int n = 0;
			for (int i = 0; i < combatants.size(); i++)
			{
				if (combatants[i].getNPC() == true)
				{
					std::string s = " (" + std::to_string(n) + ")";
					combatants[i].setID(s);
					n++;
				}
			}
		}
	}
	
}

std::string getEncounter(std::vector<std::string>& encounters, std::string& currentEncounter)
{
	std::cout << "Select Encounter" << '\n';
	std::cout << "0. None" << '\n';
	for (int i = 0; i < encounters.size(); i++)
	{
		std::cout << i + 1 << ". " << encounters[i] << '\n';
	}

	int response = getIntInput();

	while (response < 0 || response > encounters.size())
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	if (response != 0)
	{
		currentEncounter = encounters[response - 1];
		return encounters[response - 1];
	}
	else
	{
		return "";
	}
}

int encounterLookup(std::vector<std::string>& vector, std::string encounter, const int& l, const int& r)
{

	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (vector[mid] == encounter)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (vector[mid] > encounter)
			return encounterLookup(vector, encounter, l, mid - 1);

		// Else the element can only be present
		// in right subarray
		return encounterLookup(vector, encounter, mid + 1, r);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

void displayEncounters(std::vector<std::string>& encounters)
{
	for (int i = 0; i < encounters.size(); i++)
	{
		std::cout << encounters[i] << '\n';
	}
}

void deleteEncounter(std::vector<std::string>& encounters)
{
	std::cout << "Select encounter to delete:" << '\n';
	std::cout << "0. None" << '\n';

	for (int i = 0; i < encounters.size(); i++)
	{
		std::cout << i + 1 << ". " << encounters[i] << '\n';
	}

	int response = getIntInput();

	while (response < 0 || response > encounters.size())
	{
		std::cout << "Invalid Input" << '\n';
	}

	if (response != 0)
	{
		std::string s = encounters[response - 1] + ".txt";
		std::remove(s.c_str());
		
		encounters.erase(encounters.begin() + (response - 1));

		std::ofstream outFile;
		outFile.open("Encounters.txt", std::ios::trunc);
		outFile.close();
		outFile.open("Encounters.txt", std::ios::app);
		for (int i = 0; i < encounters.size(); i++)
		{
			outFile << encounters[i] << '\n';
		}
		outFile.close();
	}
}

void newEncounter(std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants, std::vector<std::string>& encounters)
{
	std::string name = "";
	std::cout << "Enter encounter name" << '\n';
	std::getline(std::cin, name);

	// write name to encounters file
	std::ofstream outFile;
	outFile.open("Encounters.txt", std::ios::app);
	outFile << name << '\n';
	outFile.close();

	std::vector<std::string> names;
	std::vector<int> nums;
	getCombatants(playerCharacters, NPCs, names, nums);
	// write combatants to new file
	
	outFile.open(name + ".txt", std::ios::app);
	
	for (int i = 0; i < names.size() && i < nums.size(); i++)
	{
		outFile << names[i] << '\n';
		outFile << nums[i] << '\n';
	}
	outFile.close();
	loadEncounters(encounters);
}

void getCombatants(std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<std::string>& names, std::vector<int>& nums)
{
	int response = -1;

	names.clear();
	nums.clear();

	while (response != 0)
	{
		int i = 0;
		std::cout << "Choose player character combatants" << '\n';
		std::cout << "0. None (Proceed to NPCs)" << '\n';
		for (i = 0; i < playerCharacters.size(); i++)
		{
			std::cout << i + 1 << ". " << playerCharacters[i].getName() << '\n';
		}

		response = getIntInput();

		while (response < 0 || response > playerCharacters.size())
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response != 0)
		{
			names.push_back(playerCharacters[response - 1].getName());
			nums.push_back(0);
			playerCharacters.erase(playerCharacters.begin() + (response - 1));
		}
	}

	playerCharacters.clear();

	loadCharacterVector(playerCharacters);

	response = -1;

	while (response != 0)
	{
		std::cout << "Choose NPC combatant" << '\n';
		std::cout << "0. Done (Save Combatants)" << '\n';
		
		for (int i = 0; i < NPCs.size(); i++)
		{
			std::cout << i + 1 << ". " << NPCs[i].getName() << '\n';
		}

		response = getIntInput();

		while (response < 0 || response > NPCs.size())
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response > 0)
		{
			std::cout << "Enter number to add" << '\n';
			int num = getIntInput();
			if (num > 0)
			{
				names.push_back(NPCs[response - 1].getName());
				nums.push_back(num);
			}
		}
	}
}

void loadEncounters(std::vector<std::string>& encounters)
{
	encounters.clear();
	std::ifstream inFile;
	inFile.open("Encounters.txt");
	std::string temp = "";
	while (!inFile.eof())
	{
		std::getline(inFile, temp, '\n');

		if (temp != "")
		{
			encounters.push_back(temp);
		}
	}
	inFile.close();
	sortEncounters(encounters);
}

void sortEncounters(std::vector<std::string>& encounters)
{
	int i, j, min_idx;
	int n = encounters.size();

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (encounters[j] < encounters[min_idx])
				min_idx = j;

		// Swap the found minimum element
		// with the first element
		std::string temp = encounters[min_idx];
		encounters[min_idx] = encounters[i];
		encounters[i] = temp;
	}
}

void displayNPCs(std::vector<Character>& NPCs)
{
	for (int i = 0; i < NPCs.size(); i++)
	{
		std::cout << '\n' << NPCs[i].getName() << '\n';
		std::cout << "Resistances: " << NPCs[i].getResistance(damageType::blunt) << " blunt, "
			<< NPCs[i].getResistance(damageType::cut) << " cut, "
			<< NPCs[i].getResistance(damageType::pierce) << " pierce, "
			<< NPCs[i].getResistance(damageType::chop) << " chop, "
			<< NPCs[i].getResistance(damageType::ballistic) << " ballistic, "
			<< NPCs[i].getResistance(damageType::environmental) << " environmental, "
			<< NPCs[i].getResistance(damageType::flame) << " flame, "
			<< NPCs[i].getResistance(damageType::energy) << " energy, "
			<< NPCs[i].getResistance(damageType::shock) << " shock, "
			<< NPCs[i].getResistance(damageType::acid) << " acid, "
			<< NPCs[i].getResistance(damageType::magical) << " magical" << '\n' << '\n';
		std::cout << "Skills: " << '\n' << '\n';
		std::cout << "Grapple: " << NPCs[i].getTrueSkillLevel(skill::S_grapple) << '\n';
		std::cout << "Melee: " << NPCs[i].getTrueSkillLevel(skill::S_melee) << '\n';
		std::cout << "Strength Ranged: " << NPCs[i].getTrueSkillLevel(skill::S_strenghtRanged) << '\n';
		std::cout << "Dex Ranged: " << NPCs[i].getTrueSkillLevel(skill::S_dexRanged) << '\n';
		std::cout << "Initiative: " << NPCs[i].getTrueSkillLevel(skill::S_initiative) << '\n';
		std::cout << "Athletics: " << NPCs[i].getTrueSkillLevel(skill::S_athletics) << '\n';
		std::cout << "Acrobatics: " << NPCs[i].getTrueSkillLevel(skill::S_Acrobatics) << '\n';
		std::cout << "Constitution: " << NPCs[i].getTrueSkillLevel(skill::S_constitution) << '\n';
		std::cout << "Evasion: " << NPCs[i].getTrueSkillLevel(skill::S_evasion) << '\n' << '\n';
		std::cout << "Weapon 1:" << NPCs[i].w1.getName() << '\n';
		std::cout << "Weapon 2:" << NPCs[i].w2.getName() << '\n';
		std::cout << "Weapon 3:" << NPCs[i].w3.getName() << '\n';
		if (NPCs[i].getNPC() != true)
		{
			std::cout << "Weapon 4:" << NPCs[i].w4.getName() << '\n';
			std::cout << "Weapon 5:" << NPCs[i].w5.getName() << '\n';
		}
	}
}

int weaponLookup(std::vector<Weapon>& vector, std::string weaponName, const int& l, const int& r)
{

	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (vector[mid].getName() == weaponName)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (vector[mid].getName() > weaponName)
			return weaponLookup(vector, weaponName, l, mid - 1);

		// Else the element can only be present
		// in right subarray
		return weaponLookup(vector, weaponName, mid + 1, r);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

void displayWeapons(std::vector<Weapon>& weapons)
{
	
	for (int i = 0; i < weapons.size(); i++)
	{
		std::cout << weapons[i].getName() << '\n';
		std::cout << "Max Loaded: " << weapons[i].getMaxAmmo() << "  Ammo per shot: " << weapons[i].getAmmoPerShot() << '\n';

		if (weapons[i].a1.getName() != "")
		{
			std::cout << "     " << weapons[i].a1.getName() << '\n';
			std::cout << "          Damage: 1d" << weapons[i].a1.getBaseDamage() << " + " << weapons[i].a1.getDamageModifier() << " " << damageTypeToString(weapons[i].a1.getDamageType()) << " damage" << '\n';
			std::cout << "          Grapple: " << weapons[i].a1.getGrappleBonus() << "  Melee: " << weapons[i].a1.getMeleeBonus() << "  Short: " << weapons[i].a1.getShortRangeBonus() << "  Medium: " << weapons[i].a1.getMediumRangeBonus() << "  Long: " << weapons[i].a1.getLongRangeBonus() << '\n';
			
			if (weapons[i].a1.getRangeAttackType() == skill::S_strenghtRanged)
			{
				std::cout << "          Range Attack Type: Strength Ranged" << '\n';
			}
			else if (weapons[i].a1.getRangeAttackType() == skill::S_dexRanged)
			{
				std::cout << "          Range Attack Type: Dex Ranged" << '\n';
			}

			if (weapons[i].a2.getName() != "")
			{
				std::cout << "     " << weapons[i].a2.getName() << '\n';
				std::cout << "          Damage: 1d" << weapons[i].a2.getBaseDamage() << " + " << weapons[i].a2.getDamageModifier() << " " << damageTypeToString(weapons[i].a2.getDamageType()) << " damage" << '\n';
				std::cout << "          Grapple: " << weapons[i].a2.getGrappleBonus() << "  Melee: " << weapons[i].a2.getMeleeBonus() << "  Short: " << weapons[i].a2.getShortRangeBonus() << "  Medium: " << weapons[i].a2.getMediumRangeBonus() << "  Long: " << weapons[i].a2.getLongRangeBonus() << '\n';

				if (weapons[i].a2.getRangeAttackType() == skill::S_strenghtRanged)
				{
					std::cout << "          Range Attack Type: Strength Ranged" << '\n';
				}
				else if (weapons[i].a2.getRangeAttackType() == skill::S_dexRanged)
				{
					std::cout << "          Range Attack Type: Dex Ranged" << '\n';
				}

				if (weapons[i].a3.getName() != "")
				{
					std::cout << "     " << weapons[i].a3.getName() << '\n';
					std::cout << "          Damage: 1d" << weapons[i].a3.getBaseDamage() << " + " << weapons[i].a3.getDamageModifier() << " " << damageTypeToString(weapons[i].a3.getDamageType()) << " damage" << '\n';
					std::cout << "          Grapple: " << weapons[i].a3.getGrappleBonus() << "  Melee: " << weapons[i].a3.getMeleeBonus() << "  Short: " << weapons[i].a3.getShortRangeBonus() << "  Medium: " << weapons[i].a3.getMediumRangeBonus() << "  Long: " << weapons[i].a3.getLongRangeBonus() << '\n';

					if (weapons[i].a3.getRangeAttackType() == skill::S_strenghtRanged)
					{
						std::cout << "          Range Attack Type: Strength Ranged" << '\n';
					}
					else if (weapons[i].a3.getRangeAttackType() == skill::S_dexRanged)
					{
						std::cout << "          Range Attack Type: Dex Ranged" << '\n';
					}

					if (weapons[i].a4.getName() != "")
					{
						std::cout << "     " << weapons[i].a4.getName() << '\n';
						std::cout << "          Damage: 1d" << weapons[i].a4.getBaseDamage() << " + " << weapons[i].a4.getDamageModifier() << " " << damageTypeToString(weapons[i].a4.getDamageType()) << " damage" << '\n';
						std::cout << "          Grapple: " << weapons[i].a4.getGrappleBonus() << "  Melee: " << weapons[i].a4.getMeleeBonus() << "  Short: " << weapons[i].a4.getShortRangeBonus() << "  Medium: " << weapons[i].a4.getMediumRangeBonus() << "  Long: " << weapons[i].a4.getLongRangeBonus() << '\n';

						if (weapons[i].a4.getRangeAttackType() == skill::S_strenghtRanged)
						{
							std::cout << "          Range Attack Type: Strength Ranged" << '\n';
						}
						else if (weapons[i].a4.getRangeAttackType() == skill::S_dexRanged)
						{
							std::cout << "          Range Attack Type: Dex Ranged" << '\n';
						}
					}
				}
			}
		}
	}
}

std::string damageTypeToString(damageType dt)
{
	switch (dt)
	{
		case damageType::blunt:
		{
			return "blunt";
			break;
		}
		case damageType::cut:
		{
			return "cut";
			break;
		}
		case damageType::pierce:
		{
			return "pierce";
			break;
		}
		case damageType::chop:
		{
			return "chop";
			break;
		}
		case damageType::ballistic:
		{
			return "ballistic";
			break;
		}
		case damageType::environmental:
		{
			return "environmental";
			break;
		}
		case damageType::flame:
		{
			return "flame";
			break;
		}
		case damageType::energy:
		{
			return "energy";
			break;
		}
		case damageType::shock:
		{
			return "shock";
			break;
		}
		case damageType::acid:
		{
			return "acid";
			break;
		}
		case damageType::magical:
		{
			return "magical";
			break;
		}
		default:
		{
			return "";
		}
	}
}

int armorLookup(std::vector<Armor>& vector, std::string armorName, const int& l, const int& r)
{

	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (vector[mid].type == armorName)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (vector[mid].type > armorName)
			return armorLookup(vector, armorName, l, mid - 1);

		// Else the element can only be present
		// in right subarray
		return armorLookup(vector, armorName, mid + 1, r);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

void displayArmor(std::vector<Armor>& armor)
{
	std::cout << "Name" << std::setw(14) << "Penalty" << std::setw(14) << "Blunt" << std::setw(14) << "Cut" << std::setw(14)
		<< "Pierce" << std::setw(14) << "Chop" << std::setw(14) << "Ballistic" << std::setw(14) << "Environmental" << std::setw(14)
		<< "Fire" << std::setw(14) << "Energy" << std::setw(14) << "Shock" << std::setw(14) << "Acid" << std::setw(14) << "Magic" << '\n';
	for (int i = 0; i < armor.size(); i++)
	{
		std::cout << armor[i].type << std::setw(14) << armor[i].armorPenalty << std::setw(14) << armor[i].bluntResistance << std::setw(14) << armor[i].cutResistance << std::setw(14)
			<< armor[i].pierceResistance << std::setw(14) << armor[i].chopResistance << std::setw(14) << armor[i].ballisticResistance << std::setw(14) << armor[i].environmentalResistance
			<< std::setw(14) << armor[i].flameResistance << std::setw(14) << armor[i].energyResistance << std::setw(14) << armor[i].shockResistance << std::setw(14) << armor[i].acidResistance
			<< std::setw(14) << armor[i].magicalResistance << std::setw(14) << '\n';
	}
}

void deleteArmorType(std::vector<Armor>& armor)
{
	std::cout << "Select armor to delete" << '\n';
	std::cout << "0. None" << '\n';
	for (int i = 0; i < armor.size(); i++)
	{
		std::cout << i + 1 << ". " << armor[i].type << '\n';
	}

	int response = getIntInput();

	while (response < 0 || response > armor.size())
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	if (response != 0)
	{
		armor.erase(armor.begin() + (response - 1));

		std::ofstream outFile;
		outFile.open("Armor.txt", std::ios::trunc);
		outFile.close();
		for (int i = 0; i < armor.size(); i++)
		{
			writeToArmorFile(armor[i]);
		}
	}
}

int combatEncounter(std::vector<std::string>& args, std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants,
	std::vector<Weapon>& weapons, std::vector<Armor>& armor, std::vector<std::string>& encounters, std::string& currentEncounter)
{
	int escapeCode = 0;

	if (combatants.size() == 0)
	{
		chooseCombatants(playerCharacters, NPCs, combatants);
	}
	
	std::cout << "Revive and heal all combatants?" << '\n';
	std::cout << "1. Yes" << '\n';
	std::cout << "2. No" << '\n';

	int response = getIntInput();
	while (response < 1 || response > 2)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	if (response == 1)
	{
		for (int i = 0; i < combatants.size(); i++)
		{
			combatants[i].revive();
			combatants[i].heal(bodyPrt::all, 0);
		}
	}
	
	while (escapeCode < 2)
	{
		for (int i = 0; i < combatants.size(); i++)
		{
			combatants[i].replenishAction();
			std::cout << '\n';
			combatants[i].rollInitiative();
		}

		int i, j, min_idx;
		int n = combatants.size();
		// One by one move boundary of
		// unsorted subarray
		for (i = 0; i < n - 1; i++)
		{

			// Find the minimum element in
			// unsorted array
			min_idx = i;
			for (j = i + 1; j < n; j++)
				if (combatants[j].getInitiative() < combatants[min_idx].getInitiative())
					min_idx = j;

			// Swap the found minimum element
			// with the first element

			Character temp = combatants[min_idx];
			combatants[min_idx] = combatants[i];
			combatants[i] = temp;
		}

		std::string temp;

		for (int i = 0; i < combatants.size(); i++)
		{
			if (combatants[i].getAlive() == true)
			{
				std::cout << '\n';
				std::cout << "Enter planned action for " << combatants[i].getName() << '\n';
				std::getline(std::cin, temp);
				combatants[i].setAction(temp);
				std::cout << '\n';
				for (int j = 0; j < i + 1; j++)
				{
					if (combatants[j].getAlive() == true)
					{
						std::cout << combatants[j].getName() << " (" << combatants[j].getAction() << ")" << '\n';
					}
				}
			}
		}

		int max_index;
		n = combatants.size();
		// One by one move boundary of
		// unsorted subarray
		for (i = 0; i < n - 1; i++)
		{

			// Find the maximum element in
			// unsorted array
			max_index = i;
			for (j = i + 1; j < n; j++)
				if (combatants[j].getInitiative() > combatants[max_index].getInitiative())
					max_index = j;

			// Swap the found maximum element
			// with the first element

			Character temp = combatants[max_index];
			combatants[max_index] = combatants[i];
			combatants[i] = temp;
		}

		for (int i = 0; i < combatants.size() && escapeCode < 2; i++)
		{
			escapeCode = 0;
			while (escapeCode < 1)
			{
				if (combatants[i].getAlive() == true)
				{
					std::cout << '\n';
					std::cout << "Current encounter: " << currentEncounter << '\n';
					std::cout << '\n';
					std::cout << "Current character: " << combatants[i].getName() << '\n';
					std::cout << combatants[i].getName() << " wound level: " << combatants[i].getWoundLevel() << '\n';
					
					if (combatants[i].getActed() == true)
					{
						std::cout << combatants[i].getName() << " HAS acted this round" << '\n';
					}
					else
					{
						std::cout << combatants[i].getName() << " has NOT acted this round" << '\n';
					}
					std::cout << combatants[i].getName() << " declared action(s): " << combatants[i].getAction() << '\n';
					std::cout << '\n';
					std::cout << "Enter command: 'endturn' to end current player's turn, or 'endcombat' to end combat encounter" << '\n';

					// call command function till endturn command is called
					getCommandInput(args);
					while (args[0] == "encounter")
					{
						std::cout << "Cannot access encounter commands while in combat" << '\n';
						getCommandInput(args);
					}
					while (args[0] == "combat")
					{
						std::cout << "Cannot initiate new combat while combat is in progress ('endcombat' to end current combat)" << '\n';
						getCommandInput(args);
					}
					if (args.size() < 2)
					{
						if (args[0] == "rollskill" || args[0] == "attack" || args[0] == "heal" || args[0] == "reload" || args[0] == "kill")
						{
							args.push_back(combatants[i].getName());
						}
					}
					escapeCode = executeCommand(args, playerCharacters, NPCs, combatants, weapons, armor, encounters, currentEncounter);
				}
				else
				{
					escapeCode = 1;
					std::cout << '\n';
					std::cout << combatants[1].getName() << " is knocked out" << '\n';
				}
				
			}
			
		}
	}

	return escapeCode;
}

void chooseCombatants(std::vector<Character>& playerCharacters, std::vector<Character>& NPCs, std::vector<Character>& combatants)
{
	int response = -1;

	combatants.clear();

	while (response != 0)
	{
		int i = 0;
		std::cout << "Choose player character combatants" << '\n';
		std::cout << "0. None (Proceed to NPCs)" << '\n';
		for (i = 0; i < playerCharacters.size(); i++)
		{
			std::cout << i + 1 << ". " << playerCharacters[i].getName() << '\n';
		}

		response = getIntInput();

		while (response < 0 || response > playerCharacters.size())
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response != 0)
		{
			combatants.push_back(playerCharacters[response - 1]);
			playerCharacters.erase(playerCharacters.begin() + (response - 1));
		}
	}

	playerCharacters.clear();

	loadCharacterVector(playerCharacters);

	while (response != 1)
	{
		std::cout << "Choose NPC combatants" << '\n';
		std::cout << "1. Done (Save Combatants)" << '\n';
		std::cout << "2. add npc" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 2)
		{
			activateNPC(NPCs, combatants);
		}
	}

}

void attackDefend(Character& attacker, Character& defender)
{
	range r;
	
	int dmg = 0;
	damageType dt;

	int dmg2 = 0;
	damageType dt2;

	attacker.act();

	std::cout << "Enter Range" << '\n';
	std::cout << "1. Grapple" << '\n';
	std::cout << "2. Melee" << '\n';
	std::cout << "3. Short" << '\n';
	std::cout << "4. Medium" << '\n';
	std::cout << "5. Long" << '\n';

	int response = getIntInput();

	while (response < 1 || response > 5)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	r = static_cast<range>(response -1);

	int attackRoll = attacker.rollAttack(dmg, dt, r);
	int defendRoll = 0;

	if (r < range::shortR && !defender.getActed())
	{
		std::cout << "What does " << defender.getName() << " choose to do?" << '\n';
		std::cout << "1. Dodge" << '\n';
		std::cout << "2. Attack (Uses action)" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			if (attackRoll > 0)
			{
				defendRoll = defender.evade();
				if (defendRoll <= attackRoll)
				{
					std::cout << defender.getName() << " is hit!" << '\n';
					defender.takeDamage(dt, dmg);
				}
				else
				{
					std::cout << attacker.getName() << " failed to hit " << defender.getName() << "!" << '\n';
				}
			}
			else
			{
				std::cout << attacker.getName() << " failed to hit " << defender.getName() << "!" << '\n';
			}
		}
		else
		{
			defender.act();
			defendRoll = defender.rollAttack(dmg2, dt2, r);
			if (defendRoll <= attackRoll)
			{
				std::cout << defender.getName() << " is hit!" << '\n';
				defender.takeDamage(dt, dmg);
			}
			else
			{
				std::cout << attacker.getName() << " is hit!" << '\n';
				attacker.takeDamage(dt2, dmg2);
			}
		}
	}
	else
	{
		if (attackRoll > 0)
		{
			defendRoll = defender.evade();
			if (defendRoll <= attackRoll)
			{
				std::cout << defender.getName() << " is hit!" << '\n';
				defender.takeDamage(dt, dmg);
			}
			else
			{
				std::cout << attacker.getName() << " failed to hit " << defender.getName() << "!" << '\n';
			}
		}
		else
		{
			std::cout << attacker.getName() << " failed to hit " << defender.getName() << "!" << '\n';
		}
		
	}
	
}

void addNewArmor(std::vector<Armor>& ArmorVector)
{
	std::cout << "Enter Armor Type Name:" << '\n';
	std::string name;
	std::getline(std::cin, name);
	Armor a;
	a.type = name;

	int selection = 0;
	while (selection != 13)
	{

		std::cout << "Choose Resistances" << '\n';
		std::cout << "1. Blunt " << a.bluntResistance << '\n';
		std::cout << "2. Cutting " << a.cutResistance << '\n';
		std::cout << "3. Piecing " << a.pierceResistance << '\n';
		std::cout << "4. Chopping " << a.chopResistance << '\n';
		std::cout << "5. Ballistic " << a.ballisticResistance << '\n';
		std::cout << "6. Environmental " << a.environmentalResistance << '\n';
		std::cout << "7. Fire " << a.flameResistance << '\n';
		std::cout << "8. Energy " << a.energyResistance << '\n';
		std::cout << "9. Shock " << a.shockResistance << '\n';
		std::cout << "10. Acid " << a.acidResistance << '\n';
		std::cout << "11. Magic " << a.magicalResistance << '\n';
		std::cout << "12. Reset" << '\n';
		std::cout << "13. Done (Save)" << '\n';

		selection = getIntInput();

		while (!std::cin.good() || selection < 1 || selection > 13)
		{
			std::cout << "Invalid input. Please try again" << '\n';
			std::cin.ignore(INT_MAX, '\n');
			selection = getIntInput();
		}

		switch (selection)
		{
		case 1:
		{
			a.bluntResistance++;
			break;
		}
		case 2:
		{
			a.cutResistance++;
			break;
		}
		case 3:
		{
			a.pierceResistance++;
			break;
		}
		case 4:
		{
			a.chopResistance++;
			break;
		}
		case 5:
		{
			a.ballisticResistance++;
			break;
		}
		case 6:
		{
			a.environmentalResistance++;
			break;
		}
		case 7:
		{
			a.flameResistance++;
			break;
		}
		case 8:
		{
			a.energyResistance++;
			break;
		}
		case 9:
		{
			a.shockResistance++;
			break;
		}
		case 10:
		{
			a.acidResistance++;
			break;
		}
		case 11:
		{
			a.magicalResistance++;
			break;
		}
		case 12:
		{
			a.bluntResistance = 0, a.cutResistance = 0, a.pierceResistance = 0, a.chopResistance = 0, a.ballisticResistance = 0, a.environmentalResistance = 0, a.flameResistance = 0,
				a.energyResistance = 0, a.shockResistance = 0, a.acidResistance = 0, a.magicalResistance = 0;
			break;
		}
		case 13:
		{
			break;
		}
		}
	}

	std::cout << "Enter Armor Penalty" << '\n';
	a.armorPenalty = getIntInput();

	ArmorVector.push_back(a);
	writeToArmorFile(a);
}

void writeToArmorFile(const Armor& a)
{
	std::ofstream outFile;
	outFile.open("Armor.txt", std::ios::app);

	outFile << a.type << '\n';
	outFile << a.bluntResistance << '\n';
	outFile << a.cutResistance << '\n';
	outFile << a.pierceResistance << '\n';
	outFile << a.chopResistance << '\n';
	outFile << a.ballisticResistance << '\n';
	outFile << a.environmentalResistance << '\n';
	outFile << a.flameResistance << '\n';
	outFile << a.energyResistance << '\n';
	outFile << a.shockResistance << '\n';
	outFile << a.acidResistance << '\n';
	outFile << a.magicalResistance << '\n';
	outFile << a.armorPenalty << '\n';

	outFile.close();
}

void loadArmorVector(std::vector<Armor>& ArmorVector)
{
	std::string temp;
	std::ifstream inputFile;
	inputFile.open("Armor.txt");
	Armor a;

	while (!inputFile.eof())
	{
		std::getline(inputFile, a.type);

		std::getline(inputFile, temp);
		a.bluntResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.cutResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.pierceResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.chopResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.ballisticResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.environmentalResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.flameResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.energyResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.shockResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.acidResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.magicalResistance = stoi(temp);

		std::getline(inputFile, temp);
		a.armorPenalty = stoi(temp);

		if (a.type != "")
		{
			ArmorVector.push_back(a);
		}
	}
	sortArmorVector(ArmorVector);
}

void sortArmorVector(std::vector<Armor>& ArmorVector)
{
	int i, j, min_idx;
	int n = ArmorVector.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (ArmorVector[j].type < ArmorVector[min_idx].type)
				min_idx = j;

		// Swap the found minimum element
		// with the first element

		Armor temp = ArmorVector[min_idx];
		ArmorVector[min_idx] = ArmorVector[i];
		ArmorVector[i] = temp;
	}
}

void deleteCharacter(std::vector<Character>& Characters)
{
	std::cout << "Select character to delete" << '\n';
	std::cout << "0. None" << '\n';
	for (int i = 0; i < Characters.size(); i++)
	{
		std::cout << i + 1 << ". " << Characters[i].getName() << '\n';
	}

	int response = getIntInput();

	while (response < 0 || response > Characters.size())
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	if (response != 0)
	{
		Characters.erase(Characters.begin() + response - 1);
	}

	saveCharacterChanges(Characters);
}

void saveCharacterChanges(std::vector<Character>& Characters)
{
	std::ofstream inputFile;
	inputFile.open("Character.txt", std::ofstream::out | std::ofstream::trunc);
	inputFile.close();

	for (int i = 0; i < Characters.size(); i++)
	{
		Characters[i].writeToCharacterFile();
	}
}

void loadCharacterVector(std::vector<Character>& Characters)
{
	Characters.clear();
	
	std::ifstream inputFile;
	inputFile.open("Character.txt");

	std::string name = "";
	std::string vocation1 = "";
	std::string vocation2 = "";
	std::string vocation3 = "";
	std::string temp = "", temp2 = "";
	int bluntResistance = 0, cutResistance = 0, pierceResistance = 0, choppResistance = 0, ballisticResistance = 0, environmentalResistance = 0, flameResistance = 0,
		energyResistance = 0, shockResistance = 0, acidResistance = 0, magicalResistance = 0, grapple = 0, melee = 0, strengthRanged = 0, dexRanged = 0, initiative = 0,
		athletics = 0, acrobatics = 0, constitution = 0, evasion = 0, armorPenalty = 0, points = 0;
	int woundLevel = 0;

	std::string weaponName = "";
	int maxLoaded = 1;
	int loadedAmmo = 1;
	int spareAmmo = 0;
	int ammoPerShot = 1;

	std::string attackName = "";
	damageType dmgType = damageType::blunt;
	int baseDamage = 0;
	int damageModifier = 0;
	int grappleBonus = 0;
	int meleeBonus = 0;
	int shortRangeBonus = 0;
	int mediumRangeBonus = 0;
	int longRangeBonus = 0;
	skill rangeAttackType;

	Character c;

	while (!inputFile.eof() && inputFile.good())
	{
		std::getline(inputFile, name, '\n');
		c.setName(name);
		std::getline(inputFile, vocation1, '\n');
		c.setVocation(1, vocation1);
		std::getline(inputFile, vocation2, '\n');
		c.setVocation(2, vocation2);
		std::getline(inputFile, vocation3, '\n');
		c.setVocation(3, vocation3);

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_grapple, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_melee, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_strenghtRanged, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_dexRanged, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_initiative, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_athletics, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_Acrobatics, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_constitution, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_evasion, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_perception_Investigation, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_tactics_Command, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_artillery, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_strength, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_ride_Pilot, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_stealth_SlightofHand, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_persuasion_Deception, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_charm_Seduction, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_intimidation, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_fortitude_Tolerence, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_navigation, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_survival, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_technology, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_engineering, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_medicine, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_calculation_Mathematics, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_memory, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_languages_linguistics, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_sketching_Painting, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_sculpting_Carving, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_sewing_Weaving_Knitting, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_oratory_Performance, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_writing_Composition, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_dance, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_music_Composition, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_music_InstrumentalPerformance, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		c.setSkill(skill::S_music_VocalPerformance, std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		std::getline(inputFile, temp2, '\n');
		c.setSpecialSkill(1, temp, std::stoi(temp2));

		std::getline(inputFile, temp, '\n');
		std::getline(inputFile, temp2, '\n');
		c.setSpecialSkill(2, temp, std::stoi(temp2));

		std::getline(inputFile, temp, '\n');
		std::getline(inputFile, temp2, '\n');
		c.setSpecialSkill(3, temp, std::stoi(temp2));

		std::getline(inputFile, temp, '\n');
		std::getline(inputFile, temp2, '\n');
		c.setSpecialSkill(4, temp, std::stoi(temp2));

		std::getline(inputFile, temp, '\n');
		std::getline(inputFile, temp2, '\n');
		c.setSpecialSkill(5, temp, std::stoi(temp2));

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::all, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance, 
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::head, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::neck, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::rightArm, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::leftArm, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::chest, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::gut, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::rightLeg, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);

		std::getline(inputFile, temp, '\n');
		woundLevel = (std::stoi(temp));

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		c.setBodyPart(bodyPrt::leftLeg, woundLevel, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, armorPenalty);
		
		
		for (int i = 0; i < 5; i++)
		{
			std::getline(inputFile, weaponName, '\n');
			std::getline(inputFile, temp, '\n');
			maxLoaded = stoi(temp);
			std::getline(inputFile, temp, '\n');
			loadedAmmo = stoi(temp);
			std::getline(inputFile, temp, '\n');
			spareAmmo = stoi(temp);
			std::getline(inputFile, temp, '\n');
			ammoPerShot = stoi(temp);

			Weapon w(weaponName, maxLoaded, loadedAmmo, spareAmmo, ammoPerShot);

			for (int i = 0; i < 4; i++)
			{
				std::getline(inputFile, attackName, '\n');
				std::getline(inputFile, temp, '\n');
				dmgType = static_cast<damageType>(stoi(temp));
				std::getline(inputFile, temp, '\n');
				baseDamage = stoi(temp);
				std::getline(inputFile, temp, '\n');
				damageModifier = stoi(temp);
				std::getline(inputFile, temp, '\n');
				grappleBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				meleeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				shortRangeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				mediumRangeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				longRangeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				rangeAttackType = static_cast<skill>(stoi(temp));

				switch (i)
				{
				case 0:
				{
					w.a1.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 1:
				{
					w.a2.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 2:
				{
					w.a3.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 3:
				{
					w.a4.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				}
			}

			switch (i)
			{
			case 0:
			{
				c.w1 = w;
				break;
			}
			case 1:
			{
				c.w2 = w;
				break;
			}
			case 2:
			{
				c.w3 = w;
				break;
			}
			case 3:
			{
				c.w4 = w;
				break;
			}
			case 4:
			{
				c.w5 = w;
				break;
			}

			}
		}

		if (c.getChName() != "")
		{
			Characters.push_back(c);
		}

	}

	inputFile.close();

	sortCharacterVector(Characters);
}

void newCharacter(std::vector<Weapon>& weaponVector)
{
	Character c;
	c.characterCreate(weaponVector);
}

void deleteWeapon(std::vector<Weapon>& weaponVector)
{
	std::cout << "Select Weapon to Delete (enter number)" << '\n';
	
	for (int i = 0; i < weaponVector.size(); i++)
	{
		std::cout << i << ": " << weaponVector[i].getName() << '\n';
	}

	int num = -1;

	num = getIntInput();

	while (num >= weaponVector.size() || num < 0)
	{
		std::cout << "Invalid Input" << '\n';
		num = getIntInput();
	}

	std::cout << "Delete " << weaponVector[num].getName() << "?" << '\n';
	std::cout << "1. Yes" << '\n';
	std::cout << "2. No" << '\n';

	num = getIntInput();
	while (num < 1 || num > 2)
	{
		std::cout << "Invalid Input" << '\n';
		num = getIntInput();
	}

	if (num == 1)
	{
		weaponVector.erase(weaponVector.begin() + num);

		std::ofstream ofs;
		ofs.open("Weapons.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		// re-write to file

		for (int i = 0; i < weaponVector.size(); i++)
		{
			weaponVector[i].writeToFile();
		}
	}

	loadWeaponVector(weaponVector);
}

void loadWeaponVector(std::vector<Weapon>& WeaponVector)
{
	
	WeaponVector.clear();

	std::string weaponName = "";
	int maxLoaded = 1;
	int loadedAmmo = 1;
	int spareAmmo = 0;
	int ammoPerShot = 1;

	std::string attackName = "";
	damageType dmgType = damageType::blunt;
	int baseDamage = 0;
	int damageModifier = 0;
	int grappleBonus = 0;
	int meleeBonus = 0;
	int shortRangeBonus = 0;
	int mediumRangeBonus = 0;
	int longRangeBonus = 0;
	skill rangeAttackType;

	std::string temp = "";

	std::ifstream inputFile;
	inputFile.open("Weapons.txt");

	while (!inputFile.eof() && inputFile.good())
	{
		std::getline(inputFile, weaponName, '\n');
		std::getline(inputFile, temp, '\n');
		maxLoaded = stoi(temp);
		std::getline(inputFile, temp, '\n');
		loadedAmmo = stoi(temp);
		std::getline(inputFile, temp, '\n');
		spareAmmo = stoi(temp);
		std::getline(inputFile, temp, '\n');
		ammoPerShot = stoi(temp);

		Weapon w(weaponName, maxLoaded, loadedAmmo, spareAmmo, ammoPerShot);

		for (int i = 0; i < 4; i++)
		{
			std::getline(inputFile, attackName, '\n');
			std::getline(inputFile, temp, '\n');
			dmgType = static_cast<damageType>(stoi(temp));
			std::getline(inputFile, temp, '\n');
			baseDamage = stoi(temp);
			std::getline(inputFile, temp, '\n');
			damageModifier = stoi(temp);
			std::getline(inputFile, temp, '\n');
			grappleBonus = stoi(temp);
			std::getline(inputFile, temp, '\n');
			meleeBonus = stoi(temp);
			std::getline(inputFile, temp, '\n');
			shortRangeBonus = stoi(temp);
			std::getline(inputFile, temp, '\n');
			mediumRangeBonus = stoi(temp);
			std::getline(inputFile, temp, '\n');
			longRangeBonus = stoi(temp);
			std::getline(inputFile, temp, '\n');
			rangeAttackType = static_cast<skill>(stoi(temp));

			switch (i)
			{
				case 0:
				{
					w.a1.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 1:
				{
					w.a2.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 2:
				{
					w.a3.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 3:
				{
					w.a4.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
			}
		}
		
		if (w.getName() != "")
		{
			WeaponVector.push_back(w);
		}
	}

	inputFile.close();

	sortWeaponVector(WeaponVector);

}

void createNewWeaponType()
{
	std::string weaponName = "";
	int maxLoaded = 1;
	int loadedAmmo = 1;
	int spareAmmo = 0;
	int ammoPerShot = 1;
	/*weaponID weaponNum = weaponID::other;*/

	Attack a1;
	
	int response = 0;

	std::cout << "Enter Weapon Name" << '\n';

	std::getline(std::cin, weaponName);

	std::cout << "Enter Ammo (1 for melee)" << '\n';

	maxLoaded = getIntInput();

	if (maxLoaded < 1)
	{
		maxLoaded = 1;
	}

	loadedAmmo = maxLoaded;

	std::cout << "How much ammo is expended per shot?" << '\n';

	ammoPerShot = getIntInput();

	if (ammoPerShot < 1)
	{
		ammoPerShot = 1;
	}

	std::ofstream inFile;
	inFile.open("Weapons.txt", std::ios::app);

	inFile << weaponName << '\n';
	inFile << maxLoaded << '\n';
	inFile << loadedAmmo << '\n';
	inFile << spareAmmo << '\n';
	inFile << ammoPerShot << '\n';

	inFile.close();

	std::string attackName = "";
	int dmgType = 0;
	int baseDamage = 0;
	int damageModifier = 0;
	int grappleBonus = 0;
	int meleeBonus = 0;
	int shortRangeBonus = 0;
	int mediumRangeBonus = 0;
	int longRangeBonus = 0;
	int rangeAttackType ;

	for (int i = 0; i < 4; i++)
	{
		if (i > 0)
		{
			std::cout << "Enter additional attack?" << '\n';
			std::cout << "1. Yes" << '\n';
			std::cout << "2. No" << '\n';

			response = getIntInput();

			while (response < 1 || response > 2)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response == 1)
			{
				std::cout << "Enter Attack " << i + 1 << " Name" << '\n';

				std::getline(std::cin, attackName);

				std::cout << "Enter Damage Type" << '\n';
				std::cout << "1. Blunt" << '\n';
				std::cout << "2. Cutting" << '\n';
				std::cout << "3. Pierce" << '\n';
				std::cout << "4. Chopping" << '\n';
				std::cout << "5. Ballistic" << '\n';
				std::cout << "6. Environmental" << '\n';
				std::cout << "7. Fire" << '\n';
				std::cout << "8. Energy" << '\n';
				std::cout << "9. Shock" << '\n';
				std::cout << "10. Acid" << '\n';
				std::cout << "11. Magic" << '\n';

				dmgType = (getIntInput() - 1);

				while (dmgType < 0 || dmgType > 10)
				{
					std::cout << "Invalid Input" << '\n';
					dmgType = (getIntInput() - 1);
				}

				std::cout << "Enter base damage (1dX)" << '\n';

				baseDamage = (getIntInput());

				std::cout << "Enter damage modifier (+X)" << '\n';

				damageModifier = (getIntInput());

				std::cout << "Enter grapple bonus (<-10 to make unusable)" << '\n';

				grappleBonus = (getIntInput());

				std::cout << "Enter melee bonus (<-10 to make unusable)" << '\n';

				meleeBonus = (getIntInput());

				std::cout << "Enter short range bonus (<-10 to make unusable)" << '\n';

				shortRangeBonus = (getIntInput());

				std::cout << "Enter medium range bonus (<-10 to make unusable)" << '\n';

				mediumRangeBonus = (getIntInput());

				std::cout << "Enter long range bonus (<-10 to make unusable)" << '\n';

				longRangeBonus = (getIntInput());

				std::cout << "Enter skillType for ranged" << '\n';
				std::cout << "1. Strength Ranged" << '\n';
				std::cout << "2. Dex Ranged" << '\n';
				std::cout << "3. N.A." << '\n';

				response = getIntInput();

				while (response < 1 || response > 3)
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}

				switch (response)
				{
				case 1:
				{
					rangeAttackType = 2;
					break;
				}
				case 2:
				{
					rangeAttackType = 3;
					break;
				}
				case 3:
				{
					rangeAttackType = -1;
					break;
				}
				}

				a1.setAttack(attackName, static_cast<damageType>(dmgType), baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, 
					static_cast<skill>(rangeAttackType));
				a1.writeToFile();

			}
			else
			{
				a1.setAttack("", static_cast<damageType>(dmgType), baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, 
					static_cast<skill>(rangeAttackType));
				for (int k = 0; k < 4 - i; k++)
				{
					a1.writeToFile();
				}
				i = 5;
			}
		}
		else
		{
		std::cout << "Enter Attack " << i + 1 << " Name" << '\n';

		std::getline(std::cin, attackName);

		std::cout << "Enter Damage Type" << '\n';
		std::cout << "1. Blunt" << '\n';
		std::cout << "2. Cutting" << '\n';
		std::cout << "3. Pierce" << '\n';
		std::cout << "4. Chopping" << '\n';
		std::cout << "5. Ballistic" << '\n';
		std::cout << "6. Environmental" << '\n';
		std::cout << "7. Fire" << '\n';
		std::cout << "8. Energy" << '\n';
		std::cout << "9. Shock" << '\n';
		std::cout << "10. Acid" << '\n';
		std::cout << "11. Magic" << '\n';

		dmgType = (getIntInput() - 1);

		while (dmgType < 0 || dmgType > 10)
		{
			std::cout << "Invalid Input" << '\n';
			dmgType = (getIntInput() - 1);
		}

		std::cout << "Enter base damage (1dX)" << '\n';

		baseDamage = (getIntInput());

		std::cout << "Enter damage modifier (+X)" << '\n';

		damageModifier = (getIntInput());

		std::cout << "Enter grapple bonus (<-10 to make unusable)" << '\n';

		grappleBonus = (getIntInput());

		std::cout << "Enter melee bonus (<-10 to make unusable)" << '\n';

		meleeBonus = (getIntInput());

		std::cout << "Enter short range bonus (<-10 to make unusable)" << '\n';

		shortRangeBonus = (getIntInput());

		std::cout << "Enter medium range bonus (<-10 to make unusable)" << '\n';

		mediumRangeBonus = (getIntInput());

		std::cout << "Enter long range bonus (<-10 to make unusable)" << '\n';

		longRangeBonus = (getIntInput());

		std::cout << "Enter skillType for ranged" << '\n';
		std::cout << "1. Strength Ranged" << '\n';
		std::cout << "2. Dex Ranged" << '\n';
		std::cout << "3. N.A." << '\n';

		response = getIntInput();

		while (response < 1 || response > 3)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		switch (response)
		{
		case 1:
		{
			rangeAttackType = 2;
			break;
		}
		case 2:
		{
			rangeAttackType = 3;
			break;
		}
		case 3:
		{
			rangeAttackType = -1;
			break;
		}
		}

		a1.setAttack(attackName, static_cast<damageType>(dmgType), baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, static_cast<skill>(rangeAttackType));
		a1.writeToFile();
		}
	}
	
	

}


void removeNPCType(std::vector<Character>& NPCvector)
{
	removeNPC(NPCvector);

	// delete contents of file

	std::ofstream ofs;
	ofs.open("NPC.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	// re-write to file

	for (int i = 0; i < NPCvector.size(); i++)
	{
		NPCvector[i].writeToFileNPC();
	}
}

int getIntInput()
{
	std::string number;

	std::getline(std::cin, number);

	if (isInteger(number))
	{
		return stoi(number);
	}
	else
	{
		std::cout << "Invalid Input. Please Input Integer" << '\n';
		return getIntInput();
	}
}

bool isInteger(const std::string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			if (i > 0)
			{
				return false;
			}
			else if (s[i] != '-')
			{
				return false;
			}
			
		}
		
	}

	if (s.size() < 1)
	{
		return false;
	}

	return true;
}

void removeNPC(std::vector<Character>& activeCharacterVector)
{
	for (int i = 0; i < activeCharacterVector.size(); i++)
	{
		std::cout  << i  << ": " << activeCharacterVector[i].getChName() << '\n';
	}

	std::cout << "Select NPC to Delete (enter number)" << '\n';

	int num = -1;

	num = getIntInput();

	if (num < activeCharacterVector.size() && num > -1)
	{
		activeCharacterVector.erase(activeCharacterVector.begin() + num);
	}
	else
	{
		std::cout << "Invalid Input" << '\n';
	}
}

void killActiveCreature(std::vector<Character>& activeCharacterVector, const int& e)
{
	activeCharacterVector.erase(activeCharacterVector.begin() + e);
}

void activateNPC(std::vector<Character>& NPCvector, std::vector<Character>& activeCharacterVector)
{
	for (int i = 0; i < NPCvector.size(); i++)
	{
		std::cout << NPCvector[i].getChName() << '\n';
	}
	
	

	std::string name;


	std::cout << "Enter NPC Name" << '\n';
	std::getline(std::cin, name, '\n');

	while (name == "" || name == "\n")
	{
		std::cout << "Enter NPC Name" << '\n';
		std::cin.ignore(INT_MAX, '\n');
		std::getline(std::cin, name, '\n');
	}

	std::cout << "Enter Number to Create" << '\n';

	int num = 0;
	
	num = getIntInput();

	int temp = vectorLookup(NPCvector, name, 0, NPCvector.size() - 1);

	if (temp != -1)
	{
		for (int i = 0; i < num; i++)
		{
			Character tempC = NPCvector[temp];
			std::string ID = " (" + std::to_string(i) +")";
			tempC.setID(ID);
			activeCharacterVector.push_back(tempC);
			
		}
	}
	else
	{
		std::cout << "NPC Not Found" << '\n';
	}
	
	
	
}

void sortWeaponVector(std::vector<Weapon>& vector)
{
	int i, j, min_idx;
	int n = vector.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (vector[j].getName() < vector[min_idx].getName())
				min_idx = j;

		// Swap the found minimum element
		// with the first element

		Weapon temp = vector[min_idx];
		vector[min_idx] = vector[i];
		vector[i] = temp;
	}
}

void sortCharacterVector(std::vector<Character>& vector)
{
	int i, j, min_idx;
	int n = vector.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (vector[j].getChName() < vector[min_idx].getChName())
				min_idx = j;

		// Swap the found minimum element
		// with the first element

		Character temp = vector[min_idx];
		vector[min_idx] = vector[i];
		vector[i] = temp;
	}
}

int unsortedLookup(std::vector<Character>& vector, std::string creatureName)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i].getName() == creatureName)
		{
			return i;
		}
	}
	return -1;
}

int vectorLookup(std::vector<Character>& vector, std::string creatureName, const int &l, const int &r)
{
		
	if (r >= l) 
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (vector[mid].getChName() == creatureName)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (vector[mid].getChName() > creatureName)
			return vectorLookup(vector, creatureName, l,  mid - 1);

		// Else the element can only be present
		// in right subarray
		return vectorLookup(vector, creatureName, mid + 1, r);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

void loadNPCvector(std::vector<Character>& NPCvector)
{
	NPCvector.clear();
	
	std::ifstream inputFile;
	inputFile.open("NPC.txt");
	
	std::string name = "";
	std::string temp = "";
	int bluntResistance = 0, cutResistance = 0, pierceResistance = 0, choppResistance = 0, ballisticResistance = 0, environmentalResistance = 0, flameResistance = 0,
		energyResistance = 0, shockResistance = 0, acidResistance = 0, magicalResistance = 0, grapple = 0, melee = 0, strengthRanged = 0, dexRanged = 0, initiative = 0,
		athletics = 0, acrobatics = 0, constitution = 0, evasion = 0, armorPenalty = 0, points = 0;

	std::string weaponName = "";
	int maxLoaded = 1;
	int loadedAmmo = 1;
	int spareAmmo = 0;
	int ammoPerShot = 1;

	std::string attackName = "";
	damageType dmgType = damageType::blunt;
	int baseDamage = 0;
	int damageModifier = 0;
	int grappleBonus = 0;
	int meleeBonus = 0;
	int shortRangeBonus = 0;
	int mediumRangeBonus = 0;
	int longRangeBonus = 0;
	skill rangeAttackType;

	while (!inputFile.eof() && inputFile.good())
	{
		std::getline(inputFile, name, '\n');

		std::getline(inputFile, temp, '\n');
		bluntResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		cutResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		pierceResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		choppResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		ballisticResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		environmentalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		flameResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		energyResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		shockResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acidResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		magicalResistance = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		grapple = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		melee = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		strengthRanged = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		dexRanged = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		initiative = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		athletics = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		acrobatics = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		constitution = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		evasion = std::stoi(temp);

		std::getline(inputFile, temp, '\n');
		armorPenalty = std::stoi(temp);

		Character c(name, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
			shockResistance, acidResistance, magicalResistance, grapple, melee, strengthRanged, dexRanged, initiative, athletics, acrobatics, constitution, evasion, armorPenalty);

		for (int i = 0; i < 3; i++)
		{
			std::getline(inputFile, weaponName, '\n');
			std::getline(inputFile, temp, '\n');
			maxLoaded = stoi(temp);
			std::getline(inputFile, temp, '\n');
			loadedAmmo = stoi(temp);
			std::getline(inputFile, temp, '\n');
			spareAmmo = stoi(temp);
			std::getline(inputFile, temp, '\n');
			ammoPerShot = stoi(temp);

			Weapon w(weaponName, maxLoaded, loadedAmmo, spareAmmo, ammoPerShot);

			for (int i = 0; i < 4; i++)
			{
				std::getline(inputFile, attackName, '\n');
				std::getline(inputFile, temp, '\n');
				dmgType = static_cast<damageType>(stoi(temp));
				std::getline(inputFile, temp, '\n');
				baseDamage = stoi(temp);
				std::getline(inputFile, temp, '\n');
				damageModifier = stoi(temp);
				std::getline(inputFile, temp, '\n');
				grappleBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				meleeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				shortRangeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				mediumRangeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				longRangeBonus = stoi(temp);
				std::getline(inputFile, temp, '\n');
				rangeAttackType = static_cast<skill>(stoi(temp));

				switch (i)
				{
				case 0:
				{
					w.a1.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 1:
				{
					w.a2.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 2:
				{
					w.a3.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				case 3:
				{
					w.a4.setAttack(attackName, dmgType, baseDamage, damageModifier, grappleBonus, meleeBonus, shortRangeBonus, mediumRangeBonus, longRangeBonus, rangeAttackType);
					break;
				}
				}
			}

			switch (i)
			{
				case 0:
				{
					c.w1 = w;
					break;
				}
				case 1:
				{
					c.w2 = w;
					break;
				}
				case 2:
				{
					c.w3 = w;
					break;
				}
			
			}
		}

		if (c.getChName() != "")
		{
			NPCvector.push_back(c);
		}
		
	}

	inputFile.close();

	for (int i = 0; i < NPCvector.size(); i++)
	{
		NPCvector[i].setNPC();
	}

	sortCharacterVector(NPCvector);
}

void newNPCType(std::vector<Weapon>& weapons)
{
	std::string name = "";
	int bluntResistance = 0, cutResistance = 0, pierceResistance = 0, choppResistance = 0, ballisticResistance = 0, environmentalResistance = 0, flameResistance = 0,
		energyResistance = 0, shockResistance = 0, acidResistance = 0, magicalResistance = 0, grapple = 4, melee = 4, strengthRanged = 4, dexRanged = 4, initiative = 4, 
		athletics = 4, acrobatics = 4, constitution = 4, evasion = 4, armorPenalty = 4, points = 0;
	
	Weapon w1, w2, w3, temp;

	std::cout << "Enter New NPC Type Name" << '\n';
	std::getline(std::cin, name, '\n');

	while (name == "" || name == "\n")
	{
		std::cout << "Enter New NPC Type Name" << '\n';
		std::cin.ignore(INT_MAX, '\n');
		std::getline(std::cin, name, '\n');
	}

	int selection = 0;

	while (selection != 11)																											
	{
		std::cout << "Skill Points used: " << points << '\n' << '\n';
		std::cout << "1. grapple: " << grapple << '\n';
		std::cout << "2. melee: " << melee << '\n';
		std::cout << "3. ranged (strength): " << strengthRanged << '\n';
		std::cout << "4. ranged (dexterity): " << dexRanged << '\n';
		std::cout << "5. initiative: " << initiative << '\n';
		std::cout << "6. athletics: " << athletics << '\n';
		std::cout << "7. acrobatics: " << acrobatics << '\n';
		std::cout << "8. constitution: " << constitution << '\n';
		std::cout << "9. evasion: " << evasion << '\n';
		std::cout << "10. Reset Points: " << '\n';
		std::cout << "11. Exit & Save: " << '\n';
		

		selection = getIntInput();

		while (!std::cin.good() || selection < 1 || selection > 11)
		{
			std::cout << "Invalid input. Please try again" << '\n';
			std::cin.ignore(INT_MAX, '\n');
			selection = getIntInput();
		}

		switch (selection)
		{
		case 1:
		{
			grapple++;
			points++;
			break;
		}
		case 2:
		{
			melee++;
			points++;
			break;
		}
		case 3:
		{
			strengthRanged++;
			points++;
			break;
		}
		case 4:
		{
			dexRanged++;
			points++;
			break;
		}
		case 5:
		{
			initiative++;
			points++;
			break;
		}
		case 6:
		{
			athletics++;
			points++;
			break;
		}
		case 7:
		{
			acrobatics++;
			points++;
			break;
		}
		case 8:
		{
			constitution++;
			points++;
			break;
		}
		case 9:
		{
			evasion++;
			points++;
			break;
		}
		case 10:
		{
			grapple = 0, melee = 0, strengthRanged = 0, dexRanged = 0, initiative = 0, athletics = 0, acrobatics = 0, constitution = 0, evasion = 0, armorPenalty = 0, points = -40;
			break;
		}

		}
	}

	
	while (selection != 13)
	{
		
		std::cout << "Choose Resistances" << '\n';															
		std::cout << "1. Blunt " << bluntResistance << '\n';
		std::cout << "2. Cutting " << cutResistance << '\n';
		std::cout << "3. Piecing " << pierceResistance << '\n';
		std::cout << "4. Chopping " << choppResistance << '\n';
		std::cout << "5. Ballistic " << ballisticResistance << '\n';
		std::cout << "6. Environmental " << environmentalResistance << '\n';
		std::cout << "7. Fire " << flameResistance << '\n';
		std::cout << "8. Energy " << energyResistance << '\n';
		std::cout << "9. Shock " << shockResistance << '\n';
		std::cout << "10. Acid " << acidResistance << '\n';
		std::cout << "11. Magic " << magicalResistance << '\n';
		std::cout << "12. Reset" << '\n';
		std::cout << "13. Done (Save)" << '\n';

		selection = getIntInput();

		while (!std::cin.good() || selection < 1 || selection > 13)
		{
			std::cout << "Invalid input. Please try again" << '\n';
			std::cin.ignore(INT_MAX, '\n');
			selection = getIntInput();
		}

		switch (selection)
		{
		case 1:
		{
			bluntResistance++;
			break;
		}
		case 2:
		{
			cutResistance++;
			break;
		}
		case 3:
		{
			pierceResistance++;
			break;
		}
		case 4:
		{
			choppResistance++;
			break;
		}
		case 5:
		{
			ballisticResistance++;
			break;
		}
		case 6:
		{
			environmentalResistance++;
			break;
		}
		case 7:
		{
			flameResistance++;
			break;
		}
		case 8:
		{
			energyResistance++;
			break;
		}
		case 9:
		{
			shockResistance++;
			break;
		}
		case 10:
		{
			acidResistance++;
			break;
		}
		case 11:
		{
			magicalResistance++;
			break;
		}
		case 12:
		{
			bluntResistance = 0, cutResistance = 0, pierceResistance = 0, choppResistance = 0, ballisticResistance = 0, environmentalResistance = 0, flameResistance = 0,
				energyResistance = 0, shockResistance = 0, acidResistance = 0, magicalResistance = 0;
			break;
		}
		case 13:
		{
			break;
		}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
		{
			std::cout << "Choose Primary Weapon" << '\n';
			break;
		}
		case 1:
		{
			std::cout << "Choose Second Weapon" << '\n';
			break;
		}
		case 2:
		{
			std::cout << "Choose Third Weapon" << '\n';
			break;
		}
		}

		std::cout << "1. Knife" << '\n';
		std::cout << "2. Sword" << '\n';
		std::cout << "3. Spear" << '\n';
		std::cout << "4. Bow" << '\n';
		std::cout << "5. Crossbow" << '\n';
		std::cout << "6. Pistol" << '\n';
		std::cout << "7. Rifle" << '\n';
		std::cout << "8. Other" << '\n';

		selection = getIntInput();
		while (!std::cin.good() || selection < 1 || selection > 8)
		{
			std::cout << "Invalid input. Please try again" << '\n';
			std::cin.ignore(INT_MAX, '\n');
			selection = getIntInput();
		}

		if (selection != 8)
		{
			temp.setWeapon(static_cast<weaponID>(selection));
		}
		else
		{
			for (int i = 0; i < weapons.size(); i++)
			{
				std::cout << i + 1 << ". " << weapons[i].getName() << '\n';
			}

			selection = getIntInput();
			while (!std::cin.good() || selection < 1 || selection > weapons.size())
			{
				std::cout << "Invalid input. Please try again" << '\n';
				std::cin.ignore(INT_MAX, '\n');
				selection = getIntInput();
			}

			temp = weapons[selection - 1];
		}

		switch (i)
		{
		case 0:
		{
			w1 = temp;
			break;
		}
		case 1:
		{
			w2 = temp;			
			break;
		}
		case 2:
		{
			w3 = temp;
			break;
		}
		}
	}


	Character NPCType(name, bluntResistance, cutResistance, pierceResistance, choppResistance, ballisticResistance, environmentalResistance, flameResistance, energyResistance,
		shockResistance, acidResistance, magicalResistance, grapple, melee, strengthRanged, dexRanged, initiative, athletics, acrobatics, constitution, evasion, armorPenalty);

	NPCType.w1 = w1;
	NPCType.w2 = w2;
	NPCType.w3 = w3;
	
	NPCType.writeToFileNPC();

}

