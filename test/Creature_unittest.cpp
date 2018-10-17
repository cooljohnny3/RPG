#include "../src/headers/Creature.h"
#include "gtest/gtest.h"

Creature defaultCreature = Creature();
Creature constructedCreature = Creature("Example", 100, 87);

TEST(CreatureTest, getMaxHealth) {
  EXPECT_EQ(10, defaultCreature.getMaxHealth());
  EXPECT_EQ(100, constructedCreature.getMaxHealth());
}

TEST(CreatureTest, getHealth) {
  EXPECT_EQ(10, defaultCreature.getHealth());
  EXPECT_EQ(87, constructedCreature.getHealth());
}

TEST(CreatureTest, getAttack) {
  EXPECT_EQ(1, defaultCreature.getAttack());
  EXPECT_EQ(100, constructedCreature.getAttack());
}

TEST(CreatureTest, getDefense) {
  EXPECT_EQ(0, defaultCreature.getDefense());
  EXPECT_EQ(100, constructedCreature.getDefense());
}