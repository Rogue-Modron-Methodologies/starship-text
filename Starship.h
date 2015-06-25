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

#ifndef STARSHIP_H
#define STARSHIP_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Module.h"
#include "Card.h"

using namespace std;

enum Booster {B1, B2, B3};
enum Laser {L1, L2, L3};
enum Ships {H1, H2};


class Starship{
private:
	int laser[3];
	int booster[3];
	int resource[6];
	int rCap;
	int maxActions;
	int maxMovement;
	int astro;	
	char shipHold[2];
	int vPts;						// victory points
	int fdPts;					// friendship points (for friend of the people)
	int fmPts;					// fame points (for hero of th people)

public:
	Starship()
	{
		resource[Carbon] = 0;
		resource[Fuel] = 0;
		resource[Ore] = 0;
		resource[Science] = 1;
		resource[TradeGood] = 1;		
		resource[Wheat] = 0;
		booster[B1] = 1;
		booster[B2] = 0;
		booster[B3] = 10; /////////////////////////// S/B 1
		laser[L1] = 0;
		laser[L2] = 1; 
		laser[L3] = 0;
		shipHold[H1] = 'C';
		shipHold[H2] = 'T';
		maxActions = 2;
		rCap = 2; 
		astro = 25;
		vPts = 1;
		fdPts = 0;
		fmPts = 0;
	}	
	//Getters and Setters
	int getRCap() const
	{	return rCap;	}

	int getAstro() const
	{	return astro;	}
	// Called when Astros are used or gained;
	bool modAstro(int num){					
		bool success = true;
		if (astro + num >= 0)
			this->astro += num;
		else{
			cout << "Not enough Astro!!!\n";
			success = false;
		}
		return success;
	}	
	int getResQty(int type)
	{	return resource[type];	}
	string getResName(int type)
	{
		string tempName;
		switch (type)
		{
		case 0:
			tempName = "Carbon";
			break;
		case 1:
			tempName = "Fuel";
			break;
		case 2:
			tempName = "Ore";
			break;
		case 3:
			tempName = "Science";
			break;
		case 4:
			tempName = "TradeGood";
			break;
		case 5:
			tempName = "Wheat";
			break;
		default:
			tempName = "Any";
		}
	return tempName;
}
	// Called when resources are gained or lost;
	bool modResource(int num, int type, int cost = 0)
	{
		bool success = false;
		
		if (num * cost > astro)
		{
			cout << "Not enough Astro!\n";
			return false;
		}
		if (resource[type] + num < 0 && resource[type] + num <= rCap)
			cout << "Failed.  Not enough resource\n";
		else if (resource[type] + num > rCap)
			cout << endl << getResName(type) << " not added.  Would Exceed Max Capacity\n\n";
		else
		{
			cout << endl << abs(num) << " " << getResName(type);
			if (cost != 0)
				cout << " traded for " << (0 - (num * cost)) << " astro!!\n\n";
			else
				cout << " traded!!\n\n";
		
			resource[type] += num;
			astro -= num * cost;
			success = true;
		}
		return success;
	}
	bool haveShip(char type)
	{
		return (getH1() == type || getH2() == type);
	}
	char getShip(int num) const
	{	return shipHold[num];	}
	char getH1()
	{	return shipHold[H1];	}
	char getH2()
	{	return shipHold[H2];	}
	void setH1(char type)
	{	shipHold[H1] = type;	}
	void setH2(char type)
	{	shipHold[H2] = type;	}
	void removeTradeShip()
	{
		if (getH1() == 'T')
			setH1(' ');
		else
			setH2(' ');
	}
	void removeColonyShip()
	{
		if (getH1() == 'C')
			setH1(' ');
		else
			setH2(' ');
	}

	void setMaxActions(int num)				// called by a module
	{	this->maxActions = num;	}
	void calcMaxDistance(int dieRoll)		// called in Flight Phase
	{	maxMovement = (dieRoll + totalBoosters()); }
	int getMaxDistance() const
	{	return maxMovement;	}
	int getMaxActions() const
	{	return maxActions;	}
	int totalBoosters()						// called by calcMaxDistance and events	
	{	return booster[0] + booster[1] + booster[2];	}
	int totalLasers()						// called by events and combat 
	{	return laser[0] + laser[1] + laser[2];	}
	bool addLaser(int pos);					// Called by ???
	bool addBooster(int pos);				// Called by ???	
	void printShip();						// called in menus	
};

#endif // STARSHIP_H