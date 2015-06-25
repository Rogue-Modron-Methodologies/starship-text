#ifndef LASER_H
#define LASER_H

class Laser{
private:
	int lvl;
public:
	Laser(int nLvl = 0){
		lvl = nLvl;
	}
	~Laser() {}
	// Getters and Setters
	int getLvl() const
	{  return lvl;  }
	void setLvl(int lvl)
	{  this->lvl = lvl;  }
};
#endif // LASER_H
