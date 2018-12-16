#include "../src/headers/Player.h"
#include "gtest/gtest.h"

Player constructedPlayer = Player("Name", 100, 95, 10, 11,  1000);
Weapon weapon = Weapon("Sword", 1, 1);
Shield shield = Shield("Sheild", 1, 1);
Helm helm = Helm("Helm", 1, 1);
Body body = Body("Body", 1, 1);
Pants pants = Pants("Pants", 1, 1);

void addEquipment() {
  constructedPlayer.setWep(weapon);
  constructedPlayer.setShield(shield);
  constructedPlayer.setHelm(helm);
  constructedPlayer.setBody(body);
  constructedPlayer.setPants(pants);
}

TEST(PlayerTest, calculateStats) {
  addEquipment();
  constructedPlayer.calculateStats();
  ASSERT_EQ(2, constructedPlayer.getAttack());
  ASSERT_EQ(4, constructedPlayer.getDefense());
}

// Should test create_player function 