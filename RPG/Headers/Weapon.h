#ifndef WEAPON_H
#define WEAPON_H

#include "Equipment.h"

class Weapon : public Equipment{
public:
	Weapon();
	Weapon(std::string n, int r, int s);
};
#endif