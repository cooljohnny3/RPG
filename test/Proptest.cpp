#include <rapidcheck.h>
#include <fstream>

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
        gen::inRange<int>(10, 100),
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
        gen::makeShared<TestMenu>(gen::inRange(1, 3)),
        gen::arbitrary<Player>(),
        gen::inRange(0, 100));
    }
  };
} // namespace rc

std::istream& ignoreline(std::ifstream& in, std::ifstream::pos_type& pos) {
  pos = in.tellg();
  return in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getLastLine(std::ifstream& in) {
  std::ifstream::pos_type pos = in.tellg();

  std::ifstream::pos_type lastPos;
  while (in >> std::ws && ignoreline(in, lastPos))
      pos = lastPos;

  in.clear();
  in.seekg(pos);

  std::string line;
  std::getline(in, line);
  return line;
}

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

  // Combat is Interactive
  /*
    I think this is supposed to be working but I get the feeling Rapidcheck uses threads or something 
    which would cause the file checking to not work as intended
  */

  rc::check("Attack is run when player slects 1",
            [](Dungeon dung) {
              dung.getPlayer().setWep(Weapon("Test", 1, 1));
              dung.combatAction(1);
              std::ifstream f;
              std::string line = getLastLine(f);
              f.close();
              RC_ASSERT(line == "1");
            });

  rc::check("Use Item is run when player selects 2",
            [](Dungeon dung) {
              dung.combatAction(2);
              std::ifstream f;
              std::string line = getLastLine(f);
              f.close();
              RC_ASSERT(line == "2");
            });

  rc::check("Run Away is run when player selects 3",
            [](Dungeon dung) {
              dung.combatAction(3);
              std::ifstream f;
              std::string line = getLastLine(f);
              f.close();
              RC_ASSERT(line == "3");
            });        

  return 0;
}