#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <iostream>
#include <cmath>
#include "Headers/Player.h"

using namespace std;

Player::Player(){
	std::cout << "What is your name? ";
	std::cin >> name;
	maxHealth = 10;  //TODO make way to increase health
	health = 10;
	level = 1;
	experience = 0;
	weapon = Weapon("Wooden Sword", 1, 5);
}

Player::Player(int& n, int& m, int& h, int& l, int& e){ //NOTE might only be assigning pointers, bad?
	name = to_string(n);
	maxHealth = m;
	health = h;
	level = l;
	experience = e;
}

//Health
void Player::subHealth(int num){
	health -= num;
	if (health <= 0) {
		std::cout << "You have died" << std::endl;
		health = maxHealth;
	}

	else
		std::cout << "You have " << health << " HP." << std::endl;	
}

void Player::addHealth(int num){
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

//XP (need to actually do this)
void Player::addXp(int xp) {
	experience += xp;
	if (experience > (level + 2) ^ 2) {
		experience -= (level + 2) ^ 2;
		level += 1;
	}
}

//Getters
std::string Player::getName(){ return name; }

int Player::getHealth(){ return health; }

int Player::getMaxHealth(){return maxHealth; }

int Player::getLevel(){ return level; }

int Player::getXp(){ return experience; }

Weapon Player::getWep(){ return weapon; }

Shield Player::getShield(){ return shield; }

Helm Player::getHelm(){ return helm; }

Body Player::getBody(){ return body; }

Pants Player::getPants(){ return pants; }

//Setters
Weapon Player::setWep(Weapon new_weapon){ //Returns old wep
	Weapon old_weapon = weapon;
	weapon = new_weapon;
	return weapon;
}

Shield Player::setShield(Shield new_shield){ //Returns old shield
	Shield old_shield = shield;
	shield = new_shield;
	return old_shield;
}

Helm Player::setHelm(Helm new_helm){ //Returns old helm
	Helm old_helm = helm;
	helm = new_helm;
	return old_helm;
}

Body Player::setBody(Body new_body){ //Returns old body
	Body old_shield = body;
	body = new_body;
	return old_shield;
}

Pants Player::setPants(Pants new_pants){ //Returns old pants
	Pants old_shield = pants;
	pants = new_pants;
	return old_shield;
}
#endif