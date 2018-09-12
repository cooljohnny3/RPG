#ifndef PLAYER_H
#define PLAYER_H

#include "./Body.h"
#include "./Helm.h"
#include "./Pants.h"
#include "./Shield.h"
#include "./Weapon.h"

class Player {
public:
	Player();
	Player(int&, int&, int&, int&, int&);
	std::string getName();
	int getHealth();
	int getMaxHealth();
	int getLevel();
	int getXp();
	Weapon getWep();
	Shield getShield();
	Helm getHelm();
	Body getBody();
	Pants getPants();
	void subHealth(int);
	void addHealth(int);
	void addXp(int);
	Weapon setWep(Weapon);
	Shield setShield(Shield);
	Helm setHelm(Helm);
	Body setBody(Body);
	Pants setPants(Pants);

private:
	std::string name;
	int maxHealth; //TODO make way to increase health
	int health;
	int level;
	int experience;
	int inv[10]; 
	Weapon weapon;
	Shield shield;
	Helm helm;
	Body body;
	Pants pants;
};
#endif
