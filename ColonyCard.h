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

#ifndef COLONYCARD_H
#define COLONYCARD_H

#include "Card.h"
#include <iostream>

class ColonyCard : public Card
{
private:
	int resource;		// type of resource
	int actNum;			// activation number
	int vicPts;

public:
	ColonyCard(int num, string name, int type, int resource, int actNum, int vicPts) 
		: Card(num, name, type)
	{
		this->resource = resource;
		this->actNum = actNum;
		this->vicPts = vicPts;
	}
	~ColonyCard() {}
	// Getters and Setters
	int getResource() const
	{	return resource;	}
	int getActNum() const
	{	return actNum;	}
	int getPts() const
	{  return vicPts;  }
	void printCard(){
		std::cout << std::left
			//			<< setw(15) << "DeckNum: " << getDeckNum() << endl
			<< setw(15) << "Name: " << getName() << endl
			//			<< setw(15) << "Type: " << getType() << endl
			<< setw(15) << "Resourse: " << getResName(getResource()) << endl
			<< setw(15) << "Die Number: " << getActNum() << endl
			//			<< setw(15) << "Victory Pts: " << getVicPts() << endl;
			<< endl << endl;
	}
};
#endif // COLONYCARD_H
