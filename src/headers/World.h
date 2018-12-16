#ifndef WORLD_H
#define WORLD_H

#include "Menu.hpp"
#include "Player.h"

class World {
public:
	World();
  World(Player, Menu*, Menu*);
	~World();
	void start();
  void handleMainMenu(int);
	void loaded();
  void handleLoadedMenu(int);
	void enterDung(int);
	void save(std::string) const;
	void load();

private:
  Menu *mainMenu;
  Menu *loadedMenu;
	Player player;
  void loadData(std::string);

};
#endif