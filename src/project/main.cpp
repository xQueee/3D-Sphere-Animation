#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#include "Circle.hpp"

const int WIDTH = 900, HEIGHT = 600;
const uint32_t COLOR_BLUE = 0xFF0000FF;
const uint32_t COLOR_BLACK = 0x00000000;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window =
      SDL_CreateWindow("3D Sphere Animation", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

  SDL_Surface* screen = SDL_GetWindowSurface(window);
  SDL_Rect erase_rect = (SDL_Rect){0, 0, WIDTH, HEIGHT};
  Circle circle = Circle(200, 200, 80);

  circle.fillCircle(screen, circle, COLOR_BLUE);

  SDL_UpdateWindowSurface(window);

  bool simRunning = 1;
  SDL_Event event;

  while (simRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        simRunning = 0;
      }
      if (event.type == SDL_MOUSEMOTION && event.motion.state != 0) {
        circle.x = event.motion.x;
        circle.y = event.motion.y;
      }
    }
    SDL_FillRect(screen, &erase_rect, COLOR_BLACK);
    circle.fillCircle(screen, circle, COLOR_BLUE);

    SDL_UpdateWindowSurface(window);
    SDL_Delay(10);
  }

  return 0;
}
