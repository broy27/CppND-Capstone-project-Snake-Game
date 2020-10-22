#include "menu.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "snake.h"
#include "game.h"

void Menu::optionMenu() 
{
  int options;
  std::cout << "====MENU====\n\n"
            << "Enter 1 to play \n"
            << "Enter 2 to view highscore\n"
            << "Enter 3 to change avatar \n"
            << "Enter 4 to Quit Game\n"
            << "Awaiting response ...\n"
            << std::endl;
  while (std::cin >> options) 
  {
    if (options == 1 || options == 2 || options == 3) 
    {
      break;
    }
    else
    {
        std::cerr << "Wrong Input" << std::endl;
        break;
    }
    
  }
  if (std::cin.fail()) 
  {
    options = 4;
    std::cerr << "Wrong Input" << std::endl;
  }
  gameOption = std::move(options);
};

int Menu::getOption() 
{ 
    return gameOption; 
}

void Menu::snakeColorOption() 
{
  int options;
  std::cout << "====Select Snake Color====\n\n"
            << "Enter 1 Red \n"
            << "Enter 2 Green\n"
            << "Enter 3 White\n"
            << "Awaiting response ...\n"
            << std::endl;
  while (std::cin >> options) 
  {
    if (options == 1 || options == 2 || options == 3) 
    {
      break;
    }
    else
    {
        std::cerr << "Wrong Input" << std::endl;
        break;
    }
  }
  if (std::cin.fail()) 
  {
    options = 3;
    std::cerr << "Wrong Input" << std::endl;
  }
  Snake::snakeColor = std::move(options);
};


void Menu::difficultyLevel() 
{
  int options;
  std::cout << "====Select Difficulty Level====\n\n"
            << "Enter 1 for low \n"
            << "Enter 2 for medium\n"
            << "Enter 3 for hard\n"
            << "Awaiting response ...\n"
            << std::endl;
  while (std::cin >> options) 
  {
    if (options == 1 || options == 2 || options == 3 || options == 4) 
    {
      break;
    }
    else
    {
        std::cerr << "Wrong Input. using medium level" << std::endl;
        options = 2;
        break;
    }
  }
  if (std::cin.fail()) 
  {
    options = 2;
    std::cerr << "Wrong Input" << std::endl;
  }
  Game::diffLevel = std::move(options);
};
