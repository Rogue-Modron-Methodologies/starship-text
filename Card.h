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

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

enum cTypes{trade, colony, pirate, adventure, lost};
enum Resource { Carbon, Fuel, Ore, Science, TradeGood, Wheat, Any };

class Card{
private:
	int deckNum;	// place in the deck
	string name;	// card name
	int type;	    // card type

public:
	Card(int num = 0, string name = "", int type = 0){
		this->deckNum = num;
		this->name = name;
		this->type = type;
	}
	virtual	Card* operator = (Card* right)
	{
		this->deckNum = right->deckNum;
		this->name = right->name;
		this->type = right->type;
		return this;
	}
	~Card() {}
	// Getters and Setters
	void setDeckNum(int num)
	{  this->deckNum = num;  }
	void setName(string name)
	{  this->name = name;  }
	void setType(int type)
	{	this->type = type;	}
	int getDeckNum() const
	{  return deckNum; 	}
	string getName() const
	{  return name;	}
	int getType() const
	{	return type;	}
	virtual string getRequirement() const
	{	return "This should never print.";	}
	virtual int getActNum() const
	{	return 0;	}
	virtual int getResource() const
	{	return -100;	}
	virtual int getPts() const
	{	return -100;  }
	virtual int getCost() const
	{	return -100;	}
	virtual int getCannons() const
	{	return -100;	}
	virtual int getLimit() const
	{	return -100;	}
	virtual string getTransaction() const
	{	return "This should never print.";	}
	virtual string getResult() const
	{	return "This should never print.";	}
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
	virtual int getRecRcvd() const
	{	return -100;	}
	virtual int getAstros() const
	{	return -100;	}
	virtual int getFame() const
	{	return -100;	}
	virtual int getVicPts() const
	{	return -100;	}
	virtual void printCard(){
		cout << left
			//			<< setw(15) << "DeckNum: " << getDeckNum() << endl
			<< setw(15) << "Name: " << getName() << endl
			//			<< setw(15) << "Type: " << getType() << endl << endl;
			<< endl << endl;
	}
};
#endif // CARD_H
