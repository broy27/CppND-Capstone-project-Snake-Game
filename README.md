# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Additional Functionality

1. Added a command line menu that allows the user to enter their desired options
2. Added support for maintaining a highscore by saving the highest score in a txt file.
3. Added feature to enable the user to select  difficulty level. user can choose low, medium and hard levels. 
   Level differs in terms of change of speed of the snake eveytime the snake consumes food
4. Added a feature where user can select snake avatar as per their choice. ( Red, Green and white options available)


## Rubric Points Addressed

1. The project demonstrates an understanding of C++ functions and control structures:    
      1. main.cpp: lines 20,24
      2. menu.cpp: lines 18,20
      3. renderer.cpp: line 62
      4. game.cpp : line 101
2. The project reads data from a file and process the data, or the program writes data to a file:      
      1. main.cpp: line 42
      2. game.cpp: lines 12, 56
3. The project accepts user input and processes the input:      
      1. Menu.cpp : line 8, Multiple functions written to accept and process user inputs
4. Classes use appropriate access specifiers for class members: 
      1. In line 39 of the Menu.cpp, a getter function is defined to access the private member of the Menu class 
      2. snake.h: line 29
      3. game.h: line 18,17
      4. game.cpp : line 112 
5. The project uses Object Oriented Programming techniques:    
      1. Menu.cpp: Wrote a class Menu which follows object orriented techniques.
      
     
