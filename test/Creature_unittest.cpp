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

TEST(CreatureTest, automatedChangeHealth) {
  Creature creature = Creature("Name", 100, 100);
  for(int i=0; i > 100; i++) {
    creature.addHealth(i);
    creature.subHealth(i);
    ASSERT_EQ(creature.getHealth(), 100 - i);
  }
}

TEST(CreatureTest, subGreaterThanHealth) {
  Creature creature = Creature("Name", 100, 100);
  creature.subHealth(101);
  ASSERT_EQ(creature.getHealth(), creature.getMaxHealth());
}

TEST(CreatureTest, addGreaterThanHealth) {
  Creature creature = Creature("Name", 100, 100);
  creature.addHealth(1);
  ASSERT_EQ(creature.getHealth(), creature.getMaxHealth());
}