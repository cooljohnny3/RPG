#ifndef WORLD_H
#define WORLD_H

#include "./Player.h"

class World {
public:
	World();
	~World();
	void mainMenu();
	void loadedMenu();
	void enterDung(int);
	void save();
  void saveData(std::string);
	void load();
  void loadData(std::string);

private:
	Player* player;
};
#endif