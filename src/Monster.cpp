#include <iostream>
#include <fstream>
#include "headers/Monster.h"

Monster::Monster() {
	setName("default");
}

// Creates monster from list using id
Monster::Monster(int) : Creature() {
	std::ifstream monsters("Monsters.dat");
	std::string line;
	if (monsters.is_open()) {
		std::getline(monsters, line);
	}
}