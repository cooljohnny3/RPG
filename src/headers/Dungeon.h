#ifndef DUNGEON_H
#define DUNGEON_H

#include "Menu.hpp"
#include "Player.h"
#include "Monster.h"

class Dungeon {
public:
	Dungeon();
	Dungeon(Menu*, Player, int);
	~Dungeon();
  void nextLevel();
	//initiates combat with a monster
	//return 0 if player dies, 1 if runs away, and 2 if monster dies
	int combat();
  int playerDamage(int);
  int monsterDamage(int);
  int combatAction(int);
  Monster getMonster();
  Player getPlayer();

private:
  Menu *menu;
	Monster monster;
  Player player;
	int level; //gets harder when higher
};

#endif