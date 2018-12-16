#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class Menu {
  public:
    virtual int getChoice() = 0;

  private:
    virtual bool checkChoice(int) = 0;
};

class MainMenu : public Menu {
  public:
    int getChoice() {
      int choice;
      while(!checkChoice(choice)) {
        std::cout << "Welcome to RPG!" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1 - New Game" << std::endl;
        std::cout << "2 - Load save" << std::endl;
        std::cout << "3 - Quit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
      }
      return choice;
    }
  private:
    bool checkChoice(int choice) {
      return choice > 0 && choice < 4;
    }
};

class LoadedMenu : public Menu {
  public:
    int getChoice() {
      int choice;
      while(!checkChoice(choice)) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1 - Enter dungeon" << std::endl;
        std::cout << "2 - Rest Up" << std::endl;
        std::cout << "3 - Status" << std::endl;
        std::cout << "4 - Save" << std::endl;
        std::cout << "5 - Quit" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
      }
      return choice;
    }
  private:
    bool checkChoice(int choice) {
      return choice > 0 && choice < 6;
    }
};

class TestMenu : public Menu {
  private:
    int choice;
  public:
    TestMenu(int choice) {
      TestMenu::choice = choice;
    }

    int getChoice() {
      return choice;
    }

  private:
    bool checkChoice(int choice) { 
      if(choice) {
        return true; 
      }
      return false;
    }
};

class DungeonMenu : public Menu {
  public:
    int getChoice() {
      int choice;
      while(!checkChoice(choice)) {
        // std::cout << "Player: Attack: " << player.getAttack() << " Defence: " << player.getDefense() << " Health: " << player.getHealth() <<std::endl;
        // std::cout << "Monster: Attack: " << monster.getAttack() << " Defence: " << monster.getDefense() << " Health: " << monster.getHealth() <<std::endl;
        std::cout << "\nHow do you wish to proceed?" << std::endl;
        std::cout << "1 - Attack" << std::endl;
        std::cout << "2 - Use Item" << std::endl;
        std::cout << "3 - Run Away" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
      }
      return choice;
    }

  private:
    bool checkChoice(int choice) {
      return choice > 0 && choice < 4;
    }
};

#endif

/*
public class UserMenu implements Menu {
  int getChoice() {
    // what C++ code does now
  }
}

public class TestMenu implements Menu {
  public final int choice;
  public TestMenu(final int choice) {
     this.choice = choice;
  }

  int getChoice() {
    return choice;
  }
}

public class Dungeon {
  private final Menu menu;
  public Dungeon(final Menu menu) {
    this.menu = menu;
  }

  public int combatMenu() {
    return menu.getChoice();
  }
}
*/