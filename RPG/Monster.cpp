#ifndef MONSTER_CPP
#define MONSTER_CPP

#include <iostream>
#include <fstream>
#include "Headers/Monster.h"

Monster::Monster(){
	name = "default";
	health = 10;
	attack = 2;
	defense = 1;
}

// Creates monster from list using id
Monster::Monster(int){
	std::ifstream monsters("Monsters.dat");
	std::string line;
	if (monsters.is_open()) {
		std::getline(monsters, line);
	}
}

Monster::~Monster(){}

//Health 
void Monster::subHealth(int h){ health -= h; }

void Monster::addHealth(int h){ health += h; }

//Getters
std::string Monster::getName() { return name; }

int Monster::getHealth(){ return health; }

int Monster::getAttack() { return attack; }

int Monster::getDefense() { return defense; }
#endif