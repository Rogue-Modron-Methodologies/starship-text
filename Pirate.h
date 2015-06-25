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

#ifndef PIRATE_H
#define PIRATE_H

#include "Card.h"

class Pirate : public Card
{
private:
	string result;				// lose result
	int cost;					// cost of to bribe
	int cannons;				// number of cannons
	int pts;					// num of hero points

public:
	Pirate(int num, string name, int type, int cost, int cannons, string result, int pts) : Card(num, name, type)
	{
		this->cost = cost;
		this->cannons = cannons;
		this->result = result;
		this->pts = pts;
	}
	~Pirate() {}
	// Getters and Setters
	string getResult() const
	{	return result;	}
	int getCost() const
	{	return cost;	}
	int getCannons() const
	{	return cannons;		}
	int getPts() const
	{	return pts;		}

	void printCard(){
		cout << left
//			<< setw(15) << "DeckNum: " << getDeckNum() << endl
			<< setw(15) << "Name: " << getName() << endl
			<< setw(15) << "Type: " << getType() << endl
			<< setw(15) << "Bribe Cost: " << cost << endl
			<< setw(15) << "Cannons: " << cannons << endl
			<< setw(15) << "Hero Points" << pts << endl			
			<< setw(15) << "Lose Result: " << result << endl
			<< endl << endl;
	}
};
#endif // PIRATE_H
