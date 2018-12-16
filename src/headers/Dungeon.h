#ifndef DUNGEON_H
#define DUNGEON_H

#include <memory>

#include "Menu.hpp"
#include "Player.h"
#include "Monster.h"

class Dungeon {
public:
	Dungeon();
	Dungeon(std::shared_ptr<Menu>, Player, int);
	~Dungeon();
  void nextLevel();
	//initiates combat with a monster
	//return 0 if player dies, 1 if runs away, and 2 if monster dies
	int combat();
  int playerDamage(int);
  int monsterDamage(int);
  int combatAction(int, int = 0);
  Monster getMonster();
  Player getPlayer();

private:
  std::shared_ptr<Menu> menu;
	Monster monster;
  Player player;
	int level; //gets harder when higher
};

#endif