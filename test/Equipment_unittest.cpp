#include "../src/headers/Equipment.h"
#include "gtest/gtest.h"

Equipment emptyEquipment = Equipment();
Equipment constructedEquipment1 = Equipment("Example", 10, 8);
Equipment constructedEquipment2 = Equipment("Example", 10, 8);

TEST(EquipmentTest, equals_operator) {
  ASSERT_FALSE(emptyEquipment == constructedEquipment1);
  ASSERT_TRUE(constructedEquipment1 == constructedEquipment2);
}