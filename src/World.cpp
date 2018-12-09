#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "World.h"
#include "Dungeon.h"
#include "Functions.hpp"

World::World(){}

World::~World(){}

void World::mainMenu(){
	int choice = 0;

	while (choice != 3) {
		std::cout << "Welcome to RPG!" << std::endl;
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 - New Game" << std::endl;
		std::cout << "2 - Load save" << std::endl;
		std::cout << "3 - Quit" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice){
			case 1:		//New Game
				player = Player();
        player.createPlayer();
				loadedMenu();
				break;
			case 2:		//Load
				load();
				loadedMenu();
				break;
			case 3:		//Quit
				std::cout << "Bye!" << std::endl;
				break;
			default:
				std::cout << "Please enter a valid number.\n" << std::endl;	
		}
	}			
}

void World::loadedMenu() {
	int choice = 0;

	while (choice != 5 && player.getHealth() > 0) {
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1 - Enter dungeon" << std::endl;
		std::cout << "2 - Rest Up" << std::endl;
		std::cout << "3 - Status" << std::endl;
		std::cout << "4 - Save" << std::endl;
		std::cout << "5 - Quit" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice){
			case 1:		//enter dungeon
				enterDung(0);
				break;
			case 2:		//rest
				player.addHealth(5);
				std::cout << std::endl;
				break;
			case 3:		//status
				std::cout << "Health: " << player.getHealth() << std::endl;
				std::cout << "Level: " << player.getLevel() << std::endl;
				//std::cout << "XP to level: " << player.getXP() << std::endl; //Not implimented
				std::cout << std::endl;
				break;
			case 4:		//save
				save();
				break;
			case 5:		//Exit
				break;
			default:
				std::cout << "Please enter a valid number.\n" << std::endl;	
		}
	}
}

void World::enterDung(int level) {
	Dungeon dungeon = Dungeon(player, level);
	int status;
	char choice;

	std::cout << "You enter the dungeon..." << std::endl;

  // Start combat loop
  while(status != 1 || status != 2) {
    status = dungeon.combat();

    if (status == 1) { std::cout << "You are revived in town.\n" << std::endl; }

    else if (status == 2) { std::cout << "You emerge from the dungeon.\n" << std::endl; }

    else {
      while(true) {
        std::cout << "Continue to next level? (Y/N)" << std::endl;
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
          std::cout << "\nYou continue on..." << std::endl;
          dungeon.nextLevel();
          break;
        }

        else if(choice == 'n' || choice == 'N') {
          std::cout << "You emerge from the dungeon.\n" << std::endl;
          save();
          return;
        }
	    }
    }
  }
}

void World::save() const{
  std::fstream f;
	f.open("saves/" + player.getName(), std::fstream::out);
  
	f << player.getName() << std::endl;
	f << player.getMaxHealth() << std::endl;
	f << player.getHealth() << std::endl;
	f << player.getLevel() <<  std::endl;
  f << player.getDeepestLevel() << std::endl;
	f << player.getXp() << std::endl;
  f << player.getWep() << std::endl;
  f << player.getShield() << std::endl;
  f << player.getHelm() << std::endl;
  f << player.getBody() << std::endl;
  f << player.getPants() << std::endl;

	f.close();
}

void World::load() {
	std::string name;
	std::fstream f;

  // Loops until a valid file has been selected
	do {
		std::cout << "Enter the name of the file to load: ";
		std::cin >> name;

		f.open("saves/" + name, std::fstream::in);

    // Checks to see if file exists
		if(f.peek() != std::ifstream::traits_type::eof()){
      f.close();
		}
		else {
			std::cout << "A file with that name does not exist.  Please enter a valid name." << std::endl;
    }
	} while(f.is_open());
  loadData(name);
}

// Requires a valid save file name
void World::loadData(std::string name) {
  std::fstream f;
  std::string line;
  std::vector<std::string> stats;
  std::vector<std::string> temp;

	f.open("saves/" + name, std::fstream::in);

	while(std::getline(f, line)) {
    temp = split(line, ' ');
    stats.reserve(stats.size() + temp.size()); // preallocate memory
    stats.insert(stats.end(), temp.begin(), temp.end());
  }

  player = Player(stats[0], std::stoi(stats[1]), std::stoi(stats[2]), std::stoi(stats[3]), std::stoi(stats[4]));
  player.setDeepestLevel(std::stoi(stats[5]));
  player.setWep(Weapon(stats[6], std::stoi(stats[7]), std::stoi(stats[8])));
  player.setShield(Shield(stats[9], std::stoi(stats[10]), std::stoi(stats[11])));
  player.setHelm(Helm(stats[12], std::stoi(stats[13]), std::stoi(stats[14])));
  player.setBody(Body(stats[15], std::stoi(stats[16]), std::stoi(stats[17])));
  player.setPants(Pants(stats[18], std::stoi(stats[19]), std::stoi(stats[20])));
  player.calculateStats();

	f.close();
}