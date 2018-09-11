#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster
{
public:
	Monster();
	Monster(int);
	Monster(std::string);
	std::string getName();
	int getHealth();
	int getAttack();
	int getDefense();
	~Monster();
	void subHealth(int);
	void addHealth(int);

private:
	std::string name;
	int health;
	int attack;
	int defense;
};
#endif