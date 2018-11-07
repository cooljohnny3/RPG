#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Equipment
{
public:
	Equipment();
	Equipment(std::string n, int r, int s);
	std::string getName();
	int getStat();
	int getReq();
  bool operator ==(const Equipment &equip1) const;

protected:
	void setName(std::string new_name);
	void setReq(int r);
	void setStat(int s);

private:
	std::string name;
	int requirement;
	int stat;
};
#endif