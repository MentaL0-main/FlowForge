#include <SDL3/SDL_render.h>
#include <canvas.hpp>

#include <SDL3/SDL.h>

#include <stdexcept>
#include <string>

namespace ff
{
Canvas::Canvas(int width, int height)
      : width_(width), height_(height)
{
  // Init SDL3
  if (!SDL_Init(SDL_INIT_VIDEO))
    throw std::runtime_error(std::string("SDL_Init(): ") + SDL_GetError() + '\n');

  // Init window
  window_ = SDL_CreateWindow("FlowForge",
                             width_, height_,
                             SDL_WINDOW_RESIZABLE);
  if (!window_)
    throw std::runtime_error(std::string("SDL_CreateWindow(): ") + SDL_GetError() + '\n');

  // Init renderer
  renderer_ = SDL_CreateRenderer(window_, nullptr);

  if (!renderer_)
    throw std::runtime_error(std::string("SDL_CreateRenderer(): ") + SDL_GetError() + '\n');
}

Canvas::~Canvas()
{
  if (renderer_) SDL_DestroyRenderer(renderer_);
  if (window_) SDL_DestroyWindow(window_);

  SDL_Quit();
}

void Canvas::clear()
{
  // TODO: Add dark theme
  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
  SDL_RenderClear(renderer_);
}

void Canvas::present()
{
  SDL_RenderPresent(renderer_);
}

void Canvas::add_block()
{
  // TODO: Add add block logic.
  // Type/Connect/Text
}

} // namespace ff
