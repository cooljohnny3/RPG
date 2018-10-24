#include "../src/headers/Player.h"
#include "gtest/gtest.h"

Player constructedPlayer = Player("Name", 100, 95, 10, 1000);
Weapon weapon = Weapon("Sword", 1, 1);
Shield shield = Shield("Sheild", 1, 1);
Helm helm = Helm("Helm", 1, 1);
Body body = Body("Body", 1, 1);
Pants pants = Pants("Pants", 1, 1);

TEST(PlayerTest, getName) {
  EXPECT_EQ("Name", constructedPlayer.getName());
}

TEST(PlayerTest, getMaxHealth) {
  EXPECT_EQ(100, constructedPlayer.getMaxHealth());
}

TEST(PlayerTest, getHealth) {
  EXPECT_EQ(95, constructedPlayer.getHealth());
}

TEST(PlayerTest, getLevel) {
  EXPECT_EQ(10, constructedPlayer.getLevel());
}

TEST(PlayerTest, getXp) {
  EXPECT_EQ(1000, constructedPlayer.getXp());
}

TEST(PlayerTest, getWep) {
  constructedPlayer.setWep(weapon);
  EXPECT_EQ(weapon, constructedPlayer.getWep());
}

TEST(PlayerTest, getShield) {
  constructedPlayer.setShield(shield);
  EXPECT_EQ(shield, constructedPlayer.getShield());
}

TEST(PlayerTest, getHelm) {
  constructedPlayer.setHelm(helm);
  EXPECT_EQ(helm, constructedPlayer.getHelm());
}

TEST(PlayerTest, getBody) {
  constructedPlayer.setBody(body);
  EXPECT_EQ(body, constructedPlayer.getBody());
}

TEST(PlayerTest, getPants) {
  constructedPlayer.setPants(pants);
  EXPECT_EQ(pants, constructedPlayer.getPants());
}