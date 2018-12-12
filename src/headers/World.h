#ifndef WORLD_H
#define WORLD_H

#include "Menu.hpp"
#include "Player.h"

class World {
public:
	World();
  World(Menu*, Menu*);
	~World();
	void start();
	void loaded();
	void enterDung(int);
	void save() const;
	void load();

private:
  Menu *mainMenu;
  Menu *loadedMenu;
	Player player;
  void loadData(std::string);

};
#endif