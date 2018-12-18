#include "../src/headers/World.h"
#include "Menu.hpp"
#include "gtest/gtest.h"

#include <fstream>

Player player = Player("TEST", 100, 95, 10, 15, 1000);
World world = World(player, new TestMenu(1), new TestMenu(4));

TEST(WorldTest, saving_on_loaded_menu_choice) {
  world.handleLoadedMenu(4);
  std::fstream f;
  f.open("saves/TEST", std::fstream::in);
  f.close();
  ASSERT_EQ(f.peek(), std::ifstream::traits_type::eof());
}

TEST(WorldTest, loading_on_menu_choice) {
  world.handleLoadedMenu(2);
  ASSERT_EQ(player.getName(), "TEST");
  ASSERT_EQ(player.getMaxHealth(), 100);
  ASSERT_EQ(player.getHealth(), 95);
  ASSERT_EQ(player.getLevel(), 10);
  ASSERT_EQ(player.getDeepestLevel(), 15);
  ASSERT_EQ(player.getXp(), 1000);
  ASSERT_EQ(player.getWep(), Weapon("Wooden_Sword", 1, 5));
  ASSERT_EQ(player.getShield(), Shield());
  ASSERT_EQ(player.getHelm(), Helm());
  ASSERT_EQ(player.getBody(), Body());
  ASSERT_EQ(player.getPants(), Pants());
}