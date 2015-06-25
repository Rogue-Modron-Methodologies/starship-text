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

#ifndef ADVENTURECARD_H
#define ADVENTURECARD_H

#include "Card.h"
#include <iostream>

class AdventureCard : public Card
{
private:	
	string mission;		// mission name
	string requirement;		// requirements	
	int recRcvd;			// resources received	
	int astroPts;			// astros received
	int fmPts;			// fame points
	int vicPts;			// victory points

public:
	AdventureCard(int num, string name, int type, string mission, string requirement, int resource, int astro, int fmPts, int vicPts)
		: Card(num, name, type)
	{
		this->mission = mission;
		this->requirement = requirement;
		this->recRcvd = resource;
		this->astroPts = astro;
		this->fmPts = fmPts;
		this->vicPts = vicPts;
	}
	~AdventureCard() {}
	// Getters and Setters
	string getMission() const
	{	return mission;	}
	string getRequirement() const
	{	return requirement;	}
	int getRecRcvd() const
	{	return recRcvd;	}
	int getAstros() const
	{	return astroPts;	}
	int getFame() const
	{	return fmPts;	}
	int getVicPts() const
	{	return vicPts;	}
	// deck, planet, mission, requirement, resources, astro, fame, victory
	void printCard(){
		std::cout << std::left
			//			<< setw(15) << "DeckNum: " << getDeckNum() << endl
			<< setw(15) << "Planet Name: " << getName() << endl
			<< setw(15) << "Mission: " << getMission() << endl
			<< setw(15) << "Requirement: " << getRequirement() << endl
			<< "------REWARDS------\n";
		if (getRecRcvd() > 0)
			cout << setw(15) << "Resources: " << getRecRcvd() << endl;
		if (getAstros() > 0)
			cout << setw(15) << "Astros: " << getAstros() << endl;
		if (getFame() > 0)
			cout << setw(15) << "Fame Points: " << getFame() << endl;
		if (getVicPts() > 0)
			cout << setw(15) << "Victory Pts: " << getVicPts() << endl;
		cout << endl << endl;
	}
};
#endif // ADVENTURECARD_H
