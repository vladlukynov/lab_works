#define _USE_MATH_DEFINES

#include "circle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

Circle::Circle(double radius, const point_t& pos) :
  radius_(radius),
  pos_(pos)
{
  if (radius < 0)
  {
    throw std::invalid_argument("Thrown an exception: radius less than 0...");
  }
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return { radius_ * 2, radius_ * 2, pos_ };
}

void Circle::move(const point_t& newPosition)
{
  pos_ = newPosition;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::print(std::ostream& output) const
{
  output << "Circle" << "\n"
         << "Radius: " << radius_ << "\n"
         << "Center: " << "x: " << pos_.x
         << ", y: " << pos_.y << "\n\n";
}
