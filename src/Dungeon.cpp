#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Dungeon.h"

Dungeon::Dungeon() {
  menu = std::make_shared<DungeonMenu>();
  level = 1; 
}

Dungeon::Dungeon(std::shared_ptr<Menu> menu, Player player, int l) {
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

int Dungeon::combatAction(int choice, int seed) {
  std::fstream f;
	f.open("logs/log.txt", std::fstream::app);

  if(seed != 0) {
    srand(seed);
  }
  else {
    srand(time(NULL));
  }
  
  int damage;
  if (choice == 1) { //Attack
    f << "1" << std::endl;
    f.close();
    // calculate damage
    damage = rand() % player.getWep().getStat();
    if(playerDamage(damage) == 1) {
      return 3; // Monster killed
    }
  }			

  else if (choice == 2) { // Use item
    f << "2" << std::endl;
    f.close();
    std::cout << "Not implimented" << std::endl;
  }

  else if (choice == 3) { // Run away, 50% success
    f << "3" << std::endl;
    f.close();
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

Monster Dungeon::getMonster() { return monster; }

Player Dungeon::getPlayer() { return player; }