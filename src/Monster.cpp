#include <iostream>
#include <vector>
#include <limits>
#include "headers/Monster.h"

Monster::Monster() {
	setName("default");
}

Monster::Monster(int level) {
  srand(time(NULL));
	std::fstream monsters("resources/Monsters.dat");
	std::string name;
  // Number of lines in Monster.dat
  int numOfLines = 11;
  int lineNumber = rand() % numOfLines + 1;
	if (monsters.is_open()) {
    GotoLine(monsters, lineNumber);
    monsters >> name;
    setName(name);
    monsters.close();
    generate(level);
	}
}

// For each level add a point randonly to max health, strength, and defense
void Monster::generate(int level) {
  std::vector<int> stats = {10, 1, 0};
  int temp;
  for(int i=0; i < level; i++) {
    temp = rand() % 3;
    stats[temp]++;
  }
  setMaxHealth(stats[0]);
  setAttack(stats[1]);
  setDefense(stats[2]);
}

std::fstream& Monster::GotoLine(std::fstream& file, int num) const{
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; i++){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}