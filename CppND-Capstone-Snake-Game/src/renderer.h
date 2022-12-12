#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include "SDL.h"
#include "snake.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &object, SDL_Point const &bad_food);
  void UpdateWindowTitle(int score, int fps, int& count, bool& happen, Snake& snake);
  SDL_Window *sdl_window;

 private:
  SDL_Renderer *sdl_renderer;
  
  //std::string intro_statement;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif