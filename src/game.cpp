#include "game.h"
#include <iostream>
#include <fstream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width-1)),
      random_h(0, static_cast<int>(grid_height-1)) {
  //Reading high score from highscore.txt 
  std::ifstream input("highscore.txt");
  std::string tempScore="";
  input>>tempScore;
  if(tempScore=="")
    highScore=0;
  else
    highScore = std::stoi(tempScore);
  input.close();
  PlaceFood();

}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {

    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, highScore);
      frame_count = 0;
      title_timestamp = frame_end;

      //pushing the highScore to the highscore.txt file
      std::ofstream output("highscore.txt");
      output<<highScore;
      output.close();
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    if(score>highScore) 
      highScore=score; 
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    if(diffLevel == 1)
      snake.speed += 0.02;
    else if(diffLevel == 2)
      snake.speed += 0.04;
    else if(diffLevel == 3)
      snake.speed += 0.06;

  }
}

int Game::GetScore() const { return score; }
int Game::GetHighScore() const { return highScore; }
int Game::GetSize() const { return snake.size; }







