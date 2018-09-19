#ifndef WEAPON_CPP
#define WEAPON_CPP

#include "headers/Weapon.h"

Weapon::Weapon() : Equipment(){}

Weapon::Weapon(std::string n, int r, int s) : Equipment(n, r, s) {}
#endif