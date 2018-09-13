#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "Creature.h"

class Monster : public Creature {
public:
	Monster();
	Monster(int);
	Monster(std::string);
};
#endif