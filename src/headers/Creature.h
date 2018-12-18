#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature {
  public:
  Creature();
  Creature(std::string, int, int);
  std::string getName() const;
  int getMaxHealth() const;
	int getHealth() const;
  void subHealth(int);
	void addHealth(int);
  int getAttack() const;
  int getDefense() const;

  protected:
  void setName(std::string);
  void setMaxHealth(int);
  void setHealth(int);
  void setAttack(int);
  void setDefense(int);

  private:
  std::string name;
	int maxHealth;
	int health;
  int attack;
  int defense;
};

#endif