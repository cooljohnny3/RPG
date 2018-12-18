#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <fstream>
#include "Creature.h"

class Monster : public Creature {
public:
	Monster();
	Monster(int);

private:
  void generate(int);
  std::fstream& GotoLine(std::fstream& file, int num) const;
};
#endif