#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t& newPosition) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void print(std::ostream& output) const = 0;
};
#endif
