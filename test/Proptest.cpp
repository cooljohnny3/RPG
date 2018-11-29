#include <rapidcheck.h>

#include "Dungeon.h"

// Definitions for generators
// NOTE: Must be in rc namespace!
namespace rc {
  template<>
  struct Arbitrary<Player> {
    static Gen<Player> arbitrary() {
      const auto maxHealth = gen::inRange<int>(10, 100);
      // Think supposed to be pointer but works without?
      return gen::construct<Player>(
        gen::arbitrary<std::string>(),
        maxHealth,
        gen::inRange<int>(1, 100),  // Ideally would want the max of this to be max health
        gen::inRange<int>(1, 100),
        gen::inRange<int>(0, 100));
    }
  };

  template<>
  struct Arbitrary<Dungeon> {
    static Gen<Dungeon> arbitrary() {
      // Think supposed to be pointer but works without?
      return gen::construct<Dungeon>(
        gen::arbitrary<Player>(),
        gen::inRange(0, 100));
    }
  };
} // namespace rc

int main() {
  rc::check("monster health should remain unchanged",
            [](Dungeon dung) {
              int initialHealth = dung.getMonster().getHealth();
              dung.playerDamage(0);
              RC_ASSERT(initialHealth == dung.getMonster().getHealth());
            });

  rc::check("monster health should should decrease",
            [](Dungeon dung) {
              int initialHealth = dung.getMonster().getHealth();
              dung.playerDamage(1);
              RC_ASSERT(initialHealth >= dung.getMonster().getHealth());
            });

  rc::check("player health should remain unchanged",
            [](Dungeon dung) {
              int initialHealth = dung.getPlayer().getHealth();
              dung.monsterDamage(0);
              RC_ASSERT(initialHealth == dung.getPlayer().getHealth());
            });

  rc::check("player health should should decrease",
            [](Dungeon dung) {
              int initialHealth = dung.getPlayer().getHealth();
              dung.monsterDamage(1);
              if(initialHealth == 1) {
                RC_ASSERT(dung.getPlayer().getHealth() == dung.getPlayer().getMaxHealth());
              }
              else {
                RC_ASSERT(initialHealth >= dung.getPlayer().getHealth());
              }
            });

  return 0;
}