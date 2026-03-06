#pragma once

#include <SDL3/SDL.h>

namespace ff
{
class Canvas
{
public:
  Canvas(int width, int height);
  ~Canvas();

  SDL_Event event{};

  void clear();
  void present();
  
  void add_block();

private:
  int width_ = 0;
  int height_ = 0;
  
  SDL_Window* window_ = nullptr;
  SDL_Renderer* renderer_ = nullptr;
};
} // namespace ff
