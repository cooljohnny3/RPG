#include <iostream>
#include <fstream>
#include "World.h"
#include "Dungeon.h"

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
	Dungeon dungeon = Dungeon(level);
	int status;
	char choice;

	std::cout << "You enter the dungeon..." << std::endl;

  // Start combat loop
  while(true) {
    status = dungeon.combat();

    if (status == 0) { std::cout << "You are revived in town.\n" << std::endl; }

    else if (status == 1) { std::cout << "You emerge from the dungeon.\n" << std::endl; }

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
          return;
        }
	    }
    }
  }
}

void World::save() const{
	std::string name;
	std::fstream f;
	bool valid = true;
	char choice;

  // Loops until a valid option has been reached
	while(valid){
		std::cout << "Enter a name: ";
		std::cin >> name;

		f.open("saves/" + name, std::fstream::in);

    // Checks to see if file exists
		if(f.peek() != std::ifstream::traits_type::eof()){
			std::cout << "A file with that name already exists, would you like to overwrite this? (Y/N)";
      while(choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n') {
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y')
          valid = false;

        else if(choice != 'N' || choice != 'n')
          f.close();

        else 
          std::cout << "Please answer Y/N" << std::endl;
      }
		}
		else
			valid = false;	
	}

	f.close();
  saveData(name);
}

void World::saveData(std::string name) const {
  std::fstream f;
	f.open("saves/" + name, std::fstream::out);

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

void World::load() const{
	std::string name;
	std::fstream f;
	char choice;
	bool valid = true;
	int stats[5] = {};

	while(valid){
		std::cout << "Enter the name of the file to load: ";
		std::cin >> name;

		f.open("saves/" + name, std::fstream::in);

		if(f.peek() != std::ifstream::traits_type::eof()){
			std::cout << "A file with that name already exists, would you like to overwrite it? (Y/N)";
			std::cin >> choice;
			if(choice == 'Y' || choice == 'y')
				valid = false;

			else
				f.close();	
		}
		else
			valid = false;	
	}
	f.open("saves/" + name, std::fstream::in);

	for(int i = 0; i < 5; i++)
		f >> stats[i];

  // TODO Fix this
	//player = new Player(stats[0], stats[1], stats[2], stats[3], stats[4]);

	f.close();
}