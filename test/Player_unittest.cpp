#include "../src/headers/Player.h"
#include "gtest/gtest.h"

Player constructedPlayer = Player("Name", 100, 95, 10, 1000);
Weapon weapon = Weapon();
Shield shield = Shield();
Helm helm = Helm();
Body body = Body();
Pants pants = Pants();

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
  EXPECT_EQ(weapon, constructedPlayer.getWep());
}

TEST(PlayerTest, getShield) {
  EXPECT_EQ(shield, constructedPlayer.getShield());
}

TEST(PlayerTest, getHelm) {
  EXPECT_EQ(helm, constructedPlayer.getHelm());
}

TEST(PlayerTest, getBody) {
  EXPECT_EQ(body, constructedPlayer.getBody());
}

TEST(PlayerTest, getPants) {
  EXPECT_EQ(pants, constructedPlayer.getPants());
}

/*
	Weapon setWep(Weapon);
	Shield setShield(Shield);
	Helm setHelm(Helm);
	Body setBody(Body);
	Pants setPants(Pants);
*/