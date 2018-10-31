#include <iostream>
#include <time.h>
#include <cstdlib>
#include "headers/Dungeon.h"

Dungeon::Dungeon(){	level = 1; }

Dungeon::Dungeon(int l){ level = l; }

Dungeon::~Dungeon(){}

void Dungeon::nextLevel(){ level++; }

int Dungeon::combat(Player* player){
  monster = Monster(level);
	int damage, choice = 0;
	srand(time(NULL));

	std::cout << "You encounter " << monster.getName() << std::endl;

	while (true) {
		std::cout << "\nHow do you wish to proceed?" << std::endl;
		std::cout << "1 - Attack" << std::endl;
		std::cout << "2 - Use Item" << std::endl;
		std::cout << "3 - Run Away" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1) { //Attack
			damage = rand() % player->getWep().getStat();

			if (damage != 0) {
				std::cout << "You did " << damage << " damage to " << monster.getName() << "." << std::endl;
        monster.subHealth(damage);

				if (monster.getHealth() <= 0) {
					std::cout << "You have slain the " << monster.getName() << std::endl;
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

		int monsterDamage = rand() % monster.getAttack();
		if (monsterDamage != 0 && monster.getHealth() > 0) {
			std::cout << monster.getName() << " did " << monsterDamage << " damage to you." << std::endl;
      player->subHealth(damage);

			if (player->getHealth() <= 0) {
        std::cout << "You have died" << std::endl;
        return 0;  //dead
      }
		}

		else
			std::cout << monster.getName() << " misses." << std::endl;
	}
}
