#include "circle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

lukyanov::Circle::Circle(double radius, const point_t &pos) :
  radius_(radius),
  pos_(pos)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Thrown an exception: radius less than 0");
  }
}

double lukyanov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

lukyanov::rectangle_t lukyanov::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, pos_};
}

void lukyanov::Circle::move(const point_t &newPosition)
{
  pos_ = newPosition;
}

void lukyanov::Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void lukyanov::Circle::print(std::ostream &output) const
{
  output << "Circle" << "\n"
         << "Radius: " << radius_ << "\n"
         << "Center: " << "x: " << pos_.x
         << ", y: " << pos_.y << "\n\n";
}

void lukyanov::Circle::scale(double coefficient)
{
  if (coefficient == 0)
  {
    throw std::invalid_argument("Scale error. Coefficient is 0");
  }
  if (coefficient < 0)
  {
    throw std::invalid_argument("Scale error. Coefficient is less than 0");
  }
  radius_ *= coefficient;
}
