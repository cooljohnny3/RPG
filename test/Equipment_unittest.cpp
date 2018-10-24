#include "../src/headers/Equipment.h"
#include "gtest/gtest.h"

Equipment emptyEquipment = Equipment();
Equipment constructedEquipment = Equipment("Example", 10, 8);

TEST(EquipmentTest, getName) {
  EXPECT_EQ ("", emptyEquipment.getName());
  EXPECT_EQ ("Example", constructedEquipment.getName());
}

TEST(EquipmentTest, getStat) {
  EXPECT_EQ (0, emptyEquipment.getStat());
  EXPECT_EQ (8, constructedEquipment.getStat());
}

TEST(EquipmentTest, getReq) {
  EXPECT_EQ (0, emptyEquipment.getReq());
  EXPECT_EQ (10, constructedEquipment.getReq());
}