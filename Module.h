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

#ifndef MODULE_H
#define MODULE_H

class Module{
private:
	std::string type;
	int qty;
	int maxQty;

public:
	Module(std::string type = " ", int qty = 0, int maxQty = 2){
		this->type = type;
		this->qty = qty;
		this->maxQty = maxQty;
	}
	Module operator = (Module &right){
		type = right.type;
		qty = right.qty;
		maxQty = right.maxQty;
	}	
	~Module() {}
	// Getters and Setters
	std::string getType() const
	{  return type;  }
	int getQty() const
	{  return qty;  }
	int getMaxQty() const
	{  return maxQty;  }
	void setQty(int qty)
	{  this->qty = qty;  }
	void setMaxQty(int maxQty)
	{  this->maxQty = maxQty;  }
};
#endif // MODULE_H