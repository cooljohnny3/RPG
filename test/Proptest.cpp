#include <rapidcheck.h>

#include "Dungeon.h"

// Definitions for generators
// NOTE: Must be in rc namespace!
namespace rc {
  template<>
  struct Arbitrary<Player> {
    static Gen<Player> arbitrary() {
      // Think supposed to be pointer but works without?
      return gen::construct<Player>(
        gen::arbitrary<std::string>(),
        gen::inRange(0, 100),
        gen::inRange(0, 100),
        gen::inRange(0, 100),
        gen::inRange(0, 100));
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
              RC_ASSERT(initialHealth >= dung.getPlayer().getHealth());
            });

  return 0;
}