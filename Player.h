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

#ifndef PLAYER_H
#define PLAYER_H

#include "Starship.h"
#include "LinkedList.h"
#include "ColonyCard.h"

enum Phases{production, flight, trades, build};

class Player{
private:
	Starship* starship;
	LinkedList<Card>* ColonyZone;
	LinkedList<Card>* TradeZone;
	int phases[4];
	string name;


public:
	Player() {
		starship = new Starship;
		ColonyZone = new LinkedList<Card>;
		TradeZone = new LinkedList<Card>;
		phases[0] = production;
		phases[1] = flight;
		phases[2] = trades;
		phases[3] = build;

	}
	~Player() 
	{ 	
		delete starship;
		delete ColonyZone;
		delete TradeZone;
	}
	// getters and setters
	Starship* getStarship() const
	{  return starship;  }
	LinkedList<Card>* getColonyZone() const
	{	return ColonyZone;	}
	LinkedList<Card>* getTradeZone() const
	{	return TradeZone;	}
	string getName() const
	{	return name;	}
	void setName(string name)
	{	this->name = name;	}
	string getPhaseName(int pNum)
	{	
		string tempName;
		switch (pNum)
		{
		case 0:
			tempName = "Production";
			break;
		case 1:
			tempName = "Flight";
			break;
		case 2:
			tempName = "Trade";
			break;
		case 3:
			tempName = "Build";
			break;
		case 4:
			tempName = "Trade/Build";
		}
		return tempName;	
	}
};
#endif // PLAYER_H
