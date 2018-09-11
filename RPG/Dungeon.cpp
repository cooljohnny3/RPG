#ifndef DUNGEON_CPP
#define DUNGEON_CPP

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Headers/Dungeon.h"

Dungeon::Dungeon(){
	m = Monster();
	level = 1;
}

Dungeon::Dungeon(int l){
	m = Monster();
	level = l;
}

Dungeon::~Dungeon(){}

void Dungeon::nextLevel(){
	m = Monster();
	level++;
}

int Dungeon::combat(Player* p){
	int damage, choice = 0;
	srand(time(NULL));

	std::cout << "You encounter " << m.getName() << std::endl;

	while (true) {
		std::cout << "\nHow do you wish to proceed?" << std::endl;
		std::cout << "1 - Attack" << std::endl;
		std::cout << "2 - Use Item" << std::endl;
		std::cout << "3 - Run Away" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1) { //Attack
			damage = rand() % p->getWep().getStat();

			if (damage != 0) {
				m.subHealth(damage);
				std::cout << "You did " << damage << " damage to " << m.getName() << "." << std::endl;

				if (m.getHealth() <= 0) {
					std::cout << "You have slain the " << m.getName() << std::endl;
					return 2; //win
				}
			}	

			else
				std::cout << "Doh! you missed." << std::endl;
		}			

		else if (choice == 2) //Use item
			std::cout << "Not implimented" << std::endl;

		else if (choice == 3) { //Run away, 50% success
			if (rand() % 2 == 0) {
				std::cout << "You run away." << std::endl;
				return 1; //run away
			}
				
			else
				std::cout << "You fail to escape." << std::endl;
		}

		damage = rand() % m.getAttack();
		if (damage != 0 && m.getHealth() > 0) {
			std::cout << m.getName() << " did " << damage << " damage to you." << std::endl;

			if (damage >= p->getHealth())
				return 0;  //dead

			p->subHealth(damage);
		}

		else
			std::cout << m.getName() << " misses." << std::endl;
	}
}

#endif
