#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Body.h"
#include "Helm.h"
#include "Pants.h"
#include "Shield.h"
#include "Weapon.h"

class Player : public Creature{
public:
	Player();
	Player(std::string, int, int, int, int);
	int getLevel() const;
  int getDeepestLevel() const;
	int getXp() const;
	Weapon getWep() const;
	Shield getShield() const;
	Helm getHelm() const;
	Body getBody() const;
	Pants getPants() const;
	void addXp(int);
  void setDeepestLevel(int);
	Weapon setWep(Weapon);
	Shield setShield(Shield);
	Helm setHelm(Helm);
	Body setBody(Body);
	Pants setPants(Pants);
    void calculateStats();

private:
  int deepestLevel;
	int level;
	int experience;
	Weapon weapon;
	Shield shield;
	Helm helm;
	Body body;
	Pants pants;
};
#endif
