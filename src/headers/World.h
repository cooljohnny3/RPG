#ifndef WORLD_H
#define WORLD_H

#include "Player.h"

class World {
public:
	World();
	~World();
	void mainMenu();
	void loadedMenu();
	void enterDung(int);
	void save() const;
	void load();

private:
	Player player;
  void saveData(std::string) const;
    void loadData(std::string);

};
#endif