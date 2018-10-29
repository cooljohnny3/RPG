#include "../src/headers/Monster.h"
#include "gtest/gtest.h"

int main() {
  for(int i=0; i < 100; i++) {
    Monster monster = Monster(i);
    std::cout << "Level " << i+1 << ": " << monster.getName() << " " << monster.getMaxHealth() << " " << monster.getAttack() << " " << monster.getDefense() << std::endl;
  }
}