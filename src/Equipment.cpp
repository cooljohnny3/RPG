#include "headers/Equipment.h"

Equipment::Equipment()
{
	name = "<Empty>";
	requirement = 0;
	stat = 0;
}

Equipment::Equipment(std::string n, int r, int s) {
	name = n;
	requirement = r;
	stat = s;
}

//Getters
std::string Equipment::getName() const{
	return name;
}

int Equipment::getStat() const{
	return stat;
}

int Equipment::getReq() const{
	return requirement;
}

//Setters
void Equipment::setName(std::string new_name){
	name = new_name;
}

void Equipment::setReq(int r){
	requirement = r;
}
void Equipment::setStat(int s){
	stat = s;
}

bool Equipment::operator==(const Equipment &equip1) const {
  bool sameName = name == equip1.name;
  bool sameReq = requirement == equip1.requirement;
  bool sameStat = stat == equip1.stat;
  return sameName && sameReq && sameStat;
}

std::ostream& operator<<(std::ostream &strm, const Equipment &E) {
  std::string returnVal = E.getName() + " " + std::to_string(E.getReq()) + " " + std::to_string(E.getStat());
  return strm << returnVal;
}