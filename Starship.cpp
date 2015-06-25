//  The MIT License(MIT)
//
//  Copyright(c) 2015 Jamie Johnson
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files(the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions :
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.

#include "Starship.h"

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//  Adds/Upgrades a laser 
//		Can only have value between 0-2 
//		Validated before function call
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Starship::addLaser(int pos)
{
	bool success = true;

	if (laser[pos] == 0)
		laser[pos]++;
	else if (laser[pos] == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (laser[i] == 0)
				success = false;
		}
		if (success)
			laser[pos]++;
		else
			cout << "Cannot upgrade to max level until all lasers have been bought\n";
	}
	else
		cout << "Laser " << pos << " is already at max level!\n";

	return success;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//  Adds/Upgrades a booster 
//		Can only have value between 0-2 
//		Validated before function call
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
bool Starship::addBooster(int pos)
{
	bool success = true;

	if (booster[pos] == 0)
		booster[pos]++;
	else if (booster[pos] == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (booster[i] == 0)
				success = false;
		}
		if (success)
			booster[pos]++;
		else
			cout << "Cannot upgrade to max level until all boosters have been purchased\n";
	}
	else
		cout << "Booster " << pos << " is already at max level!\n";

	return success;
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  Prints the contents of the players Ship
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
void Starship::printShip(){

	cout << left << endl
		<< setw(15) << "Lasers: " << laser[0] << " " << laser[1] << " " << laser[2] << endl << endl
		<< setw(15) << "Carbon " << getResQty(Carbon) << " / " << rCap << endl
		<< setw(15) << "Food " << getResQty(Wheat) << " / " << rCap << endl
		<< setw(15) << "Fuel " << getResQty(Fuel) << " / " << rCap << endl
		<< setw(15) << "Ore " << getResQty(Ore) << " / " << rCap << endl
		<< setw(15) << "Trade Goods " << getResQty(TradeGood) << " / " << rCap << endl
		<< setw(15) << "Science " << getResQty(Science) << " / " << rCap << endl << endl
		<< setw(15) << "Ship Hangers" << getShip(H1) << " / " << getShip(H2) << endl << endl
		<< setw(15) << "Boosters: " << booster[0] << " " << booster[1] << " " << booster[2] << endl << endl
		<< setw(15) << "Friendship Points Here\n\n"
		<< setw(15) << "Fame Points Here\n\n"
		<< setw(15) << "Victory Points Here\n\n";
}

// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
//
//  
//
// (¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯`'•.¸//(*_*)\\¸.•'´¯) 
