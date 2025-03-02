#include "Circle.hpp"

#include <SDL2/SDL.h>

#include <cmath>
#include <cstdint>

Circle::Circle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {}

Circle::~Circle() {}

void Circle::fillCircle(SDL_Surface* surface, Circle circle, uint32_t color) {
  double radiusSquared = pow(circle.radius, 2);
  for (int x = circle.x - circle.radius; x <= circle.x + circle.radius; x++) {
    for (int y = circle.y - circle.radius; y < circle.y + circle.radius; y++) {
      double distanceCentreSquared =
          pow(x - circle.x, 2) + pow(y - circle.y, 2);
      if (distanceCentreSquared < radiusSquared) {
        SDL_Rect pixel = (SDL_Rect){x, y, 1, 1};
        SDL_FillRect(surface, &pixel, color);
      }
    }
  }
}