#ifndef SHIP_H
#define SHIP_H

class Ship{
private:
	int qty;
public:
	Ship(int nQty = 1){
		qty = nQty;
	}
	Ship operator = (Ship &right){
		qty = right.qty;
		return *this;
	}	
	~Ship() {}
	// Getters and Setters
	int getQty() const
	{  return qty;  }
	void setQty(int qty)
	{  this->qty = qty;  }
};
#endif  // SHIP_H