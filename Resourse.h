#ifndef RESOURCE_H
#define RESOURCE_H

class Resource{
private:
	int qty;

public:
	Resource(int qty = 0)
	{
		this->qty = qty;
	}
	Resource operator = (Resource &right)
	{
		qty = right.qty;
		return *this;
	}	
	~Resource()	{}
	// Getters and Setters
	int getQty() const
	{  return qty;  }
	void setQty(int qty)
	{  this->qty = qty;   }
	bool changeQty(int num)
	{	qty+= num;	}
};
#endif // RESOURCE_H