#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Equipment
{
public:
	Equipment();
	Equipment(std::string n, int r, int s);
	std::string getName() const;
	int getStat() const;
	int getReq() const;
  bool operator ==(const Equipment &equip1) const;

protected:
	void setName(std::string new_name);
	void setReq(int r);
	void setStat(int s);

private:
	std::string name;
	int requirement;
	int stat;
  friend std::ostream& operator<<(std::ostream &strm, const Equipment&);
};
#endif