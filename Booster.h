#ifndef BOOSTER_H
#define BOOSTER_H

class Booster{
private:
	int lvl;
public:
	Booster(int nLvl = 0){
		lvl = nLvl;
	}
	~Booster() {}
	// Getters and Setters
	int getLvl() const
	{  return lvl;  }
	void setLvl(int lvl)
	{  this->lvl = lvl;  }
};
#endif // BOOSTER_H
