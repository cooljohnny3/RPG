#include <iostream>
#include <fstream>
#include <cmath>
#include "Player.h"

Player::Player() {
  level = 1;
  deepestLevel = 0;
	experience = 0;
	weapon = Weapon("Wooden_Sword", 1, 5);
  calculateStats();
}

Player::Player(std::string name, int maxHealth, int health, int level, int deepeestLevel, int experience) {
  setName(name);
  setMaxHealth(maxHealth);
  setHealth(health);
	Player::level = level;
  setDeepestLevel(deepeestLevel);
	Player::experience = experience;
  weapon = Weapon("Wooden_Sword", 1, 5);
  calculateStats();
}

void Player::createPlayer() {
  std::fstream f;
  bool valid;
  char choice;
  std::string name;

  // Loops until a valid name has been entered
	do {
    valid = false;
    choice = 'x';
    std::cout << "What is your name? ";
	  std::cin >> name;
		f.open("saves/" + name, std::fstream::in);

    // Checks to see if file exists
		if(f.peek() != std::ifstream::traits_type::eof()) {
      while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        std::cout << "A character with that name already exists, would you like to overwrite this? (Y/N) ";
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y') {
          // std::cout << "Answered Y/y" << std::endl;
          valid = true;
        }

        else if(choice == 'N' || choice == 'n') {
          // std::cout << "Answered N/n" << std::endl;
          valid = false;
        }

        else {
          std::cout << "Please answer Y/N" << std::endl;
        }
      }
		}
		else {
      valid = true;
    }
    // std::cout << "Closing f" << std::endl;
    f.close();
	} while(!valid); // While not valid

  setName(name);
}

void Player::calculateStats() {
  setAttack(weapon.getStat() + 1);
  int sum = 0;
	sum += getShield().getStat();
	sum += getHelm().getStat();
	sum += getBody().getStat();
	sum += getPants().getStat();
  setDefense(sum);
}

// XP (need to actually do this)
void Player::addXp(int xp) {
	experience += xp;
	if (experience > ((level + 2) ^ 2)) {
		experience -= ((level + 2) ^ 2);
		level += 1;
	}
}

// Getters
int Player::getDeepestLevel() const { return deepestLevel; }

int Player::getLevel() const { return level; }

int Player::getXp() const { return experience; }

Weapon Player::getWep() const { return weapon; }

Shield Player::getShield() const { return shield; }

Helm Player::getHelm() const { return helm; }

Body Player::getBody() const { return body; }

Pants Player::getPants() const { return pants; }

// Setters
void Player::setDeepestLevel(int level) { deepestLevel = level; }

Weapon Player::setWep(Weapon new_weapon) { // Returns old wep
	Weapon old_weapon = weapon;
	weapon = new_weapon;
	return weapon;
}

Shield Player::setShield(Shield new_shield) { // Returns old shield
	Shield old_shield = shield;
	shield = new_shield;
	return old_shield;
}

Helm Player::setHelm(Helm new_helm) { // Returns old helm
	Helm old_helm = helm;
	helm = new_helm;
	return old_helm;
}

Body Player::setBody(Body new_body) { // Returns old body
	Body old_shield = body;
	body = new_body;
	return old_shield;
}

Pants Player::setPants(Pants new_pants) { // Returns old pants
	Pants old_shield = pants;
	pants = new_pants;
	return old_shield;
}