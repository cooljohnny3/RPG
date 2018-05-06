#ifndef EQUIPMENT_CPP
#define EQUIPMENT_CPP

#include "Equipment.h"

Equipment::Equipment()
{
	name = "";
	requirement = 0;
	stat = 0;
}

Equipment::Equipment(std::string n, int r, int s) {
	name = n;
	requirement = r;
	stat = s;
}

//Getters
std::string Equipment::getName(){
	return name;
}

int Equipment::getStat(){
	return stat;
}

int Equipment::getReq(){
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
#endif