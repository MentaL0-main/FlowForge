#include <SDL3/SDL.h>

#include <SDL3/SDL_events.h>
#include <canvas.hpp>

ff::Canvas canvas(900, 800);

bool running = true;

int main(int argc, char* argv[])
{
  while (running)
  {
    while (SDL_PollEvent(&canvas.event))
    {
      if (canvas.event.type == SDL_EVENT_QUIT)
      {
        running = false;
      }
    }

    canvas.clear();

    canvas.present();
  }

  return 0;
}
