#include <iostream>
#include "Creature.h"

Creature::Creature() {
	maxHealth = 10;  // TODO make way to increase health
	health = 10;
  attack = 1;
  defense = 0;
}

Creature::Creature(std::string n, int m, int h) {
	name = n;
	maxHealth = m;
	health = h;
}

// Health
void Creature::subHealth(int num) {	
  health -= num; 
  if (health <= 0) { health = maxHealth; }
}

void Creature::addHealth(int num) {
	if ((health + num) > maxHealth) {
		health = maxHealth;
		std::cout << "You are max health." << std::endl;
	}

	else if(health == maxHealth)
		std::cout << "You are already max health." << std::endl;

	else {
		health += num;
		std::cout << "You have " << health << " HP." << std::endl;
	}		
}

// Protected Setters
void Creature::setName(std::string n) { name = n; }

void Creature::setMaxHealth(int m) { maxHealth = m; }

void Creature::setHealth(int h) { health = h; }

void Creature::setAttack(int a){ attack = a; }

void Creature::setDefense(int d){ defense = d; }

// Getters
int Creature::getAttack() const { return attack; }

int Creature::getDefense() const { return defense; }

std::string Creature::getName() const { return name; }

int Creature::getHealth() const { return health; }

int Creature::getMaxHealth() const {return maxHealth; }