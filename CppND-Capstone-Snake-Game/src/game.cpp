#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <chrono>


//Prateek Code: the random_w and random_h have been adjusted to account for foods, objects, and bad foods
//not appearing on the wall borders
Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(1, static_cast<int>(grid_width - 2)),
      random_h(1, static_cast<int>(grid_height - 2)) 
{
  //Prateek Code: when the constructor executes, the food, object, and bad food will get placed via functions
  PlaceFood();
  ObjectPlacement();
  PlaceBadFood();
}

//Prateek Code: Introduction to the Snake Game Function
std::string SnakeIntro() {
	std::string intro_statement = "Welcome to the Snake Game. In this game, you control a snake that is looking for food. \nUsing the 'W', 'A', 'S', and 'D' keyboard characters, you can move the snake up, left, down, or right. \nWhen you eat a piece of food, your snake's tail will grow longer. \nIn addition, you will lose the game if you hit the wall borders or the black obstacle. \nAlso, there is bad food as well which can injure you, so make sure you don't get 2 damage hits otherwise you will lose. \nPress the 'OK' button to start.";
  
  	return intro_statement;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  
  //Prateek Code: Introduction to the Snake Game Display
  std::string intro_message = SnakeIntro();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Snake Game Introduction", intro_message.c_str(), renderer.sdl_window);

  while (running) {
    // SDL_GetTicks() Returns an unsigned 32-bit value representing the number of milliseconds since the SDL library initialized.
    frame_start = SDL_GetTicks();
    // Input, Update, Render - the main game loop.
    
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, object, bad_food);
    
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, damage, happen, snake);
      frame_count = 0;
      title_timestamp = frame_end;
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
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.01;
  }
  
  //Prateek Code: this is when the user hits the bad food and the damage increments
  else if (bad_food.x == new_x && bad_food.y == new_y) {
    PlaceBadFood();
    snake.speed -= 0.005;
    damage++;
  }
  
  //Prateek Code: this is when the user hits the object and the game will end
  else if (object.x == new_x && object.y == new_y) {
  	snake.alive = false;
  }
}

//Prateek Code: this code places the bad food on the grid
void Game::PlaceBadFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      bad_food.x = x;
      bad_food.y = y;
      return;
    }
  }
}   

//Prateek Code: this code places the object that automatically ends the game if the user hits it
void Game::ObjectPlacement() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      object.x = x;
      object.y = y;
      return;
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }