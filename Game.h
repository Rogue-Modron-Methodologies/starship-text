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

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Universe.h"
#include <string>
#include <fstream>
#include <sstream>

const int CARDLISTSIZE = 71;
const string CARDLIST = "starship.csv";
const string ADVENTURELIST = "starship2.csv";

class Game{
private:
	Player *P1, *P2;
	Player *cPlyr;
	Universe* universe;
	int speedDie[6];
	int combatDie[6];

public:
	Game()
	{
		P1 = new Player;
		P2 = new Player;
		universe = new Universe;
		cPlyr = P2;
		playerSetup();
		initSDie();
		initCDie();
		gameLoop();
	}
	~Game()
	{
		delete P1;
		delete P2;
		delete universe;
	}
	// getters and setters
	Player* getP1() const
	{	return P1;  }
	Player* getP2() const
	{	return P2;  }
	Universe* getUniverse() const
	{	return universe;	}

	int rollSpeedDie()
	{	return speedDie[rand() % 6];	}
	int rollCombatDie()
	{	return combatDie[rand() % 6];	}

private:	

	bool pirateFight(Card* cCard);
	int piratePhase(int move, int action, Card* cCard);
	void winMenu(int numRec = 1);
	void oMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show = true);
	void tfMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show = true);
	void tMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show = true);
	void fMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying, bool show = true);
	bool adventureMenu(int move, int& action, Card* cCard, int pNum, bool& keepFlying);
	void advRewards(Card* cCard, int pNum);
	void gMenu(int pNum);
	void menuSelector(int move, int& action, Card* cCard, int pNum, bool& keepFlying);
	void gameMenu(int pNum);
	void gameTurn();	
	void gameLoop();
	void playerSetup();	
	void productionPhase(int pNum);
	void flightPhase(int pNum);
	void tradeBuildToggle(int pNum);
	void tradePhase(int pNum);
	void buildPhase(int pNum);
	void initSDie();
	void initCDie();
	void phasePrompt(int pNum);
	int getValidNum(int high, int low = 1);
	void clearScreen();
	void displayFlightSectors();
	bool establishPost(Card* cCard, int cIndex, int secNum, int move, int& action);
	bool getYesOrNo();
	bool buySellResources(int pNum, Card* cCard);
};

#endif // BOARDGAME_H
