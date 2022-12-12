# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

Welcome to Prateek's Snake Game! This is the Capstone Project that I've done for Udacity's C++ Nanodegree program. In this program, I was given sample code of Snake Game in which my task was to implement more features based on the project's rubric criteria. This project demonstrates that the user can implement different applications/features on their own.

In this Snake Game, the goal is to try to obtain as many points as possible without losing. In this game, losing means hiting any of the borders, hitting an object (appears black), and accumulating two damage points. There are blocks that appear which are damage blocks and they will slow your snake down and build damage. There is a damage counter at the top of the window as well as FPS/score display. 

When you start the game, a text screen will appear and you will need to press "OK" to start the game. In addition, when one damage point is accumulated, a warning message will appear telling you to be careful.

Now then, lets play, shall we?!

## C++ Nanodegree Capstone Project Rubric Points

1. "The project demonstrates an understanding of C++ functions and control structures." This can be seen all over the program, for example, in game.cpp at lines 23-27, the SnakeIntro() is used in line 39.

2. "The project uses Object Oriented Programming techniques." For example, in game.cpp, in Update() on line 110, the snake object is being used to call its attribute for decreasing snake speed.

3. "Classes use appropriate access specifiers for class members." For example, in game.h on lines 19-20, two new variables: damage (int) and happen (bool) are declared under public for eventual use in Renderer::UpdateWindowTitle() in the renderer.cpp file.

4. "Class constructors utilize member initialization lists." In game.cpp, under the Game() constructor at lines 13-14, both member variables: random_w and random_h have been modified to make sure that objects, food, and bad-food are not placed on the wall borders. These member variables are initialized using member initialization lists.

5. "Classes abstract implementation details from their interfaces." If you look at all of my newly implemented member functions, you will see comments that document their purpose. For example, in game.cpp, on line 136, the ObjectPlacement() function has a comment that explains its application.

6. "Classes encapsulate behavior." This entire Snake Game is comprised of different classes: game, renderer, snake, etc. Each of these classes connect to one another through member attributes/functions in order to bring about the final output. An example of my implementation of this is in renderer.cpp on line 95, where my Renderer::UpdateWindowTitle() function is taking in parameters using pass by reference/value, and I pass the exact snake object that is used throughout the code. This ensures that member variables are being updated properly, especially one the function is finished.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
