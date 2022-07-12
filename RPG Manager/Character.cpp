#include "Character.h"

Character::Character(std::string n, int bR, int cR, int pR, int chR, int balR, int envR, int flR, int enR, int shR, int acR, int maR, int grp, int m, int strR, int dexR, int i, int ath, int acr, int c, int ev, int per, int ap, weaponID weapon1, weaponID weapon2, weaponID weapon3)
{
	woundLevel = 0;
	bluntResistance = bR;
	cutResistance = cR;
	pierceResistance = pR;
	chopResistance = chR;
	ballisticResistance = balR;
	environmentalResistance = envR;
	flameResistance = flR;
	energyResistance = enR;
	shockResistance = shR;
	acidResistance = acR;
	magicalResistance = maR;
	grapple = grp;
	melee = m;
	strenghtRanged = strR;
	dexRanged = dexR;
	initiative = i;
	athletics = ath;
	acrobatics = acr;
	constitution = c;
	evasion = ev;
	perception_Investigation = per;
	armorPenalty = ap;
	name = n;
	acted = false;
	w1.setWeapon(weapon1);
	w2.setWeapon(weapon2);
	w3.setWeapon(weapon3);
}

Character::Character(std::string n, int bR, int cR, int pR, int chR, int balR, int envR, int flR, int enR, int shR, int acR, int maR, int grp, int m, int strR, int dexR, int i, int ath, int acr, int c, int ev, int per, int ap)
{
	woundLevel = 0;
	bluntResistance = bR;
	cutResistance = cR;
	pierceResistance = pR;
	chopResistance = chR;
	ballisticResistance = balR;
	environmentalResistance = envR;
	flameResistance = flR;
	energyResistance = enR;
	shockResistance = shR;
	acidResistance = acR;
	magicalResistance = maR;
	grapple = grp;
	melee = m;
	strenghtRanged = strR;
	dexRanged = dexR;
	initiative = i;
	athletics = ath;
	acrobatics = acr;
	constitution = c;
	evasion = ev;
	perception_Investigation = per;
	armorPenalty = ap;
	name = n;
	acted = false;

	setBodyPart(bodyPrt::head, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::neck, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::rightArm, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::leftArm, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::chest, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::gut, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::rightLeg, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	setBodyPart(bodyPrt::leftLeg, 0, bR, cR, pR, chR, balR, envR, flR, enR, shR, acR, maR, ap);
	
}

void Character::setResistances()
{
	int response = -1;
	while (response != 0)
	{
		std::cout << "Select resistances for:" << '\n';
		std::cout << "1. General (applied to all)" << '\n';
		std::cout << "2. Head" << '\n';
		std::cout << "3. Neck" << '\n';
		std::cout << "4. Right Arm" << '\n';
		std::cout << "5. Left Arm" << '\n';
		std::cout << "6. Chest" << '\n';
		std::cout << "7. Gut" << '\n';
		std::cout << "8. Right Leg" << '\n';
		std::cout << "9. Left Leg" << '\n';
		std::cout << "0. Done" << '\n';

		response = getIntInput();
		while (response < 0 || response > 9)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			while (response != 13)
			{

				std::cout << "Choose Resistances" << '\n';
				std::cout << "1. Blunt " << bluntResistance << '\n';
				std::cout << "2. Cutting " << cutResistance << '\n';
				std::cout << "3. Piecing " << pierceResistance << '\n';
				std::cout << "4. Chopping " << chopResistance << '\n';
				std::cout << "5. Ballistic " << ballisticResistance << '\n';
				std::cout << "6. Environmental " << environmentalResistance << '\n';
				std::cout << "7. Fire " << flameResistance << '\n';
				std::cout << "8. Energy " << energyResistance << '\n';
				std::cout << "9. Shock " << shockResistance << '\n';
				std::cout << "10. Acid " << acidResistance << '\n';
				std::cout << "11. Magic " << magicalResistance << '\n';
				std::cout << "12. Reset" << '\n';
				std::cout << "13. Done (Save)" << '\n';

				response = getIntInput();

				while (!std::cin.good() || response < 1 || response > 13)
				{
					std::cout << "Invalid input. Please try again" << '\n';
					response = getIntInput();
				}

				switch (response)
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
					chopResistance++;
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
					bluntResistance = 0, cutResistance = 0, pierceResistance = 0, chopResistance = 0, ballisticResistance = 0, environmentalResistance = 0, flameResistance = 0,
						energyResistance = 0, shockResistance = 0, acidResistance = 0, magicalResistance = 0;
					break;
				}
				case 13:
				{
					setBodyPart(bodyPrt::head, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::neck, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::rightArm, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::leftArm, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::chest, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::gut, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::rightLeg, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::leftLeg, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					break;
				}
				}
			}
		}
		else if (response != 0)
		{
			switch (static_cast<bodyPrt>(response - 2))
			{
			case bodyPrt::head:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Head)" << '\n';
					std::cout << "1. Blunt " << head.bluntResistance << '\n';
					std::cout << "2. Cutting " << head.cutResistance << '\n';
					std::cout << "3. Piecing " << head.pierceResistance << '\n';
					std::cout << "4. Chopping " << head.chopResistance << '\n';
					std::cout << "5. Ballistic " << head.ballisticResistance << '\n';
					std::cout << "6. Environmental " << head.environmentalResistance << '\n';
					std::cout << "7. Fire " << head.flameResistance << '\n';
					std::cout << "8. Energy " << head.energyResistance << '\n';
					std::cout << "9. Shock " << head.shockResistance << '\n';
					std::cout << "10. Acid " << head.acidResistance << '\n';
					std::cout << "11. Magic " << head.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						head.bluntResistance++;
						break;
					}
					case 2:
					{
						head.cutResistance++;
						break;
					}
					case 3:
					{
						head.pierceResistance++;
						break;
					}
					case 4:
					{
						head.chopResistance++;
						break;
					}
					case 5:
					{
						head.ballisticResistance++;
						break;
					}
					case 6:
					{
						head.environmentalResistance++;
						break;
					}
					case 7:
					{
						head.flameResistance++;
						break;
					}
					case 8:
					{
						head.energyResistance++;
						break;
					}
					case 9:
					{
						head.shockResistance++;
						break;
					}
					case 10:
					{
						head.acidResistance++;
						break;
					}
					case 11:
					{
						head.magicalResistance++;
						break;
					}
					case 12:
					{
						head.bluntResistance = 0, head.cutResistance = 0, head.pierceResistance = 0, head.chopResistance = 0, head.ballisticResistance = 0, head.environmentalResistance = 0, head.flameResistance = 0,
							head.energyResistance = 0, head.shockResistance = 0, head.acidResistance = 0, head.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::neck:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Neck)" << '\n';
					std::cout << "1. Blunt " << neck.bluntResistance << '\n';
					std::cout << "2. Cutting " << neck.cutResistance << '\n';
					std::cout << "3. Piecing " << neck.pierceResistance << '\n';
					std::cout << "4. Chopping " << neck.chopResistance << '\n';
					std::cout << "5. Ballistic " << neck.ballisticResistance << '\n';
					std::cout << "6. Environmental " << neck.environmentalResistance << '\n';
					std::cout << "7. Fire " << neck.flameResistance << '\n';
					std::cout << "8. Energy " << neck.energyResistance << '\n';
					std::cout << "9. Shock " << neck.shockResistance << '\n';
					std::cout << "10. Acid " << neck.acidResistance << '\n';
					std::cout << "11. Magic " << neck.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						neck.bluntResistance++;
						break;
					}
					case 2:
					{
						neck.cutResistance++;
						break;
					}
					case 3:
					{
						neck.pierceResistance++;
						break;
					}
					case 4:
					{
						neck.chopResistance++;
						break;
					}
					case 5:
					{
						neck.ballisticResistance++;
						break;
					}
					case 6:
					{
						neck.environmentalResistance++;
						break;
					}
					case 7:
					{
						neck.flameResistance++;
						break;
					}
					case 8:
					{
						neck.energyResistance++;
						break;
					}
					case 9:
					{
						neck.shockResistance++;
						break;
					}
					case 10:
					{
						neck.acidResistance++;
						break;
					}
					case 11:
					{
						neck.magicalResistance++;
						break;
					}
					case 12:
					{
						neck.bluntResistance = 0, neck.cutResistance = 0, neck.pierceResistance = 0, neck.chopResistance = 0, neck.ballisticResistance = 0, neck.environmentalResistance = 0, neck.flameResistance = 0,
							neck.energyResistance = 0, neck.shockResistance = 0, neck.acidResistance = 0, neck.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::rightArm:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Right Arm)" << '\n';
					std::cout << "1. Blunt " << rightArm.bluntResistance << '\n';
					std::cout << "2. Cutting " << rightArm.cutResistance << '\n';
					std::cout << "3. Piecing " << rightArm.pierceResistance << '\n';
					std::cout << "4. Chopping " << rightArm.chopResistance << '\n';
					std::cout << "5. Ballistic " << rightArm.ballisticResistance << '\n';
					std::cout << "6. Environmental " << rightArm.environmentalResistance << '\n';
					std::cout << "7. Fire " << rightArm.flameResistance << '\n';
					std::cout << "8. Energy " << rightArm.energyResistance << '\n';
					std::cout << "9. Shock " << rightArm.shockResistance << '\n';
					std::cout << "10. Acid " << rightArm.acidResistance << '\n';
					std::cout << "11. Magic " << rightArm.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						rightArm.bluntResistance++;
						break;
					}
					case 2:
					{
						rightArm.cutResistance++;
						break;
					}
					case 3:
					{
						rightArm.pierceResistance++;
						break;
					}
					case 4:
					{
						rightArm.chopResistance++;
						break;
					}
					case 5:
					{
						rightArm.ballisticResistance++;
						break;
					}
					case 6:
					{
						rightArm.environmentalResistance++;
						break;
					}
					case 7:
					{
						rightArm.flameResistance++;
						break;
					}
					case 8:
					{
						rightArm.energyResistance++;
						break;
					}
					case 9:
					{
						rightArm.shockResistance++;
						break;
					}
					case 10:
					{
						rightArm.acidResistance++;
						break;
					}
					case 11:
					{
						rightArm.magicalResistance++;
						break;
					}
					case 12:
					{
						rightArm.bluntResistance = 0, rightArm.cutResistance = 0, rightArm.pierceResistance = 0, rightArm.chopResistance = 0, rightArm.ballisticResistance = 0, rightArm.environmentalResistance = 0, rightArm.flameResistance = 0,
							rightArm.energyResistance = 0, rightArm.shockResistance = 0, rightArm.acidResistance = 0, rightArm.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::leftArm:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Left Arm)" << '\n';
					std::cout << "1. Blunt " << leftArm.bluntResistance << '\n';
					std::cout << "2. Cutting " << leftArm.cutResistance << '\n';
					std::cout << "3. Piecing " << leftArm.pierceResistance << '\n';
					std::cout << "4. Chopping " << leftArm.chopResistance << '\n';
					std::cout << "5. Ballistic " << leftArm.ballisticResistance << '\n';
					std::cout << "6. Environmental " << leftArm.environmentalResistance << '\n';
					std::cout << "7. Fire " << leftArm.flameResistance << '\n';
					std::cout << "8. Energy " << leftArm.energyResistance << '\n';
					std::cout << "9. Shock " << leftArm.shockResistance << '\n';
					std::cout << "10. Acid " << leftArm.acidResistance << '\n';
					std::cout << "11. Magic " << leftArm.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						leftArm.bluntResistance++;
						break;
					}
					case 2:
					{
						leftArm.cutResistance++;
						break;
					}
					case 3:
					{
						leftArm.pierceResistance++;
						break;
					}
					case 4:
					{
						leftArm.chopResistance++;
						break;
					}
					case 5:
					{
						leftArm.ballisticResistance++;
						break;
					}
					case 6:
					{
						leftArm.environmentalResistance++;
						break;
					}
					case 7:
					{
						leftArm.flameResistance++;
						break;
					}
					case 8:
					{
						leftArm.energyResistance++;
						break;
					}
					case 9:
					{
						leftArm.shockResistance++;
						break;
					}
					case 10:
					{
						leftArm.acidResistance++;
						break;
					}
					case 11:
					{
						leftArm.magicalResistance++;
						break;
					}
					case 12:
					{
						leftArm.bluntResistance = 0, leftArm.cutResistance = 0, leftArm.pierceResistance = 0, leftArm.chopResistance = 0, leftArm.ballisticResistance = 0, leftArm.environmentalResistance = 0, leftArm.flameResistance = 0,
							leftArm.energyResistance = 0, leftArm.shockResistance = 0, leftArm.acidResistance = 0, leftArm.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::chest:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Chest)" << '\n';
					std::cout << "1. Blunt " << chest.bluntResistance << '\n';
					std::cout << "2. Cutting " << chest.cutResistance << '\n';
					std::cout << "3. Piecing " << chest.pierceResistance << '\n';
					std::cout << "4. Chopping " << chest.chopResistance << '\n';
					std::cout << "5. Ballistic " << chest.ballisticResistance << '\n';
					std::cout << "6. Environmental " << chest.environmentalResistance << '\n';
					std::cout << "7. Fire " << chest.flameResistance << '\n';
					std::cout << "8. Energy " << chest.energyResistance << '\n';
					std::cout << "9. Shock " << chest.shockResistance << '\n';
					std::cout << "10. Acid " << chest.acidResistance << '\n';
					std::cout << "11. Magic " << chest.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						chest.bluntResistance++;
						break;
					}
					case 2:
					{
						chest.cutResistance++;
						break;
					}
					case 3:
					{
						chest.pierceResistance++;
						break;
					}
					case 4:
					{
						chest.chopResistance++;
						break;
					}
					case 5:
					{
						chest.ballisticResistance++;
						break;
					}
					case 6:
					{
						chest.environmentalResistance++;
						break;
					}
					case 7:
					{
						chest.flameResistance++;
						break;
					}
					case 8:
					{
						chest.energyResistance++;
						break;
					}
					case 9:
					{
						chest.shockResistance++;
						break;
					}
					case 10:
					{
						chest.acidResistance++;
						break;
					}
					case 11:
					{
						chest.magicalResistance++;
						break;
					}
					case 12:
					{
						chest.bluntResistance = 0, chest.cutResistance = 0, chest.pierceResistance = 0, chest.chopResistance = 0, chest.ballisticResistance = 0, chest.environmentalResistance = 0, chest.flameResistance = 0,
							chest.energyResistance = 0, chest.shockResistance = 0, chest.acidResistance = 0, chest.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::gut:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Gut)" << '\n';
					std::cout << "1. Blunt " << gut.bluntResistance << '\n';
					std::cout << "2. Cutting " << gut.cutResistance << '\n';
					std::cout << "3. Piecing " << gut.pierceResistance << '\n';
					std::cout << "4. Chopping " << gut.chopResistance << '\n';
					std::cout << "5. Ballistic " << gut.ballisticResistance << '\n';
					std::cout << "6. Environmental " << gut.environmentalResistance << '\n';
					std::cout << "7. Fire " << gut.flameResistance << '\n';
					std::cout << "8. Energy " << gut.energyResistance << '\n';
					std::cout << "9. Shock " << gut.shockResistance << '\n';
					std::cout << "10. Acid " << gut.acidResistance << '\n';
					std::cout << "11. Magic " << gut.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						gut.bluntResistance++;
						break;
					}
					case 2:
					{
						gut.cutResistance++;
						break;
					}
					case 3:
					{
						gut.pierceResistance++;
						break;
					}
					case 4:
					{
						gut.chopResistance++;
						break;
					}
					case 5:
					{
						gut.ballisticResistance++;
						break;
					}
					case 6:
					{
						gut.environmentalResistance++;
						break;
					}
					case 7:
					{
						gut.flameResistance++;
						break;
					}
					case 8:
					{
						gut.energyResistance++;
						break;
					}
					case 9:
					{
						gut.shockResistance++;
						break;
					}
					case 10:
					{
						gut.acidResistance++;
						break;
					}
					case 11:
					{
						gut.magicalResistance++;
						break;
					}
					case 12:
					{
						gut.bluntResistance = 0, gut.cutResistance = 0, gut.pierceResistance = 0, gut.chopResistance = 0, gut.ballisticResistance = 0, gut.environmentalResistance = 0, gut.flameResistance = 0,
							gut.energyResistance = 0, gut.shockResistance = 0, gut.acidResistance = 0, gut.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::rightLeg:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Right Leg)" << '\n';
					std::cout << "1. Blunt " << rightLeg.bluntResistance << '\n';
					std::cout << "2. Cutting " << rightLeg.cutResistance << '\n';
					std::cout << "3. Piecing " << rightLeg.pierceResistance << '\n';
					std::cout << "4. Chopping " << rightLeg.chopResistance << '\n';
					std::cout << "5. Ballistic " << rightLeg.ballisticResistance << '\n';
					std::cout << "6. Environmental " << rightLeg.environmentalResistance << '\n';
					std::cout << "7. Fire " << rightLeg.flameResistance << '\n';
					std::cout << "8. Energy " << rightLeg.energyResistance << '\n';
					std::cout << "9. Shock " << rightLeg.shockResistance << '\n';
					std::cout << "10. Acid " << rightLeg.acidResistance << '\n';
					std::cout << "11. Magic " << rightLeg.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						rightLeg.bluntResistance++;
						break;
					}
					case 2:
					{
						rightLeg.cutResistance++;
						break;
					}
					case 3:
					{
						rightLeg.pierceResistance++;
						break;
					}
					case 4:
					{
						rightLeg.chopResistance++;
						break;
					}
					case 5:
					{
						rightLeg.ballisticResistance++;
						break;
					}
					case 6:
					{
						rightLeg.environmentalResistance++;
						break;
					}
					case 7:
					{
						rightLeg.flameResistance++;
						break;
					}
					case 8:
					{
						rightLeg.energyResistance++;
						break;
					}
					case 9:
					{
						rightLeg.shockResistance++;
						break;
					}
					case 10:
					{
						rightLeg.acidResistance++;
						break;
					}
					case 11:
					{
						rightLeg.magicalResistance++;
						break;
					}
					case 12:
					{
						rightLeg.bluntResistance = 0, rightLeg.cutResistance = 0, rightLeg.pierceResistance = 0, rightLeg.chopResistance = 0, rightLeg.ballisticResistance = 0, rightLeg.environmentalResistance = 0, rightLeg.flameResistance = 0,
							rightLeg.energyResistance = 0, rightLeg.shockResistance = 0, rightLeg.acidResistance = 0, rightLeg.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			case bodyPrt::leftLeg:
			{
				while (response != 13)
				{

					std::cout << "Choose Resistances (Left Leg)" << '\n';
					std::cout << "1. Blunt " << leftLeg.bluntResistance << '\n';
					std::cout << "2. Cutting " << leftLeg.cutResistance << '\n';
					std::cout << "3. Piecing " << leftLeg.pierceResistance << '\n';
					std::cout << "4. Chopping " << leftLeg.chopResistance << '\n';
					std::cout << "5. Ballistic " << leftLeg.ballisticResistance << '\n';
					std::cout << "6. Environmental " << leftLeg.environmentalResistance << '\n';
					std::cout << "7. Fire " << leftLeg.flameResistance << '\n';
					std::cout << "8. Energy " << leftLeg.energyResistance << '\n';
					std::cout << "9. Shock " << leftLeg.shockResistance << '\n';
					std::cout << "10. Acid " << leftLeg.acidResistance << '\n';
					std::cout << "11. Magic " << leftLeg.magicalResistance << '\n';
					std::cout << "12. Reset" << '\n';
					std::cout << "13. Done (Save)" << '\n';

					response = getIntInput();

					while (!std::cin.good() || response < 1 || response > 13)
					{
						std::cout << "Invalid input. Please try again" << '\n';
						std::cin.ignore(INT_MAX, '\n');
						response = getIntInput();
					}

					switch (response)
					{
					case 1:
					{
						leftLeg.bluntResistance++;
						break;
					}
					case 2:
					{
						leftLeg.cutResistance++;
						break;
					}
					case 3:
					{
						leftLeg.pierceResistance++;
						break;
					}
					case 4:
					{
						leftLeg.chopResistance++;
						break;
					}
					case 5:
					{
						leftLeg.ballisticResistance++;
						break;
					}
					case 6:
					{
						leftLeg.environmentalResistance++;
						break;
					}
					case 7:
					{
						leftLeg.flameResistance++;
						break;
					}
					case 8:
					{
						leftLeg.energyResistance++;
						break;
					}
					case 9:
					{
						leftLeg.shockResistance++;
						break;
					}
					case 10:
					{
						leftLeg.acidResistance++;
						break;
					}
					case 11:
					{
						leftLeg.magicalResistance++;
						break;
					}
					case 12:
					{
						leftLeg.bluntResistance = 0, leftLeg.cutResistance = 0, leftLeg.pierceResistance = 0, leftLeg.chopResistance = 0, leftLeg.ballisticResistance = 0, leftLeg.environmentalResistance = 0, leftLeg.flameResistance = 0,
							leftLeg.energyResistance = 0, leftLeg.shockResistance = 0, leftLeg.acidResistance = 0, leftLeg.magicalResistance = 0;
						break;
					}
					case 13:
					{
						break;
					}
					}
				}
			}
			}
		}
	}
}

void Character::setArmor(std::vector<Armor>& a)
{
	int response = -1;
	Armor temp;

	while (response != 0)
	{
		std::cout << "Choose Armor Type" << '\n';

		for (int i = 0; i < a.size(); i++)
		{
			std::cout << i + 1 << ". " << a[i].type << " (armor penalty: " << a[i].armorPenalty << ")" << '\n';
		}
		std::cout << "0. Done" << '\n';

		response = getIntInput();

		while (response < 0 || response > a.size())
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response != 0)
		{
			temp = a[response - 1];

			while (response != 0)
			{
				std::cout << "Choose Coverage (armor penalty: " << armorPenalty << ")" << '\n';
				std::cout << "1. Head" << '\n';
				std::cout << "2. Neck" << '\n';
				std::cout << "3. Right Arm" << '\n';
				std::cout << "4. Left Arm" << '\n';
				std::cout << "5. Chest" << '\n';
				std::cout << "6. Gut" << '\n';
				std::cout << "7. Right Leg" << '\n';
				std::cout << "8. Left Leg" << '\n';
				std::cout << "9. Full" << '\n';
				std::cout << "0. None (done)" << '\n';

				response = getIntInput();

				while (response < 0 || response > 9)
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}

				switch (response)
				{
				case 1:
				{
					head.bluntResistance += temp.bluntResistance;
					head.cutResistance += temp.cutResistance;
					head.pierceResistance += temp.pierceResistance;
					head.chopResistance += temp.chopResistance;
					head.ballisticResistance += temp.ballisticResistance;
					head.environmentalResistance += temp.environmentalResistance;
					head.flameResistance += temp.flameResistance;
					head.energyResistance += temp.energyResistance;
					head.shockResistance += temp.shockResistance;
					head.acidResistance += temp.acidResistance;
					head.magicalResistance += temp.magicalResistance;
					head.armorPenalty += temp.armorPenalty;
					break;
				}
				case 2:
				{
					neck.bluntResistance += temp.bluntResistance;
					neck.cutResistance += temp.cutResistance;
					neck.pierceResistance += temp.pierceResistance;
					neck.chopResistance += temp.chopResistance;
					neck.ballisticResistance += temp.ballisticResistance;
					neck.environmentalResistance += temp.environmentalResistance;
					neck.flameResistance += temp.flameResistance;
					neck.energyResistance += temp.energyResistance;
					neck.shockResistance += temp.shockResistance;
					neck.acidResistance += temp.acidResistance;
					neck.magicalResistance += temp.magicalResistance;
					neck.armorPenalty += temp.armorPenalty;
					break;
				}
				case 3:
				{
					rightArm.bluntResistance += temp.bluntResistance;
					rightArm.cutResistance += temp.cutResistance;
					rightArm.pierceResistance += temp.pierceResistance;
					rightArm.chopResistance += temp.chopResistance;
					rightArm.ballisticResistance += temp.ballisticResistance;
					rightArm.environmentalResistance += temp.environmentalResistance;
					rightArm.flameResistance += temp.flameResistance;
					rightArm.energyResistance += temp.energyResistance;
					rightArm.shockResistance += temp.shockResistance;
					rightArm.acidResistance += temp.acidResistance;
					rightArm.magicalResistance += temp.magicalResistance;
					rightArm.armorPenalty += temp.armorPenalty;
					break;
				}
				case 4:
				{
					leftArm.bluntResistance += temp.bluntResistance;
					leftArm.cutResistance += temp.cutResistance;
					leftArm.pierceResistance += temp.pierceResistance;
					leftArm.chopResistance += temp.chopResistance;
					leftArm.ballisticResistance += temp.ballisticResistance;
					leftArm.environmentalResistance += temp.environmentalResistance;
					leftArm.flameResistance += temp.flameResistance;
					leftArm.energyResistance += temp.energyResistance;
					leftArm.shockResistance += temp.shockResistance;
					leftArm.acidResistance += temp.acidResistance;
					leftArm.magicalResistance += temp.magicalResistance;
					leftArm.armorPenalty += temp.armorPenalty;
					break;
				}
				case 5:
				{
					chest.bluntResistance += temp.bluntResistance;
					chest.cutResistance += temp.cutResistance;
					chest.pierceResistance += temp.pierceResistance;
					chest.chopResistance += temp.chopResistance;
					chest.ballisticResistance += temp.ballisticResistance;
					chest.environmentalResistance += temp.environmentalResistance;
					chest.flameResistance += temp.flameResistance;
					chest.energyResistance += temp.energyResistance;
					chest.shockResistance += temp.shockResistance;
					chest.acidResistance += temp.acidResistance;
					chest.magicalResistance += temp.magicalResistance;
					chest.armorPenalty += temp.armorPenalty;
					break;
				}
				case 6:
				{
					gut.bluntResistance += temp.bluntResistance;
					gut.cutResistance += temp.cutResistance;
					gut.pierceResistance += temp.pierceResistance;
					gut.chopResistance += temp.chopResistance;
					gut.ballisticResistance += temp.ballisticResistance;
					gut.environmentalResistance += temp.environmentalResistance;
					gut.flameResistance += temp.flameResistance;
					gut.energyResistance += temp.energyResistance;
					gut.shockResistance += temp.shockResistance;
					gut.acidResistance += temp.acidResistance;
					gut.magicalResistance += temp.magicalResistance;
					gut.armorPenalty += temp.armorPenalty;
					break;
				}
				case 7:
				{
					rightLeg.bluntResistance += temp.bluntResistance;
					rightLeg.cutResistance += temp.cutResistance;
					rightLeg.pierceResistance += temp.pierceResistance;
					rightLeg.chopResistance += temp.chopResistance;
					rightLeg.ballisticResistance += temp.ballisticResistance;
					rightLeg.environmentalResistance += temp.environmentalResistance;
					rightLeg.flameResistance += temp.flameResistance;
					rightLeg.energyResistance += temp.energyResistance;
					rightLeg.shockResistance += temp.shockResistance;
					rightLeg.acidResistance += temp.acidResistance;
					rightLeg.magicalResistance += temp.magicalResistance;
					rightLeg.armorPenalty += temp.armorPenalty;
					break;
				}
				case 8:
				{
					leftLeg.bluntResistance += temp.bluntResistance;
					leftLeg.cutResistance += temp.cutResistance;
					leftLeg.pierceResistance += temp.pierceResistance;
					leftLeg.chopResistance += temp.chopResistance;
					leftLeg.ballisticResistance += temp.ballisticResistance;
					leftLeg.environmentalResistance += temp.environmentalResistance;
					leftLeg.flameResistance += temp.flameResistance;
					leftLeg.energyResistance += temp.energyResistance;
					leftLeg.shockResistance += temp.shockResistance;
					leftLeg.acidResistance += temp.acidResistance;
					leftLeg.magicalResistance += temp.magicalResistance;
					leftLeg.armorPenalty += temp.armorPenalty;
					break;
				}
				case 9:
				{
					bluntResistance += temp.bluntResistance;
					cutResistance += temp.cutResistance;
					pierceResistance += temp.pierceResistance;
					chopResistance += temp.chopResistance;
					ballisticResistance += temp.ballisticResistance;
					environmentalResistance += temp.environmentalResistance;
					flameResistance += temp.flameResistance;
					energyResistance += temp.energyResistance;
					shockResistance += temp.shockResistance;
					acidResistance += temp.acidResistance;
					magicalResistance += temp.magicalResistance;
					armorPenalty += temp.armorPenalty;

					head.bluntResistance += temp.bluntResistance;
					head.cutResistance += temp.cutResistance;
					head.pierceResistance += temp.pierceResistance;
					head.chopResistance += temp.chopResistance;
					head.ballisticResistance += temp.ballisticResistance;
					head.environmentalResistance += temp.environmentalResistance;
					head.flameResistance += temp.flameResistance;
					head.energyResistance += temp.energyResistance;
					head.shockResistance += temp.shockResistance;
					head.acidResistance += temp.acidResistance;
					head.magicalResistance += temp.magicalResistance;
					neck.bluntResistance += temp.bluntResistance;
					neck.cutResistance += temp.cutResistance;
					neck.pierceResistance += temp.pierceResistance;
					neck.chopResistance += temp.chopResistance;
					neck.ballisticResistance += temp.ballisticResistance;
					neck.environmentalResistance += temp.environmentalResistance;
					neck.flameResistance += temp.flameResistance;
					neck.energyResistance += temp.energyResistance;
					neck.shockResistance += temp.shockResistance;
					neck.acidResistance += temp.acidResistance;
					neck.magicalResistance += temp.magicalResistance;
					rightArm.bluntResistance += temp.bluntResistance;
					rightArm.cutResistance += temp.cutResistance;
					rightArm.pierceResistance += temp.pierceResistance;
					rightArm.chopResistance += temp.chopResistance;
					rightArm.ballisticResistance += temp.ballisticResistance;
					rightArm.environmentalResistance += temp.environmentalResistance;
					rightArm.flameResistance += temp.flameResistance;
					rightArm.energyResistance += temp.energyResistance;
					rightArm.shockResistance += temp.shockResistance;
					rightArm.acidResistance += temp.acidResistance;
					rightArm.magicalResistance += temp.magicalResistance;
					leftArm.bluntResistance += temp.bluntResistance;
					leftArm.cutResistance += temp.cutResistance;
					leftArm.pierceResistance += temp.pierceResistance;
					leftArm.chopResistance += temp.chopResistance;
					leftArm.ballisticResistance += temp.ballisticResistance;
					leftArm.environmentalResistance += temp.environmentalResistance;
					leftArm.flameResistance += temp.flameResistance;
					leftArm.energyResistance += temp.energyResistance;
					leftArm.shockResistance += temp.shockResistance;
					leftArm.acidResistance += temp.acidResistance;
					leftArm.magicalResistance += temp.magicalResistance;
					chest.bluntResistance += temp.bluntResistance;
					chest.cutResistance += temp.cutResistance;
					chest.pierceResistance += temp.pierceResistance;
					chest.chopResistance += temp.chopResistance;
					chest.ballisticResistance += temp.ballisticResistance;
					chest.environmentalResistance += temp.environmentalResistance;
					chest.flameResistance += temp.flameResistance;
					chest.energyResistance += temp.energyResistance;
					chest.shockResistance += temp.shockResistance;
					chest.acidResistance += temp.acidResistance;
					chest.magicalResistance += temp.magicalResistance;
					gut.bluntResistance += temp.bluntResistance;
					gut.cutResistance += temp.cutResistance;
					gut.pierceResistance += temp.pierceResistance;
					gut.chopResistance += temp.chopResistance;
					gut.ballisticResistance += temp.ballisticResistance;
					gut.environmentalResistance += temp.environmentalResistance;
					gut.flameResistance += temp.flameResistance;
					gut.energyResistance += temp.energyResistance;
					gut.shockResistance += temp.shockResistance;
					gut.acidResistance += temp.acidResistance;
					gut.magicalResistance += temp.magicalResistance;
					rightLeg.bluntResistance += temp.bluntResistance;
					rightLeg.cutResistance += temp.cutResistance;
					rightLeg.pierceResistance += temp.pierceResistance;
					rightLeg.chopResistance += temp.chopResistance;
					rightLeg.ballisticResistance += temp.ballisticResistance;
					rightLeg.environmentalResistance += temp.environmentalResistance;
					rightLeg.flameResistance += temp.flameResistance;
					rightLeg.energyResistance += temp.energyResistance;
					rightLeg.shockResistance += temp.shockResistance;
					rightLeg.acidResistance += temp.acidResistance;
					rightLeg.magicalResistance += temp.magicalResistance;
					leftLeg.bluntResistance += temp.bluntResistance;
					leftLeg.cutResistance += temp.cutResistance;
					leftLeg.pierceResistance += temp.pierceResistance;
					leftLeg.chopResistance += temp.chopResistance;
					leftLeg.ballisticResistance += temp.ballisticResistance;
					leftLeg.environmentalResistance += temp.environmentalResistance;
					leftLeg.flameResistance += temp.flameResistance;
					leftLeg.energyResistance += temp.energyResistance;
					leftLeg.shockResistance += temp.shockResistance;
					leftLeg.acidResistance += temp.acidResistance;
					leftLeg.magicalResistance += temp.magicalResistance;
					break;
				}
				}
				armorPenalty = (head.armorPenalty + neck.armorPenalty + rightArm.armorPenalty + leftArm.armorPenalty + chest.armorPenalty + gut.armorPenalty + rightLeg.armorPenalty + 
					leftLeg.armorPenalty) / 8;
			}
			
			response = -1;
		}
	}
}

void Character::resetArmor()
{
	setBodyPart(bodyPrt::all, woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::head, head.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::neck, neck.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::rightArm, rightArm.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::leftArm, leftArm.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::chest, chest.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::gut, gut.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::rightLeg, rightLeg.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	setBodyPart(bodyPrt::leftLeg, leftLeg.woundLevel, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	armorPenalty = 0;
}

std::string Character::getChName()
{
	return name;
}

Character::Character()
{
	woundLevel = 0;
	bluntResistance = 0;
	cutResistance = 0;
	pierceResistance = 0;
	chopResistance = 0;
	ballisticResistance = 0;
	environmentalResistance = 0;
	flameResistance = 0;
	energyResistance = 0;
	shockResistance = 0;
	acidResistance = 0;
	magicalResistance = 0;
	grapple = defaultLevel;
	melee = defaultLevel;
	strenghtRanged = defaultLevel;
	dexRanged = defaultLevel;
	initiative = defaultLevel;
	athletics = defaultLevel;
	acrobatics = defaultLevel;
	constitution = defaultLevel;
	evasion = defaultLevel;
	armorPenalty = 0;
	name = "";
	acted = false;
	w1.setWeapon(weaponID::knife);
}


void Character::writeToFileNPC()
{
	std::ofstream npcFile;
	npcFile.open("NPC.txt", std::ios::app);

	npcFile << name << '\n';
	npcFile << bluntResistance << '\n';
	npcFile << cutResistance << '\n';
	npcFile << pierceResistance << '\n';
	npcFile << chopResistance << '\n';
	npcFile << ballisticResistance << '\n';
	npcFile << environmentalResistance << '\n';
	npcFile << flameResistance << '\n';
	npcFile << energyResistance << '\n';
	npcFile << shockResistance << '\n';
	npcFile << acidResistance << '\n';
	npcFile << magicalResistance << '\n';
	npcFile << grapple << '\n';
	npcFile << melee << '\n';
	npcFile << strenghtRanged << '\n';
	npcFile << dexRanged << '\n';
	npcFile << initiative << '\n';
	npcFile << athletics << '\n';
	npcFile << acrobatics << '\n';
	npcFile << constitution << '\n';
	npcFile << evasion << '\n';
	npcFile << perception_Investigation << '\n';
	npcFile << armorPenalty << '\n';

	npcFile.close();

	w1.writeToNPCFile();
	w2.writeToNPCFile();
	w3.writeToNPCFile();

}

void Character::writeToCharacterFile()
{
	std::ofstream outFile;
	outFile.open("Character.txt", std::ios::app);

	outFile << name << '\n';
	outFile << vocation1 << '\n';
	outFile << vocation2 << '\n';
	outFile << vocation3 << '\n';
	
	outFile << grapple << '\n';
	outFile << melee << '\n';
	outFile << strenghtRanged << '\n';
	outFile << dexRanged << '\n';
	outFile << initiative << '\n';
	outFile << athletics << '\n';
	outFile << acrobatics << '\n';
	outFile << constitution << '\n';
	outFile << evasion << '\n';
	outFile << perception_Investigation << '\n';
	outFile << tactics_Command << '\n';
	outFile << artillery << '\n';
	outFile << strength << '\n';
	outFile << ride_Pilot << '\n';
	outFile << stealth_SlightofHand << '\n';
	outFile << persuasion_Deception << '\n';
	outFile << charm_Seduction << '\n';
	outFile << intimidation << '\n';
	outFile << fortitude_Tolerence << '\n';
	outFile << navigation << '\n';
	outFile << survival << '\n';
	outFile << technology << '\n';
	outFile << engineering << '\n';
	outFile << medicine << '\n';
	outFile << calculation_Mathematics << '\n';
	outFile << memory << '\n';
	outFile << languages_linguistics << '\n';
	outFile << sketching_Painting << '\n';
	outFile << sculpting_Carving << '\n';
	outFile << sewing_Weaving_Knitting << '\n';
	outFile << oratory_Performance << '\n';
	outFile << writing_Composition << '\n';
	outFile << dance << '\n';
	outFile << music_Composition << '\n';
	outFile << music_InstrumentalPerformance << '\n';
	outFile << music_VocalPerformance  << '\n';

	outFile << ss1.skillName << '\n';
	outFile << ss1.skillLevel << '\n';
	outFile << ss2.skillName << '\n';
	outFile << ss2.skillLevel << '\n';
	outFile << ss3.skillName << '\n';
	outFile << ss3.skillLevel << '\n';
	outFile << ss4.skillName << '\n';
	outFile << ss4.skillLevel << '\n';
	outFile << ss5.skillName << '\n';
	outFile << ss5.skillLevel << '\n';

	outFile << woundLevel << '\n';
	outFile << bluntResistance << '\n';
	outFile << cutResistance << '\n';
	outFile << pierceResistance << '\n';
	outFile << chopResistance << '\n';
	outFile << ballisticResistance << '\n';
	outFile << environmentalResistance << '\n';
	outFile << flameResistance << '\n';
	outFile << energyResistance << '\n';
	outFile << shockResistance << '\n';
	outFile << acidResistance << '\n';
	outFile << magicalResistance << '\n';
	outFile << armorPenalty << '\n';

	outFile << head.woundLevel << '\n';
	outFile << head.bluntResistance << '\n';
	outFile << head.cutResistance << '\n';
	outFile << head.pierceResistance << '\n';
	outFile << head.chopResistance << '\n';
	outFile << head.ballisticResistance << '\n';
	outFile << head.environmentalResistance << '\n';
	outFile << head.flameResistance << '\n';
	outFile << head.energyResistance << '\n';
	outFile << head.shockResistance << '\n';
	outFile << head.acidResistance << '\n';
	outFile << head.magicalResistance << '\n';
	outFile << head.armorPenalty << '\n';

	outFile << neck.woundLevel << '\n';
	outFile << neck.bluntResistance << '\n';
	outFile << neck.cutResistance << '\n';
	outFile << neck.pierceResistance << '\n';
	outFile << neck.chopResistance << '\n';
	outFile << neck.ballisticResistance << '\n';
	outFile << neck.environmentalResistance << '\n';
	outFile << neck.flameResistance << '\n';
	outFile << neck.energyResistance << '\n';
	outFile << neck.shockResistance << '\n';
	outFile << neck.acidResistance << '\n';
	outFile << neck.magicalResistance << '\n';
	outFile << neck.armorPenalty << '\n';

	outFile << rightArm.woundLevel << '\n';
	outFile << rightArm.bluntResistance << '\n';
	outFile << rightArm.cutResistance << '\n';
	outFile << rightArm.pierceResistance << '\n';
	outFile << rightArm.chopResistance << '\n';
	outFile << rightArm.ballisticResistance << '\n';
	outFile << rightArm.environmentalResistance << '\n';
	outFile << rightArm.flameResistance << '\n';
	outFile << rightArm.energyResistance << '\n';
	outFile << rightArm.shockResistance << '\n';
	outFile << rightArm.acidResistance << '\n';
	outFile << rightArm.magicalResistance << '\n';
	outFile << rightArm.armorPenalty << '\n';

	outFile << leftArm.woundLevel << '\n';
	outFile << leftArm.bluntResistance << '\n';
	outFile << leftArm.cutResistance << '\n';
	outFile << leftArm.pierceResistance << '\n';
	outFile << leftArm.chopResistance << '\n';
	outFile << leftArm.ballisticResistance << '\n';
	outFile << leftArm.environmentalResistance << '\n';
	outFile << leftArm.flameResistance << '\n';
	outFile << leftArm.energyResistance << '\n';
	outFile << leftArm.shockResistance << '\n';
	outFile << leftArm.acidResistance << '\n';
	outFile << leftArm.magicalResistance << '\n';
	outFile << leftArm.armorPenalty << '\n';

	outFile << chest.woundLevel << '\n';
	outFile << chest.bluntResistance << '\n';
	outFile << chest.cutResistance << '\n';
	outFile << chest.pierceResistance << '\n';
	outFile << chest.chopResistance << '\n';
	outFile << chest.ballisticResistance << '\n';
	outFile << chest.environmentalResistance << '\n';
	outFile << chest.flameResistance << '\n';
	outFile << chest.energyResistance << '\n';
	outFile << chest.shockResistance << '\n';
	outFile << chest.acidResistance << '\n';
	outFile << chest.magicalResistance << '\n';
	outFile << chest.armorPenalty << '\n';

	outFile << gut.woundLevel << '\n';
	outFile << gut.bluntResistance << '\n';
	outFile << gut.cutResistance << '\n';
	outFile << gut.pierceResistance << '\n';
	outFile << gut.chopResistance << '\n';
	outFile << gut.ballisticResistance << '\n';
	outFile << gut.environmentalResistance << '\n';
	outFile << gut.flameResistance << '\n';
	outFile << gut.energyResistance << '\n';
	outFile << gut.shockResistance << '\n';
	outFile << gut.acidResistance << '\n';
	outFile << gut.magicalResistance << '\n';
	outFile << gut.armorPenalty << '\n';

	outFile << rightLeg.woundLevel << '\n';
	outFile << rightLeg.bluntResistance << '\n';
	outFile << rightLeg.cutResistance << '\n';
	outFile << rightLeg.pierceResistance << '\n';
	outFile << rightLeg.chopResistance << '\n';
	outFile << rightLeg.ballisticResistance << '\n';
	outFile << rightLeg.environmentalResistance << '\n';
	outFile << rightLeg.flameResistance << '\n';
	outFile << rightLeg.energyResistance << '\n';
	outFile << rightLeg.shockResistance << '\n';
	outFile << rightLeg.acidResistance << '\n';
	outFile << rightLeg.magicalResistance << '\n';
	outFile << rightLeg.armorPenalty << '\n';

	outFile << leftLeg.woundLevel << '\n';
	outFile << leftLeg.bluntResistance << '\n';
	outFile << leftLeg.cutResistance << '\n';
	outFile << leftLeg.pierceResistance << '\n';
	outFile << leftLeg.chopResistance << '\n';
	outFile << leftLeg.ballisticResistance << '\n';
	outFile << leftLeg.environmentalResistance << '\n';
	outFile << leftLeg.flameResistance << '\n';
	outFile << leftLeg.energyResistance << '\n';
	outFile << leftLeg.shockResistance << '\n';
	outFile << leftLeg.acidResistance << '\n';
	outFile << leftLeg.magicalResistance << '\n';
	outFile << leftLeg.armorPenalty << '\n';
			  

	outFile.close();

	w1.writeToCharacterFile();
	w2.writeToCharacterFile();
	w3.writeToCharacterFile();
	w4.writeToCharacterFile();
	w5.writeToCharacterFile();
}

void Character::writeToEncounterFile(std::string encounter)
{
	std::ofstream outFile;
	outFile.open(encounter + ".txt", std::ios::app);

	outFile << name << '\n';
	outFile << vocation1 << '\n';
	outFile << vocation2 << '\n';
	outFile << vocation3 << '\n';

	outFile << grapple << '\n';
	outFile << melee << '\n';
	outFile << strenghtRanged << '\n';
	outFile << dexRanged << '\n';
	outFile << initiative << '\n';
	outFile << athletics << '\n';
	outFile << acrobatics << '\n';
	outFile << constitution << '\n';
	outFile << evasion << '\n';
	outFile << perception_Investigation << '\n';
	outFile << tactics_Command << '\n';
	outFile << artillery << '\n';
	outFile << strength << '\n';
	outFile << ride_Pilot << '\n';
	outFile << stealth_SlightofHand << '\n';
	outFile << persuasion_Deception << '\n';
	outFile << charm_Seduction << '\n';
	outFile << intimidation << '\n';
	outFile << fortitude_Tolerence << '\n';
	outFile << navigation << '\n';
	outFile << survival << '\n';
	outFile << technology << '\n';
	outFile << engineering << '\n';
	outFile << medicine << '\n';
	outFile << calculation_Mathematics << '\n';
	outFile << memory << '\n';
	outFile << languages_linguistics << '\n';
	outFile << sketching_Painting << '\n';
	outFile << sculpting_Carving << '\n';
	outFile << sewing_Weaving_Knitting << '\n';
	outFile << oratory_Performance << '\n';
	outFile << writing_Composition << '\n';
	outFile << dance << '\n';
	outFile << music_Composition << '\n';
	outFile << music_InstrumentalPerformance << '\n';
	outFile << music_VocalPerformance << '\n';

	outFile << ss1.skillName << '\n';
	outFile << ss1.skillLevel << '\n';
	outFile << ss2.skillName << '\n';
	outFile << ss2.skillLevel << '\n';
	outFile << ss3.skillName << '\n';
	outFile << ss3.skillLevel << '\n';
	outFile << ss4.skillName << '\n';
	outFile << ss4.skillLevel << '\n';
	outFile << ss5.skillName << '\n';
	outFile << ss5.skillLevel << '\n';

	outFile << woundLevel << '\n';
	outFile << bluntResistance << '\n';
	outFile << cutResistance << '\n';
	outFile << pierceResistance << '\n';
	outFile << chopResistance << '\n';
	outFile << ballisticResistance << '\n';
	outFile << environmentalResistance << '\n';
	outFile << flameResistance << '\n';
	outFile << energyResistance << '\n';
	outFile << shockResistance << '\n';
	outFile << acidResistance << '\n';
	outFile << magicalResistance << '\n';
	outFile << armorPenalty << '\n';

	outFile << head.woundLevel << '\n';
	outFile << head.bluntResistance << '\n';
	outFile << head.cutResistance << '\n';
	outFile << head.pierceResistance << '\n';
	outFile << head.chopResistance << '\n';
	outFile << head.ballisticResistance << '\n';
	outFile << head.environmentalResistance << '\n';
	outFile << head.flameResistance << '\n';
	outFile << head.energyResistance << '\n';
	outFile << head.shockResistance << '\n';
	outFile << head.acidResistance << '\n';
	outFile << head.magicalResistance << '\n';
	outFile << head.armorPenalty << '\n';

	outFile << neck.woundLevel << '\n';
	outFile << neck.bluntResistance << '\n';
	outFile << neck.cutResistance << '\n';
	outFile << neck.pierceResistance << '\n';
	outFile << neck.chopResistance << '\n';
	outFile << neck.ballisticResistance << '\n';
	outFile << neck.environmentalResistance << '\n';
	outFile << neck.flameResistance << '\n';
	outFile << neck.energyResistance << '\n';
	outFile << neck.shockResistance << '\n';
	outFile << neck.acidResistance << '\n';
	outFile << neck.magicalResistance << '\n';
	outFile << neck.armorPenalty << '\n';

	outFile << rightArm.woundLevel << '\n';
	outFile << rightArm.bluntResistance << '\n';
	outFile << rightArm.cutResistance << '\n';
	outFile << rightArm.pierceResistance << '\n';
	outFile << rightArm.chopResistance << '\n';
	outFile << rightArm.ballisticResistance << '\n';
	outFile << rightArm.environmentalResistance << '\n';
	outFile << rightArm.flameResistance << '\n';
	outFile << rightArm.energyResistance << '\n';
	outFile << rightArm.shockResistance << '\n';
	outFile << rightArm.acidResistance << '\n';
	outFile << rightArm.magicalResistance << '\n';
	outFile << rightArm.armorPenalty << '\n';

	outFile << leftArm.woundLevel << '\n';
	outFile << leftArm.bluntResistance << '\n';
	outFile << leftArm.cutResistance << '\n';
	outFile << leftArm.pierceResistance << '\n';
	outFile << leftArm.chopResistance << '\n';
	outFile << leftArm.ballisticResistance << '\n';
	outFile << leftArm.environmentalResistance << '\n';
	outFile << leftArm.flameResistance << '\n';
	outFile << leftArm.energyResistance << '\n';
	outFile << leftArm.shockResistance << '\n';
	outFile << leftArm.acidResistance << '\n';
	outFile << leftArm.magicalResistance << '\n';
	outFile << leftArm.armorPenalty << '\n';

	outFile << chest.woundLevel << '\n';
	outFile << chest.bluntResistance << '\n';
	outFile << chest.cutResistance << '\n';
	outFile << chest.pierceResistance << '\n';
	outFile << chest.chopResistance << '\n';
	outFile << chest.ballisticResistance << '\n';
	outFile << chest.environmentalResistance << '\n';
	outFile << chest.flameResistance << '\n';
	outFile << chest.energyResistance << '\n';
	outFile << chest.shockResistance << '\n';
	outFile << chest.acidResistance << '\n';
	outFile << chest.magicalResistance << '\n';
	outFile << chest.armorPenalty << '\n';

	outFile << gut.woundLevel << '\n';
	outFile << gut.bluntResistance << '\n';
	outFile << gut.cutResistance << '\n';
	outFile << gut.pierceResistance << '\n';
	outFile << gut.chopResistance << '\n';
	outFile << gut.ballisticResistance << '\n';
	outFile << gut.environmentalResistance << '\n';
	outFile << gut.flameResistance << '\n';
	outFile << gut.energyResistance << '\n';
	outFile << gut.shockResistance << '\n';
	outFile << gut.acidResistance << '\n';
	outFile << gut.magicalResistance << '\n';
	outFile << gut.armorPenalty << '\n';

	outFile << rightLeg.woundLevel << '\n';
	outFile << rightLeg.bluntResistance << '\n';
	outFile << rightLeg.cutResistance << '\n';
	outFile << rightLeg.pierceResistance << '\n';
	outFile << rightLeg.chopResistance << '\n';
	outFile << rightLeg.ballisticResistance << '\n';
	outFile << rightLeg.environmentalResistance << '\n';
	outFile << rightLeg.flameResistance << '\n';
	outFile << rightLeg.energyResistance << '\n';
	outFile << rightLeg.shockResistance << '\n';
	outFile << rightLeg.acidResistance << '\n';
	outFile << rightLeg.magicalResistance << '\n';
	outFile << rightLeg.armorPenalty << '\n';

	outFile << leftLeg.woundLevel << '\n';
	outFile << leftLeg.bluntResistance << '\n';
	outFile << leftLeg.cutResistance << '\n';
	outFile << leftLeg.pierceResistance << '\n';
	outFile << leftLeg.chopResistance << '\n';
	outFile << leftLeg.ballisticResistance << '\n';
	outFile << leftLeg.environmentalResistance << '\n';
	outFile << leftLeg.flameResistance << '\n';
	outFile << leftLeg.energyResistance << '\n';
	outFile << leftLeg.shockResistance << '\n';
	outFile << leftLeg.acidResistance << '\n';
	outFile << leftLeg.magicalResistance << '\n';
	outFile << leftLeg.armorPenalty << '\n';

	outFile.close();

	w1.writeToEncounterFile(encounter);
	w2.writeToEncounterFile(encounter);
	w3.writeToEncounterFile(encounter);
	w4.writeToEncounterFile(encounter);
	w5.writeToEncounterFile(encounter);
}

void Character::setID(std::string n)
{
	name = name + n;
}

void Character::setName(std::string n)
{
	name = n;
}

void Character::setVocation(int num, std::string voc)
{
	switch (num)
	{
		case 1:
		{
			vocation1 = voc;
			break;
		}
		case 2:
		{
			vocation2 = voc;
			break;
		}
		case 3:
		{
			vocation3 = voc;
			break;
		}
	}
}

int Character::getWoundLevel()
{
	return woundLevel;
}

int Character::getWoundLevel(bodyPrt bp)
{
	switch (bp)
	{
		case:: bodyPrt::all:
		{
			return woundLevel;
			break;
		}
		case::bodyPrt::head:
		{
			return head.woundLevel;
			break;
		}
		case::bodyPrt::neck:
		{
			return neck.woundLevel;
			break;
		}
		case::bodyPrt::rightArm:
		{
			return rightArm.woundLevel;
			break;
		}
		case::bodyPrt::leftArm:
		{
			return leftArm.woundLevel;
			break;
		}
		case::bodyPrt::chest:
		{
			return chest.woundLevel;
			break;
		}
		case::bodyPrt::gut:
		{
			return gut.woundLevel;
			break;
		}
		case::bodyPrt::rightLeg:
		{
			return rightLeg.woundLevel;
			break;
		}
		case::bodyPrt::leftLeg:
		{
			return leftLeg.woundLevel;
			break;
		}
		default:
		{
			return woundLevel;
		}
	}
}

int Character::getResistance(damageType dt)
{
	switch (dt)
	{
	case damageType::blunt:
	{
		return bluntResistance;
		break;
	}
	case damageType::cut:
	{
		return cutResistance;
		break;
	}
	case damageType::pierce:
	{
		return pierceResistance;
		break;
	}
	case damageType::chop:
	{
		return chopResistance;
		break;
	}
	}

	return 0;
}

int Character::getSkillLevel(skill s)
{
	switch (s)
	{
	case skill::S_grapple:
	{
		return grapple - woundLevel - armorPenalty;
		break;
	}
	case skill::S_melee:
	{
		return melee - woundLevel - armorPenalty;
		break;
	}
	case skill::S_strenghtRanged:
	{
		return strenghtRanged - woundLevel - armorPenalty;
		break;
	}
	case skill::S_dexRanged:
	{
		return dexRanged - woundLevel - armorPenalty;
		break;
	}
	case skill::S_initiative:
	{
		return initiative - woundLevel - armorPenalty;
		break;
	}
	case skill::S_athletics:
	{
		return athletics - woundLevel - armorPenalty;
		break;
	}
	case skill::S_Acrobatics:
	{
		return acrobatics - woundLevel - armorPenalty;
		break;
	}
	case skill::S_constitution:
	{
		return constitution - woundLevel;
		break;
	}
	case skill::S_evasion:
	{
		return evasion - woundLevel - armorPenalty;
		break;
	}
	case skill::S_perception_Investigation:
	{
		return perception_Investigation;
		break;
	}
	case skill::S_tactics_Command:
	{
		return tactics_Command;
		break;
	}
	case skill::S_artillery:
	{
		return artillery;
		break;
	}
	case skill::S_strength:
	{
		return strength - woundLevel - armorPenalty;
		break;
	}
	case skill::S_ride_Pilot:
	{
		return ride_Pilot - woundLevel - armorPenalty;
		break;
	}
	case skill::S_stealth_SlightofHand:
	{
		return stealth_SlightofHand - woundLevel - armorPenalty;
		break;
	}
	case skill::S_persuasion_Deception:
	{
		return persuasion_Deception;
		break;
	}
	case skill::S_charm_Seduction:
	{
		return charm_Seduction;
		break;
	}
	case skill::S_intimidation:
	{
		return intimidation;
		break;
	}
	case skill::S_fortitude_Tolerence:
	{
		return fortitude_Tolerence;
		break;
	}
	case skill::S_navigation:
	{
		return navigation;
		break;
	}
	case skill::S_survival:
	{
		return survival;
		break;
	}
	case skill::S_technology:
	{
		return technology;
		break;
	}
	case skill::S_engineering:
	{
		return engineering;
		break;
	}
	case skill::S_medicine:
	{
		return medicine;
		break;
	}
	case skill::S_calculation_Mathematics:
	{
		return calculation_Mathematics;
		break;
	}
	case skill::S_memory:
	{
		return memory;
		break;
	}
	case skill::S_languages_linguistics:
	{
		return languages_linguistics;
		break;
	}
	case skill::S_sketching_Painting:
	{
		return sketching_Painting;
		break;
	}
	case skill::S_sculpting_Carving:
	{
		return sculpting_Carving;
		break;
	}
	case skill::S_sewing_Weaving_Knitting:
	{
		return sewing_Weaving_Knitting;
		break;
	}
	case skill::S_oratory_Performance:
	{
		return oratory_Performance;
		break;
	}
	case skill::S_writing_Composition:
	{
		return writing_Composition;
		break;
	}
	case skill::S_dance:
	{
		return dance - woundLevel - armorPenalty;
		break;
	}
	case skill::S_music_Composition:
	{
		return music_Composition;
		break;
	}
	case skill::S_music_InstrumentalPerformance:
	{
		return music_InstrumentalPerformance;
		break;
	}
	case skill::S_music_VocalPerformance:
	{
		return music_VocalPerformance;
		break;
	}

	}

	return 0;
}

int Character::getTrueSkillLevel(skill s)
{
	switch (s)
	{
	case skill::S_grapple:
	{
		return grapple;
		break;
	}
	case skill::S_melee:
	{
		return melee;
		break;
	}
	case skill::S_strenghtRanged:
	{
		return strenghtRanged;
		break;
	}
	case skill::S_dexRanged:
	{
		return dexRanged;
		break;
	}
	case skill::S_initiative:
	{
		return initiative;
		break;
	}
	case skill::S_athletics:
	{
		return athletics;
		break;
	}
	case skill::S_Acrobatics:
	{
		return acrobatics;
		break;
	}
	case skill::S_constitution:
	{
		return constitution;
		break;
	}
	case skill::S_evasion:
	{
		return evasion;
		break;
	}
	case skill::S_perception_Investigation:
	{
		return perception_Investigation;
		break;
	}
	case skill::S_tactics_Command:
	{
		return tactics_Command;
		break;
	}
	case skill::S_artillery:
	{
		return artillery;
		break;
	}
	case skill::S_strength:
	{
		return strength;
		break;
	}
	case skill::S_ride_Pilot:
	{
		return ride_Pilot;
		break;
	}
	case skill::S_stealth_SlightofHand:
	{
		return stealth_SlightofHand;
		break;
	}
	case skill::S_persuasion_Deception:
	{
		return persuasion_Deception;
		break;
	}
	case skill::S_charm_Seduction:
	{
		return charm_Seduction;
		break;
	}
	case skill::S_intimidation:
	{
		return intimidation;
		break;
	}
	case skill::S_fortitude_Tolerence:
	{
		return fortitude_Tolerence;
		break;
	}
	case skill::S_navigation:
	{
		return navigation;
		break;
	}
	case skill::S_survival:
	{
		return survival;
		break;
	}
	case skill::S_technology:
	{
		return technology;
		break;
	}
	case skill::S_engineering:
	{
		return engineering;
		break;
	}
	case skill::S_medicine:
	{
		return medicine;
		break;
	}
	case skill::S_calculation_Mathematics:
	{
		return calculation_Mathematics;
		break;
	}
	case skill::S_memory:
	{
		return memory;
		break;
	}
	case skill::S_languages_linguistics:
	{
		return languages_linguistics;
		break;
	}
	case skill::S_sketching_Painting:
	{
		return sketching_Painting;
		break;
	}
	case skill::S_sculpting_Carving:
	{
		return sculpting_Carving;
		break;
	}
	case skill::S_sewing_Weaving_Knitting:
	{
		return sewing_Weaving_Knitting;
		break;
	}
	case skill::S_oratory_Performance:
	{
		return oratory_Performance;
		break;
	}
	case skill::S_writing_Composition:
	{
		return writing_Composition;
		break;
	}
	case skill::S_dance:
	{
		return dance;
		break;
	}
	case skill::S_music_Composition:
	{
		return music_Composition;
		break;
	}
	case skill::S_music_InstrumentalPerformance:
	{
		return music_InstrumentalPerformance;
		break;
	}
	case skill::S_music_VocalPerformance:
	{
		return music_VocalPerformance;
		break;
	}

	}

	return 0;
}

std::string Character::getName()
{
	return name;
}

bool Character::getActed()
{
	return acted;
}

bool Character::getAlive()
{
	return alive;
}

void Character::knockOut()
{
	alive = false;
}

void Character::revive()
{
	alive = true;
}

void Character::wound(int damage, damageType dt)
{
	if (damage > 0)
	{
		woundLevel += damage;
		std::cout << name << " took " << damage << " damage" << '\n';
		std::cout << name << " current wound level: " << woundLevel << '\n';
	}
}

void Character::heal()
{
	woundLevel = 0;
}

void Character::heal(bodyPrt bp, int level)
{
	switch (bp)
	{
		case bodyPrt::head:
		{
			head.woundLevel = level;
			break;
		}
		
		case bodyPrt::neck:
		{
			neck.woundLevel = level;
			break;
		}
		case bodyPrt::rightArm:
		{
			rightArm.woundLevel = level;
			break;
		}
		case bodyPrt::leftArm:
		{
			leftArm.woundLevel = level;
			break;
		}
		case bodyPrt::chest:
		{
			chest.woundLevel = level;
			break;
		}
		case bodyPrt::gut:
		{
			gut.woundLevel = level;
			break;
		}
		case bodyPrt::rightLeg:
		{
			rightLeg.woundLevel = level;
			break;
		}
		case bodyPrt::leftLeg:
		{
			leftLeg.woundLevel = level;
			break;
		}
		case bodyPrt::all:
		{
			head.woundLevel = level;
			neck.woundLevel = level;
			rightArm.woundLevel = level;
			leftArm.woundLevel = level;
			chest.woundLevel = level;
			gut.woundLevel = level;
			rightLeg.woundLevel = level;
			leftLeg.woundLevel = level;
			break;
		}
	default:
		break;
	}
}

void Character::act()
{
	acted = true;
}

void Character::replenishAction()
{
	acted = false;
}

void Character::rollInitiative()
{
	std::cout << name << " rolls initiative: ";
	initiativeRoll = diceRoll((getSkillLevel(skill::S_initiative) * 100));
	std::cout << initiativeRoll / 100 << " (" << initiativeRoll << ")" << '\n';
}

int Character::getInitiative()
{
	return initiativeRoll;
}

void Character::takeDamage(damageType dt, int damage)
{
	std::string part = "";
	if (diceRoll(getSkillLevel(skill::S_constitution)) > damage)
	{
		std::cout << name << " passed constitution check (" << damage << ") and reduced damage level by 1" << '\n';
		damage--;
	}
	else
	{
		std::cout << name << " failed constitution check (" << damage << ")" << '\n';
	}

	int preDamage = damage;

	std::cout << name << " Recieves " << damage << " damage to the:" << '\n';
	std::cout << "1. None (Apply to general wound level and resistances) Blunt Resistance = " << bluntResistance << " cutting = " << cutResistance << " pierce = " << pierceResistance << " chopping = " << chopResistance << '\n';
	std::cout << "2. Head Resistances: blunt = " << head.bluntResistance << " cutting = " << head.cutResistance << " pierce = " << head.pierceResistance << " chopping = " << head.chopResistance << '\n';
	std::cout << "3. Neck Resistances: blunt = " << neck.bluntResistance << " cutting = " << neck.cutResistance << " pierce = " << neck.pierceResistance << " chopping = " << neck.chopResistance << '\n';
	std::cout << "4. Right Arm Resistances: blunt = " << rightArm.bluntResistance << " cutting = " << rightArm.cutResistance << " pierce = " << rightArm.pierceResistance << " chopping = " << rightArm.chopResistance << '\n';
	std::cout << "5. Left Arm Resistances: blunt = " << leftArm.bluntResistance << " cutting = " << leftArm.cutResistance << " pierce = " << leftArm.pierceResistance << " chopping = " << leftArm.chopResistance << '\n';
	std::cout << "6. Chest Resistances: blunt = " << chest.bluntResistance << " cutting = " << chest.cutResistance << " pierce = " << chest.pierceResistance << " chopping = " << chest.chopResistance << '\n';
	std::cout << "7. Gut Resistances: blunt = " << gut.bluntResistance << " cutting = " << gut.cutResistance << " pierce = " << gut.pierceResistance << " chopping = " << gut.chopResistance << '\n';
	std::cout << "8. Right Leg Resistances: blunt = " << rightLeg.bluntResistance << " cutting = " << rightLeg.cutResistance << " pierce = " << rightLeg.pierceResistance << " chopping = " << rightLeg.chopResistance << '\n';
	std::cout << "9. Left Leg Resistances: blunt = " << leftLeg.bluntResistance << " cutting = " << leftLeg.cutResistance << " pierce = " << leftLeg.pierceResistance << " chopping = " << leftLeg.chopResistance << '\n';
	std::cout << "10. Random" << '\n';

	int response = getIntInput();

	while (response < 1 || response > 10)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	int preWound = head.woundLevel + neck.woundLevel + rightArm.woundLevel + leftArm.woundLevel + chest.woundLevel + gut.woundLevel + leftLeg.woundLevel + rightLeg.woundLevel;

	if (response == 1)
	{
		std::cout << name << " reduced damage by " << getResistance(dt) << " from damage resistance" << '\n';
		damage -= getResistance(dt);
		woundLevel += damage;
		std::cout << name << " took " << damage << " damage" << '\n';
		std::cout << name << " current wound level: " << woundLevel << '\n';
	}
	else
	{

		if (response == 10)
		{
			response = rand() % 7;
		}
		else
		{
			response -= 2;
		}
		switch (static_cast<bodyPrt>(response))
		{
			case bodyPrt::head:
			{
				part = "head";
				switch (dt)
				{
					case damageType::blunt:
					{
						head.woundLevel += damage - head.bluntResistance;
						break;
					}
					case damageType::cut:
					{
						head.woundLevel += damage - head.cutResistance;
						break;
					}
					case damageType::pierce:
					{
						head.woundLevel += damage - head.pierceResistance;
						break;
					}
					case damageType::chop:
					{
						head.woundLevel += damage - head.chopResistance;
						break;
					}
					case damageType::ballistic:
					{
						head.woundLevel += damage - head.ballisticResistance;
						break;
					}
					case damageType::environmental:
					{
						head.woundLevel += damage - head.environmentalResistance;
						break;
					}
					case damageType::flame:
					{
						head.woundLevel += damage - head.flameResistance;
						break;
					}
					case damageType::energy:
					{
						head.woundLevel += damage - head.energyResistance;
						break;
					}
					case damageType::shock:
					{
						head.woundLevel += damage - head.shockResistance;
						break;
					}
					case damageType::acid:
					{
						head.woundLevel += damage - head.acidResistance;
						break;
					}
					case damageType::magical:
					{
						head.woundLevel += damage - head.magicalResistance;
						break;
					}
				}

				if (head.woundLevel < 0)
				{
					head.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::neck:
			{
				part = "neck";
				switch (dt)
				{
				case damageType::blunt:
				{
					neck.woundLevel += damage - neck.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					neck.woundLevel += damage - neck.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					neck.woundLevel += damage - neck.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					neck.woundLevel += damage - neck.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					neck.woundLevel += damage - neck.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					neck.woundLevel += damage - neck.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					neck.woundLevel += damage - neck.flameResistance;
					break;
				}
				case damageType::energy:
				{
					neck.woundLevel += damage - neck.energyResistance;
					break;
				}
				case damageType::shock:
				{
					neck.woundLevel += damage - neck.shockResistance;
					break;
				}
				case damageType::acid:
				{
					neck.woundLevel += damage - neck.acidResistance;
					break;
				}
				case damageType::magical:
				{
					neck.woundLevel += damage - neck.magicalResistance;
					break;
				}
				}

				if (neck.woundLevel < 0)
				{
					neck.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::rightArm:
			{
				part = "right arm";
				switch (dt)
				{
				case damageType::blunt:
				{
					rightArm.woundLevel += damage - rightArm.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					rightArm.woundLevel += damage - rightArm.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					rightArm.woundLevel += damage - rightArm.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					rightArm.woundLevel += damage - rightArm.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					rightArm.woundLevel += damage - rightArm.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					rightArm.woundLevel += damage - rightArm.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					rightArm.woundLevel += damage - rightArm.flameResistance;
					break;
				}
				case damageType::energy:
				{
					rightArm.woundLevel += damage - rightArm.energyResistance;
					break;
				}
				case damageType::shock:
				{
					rightArm.woundLevel += damage - rightArm.shockResistance;
					break;
				}
				case damageType::acid:
				{
					rightArm.woundLevel += damage - rightArm.acidResistance;
					break;
				}
				case damageType::magical:
				{
					rightArm.woundLevel += damage - rightArm.magicalResistance;
					break;
				}
				}

				if (rightArm.woundLevel < 0)
				{
					rightArm.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::leftArm:
			{
				part = "left arm";
				switch (dt)
				{
				case damageType::blunt:
				{
					leftArm.woundLevel += damage - leftArm.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					leftArm.woundLevel += damage - leftArm.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					leftArm.woundLevel += damage - leftArm.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					leftArm.woundLevel += damage - leftArm.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					leftArm.woundLevel += damage - leftArm.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					leftArm.woundLevel += damage - leftArm.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					leftArm.woundLevel += damage - leftArm.flameResistance;
					break;
				}
				case damageType::energy:
				{
					leftArm.woundLevel += damage - leftArm.energyResistance;
					break;
				}
				case damageType::shock:
				{
					leftArm.woundLevel += damage - leftArm.shockResistance;
					break;
				}
				case damageType::acid:
				{
					leftArm.woundLevel += damage - leftArm.acidResistance;
					break;
				}
				case damageType::magical:
				{
					leftArm.woundLevel += damage - leftArm.magicalResistance;
					break;
				}
				}

				if (leftArm.woundLevel < 0)
				{
					leftArm.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::chest:
			{
				part = "chest";
				switch (dt)
				{
				case damageType::blunt:
				{
					chest.woundLevel += damage - chest.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					chest.woundLevel += damage - chest.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					chest.woundLevel += damage - chest.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					chest.woundLevel += damage - chest.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					chest.woundLevel += damage - chest.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					chest.woundLevel += damage - chest.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					chest.woundLevel += damage - chest.flameResistance;
					break;
				}
				case damageType::energy:
				{
					chest.woundLevel += damage - chest.energyResistance;
					break;
				}
				case damageType::shock:
				{
					chest.woundLevel += damage - chest.shockResistance;
					break;
				}
				case damageType::acid:
				{
					chest.woundLevel += damage - chest.acidResistance;
					break;
				}
				case damageType::magical:
				{
					chest.woundLevel += damage - chest.magicalResistance;
					break;
				}
				}

				if (chest.woundLevel < 0)
				{
					chest.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::gut:
			{
				part = "gut";
				switch (dt)
				{
				case damageType::blunt:
				{
					gut.woundLevel += damage - gut.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					gut.woundLevel += damage - gut.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					gut.woundLevel += damage - gut.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					gut.woundLevel += damage - gut.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					gut.woundLevel += damage - gut.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					gut.woundLevel += damage - gut.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					gut.woundLevel += damage - gut.flameResistance;
					break;
				}
				case damageType::energy:
				{
					gut.woundLevel += damage - gut.energyResistance;
					break;
				}
				case damageType::shock:
				{
					gut.woundLevel += damage - gut.shockResistance;
					break;
				}
				case damageType::acid:
				{
					gut.woundLevel += damage - gut.acidResistance;
					break;
				}
				case damageType::magical:
				{
					gut.woundLevel += damage - gut.magicalResistance;
					break;
				}
				}

				if (gut.woundLevel < 0)
				{
					gut.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::rightLeg:
			{
				part = "right leg";
				switch (dt)
				{
				case damageType::blunt:
				{
					rightLeg.woundLevel += damage - rightLeg.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					rightLeg.woundLevel += damage - rightLeg.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					rightLeg.woundLevel += damage - rightLeg.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					rightLeg.woundLevel += damage - rightLeg.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					rightLeg.woundLevel += damage - rightLeg.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					rightLeg.woundLevel += damage - rightLeg.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					rightLeg.woundLevel += damage - rightLeg.flameResistance;
					break;
				}
				case damageType::energy:
				{
					rightLeg.woundLevel += damage - rightLeg.energyResistance;
					break;
				}
				case damageType::shock:
				{
					rightLeg.woundLevel += damage - rightLeg.shockResistance;
					break;
				}
				case damageType::acid:
				{
					rightLeg.woundLevel += damage - rightLeg.acidResistance;
					break;
				}
				case damageType::magical:
				{
					rightLeg.woundLevel += damage - rightLeg.magicalResistance;
					break;
				}
				}

				if (rightLeg.woundLevel < 0)
				{
					rightLeg.woundLevel = 0;
				}
				break;
			}
			case bodyPrt::leftLeg:
			{
				part = "left leg";
				switch (dt)
				{
				case damageType::blunt:
				{
					leftLeg.woundLevel += damage - leftLeg.bluntResistance;
					break;
				}
				case damageType::cut:
				{
					leftLeg.woundLevel += damage - leftLeg.cutResistance;
					break;
				}
				case damageType::pierce:
				{
					leftLeg.woundLevel += damage - leftLeg.pierceResistance;
					break;
				}
				case damageType::chop:
				{
					leftLeg.woundLevel += damage - leftLeg.chopResistance;
					break;
				}
				case damageType::ballistic:
				{
					leftLeg.woundLevel += damage - leftLeg.ballisticResistance;
					break;
				}
				case damageType::environmental:
				{
					leftLeg.woundLevel += damage - leftLeg.environmentalResistance;
					break;
				}
				case damageType::flame:
				{
					leftLeg.woundLevel += damage - leftLeg.flameResistance;
					break;
				}
				case damageType::energy:
				{
					leftLeg.woundLevel += damage - leftLeg.energyResistance;
					break;
				}
				case damageType::shock:
				{
					leftLeg.woundLevel += damage - leftLeg.shockResistance;
					break;
				}
				case damageType::acid:
				{
					leftLeg.woundLevel += damage - leftLeg.acidResistance;
					break;
				}
				case damageType::magical:
				{
					leftLeg.woundLevel += damage - leftLeg.magicalResistance;
					break;
				}
				}

				if (leftLeg.woundLevel < 0)
				{
					leftLeg.woundLevel = 0;
				}
				break;
			}
		}
	int postWound = head.woundLevel + neck.woundLevel + rightArm.woundLevel + leftArm.woundLevel + chest.woundLevel + gut.woundLevel + leftLeg.woundLevel + rightLeg.woundLevel;
	
	std::cout << name << " took " << postWound - preWound << " damage to the " << part << '\n';

	if (preDamage - (postWound - preWound) > 0)
	{
		std::cout << name << " reduced damage by " << preDamage - (postWound - preWound) << " from damage resistance" << '\n';
	}
	
	woundLevel += (postWound - preWound);
	std::cout << name << " wound level: " << woundLevel << '\n';
	}

	if (woundLevel > 7)
	{
		std::cout << name << " is critically wounded! (total wound level > 7)" << '\n';
		std::cout << "enter command: 'kill/" << name << "' to remove from combat until revived" << '\n';
	}
	if (head.woundLevel > 4)
	{
		std::cout << name << " is critically wounded! (head wound level > 4)" << '\n';
		std::cout << "enter command: 'kill/" << name << "' to remove from combat until revived" << '\n';
	}
	if (neck.woundLevel > 4)
	{
		std::cout << name << " is critically wounded! (neck wound level > 4)" << '\n';
		std::cout << "enter command: 'kill/" << name << "' to remove from combat until revived" << '\n';
	}
	if (chest.woundLevel > 4)
	{
		std::cout << name << " is critically wounded! (chest wound level > 4)" << '\n';
		std::cout << "enter command: 'kill/" << name << "' to remove from combat until revived" << '\n';
	}
	
}



void Character::displayInfo()
{
	std::cout << "Name: " << getName() << '\n';
}

void Character::setWeapon(weaponID& w, weaponID nw)
{
	w = nw;
}

weaponID Character::getWeapon(int num)
{

	switch (num)
	{
	case 0:
	{
		return w1.getWeapon();
		break;
	}
	case 1:
	{
		return w2.getWeapon();
		break;
	}
	case 3:
	{
		return w3.getWeapon();
		break;
	}
	}

	return w1.getWeapon();
}

int Character::diceRoll(int level)
{
	if (level <= 0)
	{
		return 0;
	}
	if (level % 2 == 0)
	{
		return (rand() % level + 1) + (rand() % level + 1);
	}
	else
	{
		return (rand() % (level + 0) + 1) + (rand() % (level + 1) + 1);
	}
}

std::string Character::getAction()
{
	return currentAction;
}

void Character::setAction(std::string action)
{
	currentAction = action;
}

int Character::rollSkill(skill s, std::vector<Character>& combatants)
{
	int level = getSkillLevel(s);

	std::cout << "Use Vocation Bonus? (" << vocation1 << vocation2 << vocation3 << ")" << '\n';
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
		level += 2;
	}

	response = 0;

	while (response != 2)
	{
		std::cout << "Choose Assist Skill (from self or other active characters)?" << '\n';
		std::cout << "1. Yes" << '\n';
		std::cout << "2. No (Done)" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			std::cout << "Which Skill to Use?" << '\n';
			std::cout << "0. Nevermind (Done)" << '\n';
			std::cout << "1. Grapple" << '\n';
			std::cout << "2. Melee" << '\n';
			std::cout << "3. Ranged (Strength)" << '\n';
			std::cout << "4. Ranged (Dex)" << '\n';
			std::cout << "5. Initiative" << '\n';
			std::cout << "6. Athletics" << '\n';
			std::cout << "7. Acrobatics" << '\n';
			std::cout << "8. Constitution" << '\n';
			std::cout << "9. Evasion" << '\n';
			std::cout << "10. Perception/Investigation" << '\n';
			std::cout << "11. Tactics/Command" << '\n';
			std::cout << "12. Artillery" << '\n';
			std::cout << "13. Strength" << '\n';
			std::cout << "14. Ride/Pilot" << '\n';
			std::cout << "15. Stealth/Slight of Hand" << '\n';
			std::cout << "16. Persuasion/Deception" << '\n';
			std::cout << "17. Charm/Seduction" << '\n';
			std::cout << "18. Intimidation" << '\n';
			std::cout << "19. Fortitude/Tolerence" << '\n';
			std::cout << "20. Navigation" << '\n';
			std::cout << "21. Survival" << '\n';
			std::cout << "22. Technology" << '\n';
			std::cout << "23. Engineering" << '\n';
			std::cout << "24. Medicine" << '\n';
			std::cout << "25. Calculation/Mathematics" << '\n';
			std::cout << "26. Memory" << '\n';
			std::cout << "27. Language/Linguistics" << '\n';
			std::cout << "28. Sketching/Painting" << '\n';
			std::cout << "29. Sculpting/Carving" << '\n';
			std::cout << "30. Sewing/Weaving/Knitting" << '\n';
			std::cout << "31. Oratory/Verbal Performance" << '\n';
			std::cout << "32. Writing/Composition" << '\n';
			std::cout << "33. Dance" << '\n';
			std::cout << "34. Music Composition" << '\n';
			std::cout << "35. Musical Performance (Instruments)" << '\n';
			std::cout << "37. Other" << '\n';

			response = getIntInput();

			while (response < 0 || response > 37)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response != 37 && response != 0)
			{
				std::cout << "Use self or other character?" << '\n';
				std::cout << "1. Self" << '\n';
				std::cout << "2. Other" << '\n';
				int res2 = getIntInput();
				while (res2 < 1 || res2 > 2)
				{
					std::cout << "Invalid Input" << '\n';
					res2 = getIntInput();
				}
				if (res2 == 1)
				{
					level += getSkillLevel(static_cast<skill>(response - 1)) - 3;
				}
				else
				{
					std::cout << "Select character to get assistance from" << '\n';
					for (int i = 0; i < combatants.size(); i++)
					{
						std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
					}
					res2 = getIntInput();
					while (res2 < 1 || res2 > combatants.size())
					{
						std::cout << "Invalid Input" << '\n';
						res2 = getIntInput();
					}
					level += combatants[res2 - 1].getSkillLevel(static_cast<skill>(response - 1)) - 3;
				}
			}
			else if (response != 0)
			{
				std::cout << "Use self or other character?" << '\n';
				std::cout << "1. Self" << '\n';
				std::cout << "2. Other" << '\n';
				int res2 = getIntInput();
				while (res2 < 1 || res2 > 2)
				{
					std::cout << "Invalid Input" << '\n';
					res2 = getIntInput();
				}
				if (res2 == 1)
				{
					int i = 2;
					std::cout << "1. None" << '\n';
					if (ss1.skillName != "")
					{
						std::cout << i << ". " << ss1.skillName << '\n';
						i++;
					}
					if (ss2.skillName != "")
					{
						std::cout << i << ". " << ss2.skillName << '\n';
						i++;
					}
					if (ss3.skillName != "")
					{
						std::cout << i << ". " << ss3.skillName << '\n';
						i++;
					}
					if (ss4.skillName != "")
					{
						std::cout << i << ". " << ss4.skillName << '\n';
						i++;
					}
					if (ss5.skillName != "")
					{
						std::cout << i << ". " << ss5.skillName << '\n';
						i++;
					}

					response = getIntInput();

					while (response < 1 || response > i)
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}

					if (response != 1)
					{
						level += getSpecialSkillLevel(i - 1);
					}
				}
				else
				{
					std::cout << "Select character to get assistance from" << '\n';
					for (int i = 0; i < combatants.size(); i++)
					{
						std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
					}
					res2 = getIntInput();
					while (res2 < 1 || res2 > combatants.size())
					{
						std::cout << "Invalid Input" << '\n';
						res2 = getIntInput();
					}

					int i = 2;
					std::cout << "1. None" << '\n';
					if (combatants[res2 - 1].ss1.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss1.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss2.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss2.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss3.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss3.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss4.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss4.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss5.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss5.skillName << '\n';
						i++;
					}

					response = getIntInput();

					while (response < 1 || response > i)
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}

					if (response != 1)
					{
						level += combatants[res2 - 1].getSpecialSkillLevel(response - 1);
					}
				}

			}
			response = 1;
		}
	}

	std::cout << "Enter additional bonus or penalty (eg. status effects, etc.)" << '\n';

	response = getIntInput();

	level += response;

	if (level < 0)
	{
		level = 0;
	}

	std::cout << name << " Pre-roll Total: " << level << '\n';

	int result = diceRoll(level);
	std::cout << name << " Rolled " << result << '\n';

	return result;
}

int Character::rollSkill(std::vector<Character>& combatants)
{
	std::cout << "Which Skill to Use?" << '\n';
	std::cout << "1. Grapple" << '\n';
	std::cout << "2. Melee" << '\n';
	std::cout << "3. Ranged (Strength)" << '\n';
	std::cout << "4. Ranged (Dex)" << '\n';
	std::cout << "5. Initiative" << '\n';
	std::cout << "6. Athletics" << '\n';
	std::cout << "7. Acrobatics" << '\n';
	std::cout << "8. Constitution" << '\n';
	std::cout << "9. Evasion" << '\n';
	std::cout << "10. Perception/Investigation" << '\n';
	std::cout << "11. Tactics/Command" << '\n';
	std::cout << "12. Artillery" << '\n';
	std::cout << "13. Strength" << '\n';
	std::cout << "14. Ride/Pilot" << '\n';
	std::cout << "15. Stealth/Slight of Hand" << '\n';
	std::cout << "16. Persuasion/Deception" << '\n';
	std::cout << "17. Charm/Seduction" << '\n';
	std::cout << "18. Intimidation" << '\n';
	std::cout << "19. Fortitude/Tolerence" << '\n';
	std::cout << "20. Navigation" << '\n';
	std::cout << "21. Survival" << '\n';
	std::cout << "22. Technology" << '\n';
	std::cout << "23. Engineering" << '\n';
	std::cout << "24. Medicine" << '\n';
	std::cout << "25. Calculation/Mathematics" << '\n';
	std::cout << "26. Memory" << '\n';
	std::cout << "27. Language/Linguistics" << '\n';
	std::cout << "28. Sketching/Painting" << '\n';
	std::cout << "29. Sculpting/Carving" << '\n';
	std::cout << "30. Sewing/Weaving/Knitting" << '\n';
	std::cout << "31. Oratory/Verbal Performance" << '\n';
	std::cout << "32. Writing/Composition" << '\n';
	std::cout << "33. Dance" << '\n';
	std::cout << "34. Music Composition" << '\n';
	std::cout << "35. Musical Performance (Instruments)" << '\n';
	std::cout << "36. Musical Performance (Vocal)" << '\n';
	std::cout << "37. Other" << '\n';
	
	int response = getIntInput();

	while (response < 0 || response > 37)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	int level = 0;

	if (response != 37)
	{
		level = getSkillLevel(static_cast<skill>(response - 1));
	}
	else
	{
		int i = 2;
		std::cout << "1. None" << '\n';
		if (ss1.skillName != "")
		{
			std::cout << i << ". " << ss1.skillName << '\n';
			i++;
		}
		if (ss2.skillName != "")
		{
			std::cout << i << ". " << ss2.skillName << '\n';
			i++;
		}
		if (ss3.skillName != "")
		{
			std::cout << i << ". " << ss3.skillName << '\n';
			i++;
		}
		if (ss4.skillName != "")
		{
			std::cout << i << ". " << ss4.skillName << '\n';
			i++;
		}
		if (ss5.skillName != "")
		{
			std::cout << i << ". " << ss5.skillName << '\n';
			i++;
		}

		response = getIntInput();

		while (response < 1 || response > i)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response != 1)
		{
			level += getSpecialSkillLevel(i - 1);
		}
	}

	std::cout << "Use Vocation Bonus? (" << vocation1 << " " << vocation2 << " " << vocation3 << ")" << '\n';
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
		level += 2;
	}

	response = 0;

	while (response != 2)
	{
		std::cout << "Choose Assist Skill (from self or other active characters)?" << '\n';
		std::cout << "1. Yes" << '\n';
		std::cout << "2. No (Done)" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			std::cout << "Which Skill to Use?" << '\n';
			std::cout << "0. Nevermind (Done)" << '\n';
			std::cout << "1. Grapple" << '\n';
			std::cout << "2. Melee" << '\n';
			std::cout << "3. Ranged (Strength)" << '\n';
			std::cout << "4. Ranged (Dex)" << '\n';
			std::cout << "5. Initiative" << '\n';
			std::cout << "6. Athletics" << '\n';
			std::cout << "7. Acrobatics" << '\n';
			std::cout << "8. Constitution" << '\n';
			std::cout << "9. Evasion" << '\n';
			std::cout << "10. Perception/Investigation" << '\n';
			std::cout << "11. Tactics/Command" << '\n';
			std::cout << "12. Artillery" << '\n';
			std::cout << "13. Strength" << '\n';
			std::cout << "14. Ride/Pilot" << '\n';
			std::cout << "15. Stealth/Slight of Hand" << '\n';
			std::cout << "16. Persuasion/Deception" << '\n';
			std::cout << "17. Charm/Seduction" << '\n';
			std::cout << "18. Intimidation" << '\n';
			std::cout << "19. Fortitude/Tolerence" << '\n';
			std::cout << "20. Navigation" << '\n';
			std::cout << "21. Survival" << '\n';
			std::cout << "22. Technology" << '\n';
			std::cout << "23. Engineering" << '\n';
			std::cout << "24. Medicine" << '\n';
			std::cout << "25. Calculation/Mathematics" << '\n';
			std::cout << "26. Memory" << '\n';
			std::cout << "27. Language/Linguistics" << '\n';
			std::cout << "28. Sketching/Painting" << '\n';
			std::cout << "29. Sculpting/Carving" << '\n';
			std::cout << "30. Sewing/Weaving/Knitting" << '\n';
			std::cout << "31. Oratory/Verbal Performance" << '\n';
			std::cout << "32. Writing/Composition" << '\n';
			std::cout << "33. Dance" << '\n';
			std::cout << "34. Music Composition" << '\n';
			std::cout << "35. Musical Performance (Instruments)" << '\n';
			std::cout << "37. Other" << '\n';

			int response = getIntInput();

			while (response < 0 || response > 37)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response != 37 && response != 0)
			{
				std::cout << "Use self or other character?" << '\n';
				std::cout << "1. Self" << '\n';
				std::cout << "2. Other" << '\n';
				int res2 = getIntInput();
				while (res2 < 1 || res2 > 2)
				{
					std::cout << "Invalid Input" << '\n';
					res2 = getIntInput();
				}
				if (res2 == 1)
				{
					level += getSkillLevel(static_cast<skill>(response - 1)) - 3;
				}
				else
				{
					std::cout << "Select character to get assistance from" << '\n';
					for (int i = 0; i < combatants.size(); i++)
					{
						std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
					}
					res2 = getIntInput();
					while (res2 < 1 || res2 > combatants.size())
					{
						std::cout << "Invalid Input" << '\n';
						res2 = getIntInput();
					}
					level += combatants[res2 - 1].getSkillLevel(static_cast<skill>(response - 1)) - 3;
				}
			}
			else if(response != 0)
			{
				std::cout << "Use self or other character?" << '\n';
				std::cout << "1. Self" << '\n';
				std::cout << "2. Other" << '\n';
				int res2 = getIntInput();
				while (res2 < 1 || res2 > 2)
				{
					std::cout << "Invalid Input" << '\n';
					res2 = getIntInput();
				}
				if (res2 == 1)
				{
					int i = 2;
					std::cout << "1. None" << '\n';
					if (ss1.skillName != "")
					{
						std::cout << i << ". " << ss1.skillName << '\n';
						i++;
					}
					if (ss2.skillName != "")
					{
						std::cout << i << ". " << ss2.skillName << '\n';
						i++;
					}
					if (ss3.skillName != "")
					{
						std::cout << i << ". " << ss3.skillName << '\n';
						i++;
					}
					if (ss4.skillName != "")
					{
						std::cout << i << ". " << ss4.skillName << '\n';
						i++;
					}
					if (ss5.skillName != "")
					{
						std::cout << i << ". " << ss5.skillName << '\n';
						i++;
					}

					response = getIntInput();

					while (response < 1 || response > i)
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}

					if (response != 1)
					{
						level += getSpecialSkillLevel(i - 1);
					}
				}
				else
				{
					std::cout << "Select character to get assistance from" << '\n';
					for (int i = 0; i < combatants.size(); i++)
					{
						std::cout << i + 1 << ". " << combatants[i].getName() << '\n';
					}
					res2 = getIntInput();
					while (res2 < 1 || res2 > combatants.size())
					{
						std::cout << "Invalid Input" << '\n';
						res2 = getIntInput();
					}

					int i = 2;
					std::cout << "1. None" << '\n';
					if (combatants[res2 - 1].ss1.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss1.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss2.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss2.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss3.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss3.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss4.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss4.skillName << '\n';
						i++;
					}
					if (combatants[res2 - 1].ss5.skillName != "")
					{
						std::cout << i << ". " << combatants[res2 - 1].ss5.skillName << '\n';
						i++;
					}

					response = getIntInput();

					while (response < 1 || response > i)
					{
						std::cout << "Invalid Input" << '\n';
						response = getIntInput();
					}

					if (response != 1)
					{
						level += combatants[res2 - 1].getSpecialSkillLevel(response - 1);
					}
				}

			}
			response = 1;
		}
	}

	std::cout << "Enter additional bonus or penalty (eg. status effects, etc.)" << '\n';

	response = getIntInput();

	level += response;

	if (level < 0)
	{
		level = 0;
	}

	std::cout << name << " Pre-roll Total: " << level << '\n';

	int result = diceRoll(level);
	std::cout << name << " Rolled " << result << '\n';

	return result;
}

int Character::rollAttack(int& dmg, damageType& dmgType,const range& r)
{
	std::cout << name << " is attacking" << '\n';
	std::cout << "Select Weapon" << '\n';

	int numWeapons = 1;

	std::cout << "1. " << w1.getName() << " (" << w1.getLoadedAmmo() << ")" << '\n';
	if (w2.getName() != "")
	{
		std::cout << "2. " << w2.getName() << " (" << w2.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w3.getName() != "")
	{
		std::cout << "3. " << w3.getName() << " (" << w3.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w4.getName() != "")
	{
		std::cout << "4. " << w4.getName() << " (" << w4.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w5.getName() != "")
	{
		std::cout << "5. " << w5.getName() << " (" << w5.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}

	int response = getIntInput();

	while (response < 1 || response > numWeapons)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	Weapon wep;
	int whichWeapon;

	switch (response)
	{
	case 1:
	{
		wep = w1;
		whichWeapon = 1;
		break;
	}
	case 2:
	{
		wep = w2;
		whichWeapon = 2;
		break;
	}
	case 3:
	{
		wep = w3;
		whichWeapon = 3;
		break;
	}
	case 4:
	{
		wep = w4;
		whichWeapon = 4;
		break;
	}
	case 5:
	{
		wep = w5;
		whichWeapon = 5;
		break;
	}
	}

	std::cout << "Select Attack" << '\n';

	int numAttacks = 1;

	std::cout << "1. " << wep.a1.getName() << '\n';

	if (wep.a2.getName() != "")
	{
		std::cout << "2. " << wep.a2.getName() << '\n';
		numAttacks++;
	}
	if (wep.a3.getName() != "")
	{
		std::cout << "3. " << wep.a3.getName() << '\n';
		numAttacks++;
	}
	if (wep.a4.getName() != "")
	{
		std::cout << "4. " << wep.a4.getName() << '\n';
		numAttacks++;
	}

	response = getIntInput();

	while (response < 1 || response > numAttacks)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	Attack a;

	switch (response)
	{
	case 1:
	{
		a = wep.a1;
		break;
	}
	case 2:
	{
		a = wep.a2;
		break;
	}
	case 3:
	{
		a = wep.a3;
		break;
	}
	case 4:
	{
		a = wep.a4;
		break;
	}
	}

	int level = 0;

	switch (r)
	{
	case range::grappleR:
	{

		if (a.getRangeAttackType() == skill::S_strenghtRanged || a.getRangeAttackType() == skill::S_dexRanged)
		{
			if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
			{
				wep.spendAmmo(wep.getAmmoPerShot());
				level += getSkillLevel(skill::S_grapple) + a.getGrappleBonus();
			}
			else
			{
				std::cout << "Out of Ammo" << '\n';
				return 0;
			}

		}
		else
		{
			level += getSkillLevel(skill::S_grapple) + a.getGrappleBonus();
		}
		break;
	}
	case range::meleeR:
	{
		if (a.getRangeAttackType() == skill::S_strenghtRanged || a.getRangeAttackType() == skill::S_dexRanged)
		{
			if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
			{
				wep.spendAmmo(wep.getAmmoPerShot());
				level += getSkillLevel(skill::S_melee) + a.getMeleeBonus();
			}
			else
			{
				std::cout << "Out of Ammo" << '\n';
				return 0;
			}

		}
		else
		{
			level += getSkillLevel(skill::S_melee) + a.getMeleeBonus();
		}
		break;
	}
	case range::shortR:
	{
		if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
		{
			if (a.getRangeAttackType() == skill::S_strenghtRanged)
			{
				level += getSkillLevel(skill::S_strenghtRanged) + a.getShortRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else if (a.getRangeAttackType() == skill::S_dexRanged)
			{
				level += getSkillLevel(skill::S_dexRanged) + a.getShortRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else
			{
				std::cout << "Out of Range" << '\n';
				return 0;
			}
		}
		else
		{
			std::cout << "Out of ammo (reload)" << '\n';
			return 0;
		}

		break;
	}
	case range::mediumR:
	{
		if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
		{
			if (a.getRangeAttackType() == skill::S_strenghtRanged)
			{
				level += getSkillLevel(skill::S_strenghtRanged) + a.getMediumRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else if (a.getRangeAttackType() == skill::S_dexRanged)
			{
				level += getSkillLevel(skill::S_dexRanged) + a.getMediumRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else
			{
				std::cout << "Out of Range" << '\n';
				return 0;
			}
		}
		else
		{
			std::cout << "Out of ammo (reload)" << '\n';
			return 0;
		}
		break;
	}
	case range::longR:
	{
		if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
		{
			if (a.getRangeAttackType() == skill::S_strenghtRanged)
			{
				level += getSkillLevel(skill::S_strenghtRanged) + a.getLongRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else if (a.getRangeAttackType() == skill::S_dexRanged)
			{
				level += getSkillLevel(skill::S_dexRanged) + a.getLongRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else
			{
				std::cout << "Out of Range" << '\n';
				return 0;
			}
		}
		else
		{
			std::cout << "Out of ammo (reload)" << '\n';
			return 0;
		}
		break;
	}
	}

	std::cout << "Use Vocation Bonus? (" << vocation1 << " " << vocation2 << " " << vocation3 << ")" << '\n';
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
		level += 2;
	}

	response = 0;

	while (response != 2)
	{
		std::cout << "Choose Assist Skill?" << '\n';
		std::cout << "1. Yes" << '\n';
		std::cout << "2. No (Done)" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			std::cout << "Which Skill to Use?" << '\n';
			std::cout << "0. Nevermind (Done)" << '\n';
			std::cout << "1. Grapple" << '\n';
			std::cout << "2. Melee" << '\n';
			std::cout << "3. Ranged (Strength)" << '\n';
			std::cout << "4. Ranged (Dex)" << '\n';
			std::cout << "5. Initiative" << '\n';
			std::cout << "6. Athletics" << '\n';
			std::cout << "7. Acrobatics" << '\n';
			std::cout << "8. Constitution" << '\n';
			std::cout << "9. Evasion" << '\n';
			std::cout << "10. Perception/Investigation" << '\n';
			std::cout << "11. Tactics/Command" << '\n';
			std::cout << "12. Artillery" << '\n';
			std::cout << "13. Strength" << '\n';
			std::cout << "14. Ride/Pilot" << '\n';
			std::cout << "15. Stealth/Slight of Hand" << '\n';
			std::cout << "16. Persuasion/Deception" << '\n';
			std::cout << "17. Charm/Seduction" << '\n';
			std::cout << "18. Intimidation" << '\n';
			std::cout << "19. Fortitude/Tolerence" << '\n';
			std::cout << "20. Navigation" << '\n';
			std::cout << "21. Survival" << '\n';
			std::cout << "22. Technology" << '\n';
			std::cout << "23. Engineering" << '\n';
			std::cout << "24. Medicine" << '\n';
			std::cout << "25. Calculation/Mathematics" << '\n';
			std::cout << "26. Memory" << '\n';
			std::cout << "27. Language/Linguistics" << '\n';
			std::cout << "28. Sketching/Painting" << '\n';
			std::cout << "29. Sculpting/Carving" << '\n';
			std::cout << "30. Sewing/Weaving/Knitting" << '\n';
			std::cout << "31. Oratory/Verbal Performance" << '\n';
			std::cout << "32. Writing/Composition" << '\n';
			std::cout << "33. Dance" << '\n';
			std::cout << "34. Music Composition" << '\n';
			std::cout << "35. Musical Performance (Instruments)" << '\n';
			std::cout << "36. Musical Performance (Vocal)" << '\n';
			std::cout << "37. Other" << '\n';

			response = getIntInput();

			while (response < 0 || response > 37)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response != 0 && response != 37)
			{
				level += getSkillLevel(static_cast<skill>(response - 1)) - 3;
				response = 0;
			}
			else if (response == 36)
			{
				int i = 2;
				std::cout << "1. None" << '\n';
				if (ss1.skillName != "")
				{
					std::cout << i << ". " << ss1.skillName << '\n';
					i++;
				}
				if (ss2.skillName != "")
				{
					std::cout << i << ". " << ss2.skillName << '\n';
					i++;
				}
				if (ss3.skillName != "")
				{
					std::cout << i << ". " << ss3.skillName << '\n';
					i++;
				}
				if (ss4.skillName != "")
				{
					std::cout << i << ". " << ss4.skillName << '\n';
					i++;
				}
				if (ss5.skillName != "")
				{
					std::cout << i << ". " << ss5.skillName << '\n';
					i++;
				}

				response = getIntInput();

				while (response < 1 || response > i)
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}

				if (response != 1)
				{
					level += getSpecialSkillLevel(i - 2);
					level -= 3;
				}
			}
			else
			{
				response = 2;
			}


		}
	}

	std::cout << "Enter additional bonus or penalty (eg. status effects, shield, etc.)" << '\n';

	response = getIntInput();

	level += response;

	if (level <= 0)
	{
		level = 0;
		std::cout << "Attack Failed (Result Less than 0)" << '\n';
		return 0;
	}
	else
	{
		dmgType = a.getDamageType();
		std::string dmgTypeString;

		switch (dmgType)
		{
		case damageType::blunt:
		{
			dmgTypeString = "Blunt";
			break;
		}
		case damageType::cut:
		{
			dmgTypeString = "Cut";
			break;
		}
		case damageType::pierce:
		{
			dmgTypeString = "Pierce";
			break;
		}
		case damageType::chop:
		{
			dmgTypeString = "Chop";
			break;
		}
		case damageType::ballistic:
		{
			dmgTypeString = "Ballistic";
			break;
		}
		case damageType::environmental:
		{
			dmgTypeString = "Environmental";
			break;
		}
		case damageType::flame:
		{
			dmgTypeString = "Flame";
			break;
		}
		case damageType::energy:
		{
			dmgTypeString = "Energy";
			break;
		}
		case damageType::shock:
		{
			dmgTypeString = "Shock";
			break;
		}
		case damageType::acid:
		{
			dmgTypeString = "Acid";
			break;
		}
		case damageType::magical:
		{
			dmgTypeString = "Magical";
			break;
		}
		default:
		{
			dmgTypeString = "Unknown";
		}
		}

		dmg = (rand() % a.getBaseDamage() + 1) + a.getDamageModifier();
		std::cout << "Damage: " << dmg << " " << dmgTypeString << " (1d" << a.getBaseDamage() << " + " << a.getDamageModifier() << ")" << '\n';
	}

	std::cout << name << " pre-roll total = " << level << '\n';

	int result = diceRoll(level);

	std::cout << name << " rolled: " << result << '\n';

	switch (whichWeapon)
	{
	case 1:
	{
		w1 = wep;
		break;
	}
	case 2:
	{
		w2 = wep;
		break;
	}
	case 3:
	{
		w3 = wep;
		break;
	}
	case 4:
	{
		w4 = wep;
		break;
	}
	case 5:
	{
		w5 = wep;
		break;
	}
	}

	return result;
}

int Character::rollAttack(int& dmg, damageType& dmgType)
{
	std::cout << "Select Weapon" << '\n';
	
	int numWeapons = 1;
	
	std::cout << "1. " << w1.getName() << " (" << w1.getLoadedAmmo() << ")" << '\n';
	if (w2.getName() != "")
	{
		std::cout << "2. " << w2.getName() << " (" << w2.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w3.getName() != "")
	{
		std::cout << "3. " << w3.getName() << " (" << w3.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w4.getName() != "")
	{
		std::cout << "4. " << w4.getName() << " (" << w4.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w5.getName() != "")
	{
		std::cout << "5. " << w5.getName() << " (" << w5.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}

	int response = getIntInput();

	while (response < 1 || response > numWeapons)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}
	
	Weapon wep;
	int whichWeapon;

	switch (response)
	{
		case 1:
		{
			wep = w1;
			whichWeapon = 1;
			break;
		}
		case 2:
		{
			wep = w2;
			whichWeapon = 2;
			break;
		}
		case 3:
		{
			wep = w3;
			whichWeapon = 3;
			break;
		}
		case 4:
		{
			wep = w4;
			whichWeapon = 4;
			break;
		}
		case 5:
		{
			wep = w5;
			whichWeapon = 5;
			break;
		}
	}

	std::cout << "Select Range" << '\n';
	std::cout << "1. Grapple" << '\n';
	std::cout << "2. Melee" << '\n';
	std::cout << "3. Short" << '\n';
	std::cout << "4. Medium" << '\n';
	std::cout << "5. Long" << '\n';

	response = getIntInput();

	while (response < 1 || response > 5)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	range r = static_cast<range>(response - 1);

	std::cout << "Select Attack" << '\n';

	int numAttacks = 1;

	std::cout << "1. " << wep.a1.getName() << '\n';

	if (wep.a2.getName() != "")
	{
		std::cout << "2. " << wep.a2.getName() << '\n';
		numAttacks++;
	}
	if (wep.a3.getName() != "")
	{
		std::cout << "3. " << wep.a3.getName() << '\n';
		numAttacks++;
	}
	if (wep.a4.getName() != "")
	{
		std::cout << "4. " << wep.a4.getName() << '\n';
		numAttacks++;
	}
	
	response = getIntInput();

	while (response < 1 || response > numAttacks)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	Attack a;

	switch (response)
	{
		case 1:
		{
			a = wep.a1;
			break;
		}
		case 2:
		{
			a = wep.a2;
			break;
		}
		case 3:
		{
			a = wep.a3;
			break;
		}
		case 4:
		{
			a = wep.a4;
			break;
		}
	}

	int level = 0;

	switch (r)
	{
	case range::grappleR:
	{
		
		if (a.getRangeAttackType() == skill::S_strenghtRanged || a.getRangeAttackType() == skill::S_dexRanged)
		{
			if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
			{
				wep.spendAmmo(wep.getAmmoPerShot());
				level += getSkillLevel(skill::S_grapple) + a.getGrappleBonus();
			}
			else
			{
				std::cout << "Out of Ammo" << '\n';
				return 0;
			}
			
		}
		else
		{
			level += getSkillLevel(skill::S_grapple) + a.getGrappleBonus();
		}
		break;
	}
	case range::meleeR:
	{
		if (a.getRangeAttackType() == skill::S_strenghtRanged || a.getRangeAttackType() == skill::S_dexRanged)
		{
			if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
			{
				wep.spendAmmo(wep.getAmmoPerShot());
				level += getSkillLevel(skill::S_melee) + a.getMeleeBonus();
			}
			else
			{
				std::cout << "Out of Ammo" << '\n';
				return 0;
			}

		}
		else
		{
			level += getSkillLevel(skill::S_melee) + a.getMeleeBonus();
		}
		break;
	}
	case range::shortR:
	{
		if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
		{
			if (a.getRangeAttackType() == skill::S_strenghtRanged)
			{
				level += getSkillLevel(skill::S_strenghtRanged) + a.getShortRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else if (a.getRangeAttackType() == skill::S_dexRanged)
			{
				level += getSkillLevel(skill::S_dexRanged) + a.getShortRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else
			{
				std::cout << "Out of Range" << '\n';
				return 0;
			}
		}
		else
		{
			std::cout << "Out of ammo (reload)" << '\n';
			return 0;
		}
		
		break;
	}
	case range::mediumR:
	{
		if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
		{
			if (a.getRangeAttackType() == skill::S_strenghtRanged)
			{
				level += getSkillLevel(skill::S_strenghtRanged) + a.getMediumRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else if (a.getRangeAttackType() == skill::S_dexRanged)
			{
				level += getSkillLevel(skill::S_dexRanged) + a.getMediumRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else
			{
				std::cout << "Out of Range" << '\n';
				return 0;
			}
		}
		else
		{
			std::cout << "Out of ammo (reload)" << '\n';
			return 0;
		}
		break;
	}
	case range::longR:
	{
		if (wep.getLoadedAmmo() >= wep.getAmmoPerShot())
		{
			if (a.getRangeAttackType() == skill::S_strenghtRanged)
			{
				level += getSkillLevel(skill::S_strenghtRanged) + a.getLongRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else if (a.getRangeAttackType() == skill::S_dexRanged)
			{
				level += getSkillLevel(skill::S_dexRanged) + a.getLongRangeBonus();
				wep.spendAmmo(wep.getAmmoPerShot());
			}
			else
			{
				std::cout << "Out of Range" << '\n';
				return 0;
			}
		}
		else
		{
			std::cout << "Out of ammo (reload)" << '\n';
			return 0;
		}
		break;
	}
	}

	std::cout << "Use Vocation Bonus? (" << vocation1 << " " << vocation2 << " " << vocation3 << ")" << '\n';
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
		level += 2;
	}

	response = 0;

	while (response != 2)
	{
		std::cout << "Choose Assist Skill?" << '\n';
		std::cout << "1. Yes" << '\n';
		std::cout << "2. No (Done)" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			std::cout << "Which Skill to Use?" << '\n';
			std::cout << "0. Nevermind (Done)" << '\n';
			std::cout << "1. Grapple" << '\n';
			std::cout << "2. Melee" << '\n';
			std::cout << "3. Ranged (Strength)" << '\n';
			std::cout << "4. Ranged (Dex)" << '\n';
			std::cout << "5. Initiative" << '\n';
			std::cout << "6. Athletics" << '\n';
			std::cout << "7. Acrobatics" << '\n';
			std::cout << "8. Constitution" << '\n';
			std::cout << "9. Evasion" << '\n';
			std::cout << "10. Perception/Investigation" << '\n';
			std::cout << "11. Tactics/Command" << '\n';
			std::cout << "12. Artillery" << '\n';
			std::cout << "13. Strength" << '\n';
			std::cout << "14. Ride/Pilot" << '\n';
			std::cout << "15. Stealth/Slight of Hand" << '\n';
			std::cout << "16. Persuasion/Deception" << '\n';
			std::cout << "17. Charm/Seduction" << '\n';
			std::cout << "18. Intimidation" << '\n';
			std::cout << "19. Fortitude/Tolerence" << '\n';
			std::cout << "20. Navigation" << '\n';
			std::cout << "21. Survival" << '\n';
			std::cout << "22. Technology" << '\n';
			std::cout << "23. Engineering" << '\n';
			std::cout << "24. Medicine" << '\n';
			std::cout << "25. Calculation/Mathematics" << '\n';
			std::cout << "26. Memory" << '\n';
			std::cout << "27. Language/Linguistics" << '\n';
			std::cout << "28. Sketching/Painting" << '\n';
			std::cout << "29. Sculpting/Carving" << '\n';
			std::cout << "30. Sewing/Weaving/Knitting" << '\n';
			std::cout << "31. Oratory/Verbal Performance" << '\n';
			std::cout << "32. Writing/Composition" << '\n';
			std::cout << "33. Dance" << '\n';
			std::cout << "34. Music Composition" << '\n';
			std::cout << "35. Musical Performance (Instruments)" << '\n';
			std::cout << "36. Musical Performance (Vocal)" << '\n';
			std::cout << "37. Other" << '\n';

			response = getIntInput();

			while (response < 0 || response > 37)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response != 0 && response != 37)
			{
				level += getSkillLevel(static_cast<skill>(response - 1)) - 3;
				response = 0;
			}
			else if (response == 36)
			{
				int i = 2;
				std::cout << "1. None" << '\n';
				if (ss1.skillName != "")
				{
					std::cout << i << ". " << ss1.skillName << '\n';
					i++;
				}
				if (ss2.skillName != "")
				{
					std::cout << i << ". " << ss2.skillName << '\n';
					i++;
				}
				if (ss3.skillName != "")
				{
					std::cout << i << ". " << ss3.skillName << '\n';
					i++;
				}
				if (ss4.skillName != "")
				{
					std::cout << i << ". " << ss4.skillName << '\n';
					i++;
				}
				if (ss5.skillName != "")
				{
					std::cout << i << ". " << ss5.skillName << '\n';
					i++;
				}

				response = getIntInput();

				while (response < 1 || response > i)
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}

				if (response != 1)
				{
					level += getSpecialSkillLevel(i - 2);
					level -= 3;
				}
			}
			else
			{
				response = 2;
			}


		}
	}

	std::cout << "Enter additional bonus or penalty (eg. status effects, etc.)" << '\n';

	response = getIntInput();

	level += response;

	if (level <= 0)
	{
		level = 0;
		std::cout << "Attack Failed (Not in Proper Range)" << '\n';
		return 0;
	}
	else
	{
		dmgType = a.getDamageType();
		std::string dmgTypeString;

		switch (dmgType)
		{
			case damageType::blunt:
			{
				dmgTypeString = "Blunt";
				break;
			}
			case damageType::cut:
			{
				dmgTypeString = "Cut";
				break;
			}
			case damageType::pierce:
			{
				dmgTypeString = "Pierce";
				break;
			}
			case damageType::chop:
			{
				dmgTypeString = "Chop";
				break;
			}
			case damageType::ballistic:
			{
				dmgTypeString = "Ballistic";
				break;
			}
			case damageType::environmental:
			{
				dmgTypeString = "Environmental";
				break;
			}
			case damageType::flame:
			{
				dmgTypeString = "Flame";
				break;
			}
			case damageType::energy:
			{
				dmgTypeString = "Energy";
				break;
			}
			case damageType::shock:
			{
				dmgTypeString = "Shock";
				break;
			}
			case damageType::acid:
			{
				dmgTypeString = "Acid";
				break;
			}
			case damageType::magical:
			{
				dmgTypeString = "Magical";
				break;
			}
			default:
			{
				dmgTypeString = "Unknown";
			}
		}

		dmg = (rand() % a.getBaseDamage() + 1) + a.getDamageModifier();
		std::cout << "Damage: " << dmg << " " << dmgTypeString << " (1d" << a.getBaseDamage() << " + " << a.getDamageModifier() << ")" << '\n';
	}

	std::cout << name << " pre-roll total = " << level << '\n';

	int result = diceRoll(level);

	std::cout << name << " rolled: " << result << '\n';

	switch (whichWeapon)
	{
		case 1:
		{
			w1 = wep;
			break;
		}
		case 2:
		{
			w2 = wep;
			break;
		}
		case 3:
		{
			w3 = wep;
			break;
		}
		case 4:
		{
			w4 = wep;
			break;
		}
		case 5:
		{
			w5 = wep;
			break;
		}
	}

	return result;
}

void Character::reloadWeapon()
{
	std::cout << "Select Weapon" << '\n';

	int numWeapons = 1;

	std::cout << "1. " << w1.getName() << " (" << w1.getLoadedAmmo() << ")" << '\n';
	if (w2.getName() != "")
	{
		std::cout << "2. " << w2.getName() << " (" << w2.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w3.getName() != "")
	{
		std::cout << "3. " << w3.getName() << " (" << w3.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w4.getName() != "")
	{
		std::cout << "4. " << w4.getName() << " (" << w4.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}
	if (w5.getName() != "")
	{
		std::cout << "5. " << w5.getName() << " (" << w5.getLoadedAmmo() << ")" << '\n';
		numWeapons++;
	}

	int response = getIntInput();

	while (response < 1 || response > numWeapons)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	Weapon wep;
	int whichWeapon = 1;

	switch (response)
	{
	case 1:
	{
		wep = w1;
		whichWeapon = 1;
		break;
	}
	case 2:
	{
		wep = w2;
		whichWeapon = 2;
		break;
	}
	case 3:
	{
		wep = w3;
		whichWeapon = 3;
		break;
	}
	case 4:
	{
		wep = w4;
		whichWeapon = 4;
		break;
	}
	case 5:
	{
		wep = w5;
		whichWeapon = 5;
		break;
	}
	}

	int reloaded = 0;

	if (wep.getLoadedAmmo() < wep.getMaxAmmo())
	{
		while (wep.getSpareAmmo() > 0 && wep.getLoadedAmmo() < wep.getMaxAmmo())
		{
			wep.reloadOne();
			reloaded++;
		}
		if (wep.getSpareAmmo() == 0)
		{
			std::cout << "Out of spare ammo" << '\n';
		}
		std::cout << "Reloaded " << reloaded << '\n';

		switch (whichWeapon)
		{
		case 1:
		{
			w1 = wep;
			break;
		}
		case 2:
		{
			w2 = wep;
			break;
		}
		case 3:
		{
			w3 = wep;
			break;
		}
		case 4:
		{
			w4 = wep;
			break;
		}
		case 5:
		{
			w5 = wep;
			break;
		}
		}
	}
	else
	{
		std::cout << "Already Loaded" << '\n';
	}
}

void Character::setSpecialSkill(int skillNum, std::string skillName, int skillLevel)
{
	switch (skillNum)
	{
		case 1:
		{
			ss1.skillName = skillName;
			ss1.skillLevel = skillLevel;
			break;
		}
		case 2:
		{
			ss2.skillName = skillName;
			ss2.skillLevel = skillLevel;
			break;
		}
		case 3:
		{
			ss3.skillName = skillName;
			ss3.skillLevel = skillLevel;
			break;
		}
		case 4:
		{
			ss4.skillName = skillName;
			ss4.skillLevel = skillLevel;
			break;
		}
		case 5:
		{
			ss5.skillName = skillName;
			ss5.skillLevel = skillLevel;
			break;
		}
	}
}

int Character::getSpecialSkillLevel(int skillNum)
{
	switch (skillNum)
	{
	case 1:
	{
		return ss1.skillLevel;
		break;
	}
	case 2:
	{
		return ss2.skillLevel;
		break;
	}
	case 3:
	{
		return ss3.skillLevel;
		break;
	}
	case 4:
	{
		return ss4.skillLevel;
		break;
	}
	case 5:
	{
		return ss5.skillLevel;
		break;
	}
	}

	return 0;
}

void Character::setWoundLevel(int l, bodyPrt bP)
{
	switch (bP)
	{
		case bodyPrt::all:
		{
			woundLevel = l;
			head.woundLevel = l;
			neck.woundLevel = l;
			rightArm.woundLevel = l;
			leftArm.woundLevel = l;
			chest.woundLevel = l;
			gut.woundLevel = l;
			rightLeg.woundLevel = l;
			leftLeg.woundLevel = l;
			break;
		}
		case bodyPrt::head:
		{
			woundLevel += l - head.woundLevel;
			head.woundLevel = l;
			break;
		}
		case bodyPrt::neck:
		{
			woundLevel += l - neck.woundLevel;
			neck.woundLevel = l;
			break;
		}
		case bodyPrt::rightArm:
		{
			woundLevel += l - rightArm.woundLevel;
			rightArm.woundLevel = l;
			break;
		}
		case bodyPrt::leftArm:
		{
			woundLevel += l - leftArm.woundLevel;
			leftArm.woundLevel = l;
			break;
		}
		case bodyPrt::chest:
		{
			woundLevel += l - chest.woundLevel;
			chest.woundLevel = l;
			break;
		}
		case bodyPrt::gut:
		{
			woundLevel += l - gut.woundLevel;
			gut.woundLevel = l;
			break;
		}
		case bodyPrt::rightLeg:
		{
			woundLevel += l - rightLeg.woundLevel;
			rightLeg.woundLevel = l;
			break;
		}
		case bodyPrt::leftLeg:
		{
			woundLevel += l - leftLeg.woundLevel;
			leftLeg.woundLevel = l;
			break;
		}
	}


}

void Character::setBodyPart(bodyPrt bP, int wL, int bR, int cR, int pR, int chR, int baR, int eR, int fR, int enR, int sR, int aR, int mR, int aP)
{
	switch (bP)
	{
		case bodyPrt::head:
		{
			head.woundLevel = wL;
			head.bluntResistance = bR;
			head.cutResistance = cR;
			head.pierceResistance = pR;
			head.chopResistance = chR;
			head.ballisticResistance = baR;
			head.environmentalResistance = eR;
			head.flameResistance = fR;
			head.energyResistance = enR;
			head.shockResistance = sR;
			head.acidResistance = aR;
			head.magicalResistance = mR;
			head.armorPenalty = aP;
			break;
		}
		case bodyPrt::neck:
		{
			neck.woundLevel = wL;
			neck.bluntResistance = bR;
			neck.cutResistance = cR;
			neck.pierceResistance = pR;
			neck.chopResistance = chR;
			neck.ballisticResistance = baR;
			neck.environmentalResistance = eR;
			neck.flameResistance = fR;
			neck.energyResistance = enR;
			neck.shockResistance = sR;
			neck.acidResistance = aR;
			neck.magicalResistance = mR;
			neck.armorPenalty = aP;
			break;
		}
		case bodyPrt::rightArm:
		{
			rightArm.woundLevel = wL;
			rightArm.bluntResistance = bR;
			rightArm.cutResistance = cR;
			rightArm.pierceResistance = pR;
			rightArm.chopResistance = chR;
			rightArm.ballisticResistance = baR;
			rightArm.environmentalResistance = eR;
			rightArm.flameResistance = fR;
			rightArm.energyResistance = enR;
			rightArm.shockResistance = sR;
			rightArm.acidResistance = aR;
			rightArm.magicalResistance = mR;
			rightArm.armorPenalty = aP;
			break;
		}
		case bodyPrt::leftArm:
		{
			leftArm.woundLevel = wL;
			leftArm.bluntResistance = bR;
			leftArm.cutResistance = cR;
			leftArm.pierceResistance = pR;
			leftArm.chopResistance = chR;
			leftArm.ballisticResistance = baR;
			leftArm.environmentalResistance = eR;
			leftArm.flameResistance = fR;
			leftArm.energyResistance = enR;
			leftArm.shockResistance = sR;
			leftArm.acidResistance = aR;
			leftArm.magicalResistance = mR;
			leftArm.armorPenalty = aP;
			break;
		}
		case bodyPrt::chest:
		{
			chest.woundLevel = wL;
			chest.bluntResistance = bR;
			chest.cutResistance = cR;
			chest.pierceResistance = pR;
			chest.chopResistance = chR;
			chest.ballisticResistance = baR;
			chest.environmentalResistance = eR;
			chest.flameResistance = fR;
			chest.energyResistance = enR;
			chest.shockResistance = sR;
			chest.acidResistance = aR;
			chest.magicalResistance = mR;
			chest.armorPenalty = aP;
			break;
		}
		case bodyPrt::gut:
		{
			gut.woundLevel = wL;
			gut.bluntResistance = bR;
			gut.cutResistance = cR;
			gut.pierceResistance = pR;
			gut.chopResistance = chR;
			gut.ballisticResistance = baR;
			gut.environmentalResistance = eR;
			gut.flameResistance = fR;
			gut.energyResistance = enR;
			gut.shockResistance = sR;
			gut.acidResistance = aR;
			gut.magicalResistance = mR;
			gut.armorPenalty = aP;
			break;
		}
		case bodyPrt::rightLeg:
		{
			rightLeg.woundLevel = wL;
			rightLeg.bluntResistance = bR;
			rightLeg.cutResistance = cR;
			rightLeg.pierceResistance = pR;
			rightLeg.chopResistance = chR;
			rightLeg.ballisticResistance = baR;
			rightLeg.environmentalResistance = eR;
			rightLeg.flameResistance = fR;
			rightLeg.energyResistance = enR;
			rightLeg.shockResistance = sR;
			rightLeg.acidResistance = aR;
			rightLeg.magicalResistance = mR;
			rightLeg.armorPenalty = aP;
			break;
		}
		case bodyPrt::leftLeg:
		{
			leftLeg.woundLevel = wL;
			leftLeg.bluntResistance = bR;
			leftLeg.cutResistance = cR;
			leftLeg.pierceResistance = pR;
			leftLeg.chopResistance = chR;
			leftLeg.ballisticResistance = baR;
			leftLeg.environmentalResistance = eR;
			leftLeg.flameResistance = fR;
			leftLeg.energyResistance = enR;
			leftLeg.shockResistance = sR;
			leftLeg.acidResistance = aR;
			leftLeg.magicalResistance = mR;
			leftLeg.armorPenalty = aP;
			break;
		}
		case bodyPrt::all:
		{
			woundLevel = wL;
			bluntResistance = bR;
			cutResistance = cR;
			pierceResistance = pR;
			chopResistance = chR;
			ballisticResistance = baR;
			environmentalResistance = eR;
			flameResistance = fR;
			energyResistance = enR;
			shockResistance = sR;
			acidResistance = aR;
			magicalResistance = mR;
			armorPenalty = aP;
			break;
		}
		
	}
}

void Character::setArmorPenalty(int l)
{
	armorPenalty = l;
}

int Character::evade()
{
	std::cout << name << " uses evasion" << '\n';
	std::cout << "Enter bonus/penalty from cover or shield" << '\n';

	int level = getIntInput();
	level += getSkillLevel(skill::S_evasion);

	int response = 0;

	while (response != 2)
	{
		std::cout << "Choose Assist Skill?" << '\n';
		std::cout << "1. Yes" << '\n';
		std::cout << "2. No (Done)" << '\n';

		response = getIntInput();

		while (response < 1 || response > 2)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			std::cout << "Which Skill to Use?" << '\n';
			std::cout << "0. Nevermind (Done)" << '\n';
			std::cout << "1. Grapple" << '\n';
			std::cout << "2. Melee" << '\n';
			std::cout << "3. Ranged (Strength)" << '\n';
			std::cout << "4. Ranged (Dex)" << '\n';
			std::cout << "5. Initiative" << '\n';
			std::cout << "6. Athletics" << '\n';
			std::cout << "7. Acrobatics" << '\n';
			std::cout << "8. Constitution" << '\n';
			std::cout << "9. Evasion" << '\n';
			std::cout << "10. Perception/Investigation" << '\n';
			std::cout << "11. Tactics/Command" << '\n';
			std::cout << "12. Artillery" << '\n';
			std::cout << "13. Strength" << '\n';
			std::cout << "14. Ride/Pilot" << '\n';
			std::cout << "15. Stealth/Slight of Hand" << '\n';
			std::cout << "16. Persuasion/Deception" << '\n';
			std::cout << "17. Charm/Seduction" << '\n';
			std::cout << "18. Intimidation" << '\n';
			std::cout << "19. Fortitude/Tolerence" << '\n';
			std::cout << "20. Navigation" << '\n';
			std::cout << "21. Survival" << '\n';
			std::cout << "22. Technology" << '\n';
			std::cout << "23. Engineering" << '\n';
			std::cout << "24. Medicine" << '\n';
			std::cout << "25. Calculation/Mathematics" << '\n';
			std::cout << "26. Memory" << '\n';
			std::cout << "27. Language/Linguistics" << '\n';
			std::cout << "28. Sketching/Painting" << '\n';
			std::cout << "29. Sculpting/Carving" << '\n';
			std::cout << "30. Sewing/Weaving/Knitting" << '\n';
			std::cout << "31. Oratory/Verbal Performance" << '\n';
			std::cout << "32. Writing/Composition" << '\n';
			std::cout << "33. Dance" << '\n';
			std::cout << "34. Music Composition" << '\n';
			std::cout << "35. Musical Performance (Instruments)" << '\n';
			std::cout << "36. Musical Performance (Vocal)" << '\n';
			std::cout << "37. Other" << '\n';

			response = getIntInput();

			while (response < 0 || response > 37)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			if (response != 0 && response != 37)
			{
				level += getSkillLevel(static_cast<skill>(response - 1)) - 3;
				response = 0;
			}
			else if (response == 36)
			{
				int i = 2;
				std::cout << "1. None" << '\n';
				if (ss1.skillName != "")
				{
					std::cout << i << ". " << ss1.skillName << '\n';
					i++;
				}
				if (ss2.skillName != "")
				{
					std::cout << i << ". " << ss2.skillName << '\n';
					i++;
				}
				if (ss3.skillName != "")
				{
					std::cout << i << ". " << ss3.skillName << '\n';
					i++;
				}
				if (ss4.skillName != "")
				{
					std::cout << i << ". " << ss4.skillName << '\n';
					i++;
				}
				if (ss5.skillName != "")
				{
					std::cout << i << ". " << ss5.skillName << '\n';
					i++;
				}

				response = getIntInput();

				while (response < 1 || response > i)
				{
					std::cout << "Invalid Input" << '\n';
					response = getIntInput();
				}

				if (response != 1)
				{
					level += getSpecialSkillLevel(i - 2);
					level -= 3;
				}
			}
			else
			{
				response = 2;
			}


		}
	}

	if (level < 0)
	{
		level = 0;
	}

	int result = diceRoll(level);

	std::cout << name << " rolled evasion: " << result << " (Pre-Roll Total: " << level << '\n';

	return result;
}

void Character::characterCreate(std::vector<Weapon>& weapons)
{
	int points = 0;

	ss1.skillName = "Empty";
	ss2.skillName = "Empty";
	ss3.skillName = "Empty";
	ss4.skillName = "Empty";
	ss5.skillName = "Empty";

	std::cout << "Enter character name" << '\n';

	std::getline(std::cin, name);

	int response = -1;

	std::cout << "Enter vocation" << '\n';
	std::getline(std::cin, vocation1);

	std::cout << "Enter additional vocation? (4pts)" << '\n';
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
		points += 4;
		std::cout << "Enter vocation 2" << '\n';
		std::getline(std::cin, vocation2);

		std::cout << "Enter additional vocation? (4pts) current points: (" << points << ")" << '\n';
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
			points += 4;
			std::cout << "Enter vocation 3" << '\n';
			std::getline(std::cin, vocation3);
		}
	}
	
	while (response != 0)
	{
		std::cout << "Enter skill to set (current points: " << points << ")" << '\n';
		std::cout << "0. Exit (Done)" << '\n';
		std::cout << "1. Grapple (" << grapple << ")" << '\n';
		std::cout << "2. Melee (" << melee << ")" << '\n';
		std::cout << "3. Ranged (Strength) (" << strenghtRanged << ")" << '\n';
		std::cout << "4. Ranged (Dex) (" << dexRanged << ")" << '\n';
		std::cout << "5. Initiative (" << initiative << ")" << '\n';
		std::cout << "6. Athletics (" << athletics << ")" << '\n';
		std::cout << "7. Acrobatics (" << acrobatics << ")" << '\n';
		std::cout << "8. Constitution (" << constitution << ")" << '\n';
		std::cout << "9. Evasion (" << evasion << ")" << '\n';
		std::cout << "10. Perception/Investigation (" << perception_Investigation << ")" << '\n';
		std::cout << "11. Tactics/Command (" << tactics_Command << ")" << '\n';
		std::cout << "12. Artillery (" << artillery << ")" << '\n';
		std::cout << "13. Strength (" << strength << ")" << '\n';
		std::cout << "14. Ride/Pilot (" << ride_Pilot << ")" << '\n';
		std::cout << "15. Stealth/Slight of Hand (" << stealth_SlightofHand << ")" << '\n';
		std::cout << "16. Persuasion/Deception (" << persuasion_Deception << ")" << '\n';
		std::cout << "17. Charm/Seduction (" << charm_Seduction << ")" << '\n';
		std::cout << "18. Intimidation (" << intimidation << ")" << '\n';
		std::cout << "19. Fortitude/Tolerence (" << fortitude_Tolerence << ")" << '\n';
		std::cout << "20. Navigation (" << navigation << ")" << '\n';
		std::cout << "21. Survival (" << survival << ")" << '\n';
		std::cout << "22. Technology (" << technology << ")" << '\n';
		std::cout << "23. Engineering (" << engineering << ")" << '\n';
		std::cout << "24. Medicine (" << medicine << ")" << '\n';
		std::cout << "25. Calculation/Mathematics (" << calculation_Mathematics << ")" << '\n';
		std::cout << "26. Memory (" << memory << ")" << '\n';
		std::cout << "27. Language/Linguistics (" << languages_linguistics << ")" << '\n';
		std::cout << "28. Sketching/Painting (" << sketching_Painting << ")" << '\n';
		std::cout << "29. Sculpting/Carving (" << sculpting_Carving << ")" << '\n';
		std::cout << "30. Sewing/Weaving/Knitting (" << sewing_Weaving_Knitting << ")" << '\n';
		std::cout << "31. Oratory/Verbal Performance (" << oratory_Performance << ")" << '\n';
		std::cout << "32. Writing/Composition (" << writing_Composition << ")" << '\n';
		std::cout << "33. Dance (" << dance << ")" << '\n';
		std::cout << "34. Music Composition (" << music_Composition << ")" << '\n';
		std::cout << "35. Musical Performance (Instruments) (" << music_InstrumentalPerformance << ")" << '\n';
		std::cout << "36. Musical Performance (Vocal) (" << music_VocalPerformance << ")" << '\n';
		std::cout << "37. Other" << '\n';

		response = getIntInput();

		while (response < 0 || response > 37)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}
		int res2;
		if (response != 0 && response != 37)
		{
			std::cout << "Enter level" << '\n';
			res2 = getIntInput();
			while (res2 < 0)
			{
				std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
				res2 = getIntInput();
			}
			points += res2 - getSkillLevel(static_cast<skill>(response - 1));
			setSkill(static_cast<skill>(response - 1), res2);
		}
		else if (response == 37)
		{
			std::cout << "Select Skill to Overwright" << '\n';

			std::cout << "1. " << ss1.skillName << " (" << ss1.skillLevel << ")" << '\n';
			std::cout << "2. " << ss2.skillName << " (" << ss2.skillLevel << ")" << '\n';
			std::cout << "3. " << ss3.skillName << " (" << ss3.skillLevel << ")" << '\n';
			std::cout << "4. " << ss4.skillName << " (" << ss4.skillLevel << ")" << '\n';
			std::cout << "5. " << ss5.skillName << " (" << ss5.skillLevel << ")" << '\n';

			response = getIntInput();
			while (response < 1 || response > 5)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			switch (response)
			{
				case 1:
				{
					std::cout << "Enter skill name:" << '\n';
					std::getline(std::cin, ss1.skillName);
					std::cout << "Enter skill level:" << '\n';
					response = getIntInput();
					while (response < 0)
					{
						std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
						response = getIntInput();
					}
					points += response - ss1.skillLevel;
					ss1.skillLevel = response;
					break;
				}
				case 2:
				{
					std::cout << "Enter skill name:" << '\n';
					std::getline(std::cin, ss2.skillName);
					std::cout << "Enter skill level:" << '\n';
					response = getIntInput();
					while (response < 0)
					{
						std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
						response = getIntInput();
					}
					points += response - ss2.skillLevel;
					ss2.skillLevel = response;
					break;
				}
				case 3:
				{
					std::cout << "Enter skill name:" << '\n';
					std::getline(std::cin, ss3.skillName);
					std::cout << "Enter skill level:" << '\n';
					response = getIntInput();
					while (response < 0)
					{
						std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
						response = getIntInput();
					}
					points += response - ss3.skillLevel;
					ss3.skillLevel = response;
					break;
				}
				case 4:
				{
					std::cout << "Enter skill name:" << '\n';
					std::getline(std::cin, ss4.skillName);
					std::cout << "Enter skill level:" << '\n';
					response = getIntInput();
					while (response < 0)
					{
						std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
						response = getIntInput();
					}
					points += response - ss4.skillLevel;
					ss4.skillLevel = response;
					break;
				}
				case 5:
				{
					std::cout << "Enter skill name:" << '\n';
					std::getline(std::cin, ss5.skillName);
					std::cout << "Enter skill level:" << '\n';
					response = getIntInput();
					while (response < 0)
					{
						std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
						response = getIntInput();
					}
					points += response - ss5.skillLevel;
					ss5.skillLevel = response;
					break;
				}
			}

		}

		

	}

	if (ss1.skillName == "Empty")
	{
		ss1.skillName = "";
	}
	if (ss2.skillName == "Empty")
	{
		ss2.skillName = "";
	}
	if (ss3.skillName == "Empty")
	{
		ss3.skillName = "";
	}
	if (ss4.skillName == "Empty")
	{
		ss4.skillName = "";
	}
	if (ss5.skillName == "Empty")
	{
		ss5.skillName = "";
	}

	std::vector<specialSkill> s;

	s.push_back(ss1);
	s.push_back(ss2);
	s.push_back(ss3);
	s.push_back(ss4);
	s.push_back(ss5);

	int i, j, max;
	int n = s.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the maximum element in
		// unsorted array
		max = i;
		for (j = i + 1; j < n; j++)
			if (s[j].skillName > s[max].skillName)
				max = j;

		// Swap the found max element
		// with the first element

		specialSkill temp = s[max];
		s[max] = s[i];
		s[i] = temp;
	}

	ss1 = s[0];
	ss2 = s[1];
	ss3 = s[2];
	ss4 = s[3];
	ss5 = s[4];

	response = -1;

	while (response != 0)
	{
		std::cout << "Select resistances for:" << '\n';
		std::cout << "1. General (applied to all)" << '\n';
		std::cout << "2. Head" << '\n';
		std::cout << "3. Neck" << '\n';
		std::cout << "4. Right Arm" << '\n';
		std::cout << "5. Left Arm" << '\n';
		std::cout << "6. Chest" << '\n';
		std::cout << "7. Gut" << '\n';
		std::cout << "8. Right Leg" << '\n';
		std::cout << "9. Left Leg" << '\n';
		std::cout << "0. Done" << '\n';

		response = getIntInput();
		while (response < 0 || response > 9)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}

		if (response == 1)
		{
			while (response != 13)
			{

				std::cout << "Choose Resistances" << '\n';
				std::cout << "1. Blunt " << bluntResistance << '\n';
				std::cout << "2. Cutting " << cutResistance << '\n';
				std::cout << "3. Piecing " << pierceResistance << '\n';
				std::cout << "4. Chopping " << chopResistance << '\n';
				std::cout << "5. Ballistic " << ballisticResistance << '\n';
				std::cout << "6. Environmental " << environmentalResistance << '\n';
				std::cout << "7. Fire " << flameResistance << '\n';
				std::cout << "8. Energy " << energyResistance << '\n';
				std::cout << "9. Shock " << shockResistance << '\n';
				std::cout << "10. Acid " << acidResistance << '\n';
				std::cout << "11. Magic " << magicalResistance << '\n';
				std::cout << "12. Reset" << '\n';
				std::cout << "13. Done (Save)" << '\n';

				response = getIntInput();

				while (!std::cin.good() || response < 1 || response > 13)
				{
					std::cout << "Invalid input. Please try again" << '\n';
					response = getIntInput();
				}

				switch (response)
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
					chopResistance++;
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
					bluntResistance = 0, cutResistance = 0, pierceResistance = 0, chopResistance = 0, ballisticResistance = 0, environmentalResistance = 0, flameResistance = 0,
						energyResistance = 0, shockResistance = 0, acidResistance = 0, magicalResistance = 0;
					break;
				}
				case 13:
				{
					setBodyPart(bodyPrt::head, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance, 
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::neck, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::rightArm, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::leftArm, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::chest, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::gut, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::rightLeg, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					setBodyPart(bodyPrt::leftLeg, woundLevel, bluntResistance, cutResistance, pierceResistance, chopResistance, ballisticResistance, environmentalResistance,
						flameResistance, energyResistance, shockResistance, acidResistance, magicalResistance, 0);
					break;
				}
				}
			}
		}
		else if(response != 0)
		{
			switch (static_cast<bodyPrt>(response - 2))
			{
				case bodyPrt::head:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Head)" << '\n';
						std::cout << "1. Blunt " << head.bluntResistance << '\n';
						std::cout << "2. Cutting " << head.cutResistance << '\n';
						std::cout << "3. Piecing " << head.pierceResistance << '\n';
						std::cout << "4. Chopping " << head.chopResistance << '\n';
						std::cout << "5. Ballistic " << head.ballisticResistance << '\n';
						std::cout << "6. Environmental " << head.environmentalResistance << '\n';
						std::cout << "7. Fire " << head.flameResistance << '\n';
						std::cout << "8. Energy " << head.energyResistance << '\n';
						std::cout << "9. Shock " << head.shockResistance << '\n';
						std::cout << "10. Acid " << head.acidResistance << '\n';
						std::cout << "11. Magic " << head.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							head.bluntResistance++;
							break;
						}
						case 2:
						{
							head.cutResistance++;
							break;
						}
						case 3:
						{
							head.pierceResistance++;
							break;
						}
						case 4:
						{
							head.chopResistance++;
							break;
						}
						case 5:
						{
							head.ballisticResistance++;
							break;
						}
						case 6:
						{
							head.environmentalResistance++;
							break;
						}
						case 7:
						{
							head.flameResistance++;
							break;
						}
						case 8:
						{
							head.energyResistance++;
							break;
						}
						case 9:
						{
							head.shockResistance++;
							break;
						}
						case 10:
						{
							head.acidResistance++;
							break;
						}
						case 11:
						{
							head.magicalResistance++;
							break;
						}
						case 12:
						{
							head.bluntResistance = 0, head.cutResistance = 0, head.pierceResistance = 0, head.chopResistance = 0, head.ballisticResistance = 0, head.environmentalResistance = 0, head.flameResistance = 0,
								head.energyResistance = 0, head.shockResistance = 0, head.acidResistance = 0, head.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::neck:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Neck)" << '\n';
						std::cout << "1. Blunt " << neck.bluntResistance << '\n';
						std::cout << "2. Cutting " << neck.cutResistance << '\n';
						std::cout << "3. Piecing " << neck.pierceResistance << '\n';
						std::cout << "4. Chopping " << neck.chopResistance << '\n';
						std::cout << "5. Ballistic " << neck.ballisticResistance << '\n';
						std::cout << "6. Environmental " << neck.environmentalResistance << '\n';
						std::cout << "7. Fire " << neck.flameResistance << '\n';
						std::cout << "8. Energy " << neck.energyResistance << '\n';
						std::cout << "9. Shock " << neck.shockResistance << '\n';
						std::cout << "10. Acid " << neck.acidResistance << '\n';
						std::cout << "11. Magic " << neck.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							neck.bluntResistance++;
							break;
						}
						case 2:
						{
							neck.cutResistance++;
							break;
						}
						case 3:
						{
							neck.pierceResistance++;
							break;
						}
						case 4:
						{
							neck.chopResistance++;
							break;
						}
						case 5:
						{
							neck.ballisticResistance++;
							break;
						}
						case 6:
						{
							neck.environmentalResistance++;
							break;
						}
						case 7:
						{
							neck.flameResistance++;
							break;
						}
						case 8:
						{
							neck.energyResistance++;
							break;
						}
						case 9:
						{
							neck.shockResistance++;
							break;
						}
						case 10:
						{
							neck.acidResistance++;
							break;
						}
						case 11:
						{
							neck.magicalResistance++;
							break;
						}
						case 12:
						{
							neck.bluntResistance = 0, neck.cutResistance = 0, neck.pierceResistance = 0, neck.chopResistance = 0, neck.ballisticResistance = 0, neck.environmentalResistance = 0, neck.flameResistance = 0,
								neck.energyResistance = 0, neck.shockResistance = 0, neck.acidResistance = 0, neck.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::rightArm:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Right Arm)" << '\n';
						std::cout << "1. Blunt " << rightArm.bluntResistance << '\n';
						std::cout << "2. Cutting " << rightArm.cutResistance << '\n';
						std::cout << "3. Piecing " << rightArm.pierceResistance << '\n';
						std::cout << "4. Chopping " << rightArm.chopResistance << '\n';
						std::cout << "5. Ballistic " << rightArm.ballisticResistance << '\n';
						std::cout << "6. Environmental " << rightArm.environmentalResistance << '\n';
						std::cout << "7. Fire " << rightArm.flameResistance << '\n';
						std::cout << "8. Energy " << rightArm.energyResistance << '\n';
						std::cout << "9. Shock " << rightArm.shockResistance << '\n';
						std::cout << "10. Acid " << rightArm.acidResistance << '\n';
						std::cout << "11. Magic " << rightArm.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							rightArm.bluntResistance++;
							break;
						}
						case 2:
						{
							rightArm.cutResistance++;
							break;
						}
						case 3:
						{
							rightArm.pierceResistance++;
							break;
						}
						case 4:
						{
							rightArm.chopResistance++;
							break;
						}
						case 5:
						{
							rightArm.ballisticResistance++;
							break;
						}
						case 6:
						{
							rightArm.environmentalResistance++;
							break;
						}
						case 7:
						{
							rightArm.flameResistance++;
							break;
						}
						case 8:
						{
							rightArm.energyResistance++;
							break;
						}
						case 9:
						{
							rightArm.shockResistance++;
							break;
						}
						case 10:
						{
							rightArm.acidResistance++;
							break;
						}
						case 11:
						{
							rightArm.magicalResistance++;
							break;
						}
						case 12:
						{
							rightArm.bluntResistance = 0, rightArm.cutResistance = 0, rightArm.pierceResistance = 0, rightArm.chopResistance = 0, rightArm.ballisticResistance = 0, rightArm.environmentalResistance = 0, rightArm.flameResistance = 0,
								rightArm.energyResistance = 0, rightArm.shockResistance = 0, rightArm.acidResistance = 0, rightArm.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::leftArm:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Left Arm)" << '\n';
						std::cout << "1. Blunt " << leftArm.bluntResistance << '\n';
						std::cout << "2. Cutting " << leftArm.cutResistance << '\n';
						std::cout << "3. Piecing " << leftArm.pierceResistance << '\n';
						std::cout << "4. Chopping " << leftArm.chopResistance << '\n';
						std::cout << "5. Ballistic " << leftArm.ballisticResistance << '\n';
						std::cout << "6. Environmental " << leftArm.environmentalResistance << '\n';
						std::cout << "7. Fire " << leftArm.flameResistance << '\n';
						std::cout << "8. Energy " << leftArm.energyResistance << '\n';
						std::cout << "9. Shock " << leftArm.shockResistance << '\n';
						std::cout << "10. Acid " << leftArm.acidResistance << '\n';
						std::cout << "11. Magic " << leftArm.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							leftArm.bluntResistance++;
							break;
						}
						case 2:
						{
							leftArm.cutResistance++;
							break;
						}
						case 3:
						{
							leftArm.pierceResistance++;
							break;
						}
						case 4:
						{
							leftArm.chopResistance++;
							break;
						}
						case 5:
						{
							leftArm.ballisticResistance++;
							break;
						}
						case 6:
						{
							leftArm.environmentalResistance++;
							break;
						}
						case 7:
						{
							leftArm.flameResistance++;
							break;
						}
						case 8:
						{
							leftArm.energyResistance++;
							break;
						}
						case 9:
						{
							leftArm.shockResistance++;
							break;
						}
						case 10:
						{
							leftArm.acidResistance++;
							break;
						}
						case 11:
						{
							leftArm.magicalResistance++;
							break;
						}
						case 12:
						{
							leftArm.bluntResistance = 0, leftArm.cutResistance = 0, leftArm.pierceResistance = 0, leftArm.chopResistance = 0, leftArm.ballisticResistance = 0, leftArm.environmentalResistance = 0, leftArm.flameResistance = 0,
								leftArm.energyResistance = 0, leftArm.shockResistance = 0, leftArm.acidResistance = 0, leftArm.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::chest:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Chest)" << '\n';
						std::cout << "1. Blunt " << chest.bluntResistance << '\n';
						std::cout << "2. Cutting " << chest.cutResistance << '\n';
						std::cout << "3. Piecing " << chest.pierceResistance << '\n';
						std::cout << "4. Chopping " << chest.chopResistance << '\n';
						std::cout << "5. Ballistic " << chest.ballisticResistance << '\n';
						std::cout << "6. Environmental " << chest.environmentalResistance << '\n';
						std::cout << "7. Fire " << chest.flameResistance << '\n';
						std::cout << "8. Energy " << chest.energyResistance << '\n';
						std::cout << "9. Shock " << chest.shockResistance << '\n';
						std::cout << "10. Acid " << chest.acidResistance << '\n';
						std::cout << "11. Magic " << chest.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							chest.bluntResistance++;
							break;
						}
						case 2:
						{
							chest.cutResistance++;
							break;
						}
						case 3:
						{
							chest.pierceResistance++;
							break;
						}
						case 4:
						{
							chest.chopResistance++;
							break;
						}
						case 5:
						{
							chest.ballisticResistance++;
							break;
						}
						case 6:
						{
							chest.environmentalResistance++;
							break;
						}
						case 7:
						{
							chest.flameResistance++;
							break;
						}
						case 8:
						{
							chest.energyResistance++;
							break;
						}
						case 9:
						{
							chest.shockResistance++;
							break;
						}
						case 10:
						{
							chest.acidResistance++;
							break;
						}
						case 11:
						{
							chest.magicalResistance++;
							break;
						}
						case 12:
						{
							chest.bluntResistance = 0, chest.cutResistance = 0, chest.pierceResistance = 0, chest.chopResistance = 0, chest.ballisticResistance = 0, chest.environmentalResistance = 0, chest.flameResistance = 0,
								chest.energyResistance = 0, chest.shockResistance = 0, chest.acidResistance = 0, chest.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::gut:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Gut)" << '\n';
						std::cout << "1. Blunt " << gut.bluntResistance << '\n';
						std::cout << "2. Cutting " << gut.cutResistance << '\n';
						std::cout << "3. Piecing " << gut.pierceResistance << '\n';
						std::cout << "4. Chopping " << gut.chopResistance << '\n';
						std::cout << "5. Ballistic " << gut.ballisticResistance << '\n';
						std::cout << "6. Environmental " << gut.environmentalResistance << '\n';
						std::cout << "7. Fire " << gut.flameResistance << '\n';
						std::cout << "8. Energy " << gut.energyResistance << '\n';
						std::cout << "9. Shock " << gut.shockResistance << '\n';
						std::cout << "10. Acid " << gut.acidResistance << '\n';
						std::cout << "11. Magic " << gut.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							gut.bluntResistance++;
							break;
						}
						case 2:
						{
							gut.cutResistance++;
							break;
						}
						case 3:
						{
							gut.pierceResistance++;
							break;
						}
						case 4:
						{
							gut.chopResistance++;
							break;
						}
						case 5:
						{
							gut.ballisticResistance++;
							break;
						}
						case 6:
						{
							gut.environmentalResistance++;
							break;
						}
						case 7:
						{
							gut.flameResistance++;
							break;
						}
						case 8:
						{
							gut.energyResistance++;
							break;
						}
						case 9:
						{
							gut.shockResistance++;
							break;
						}
						case 10:
						{
							gut.acidResistance++;
							break;
						}
						case 11:
						{
							gut.magicalResistance++;
							break;
						}
						case 12:
						{
							gut.bluntResistance = 0, gut.cutResistance = 0, gut.pierceResistance = 0, gut.chopResistance = 0, gut.ballisticResistance = 0, gut.environmentalResistance = 0, gut.flameResistance = 0,
								gut.energyResistance = 0, gut.shockResistance = 0, gut.acidResistance = 0, gut.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::rightLeg:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Right Leg)" << '\n';
						std::cout << "1. Blunt " << rightLeg.bluntResistance << '\n';
						std::cout << "2. Cutting " << rightLeg.cutResistance << '\n';
						std::cout << "3. Piecing " << rightLeg.pierceResistance << '\n';
						std::cout << "4. Chopping " << rightLeg.chopResistance << '\n';
						std::cout << "5. Ballistic " << rightLeg.ballisticResistance << '\n';
						std::cout << "6. Environmental " << rightLeg.environmentalResistance << '\n';
						std::cout << "7. Fire " << rightLeg.flameResistance << '\n';
						std::cout << "8. Energy " << rightLeg.energyResistance << '\n';
						std::cout << "9. Shock " << rightLeg.shockResistance << '\n';
						std::cout << "10. Acid " << rightLeg.acidResistance << '\n';
						std::cout << "11. Magic " << rightLeg.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							rightLeg.bluntResistance++;
							break;
						}
						case 2:
						{
							rightLeg.cutResistance++;
							break;
						}
						case 3:
						{
							rightLeg.pierceResistance++;
							break;
						}
						case 4:
						{
							rightLeg.chopResistance++;
							break;
						}
						case 5:
						{
							rightLeg.ballisticResistance++;
							break;
						}
						case 6:
						{
							rightLeg.environmentalResistance++;
							break;
						}
						case 7:
						{
							rightLeg.flameResistance++;
							break;
						}
						case 8:
						{
							rightLeg.energyResistance++;
							break;
						}
						case 9:
						{
							rightLeg.shockResistance++;
							break;
						}
						case 10:
						{
							rightLeg.acidResistance++;
							break;
						}
						case 11:
						{
							rightLeg.magicalResistance++;
							break;
						}
						case 12:
						{
							rightLeg.bluntResistance = 0, rightLeg.cutResistance = 0, rightLeg.pierceResistance = 0, rightLeg.chopResistance = 0, rightLeg.ballisticResistance = 0, rightLeg.environmentalResistance = 0, rightLeg.flameResistance = 0,
								rightLeg.energyResistance = 0, rightLeg.shockResistance = 0, rightLeg.acidResistance = 0, rightLeg.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
				case bodyPrt::leftLeg:
				{
					while (response != 13)
					{

						std::cout << "Choose Resistances (Left Leg)" << '\n';
						std::cout << "1. Blunt " << leftLeg.bluntResistance << '\n';
						std::cout << "2. Cutting " << leftLeg.cutResistance << '\n';
						std::cout << "3. Piecing " << leftLeg.pierceResistance << '\n';
						std::cout << "4. Chopping " << leftLeg.chopResistance << '\n';
						std::cout << "5. Ballistic " << leftLeg.ballisticResistance << '\n';
						std::cout << "6. Environmental " << leftLeg.environmentalResistance << '\n';
						std::cout << "7. Fire " << leftLeg.flameResistance << '\n';
						std::cout << "8. Energy " << leftLeg.energyResistance << '\n';
						std::cout << "9. Shock " << leftLeg.shockResistance << '\n';
						std::cout << "10. Acid " << leftLeg.acidResistance << '\n';
						std::cout << "11. Magic " << leftLeg.magicalResistance << '\n';
						std::cout << "12. Reset" << '\n';
						std::cout << "13. Done (Save)" << '\n';

						response = getIntInput();

						while (!std::cin.good() || response < 1 || response > 13)
						{
							std::cout << "Invalid input. Please try again" << '\n';
							std::cin.ignore(INT_MAX, '\n');
							response = getIntInput();
						}

						switch (response)
						{
						case 1:
						{
							leftLeg.bluntResistance++;
							break;
						}
						case 2:
						{
							leftLeg.cutResistance++;
							break;
						}
						case 3:
						{
							leftLeg.pierceResistance++;
							break;
						}
						case 4:
						{
							leftLeg.chopResistance++;
							break;
						}
						case 5:
						{
							leftLeg.ballisticResistance++;
							break;
						}
						case 6:
						{
							leftLeg.environmentalResistance++;
							break;
						}
						case 7:
						{
							leftLeg.flameResistance++;
							break;
						}
						case 8:
						{
							leftLeg.energyResistance++;
							break;
						}
						case 9:
						{
							leftLeg.shockResistance++;
							break;
						}
						case 10:
						{
							leftLeg.acidResistance++;
							break;
						}
						case 11:
						{
							leftLeg.magicalResistance++;
							break;
						}
						case 12:
						{
							leftLeg.bluntResistance = 0, leftLeg.cutResistance = 0, leftLeg.pierceResistance = 0, leftLeg.chopResistance = 0, leftLeg.ballisticResistance = 0, leftLeg.environmentalResistance = 0, leftLeg.flameResistance = 0,
								leftLeg.energyResistance = 0, leftLeg.shockResistance = 0, leftLeg.acidResistance = 0, leftLeg.magicalResistance = 0;
							break;
						}
						case 13:
						{
							break;
						}
						}
					}
				}
			}
		}

	}

	Weapon temp;

	for (int i = 0; i < 5; i++)
	{
		
		std::cout << "Choose weapon " << i + 1 << '\n';

		std::cout << "1. Knife" << '\n';
		std::cout << "2. Sword" << '\n';
		std::cout << "3. Spear" << '\n';
		std::cout << "4. Bow" << '\n';
		std::cout << "5. Crossbow" << '\n';
		std::cout << "6. Pistol" << '\n';
		std::cout << "7. Rifle" << '\n';
		std::cout << "8. Other" << '\n';

		response = getIntInput();
		while (!std::cin.good() || response < 1 || response > 8)
		{
			std::cout << "Invalid input. Please try again" << '\n';
			std::cin.ignore(INT_MAX, '\n');
			response = getIntInput();
		}

		if (response != 8)
		{
			temp.setWeapon(static_cast<weaponID>(response));
		}
		else
		{
			for (int i = 0; i < weapons.size(); i++)
			{
				std::cout << i + 1 << ". " << weapons[i].getName() << '\n';
			}

			response = getIntInput();
			while (!std::cin.good() || response < 1 || response > weapons.size())
			{
				std::cout << "Invalid input. Please try again" << '\n';
				std::cin.ignore(INT_MAX, '\n');
				response = getIntInput();
			}

			temp = weapons[response - 1];
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
		case 3:
		{
			w4 = temp;
			break;
		}
		case 4:
		{
			w5 = temp;
			break;
		}
		}
	}

	std::vector<Weapon> w;
	w.push_back(w1);
	w.push_back(w2);
	w.push_back(w3);
	w.push_back(w4);
	w.push_back(w5);

	i = 0, j = 0;
	int maximum;
	int num = w.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < num - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		maximum = i;
		for (j = i + 1; j < num; j++)
			if (w[j].getName() > w[maximum].getName())
				maximum = j;

		// Swap the found minimum element
		// with the first element

		Weapon temp = w[maximum];
		w[maximum] = w[i];
		w[i] = temp;
	}

	w1 = w[0];
	w2 = w[1];
	w3 = w[2];
	w4 = w[3];
	w5 = w[4];


	writeToCharacterFile();

}

void Character::changeSkills()
{
	int response = -1;
	int points = 0;

	if (ss1.skillName == "")
	{
		ss1.skillName = "Empty";
	}
	if (ss2.skillName == "")
	{
		ss2.skillName = "Empty";
	}
	if (ss3.skillName == "")
	{
		ss3.skillName = "Empty";
	}
	if (ss4.skillName == "")
	{
		ss4.skillName = "Empty";
	}
	if (ss5.skillName == "")
	{
		ss5.skillName = "Empty";
	}
	
	while (response != 0)
	{
		std::cout << "Enter skill to set (current points used): " << points << ")" << '\n';
		std::cout << "0. Exit (Done)" << '\n';
		std::cout << "1. Grapple (" << grapple << ")" << '\n';
		std::cout << "2. Melee (" << melee << ")" << '\n';
		std::cout << "3. Ranged (Strength) (" << strenghtRanged << ")" << '\n';
		std::cout << "4. Ranged (Dex) (" << dexRanged << ")" << '\n';
		std::cout << "5. Initiative (" << initiative << ")" << '\n';
		std::cout << "6. Athletics (" << athletics << ")" << '\n';
		std::cout << "7. Acrobatics (" << acrobatics << ")" << '\n';
		std::cout << "8. Constitution (" << constitution << ")" << '\n';
		std::cout << "9. Evasion (" << evasion << ")" << '\n';
		std::cout << "10. Perception/Investigation (" << perception_Investigation << ")" << '\n';
		std::cout << "11. Tactics/Command (" << tactics_Command << ")" << '\n';
		std::cout << "12. Artillery (" << artillery << ")" << '\n';
		std::cout << "13. Strength (" << strength << ")" << '\n';
		std::cout << "14. Ride/Pilot (" << ride_Pilot << ")" << '\n';
		std::cout << "15. Stealth/Slight of Hand (" << stealth_SlightofHand << ")" << '\n';
		std::cout << "16. Persuasion/Deception (" << persuasion_Deception << ")" << '\n';
		std::cout << "17. Charm/Seduction (" << charm_Seduction << ")" << '\n';
		std::cout << "18. Intimidation (" << intimidation << ")" << '\n';
		std::cout << "19. Fortitude/Tolerence (" << fortitude_Tolerence << ")" << '\n';
		std::cout << "20. Navigation (" << navigation << ")" << '\n';
		std::cout << "21. Survival (" << survival << ")" << '\n';
		std::cout << "22. Technology (" << technology << ")" << '\n';
		std::cout << "23. Engineering (" << engineering << ")" << '\n';
		std::cout << "24. Medicine (" << medicine << ")" << '\n';
		std::cout << "25. Calculation/Mathematics (" << calculation_Mathematics << ")" << '\n';
		std::cout << "26. Memory (" << memory << ")" << '\n';
		std::cout << "27. Language/Linguistics (" << languages_linguistics << ")" << '\n';
		std::cout << "28. Sketching/Painting (" << sketching_Painting << ")" << '\n';
		std::cout << "29. Sculpting/Carving (" << sculpting_Carving << ")" << '\n';
		std::cout << "30. Sewing/Weaving/Knitting (" << sewing_Weaving_Knitting << ")" << '\n';
		std::cout << "31. Oratory/Verbal Performance (" << oratory_Performance << ")" << '\n';
		std::cout << "32. Writing/Composition (" << writing_Composition << ")" << '\n';
		std::cout << "33. Dance (" << dance << ")" << '\n';
		std::cout << "34. Music Composition (" << music_Composition << ")" << '\n';
		std::cout << "35. Musical Performance (Instruments) (" << music_InstrumentalPerformance << ")" << '\n';
		std::cout << "36. Musical Performance (Vocal) (" << music_VocalPerformance << ")" << '\n';
		std::cout << "37. Other" << '\n';

		response = getIntInput();

		while (response < 0 || response > 37)
		{
			std::cout << "Invalid Input" << '\n';
			response = getIntInput();
		}
		int res2;
		if (response != 0 && response != 37)
		{
			std::cout << "Enter level" << '\n';
			res2 = getIntInput();
			while (res2 < 0)
			{
				std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
				res2 = getIntInput();
			}
			points += res2 - getSkillLevel(static_cast<skill>(response - 1));
			setSkill(static_cast<skill>(response - 1), res2);
		}
		else if (response == 37)
		{
			std::cout << "Select Skill to Overwright" << '\n';

			std::cout << "1. " << ss1.skillName << " (" << ss1.skillLevel << ")" << '\n';
			std::cout << "2. " << ss2.skillName << " (" << ss2.skillLevel << ")" << '\n';
			std::cout << "3. " << ss3.skillName << " (" << ss3.skillLevel << ")" << '\n';
			std::cout << "4. " << ss4.skillName << " (" << ss4.skillLevel << ")" << '\n';
			std::cout << "5. " << ss5.skillName << " (" << ss5.skillLevel << ")" << '\n';

			response = getIntInput();
			while (response < 1 || response > 5)
			{
				std::cout << "Invalid Input" << '\n';
				response = getIntInput();
			}

			switch (response)
			{
			case 1:
			{
				std::cout << "Enter skill name:" << '\n';
				std::getline(std::cin, ss1.skillName);
				std::cout << "Enter skill level:" << '\n';
				response = getIntInput();
				while (response < 0)
				{
					std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
					response = getIntInput();
				}
				points += response - ss1.skillLevel;
				ss1.skillLevel = response;
				break;
			}
			case 2:
			{
				std::cout << "Enter skill name:" << '\n';
				std::getline(std::cin, ss2.skillName);
				std::cout << "Enter skill level:" << '\n';
				response = getIntInput();
				while (response < 0)
				{
					std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
					response = getIntInput();
				}
				points += response - ss2.skillLevel;
				ss2.skillLevel = response;
				break;
			}
			case 3:
			{
				std::cout << "Enter skill name:" << '\n';
				std::getline(std::cin, ss3.skillName);
				std::cout << "Enter skill level:" << '\n';
				response = getIntInput();
				while (response < 0)
				{
					std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
					response = getIntInput();
				}
				points += response - ss3.skillLevel;
				ss3.skillLevel = response;
				break;
			}
			case 4:
			{
				std::cout << "Enter skill name:" << '\n';
				std::getline(std::cin, ss4.skillName);
				std::cout << "Enter skill level:" << '\n';
				response = getIntInput();
				while (response < 0)
				{
					std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
					response = getIntInput();
				}
				points += response - ss4.skillLevel;
				ss4.skillLevel = response;
				break;
			}
			case 5:
			{
				std::cout << "Enter skill name:" << '\n';
				std::getline(std::cin, ss5.skillName);
				std::cout << "Enter skill level:" << '\n';
				response = getIntInput();
				while (response < 0)
				{
					std::cout << "Invalid Input. (Must not be less than 0)" << '\n';
					response = getIntInput();
				}
				points += response - ss5.skillLevel;
				ss5.skillLevel = response;
				break;
			}
			}

		}



	}

	if (ss1.skillName == "Empty")
	{
		ss1.skillName = "";
	}
	if (ss2.skillName == "Empty")
	{
		ss2.skillName = "";
	}
	if (ss3.skillName == "Empty")
	{
		ss3.skillName = "";
	}
	if (ss4.skillName == "Empty")
	{
		ss4.skillName = "";
	}
	if (ss5.skillName == "Empty")
	{
		ss5.skillName = "";
	}

	std::vector<specialSkill> s;

	s.push_back(ss1);
	s.push_back(ss2);
	s.push_back(ss3);
	s.push_back(ss4);
	s.push_back(ss5);

	int i, j, max;
	int n = s.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the maximum element in
		// unsorted array
		max = i;
		for (j = i + 1; j < n; j++)
			if (s[j].skillName > s[max].skillName)
				max = j;

		// Swap the found max element
		// with the first element

		specialSkill temp = s[max];
		s[max] = s[i];
		s[i] = temp;
	}

	ss1 = s[0];
	ss2 = s[1];
	ss3 = s[2];
	ss4 = s[3];
	ss5 = s[4];
}

void Character::setSkill(skill s, int l)
{
	switch (s)
	{
	case skill::S_grapple:
	{
		grapple = l;
		break;
	}
	case skill::S_melee:
	{
		melee = l;
		break;
	}
	case skill::S_strenghtRanged:
	{
		strenghtRanged = l;
		break;
	}
	case skill::S_dexRanged:
	{
		dexRanged = l;
		break;
	}
	case skill::S_initiative:
	{
		initiative = l;
		break;
	}
	case skill::S_athletics:
	{
		athletics = l;
		break;
	}
	case skill::S_Acrobatics:
	{
		acrobatics = l;
		break;
	}
	case skill::S_constitution:
	{
		constitution = l;
		break;
	}
	case skill::S_evasion:
	{
		evasion = l;
		break;
	}
	case skill::S_perception_Investigation:
	{
		perception_Investigation = l;
		break;
	}
	case skill::S_tactics_Command:
	{
		tactics_Command = l;
		break;
	}
	case skill::S_artillery:
	{
		artillery = l;
		break;
	}
	case skill::S_strength:
	{
		strength = l;
		break;
	}
	case skill::S_ride_Pilot:
	{
		ride_Pilot = l;
		break;
	}
	case skill::S_stealth_SlightofHand:
	{
		stealth_SlightofHand = l;
		break;
	}
	case skill::S_persuasion_Deception:
	{
		persuasion_Deception = l;
		break;
	}
	case skill::S_charm_Seduction:
	{
		charm_Seduction = l;
		break;
	}
	case skill::S_intimidation:
	{
		intimidation = l;
		break;
	}
	case skill::S_fortitude_Tolerence:
	{
		fortitude_Tolerence = l;
		break;
	}
	case skill::S_navigation:
	{
		navigation = l;
		break;
	}
	case skill::S_survival:
	{
		survival = l;
		break;
	}
	case skill::S_technology:
	{
		technology = l;
		break;
	}
	case skill::S_engineering:
	{
		engineering = l;
		break;
	}
	case skill::S_medicine:
	{
		medicine = l;
		break;
	}
	case skill::S_calculation_Mathematics:
	{
		calculation_Mathematics = l;
		break;
	}
	case skill::S_memory:
	{
		memory = l;
		break;
	}
	case skill::S_languages_linguistics:
	{
		languages_linguistics = l;
		break;
	}
	case skill::S_sketching_Painting:
	{
		sketching_Painting = l;
		break;
	}
	case skill::S_sculpting_Carving:
	{
		sculpting_Carving = l;
		break;
	}
	case skill::S_sewing_Weaving_Knitting:
	{
		sewing_Weaving_Knitting = l;
		break;
	}
	case skill::S_oratory_Performance:
	{
		oratory_Performance = l;
		break;
	}
	case skill::S_writing_Composition:
	{
		writing_Composition = l;
		break;
	}
	case skill::S_dance:
	{
		dance = l;
		break;
	}
	case skill::S_music_Composition:
	{
		music_Composition = l;
		break;
	}
	case skill::S_music_InstrumentalPerformance:
	{
		music_InstrumentalPerformance = l;
		break;
	}
	case skill::S_music_VocalPerformance:
	{
		music_VocalPerformance = l;
		break;
	}

	}
}

void Character::replaceOrRemoveWeapon(std::vector<Weapon>& weapons)
{
	std::cout << "Select weapon to replace/remove" << '\n';

	if (w1.getName() != "")
	{
		std::cout << "1. " << w1.getName() << '\n';
	}
	else
	{
		std::cout << "1. (Empty)" << '\n';
	}

	if (w2.getName() != "")
	{
		std::cout << "2. " << w2.getName() << '\n';
	}
	else
	{
		std::cout << "2. (Empty)" << '\n';
	}

	if (w3.getName() != "")
	{
		std::cout << "3. " << w3.getName() << '\n';
	}
	else
	{
		std::cout << "3. (Empty)" << '\n';
	}

	if (w4.getName() != "")
	{
		std::cout << "4. " << w4.getName() << '\n';
	}
	else
	{
		std::cout << "4. (Empty)" << '\n';
	}

	if (w5.getName() != "")
	{
		std::cout << "5. " << w5.getName() << '\n';
	}
	else
	{
		std::cout << "5. (Empty)" << '\n';
	}

	std::cout << "0. None" << '\n';

	int response = getIntInput();

	while (response < 0 || response > 5)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	if (response != 0)
	{
		Weapon temp;
		std::cout << "Choose weapon to replace it with" << '\n';

		std::cout << "0. None (Delete without replacing)" << '\n';

		for (int i = 0; i < weapons.size(); i++)
		{
			std::cout << i + 1 << ". " << weapons[i].getName() << '\n';
		}

		int response2 = getIntInput();

		while (response2 < 0 || response2 > weapons.size())
		{
			std::cout << "Invalid Input" << '\n';
			response2 = getIntInput();
		}

		if (response2 != 0)
		{
			temp = weapons[response2 - 1];
		}
		
		switch (response)
		{
			case 1:
			{
				w1 = temp;
				break;
			}
			case 2:
			{
				w2 = temp;
				break;
			}
			case 3:
			{
				w3 = temp;
				break;
			}
			case 4:
			{
				w4 = temp;
				break;
			}
			case 5:
			{
				w5 = temp;
				break;
			}
		}

		
	}
	
	std::vector<Weapon> w;

	w.push_back(w1);
	w.push_back(w2);
	w.push_back(w3);
	w.push_back(w4);
	w.push_back(w5);

	int i, j, max;
	int n = w.size();
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the maximum element in
		// unsorted array
		max = i;
		for (j = i + 1; j < n; j++)
			if (w[j].getName() > w[max].getName())
				max = j;

		// Swap the found max element
		// with the first element

		Weapon temp = w[max];
		w[max] = w[i];
		w[i] = temp;
	}

	w1 = w[0];
	w2 = w[1];
	w3 = w[2];
	w4 = w[3];
	w5 = w[4];
}

void Character::setSpareAmmo()
{
	std::cout << "Pick weapon to change spare ammo" << '\n';

	int i = 1;

	if (w1.getName() != "")
	{
		std::cout << i << ". " << w1.getName() << " (" << w1.getSpareAmmo() << ")" << '\n';
		i++;
	}
	if (w2.getName() != "")
	{
		std::cout << i << ". " << w2.getName() << " (" << w2.getSpareAmmo() << ")" << '\n';
		i++;
	}
	if (w3.getName() != "")
	{
		std::cout << i << ". " << w3.getName() << " (" << w3.getSpareAmmo() << ")" << '\n';
		i++;
	}
	if (w4.getName() != "")
	{
		std::cout << i << ". " << w4.getName() << " (" << w4.getSpareAmmo() << ")" << '\n';
		i++;
	}
	if (w5.getName() != "")
	{
		std::cout << i << ". " << w5.getName() << " (" << w5.getSpareAmmo() << ")" << '\n';
		i++;
	}
	
	int response = getIntInput();

	if (response < 1 || response > i - 1)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	std::cout << "Enter desired spare ammo amount" << '\n';

	int response2 = getIntInput();

	while (response2 < 0)
	{
		std::cout << "Invalid Input" << '\n';
		response = getIntInput();
	}

	switch (response)
	{
		case 1:
		{
			w1.setSpareAmmo(response2);
			break;
		}
		case 2:
		{
			w2.setSpareAmmo(response2);
			break;
		}
		case 3:
		{
			w3.setSpareAmmo(response2);
			break;
		}
		case 4:
		{
			w4.setSpareAmmo(response2);
			break;
		}
		case 5:
		{
			w5.setSpareAmmo(response2);
			break;
		}
	}
	
}

void Character::setNPC()
{
	isNPC = true;
}

bool Character::getNPC()
{
	return isNPC;
}