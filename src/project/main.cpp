#include <SDL2/SDL.h>

#include <cmath>
#include <iostream>

#include "Circle.hpp"

const int WIDTH = 1920, HEIGHT = 1080;
const uint32_t COLOR_BLUE = 0xFF0000FF;
const uint32_t COLOR_BLACK = 0x00000000;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window =
      SDL_CreateWindow("3D Sphere Animation", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

  SDL_Surface* screen = SDL_GetWindowSurface(window);
  SDL_Rect erase_rect = (SDL_Rect){0, 0, WIDTH, HEIGHT};
  Circle circle = Circle(180, 200, 80);

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
      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            circle.radius += 5;
            break;
          case SDLK_DOWN:
            circle.radius -= 5;
            break;
          case SDLK_a:
            circle.x -= 5;
            break;
          case SDLK_d:
            circle.x += 5;
            break;
          case SDLK_w:
            circle.y -= 5;
            break;
          case SDLK_s:
            circle.y += 5;
            break;
          case SDLK_q:
            for (double i = 0; i < 2 * M_PI; i += 0.01) {
              circle.x += 0.5;
              circle.y = 500 + 80 * sin(i);
              SDL_FillRect(screen, &erase_rect, COLOR_BLACK);
              circle.fillCircle(screen, circle, COLOR_BLUE);
              SDL_UpdateWindowSurface(window);
              if (circle.x > 1920) {
                for (double j = 0; j < 2 * M_PI; j += 0.01) {
                  circle.x -= 0.5;
                  circle.y = 500 + 80 * sin(j);
                  SDL_FillRect(screen, &erase_rect, COLOR_BLACK);
                  circle.fillCircle(screen, circle, COLOR_BLUE);
                  SDL_UpdateWindowSurface(window);
                }
                if (circle.x < 0) {
                  break;
                }
              }
            }
            break;
          case SDLK_ESCAPE:
            simRunning = 0;
            break;
        }
      }
    }
    SDL_FillRect(screen, &erase_rect, COLOR_BLACK);
    circle.fillCircle(screen, circle, COLOR_BLUE);

    SDL_UpdateWindowSurface(window);
  }

  return 0;
}
