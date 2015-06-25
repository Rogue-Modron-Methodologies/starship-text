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

#ifndef TRADECARD_H
#define TRADECARD_H

#include "Card.h"

class TradeCard : public Card
{
private:
	int resource;				// type of resource
	int cost;					// cost of resource
	string transaction;
	int limit;
	int pts;

public:
	TradeCard(int num, string name, int type, int resource, 
		int cost, string transaction, int limit, int pts) : Card(num, name, type)
	{
		this->resource = resource;
		this->cost = cost;
		this->transaction = transaction;
		this->limit = limit;
		this->pts = pts;
	}
	Card* operator = (Card* right)
	{
		setDeckNum(right->getDeckNum());
		setName(right->getName());
		setType(right->getType());
		this->resource = resource;
		this->cost = cost;
		this->transaction = transaction;
		this->limit = limit;
		this->pts = pts;		
		return this;
	}
	~TradeCard() {}
	// Getters and Setters
	int getResource() const
		{  return resource; }
	int getCost() const
		{  return cost;  }
	string getTransaction() const
		{	return transaction;  }
	int getLimit() const
		{	return limit;  }
	int getPts() const
		{  return pts;  }

	void printCard(){
		cout << left
//			<< setw(15) << "DeckNum: " << getDeckNum() << endl
			<< setw(15) << "Name: " << getName() << endl
//			<< setw(15) << "Type: " << getType() << endl
			<< setw(15) << "Resourse: " << getResName(getResource()) << endl
			<< setw(15) << "Cost: " << cost << endl
//			<< setw(15) << "Transaction: " << transaction << endl
//			<< setw(15) << "Limit: " << limit << endl
//			<< setw(15) << "Points" << pts << endl
			<< endl << endl;
	}
};
#endif // TRADECARD_H
