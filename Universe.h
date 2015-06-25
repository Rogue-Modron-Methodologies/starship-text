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

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "TradeCard.h"
#include "ColonyCard.h"		
#include "Pirate.h"
#include "AdventureCard.h"

class Universe{
private:
	Card* S1[10];
	Card* S2[10];
	Card* S3[10];
	Card* S4[10];
	Card* SE[28];
	Card* AD[9];
	Card* cAdv[3];
	int ExtraDeckPtr;
	int advPtr;

public:
	Universe()
	{
		universeSetup();
		adventureDeckSetup();
		ExtraDeckPtr = 0;
		advPtr = 0;
	}
	~Universe() {}
	// Getters and Setters
	Card** getSector(int num);
	Card* getAdvCard(int i);
	void setSector(Card* nCard, int sNum, int cNum);
	void shuffleDeck(Card* list[], int size);
	void addCardtoSector(int secNum, int i);
	void addCardtoAdvDeck(int i);
	void printCurrentAdventure();

private:
	void universeSetup();
	void adventureDeckSetup();
	
};
#endif // UNIVERSE_H
