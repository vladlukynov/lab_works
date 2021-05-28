#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

lukyanov::Rectangle::Rectangle(double width, double height, const point_t &pos) :
  width_(width),
  height_(height),
  pos_(pos)
{
  if (width <= 0)
  {
    throw std::invalid_argument("Thrown an exception: incorrect parametres");
  }
  if (height_ <= 0)
  {
    throw std::invalid_argument("Thrown an exception: incorrect parametres");
  }
}

double lukyanov::Rectangle::getArea() const
{
  return width_ * height_;
}

lukyanov::rectangle_t lukyanov::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void lukyanov::Rectangle::move(const point_t &newPosition)
{
  pos_ = newPosition;
}

void lukyanov::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void lukyanov::Rectangle::print(std::ostream &output) const
{
  output << "Rectangle" << "\n"
         << "Width: " << width_
         << ", height: " << height_ << "\n"
         << "Center: " << "x: " << pos_.x
         << ", y: " << pos_.y << "\n\n";
}

void lukyanov::Rectangle::scale(double coefficient)
{
  if (coefficient == 0)
  {
    throw std::invalid_argument("Scale error. Coefficient is 0");
  }
  if (coefficient < 0)
  {
    throw std::invalid_argument("Scale error. Coefficient is less than 0");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}
