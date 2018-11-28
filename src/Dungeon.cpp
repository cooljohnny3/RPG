#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Dungeon.h"

Dungeon::Dungeon() {	level = 1; }

Dungeon::Dungeon(Player player, int l) { 
  Dungeon::player = player;
  level = l;
}

Dungeon::~Dungeon() {}

void Dungeon::nextLevel() {
  level++;
  if(level > player.getDeepestLevel()) {
    player.setDeepestLevel(level);
  }
}

int Dungeon::combat() {
  monster = Monster(level);
	int damage, choice = 0;
	srand(time(NULL));

	std::cout << "You encounter " << monster.getName() << std::endl;

	while (true) {
    // std::cout << "Player: Attack: " << player.getAttack() << " Defence: " << player.getDefense() << " Health: " << player.getHealth() <<std::endl;
    // std::cout << "Monster: Attack: " << monster.getAttack() << " Defence: " << monster.getDefense() << " Health: " << monster.getHealth() <<std::endl;
		std::cout << "\nHow do you wish to proceed?" << std::endl;
		std::cout << "1 - Attack" << std::endl;
		std::cout << "2 - Use Item" << std::endl;
		std::cout << "3 - Run Away" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1) { //Attack
			damage = rand() % player.getWep().getStat();
			if(playerDamage(damage) == 2) {
        return 2;
      }
		}			

		else if (choice == 2) {//Use item
			std::cout << "Not implimented" << std::endl;
    }

		else if (choice == 3) { //Run away, 50% success
			if (rand() % 2 == 0) {
				std::cout << "You run away." << std::endl;
				return 1; //run away
			}
				
			else {
				std::cout << "You fail to escape." << std::endl;
      }
		}

    int damage = rand() % (monster.getAttack() + 1);
    if(monsterDamage(damage) == 0) {
      return 0; //dead
    }
	}
}

int Dungeon::playerDamage(int damage) {
  if (damage != 0) {
    std::cout << "You did " << damage << " damage to " << monster.getName() << "." << std::endl;
    monster.subHealth(damage);

    if (monster.getHealth() == monster.getMaxHealth()) {
      std::cout << "You have slain the " << monster.getName() << std::endl;
      return 2; //win
    }
  }	

  else {
    std::cout << "Doh! you missed." << std::endl;
  }
}

int Dungeon::monsterDamage(int damage) {
  if (damage != 0 && monster.getHealth() > 0) {
    std::cout << monster.getName() << " did " << damage << " damage to you." << std::endl;
    player.subHealth(damage);

    if (player.getHealth() == player.getMaxHealth()) {
      std::cout << "You have died" << std::endl;
      return 0;  //dead
    }
  }

  else {
    std::cout << monster.getName() << " misses." << std::endl;
  }
}

Monster Dungeon::getMonster() { return monster; }

Player Dungeon::getPlayer() { return player; }