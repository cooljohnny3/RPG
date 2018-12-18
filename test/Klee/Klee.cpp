#include "klee/klee.h"

#include "../../src/headers/Dungeon.h"

int main() {
  Player player = Player();
  Dungeon dung = Dungeon(player, 1);
  int a;
  klee_make_symbolic(&a, sizeof(a), "a");
  return dung.combatAction(a);
}