#include "../src/headers/Monster.h"
#include "gtest/gtest.h"

bool checkMonster(int level, Monster monster) {
  int attack = monster.getAttack() - 1;
  int defence = monster.getDefense();
  int maxHealth = monster.getMaxHealth() - 10;

  return (attack + defence + maxHealth) == level;
}

TEST(MonsterGen, automatedGen) {
  for(int i=0; i < 500; i++) {
    Monster monster = Monster(i);
    ASSERT_TRUE(checkMonster(i, monster));
  }
}