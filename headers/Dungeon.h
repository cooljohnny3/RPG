#ifndef DUNGEON_H
#define DUNGEON_H

#include "./Player.h"
#include "./Monster.h"

class Dungeon{
public:
	Dungeon();
	Dungeon(int);
	~Dungeon();
	void nextLevel();
	//initiates combat with a monster
	//return 0 if player dies, 1 if runs away, and 2 if monster dies
	int combat(Player*); 

private:
	Monster m;
	int level; //gets harderwhen higher
};

#endif