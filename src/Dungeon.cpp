#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Dungeon.h"

Dungeon::Dungeon() {
  menu = new DungeonMenu();
  level = 1; 
}

Dungeon::Dungeon(Menu* menu, Player player, int l) {
  Dungeon::menu = menu;
  Dungeon::player = player;
  level = l;
}

Dungeon::~Dungeon() {}

// Incriments the dungeon level and records the play's deepest level 
// if the next level is greater than the player's deepest depth
void Dungeon::nextLevel() {
  level++;
  if(level > player.getDeepestLevel()) {
    player.setDeepestLevel(level);
  }
}

// Main combat loop
int Dungeon::combat() {
  monster = Monster(level);
  int choice;
  int outcome;
	srand(time(NULL));

	std::cout << "You encounter " << monster.getName() << std::endl;

	while (true) {
    choice = menu->getChoice();
    outcome = combatAction(choice);
    if(outcome != 0) {
      // std::cout << "outcome= " << outcome << std::endl;
      return outcome;
    }
	}
}

// Called when the player deals damage to the monster
int Dungeon::playerDamage(int damage) {
  if (damage != 0) {
    std::cout << "You did " << damage << " damage to " << monster.getName() << "." << std::endl;
    monster.subHealth(damage);

    if (monster.getHealth() == monster.getMaxHealth()) {
      std::cout << "You have slain the " << monster.getName() << std::endl;
      return 1; //win
    }
  }	

  else {
    std::cout << "Doh! you missed." << std::endl;
  }
  return 0;
}

// Called when the monster deals damage to the player
int Dungeon::monsterDamage(int damage) {
  if (damage > 0) {
    std::cout << monster.getName() << " did " << damage << " damage to you." << std::endl;
    player.subHealth(damage);

    if (player.getHealth() == player.getMaxHealth()) {
      std::cout << "You have died" << std::endl;
      return 1;  //dead
    }
  }

  else {
    std::cout << monster.getName() << " misses." << std::endl;
  }
  return 0;
}

int Dungeon::combatAction(int choice) {
  int damage;
  if (choice == 1) { //Attack
    // calculate damage
    damage = rand() % player.getWep().getStat();
    if(playerDamage(damage) == 1) {
      return 3; // Monster killed
    }
  }			

  else if (choice == 2) { // Use item
    std::cout << "Not implimented" << std::endl;
  }

  else if (choice == 3) { // Run away, 50% success
    if (rand() % 2 == 0) {
      std::cout << "You run away." << std::endl;
      return 2; // run away
    }
      
    else {
      std::cout << "You fail to escape." << std::endl;
    }
  }

  // Monster attacks
  damage = rand() % (monster.getAttack() + 1);
  if(monsterDamage(damage) == 1) {
    return 1; // dead
  }
  return 0;  // Nothing
}

Monster Dungeon::getMonster() { return monster; }

Player Dungeon::getPlayer() { return player; }