#include <iostream>
#include <fstream>
#include "headers/World.h"
#include "headers/Dungeon.h"

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
				player = new Player();
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

	while (choice != 5 && player->getHealth() > 0) {
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
				player->addHealth(5);
				std::cout << std::endl;
				break;
			case 3:		//status
				std::cout << "Health: " << player->getHealth() << std::endl;
				std::cout << "Level: " << player->getLevel() << std::endl;
				//std::cout << "XP to level: " << player->getXP() << std::endl; //Not implimented
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

  while(true) {
    status = dungeon.combat(player);

    if (status == 0) { std::cout << "You are revived in town.\n" << std::endl; }

    if (status == 1) { std::cout << "You emerge from the dungeon.\n" << std::endl; }

    else {
      while(true) {
        std::cout << "Continue to next level? (Y/N)" << std::endl;
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
          std::cout << "\nYou continue on..." << std::endl;
          dungeon.nextLevel(player);
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

void World::save(){
	std::string name;
	std::fstream f;
	bool valid = true;
	char choice;

	while(valid){
		std::cout << "Enter a name: ";
		std::cin >> name;

		f.open("saves/" + name, std::fstream::in);

		if(f.peek() != std::ifstream::traits_type::eof()){
			std::cout << "A file with that name already exists, would you like to overwrite this? (Y/N)";
			std::cin >> choice;
			if(choice == 'Y' || choice == 'y')
				valid = false;

			else
				f.close();	
		}
		else
			valid = false;	
	}

	f.close();

	f.open("saves/" + name, std::fstream::out);

	f << player->getName() << std::endl;
	f << player->getMaxHealth() << std::endl;
	f << player->getHealth() << std::endl;
	f << player->getLevel() <<  std::endl;
	f << player->getXp() << std::endl;

	f.close();
}

void World::load(){
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