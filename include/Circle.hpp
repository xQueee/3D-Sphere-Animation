#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED

#include <SDL2/SDL.h>

#include <cstdint>

class Circle {
 public:
  Circle(double x, double y, double radius);
  ~Circle();

  void fillCircle(SDL_Surface* surface, Circle circle, uint32_t color);

  double x;
  double y;
  double radius;
};

#endif  // CIRCLE_HPP_INCLUDED
