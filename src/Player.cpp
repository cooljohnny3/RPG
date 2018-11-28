#include <iostream>
#include <cmath>
#include "headers/Player.h"

Player::Player() {
  std::string temp;
  std::cout << "What is your name? ";
	std::cin >> temp;
  setName(temp);
  level = 1;
	experience = 0;
	weapon = Weapon("Wooden_Sword", 1, 5);
  calculateStats();
}

Player::Player(std::string name, int maxHealth, int health, int level, int experience) {
  setName(name);
  setMaxHealth(maxHealth);
  setHealth(health);
	this->level = level;
	this->experience = experience;
}

void Player::calculateStats() {
  setAttack(weapon.getStat() + 1);
  int sum = 0;
  sum += getWep().getStat();
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