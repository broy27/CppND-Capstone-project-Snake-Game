#include <iostream>
#include "controller.h"
#include "game.h"
#include "menu.h"
#include "renderer.h"
#include <fstream>
#include "snake.h"

int Game::diffLevel=1; //Default difficulty level low
int Snake::snakeColor=3; //Default white
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Menu menu;
  while(1)
  {
    menu.optionMenu();
    int gameOption = menu.getOption();
    switch(gameOption)
    {
      case 1:
      {
        menu.difficultyLevel();
        std::cout << "Game starts"<<std::endl;
        Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
        Controller controller;
        Game game(kGridWidth, kGridHeight);
        game.Run(controller, renderer, kMsPerFrame);
        //std::cout << "Game has terminated successfully!\n";
        std::cout << "Score: " << game.GetScore() << "\n";
        std::cout << "Size: " << game.GetSize() << "\n";
        break;
      }
      case 2:
      {
        //print high score
        std::ifstream input("highscore.txt");
        std::string tempScore="";
        int highScore = 0 ;
        input>>tempScore;
        if(tempScore!="")
          highScore = std::stoi(tempScore);
        std::cout << "High Score: " << highScore << "\n";
        continue;
        break;
      }
      case 3:
      {
        menu.snakeColorOption();
        continue;
        break;

      }
      case 4:
      {
        std::cout << "Game has been terminated"<<std::endl;
        return 0;
        break;
      }
      default:
      {
        std::cerr << "Please try again"<<std::endl;
        continue;
        break;
      }
    }
  

  
 
  }
   return 0;
}