#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

const int WIDTH = 900, HEIGHT = 600;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window =
      SDL_CreateWindow("3D Sphere Animation", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  SDL_Surface* screen = SDL_GetWindowSurface(window);
  SDL_Delay(5000);

  return 0;
}
