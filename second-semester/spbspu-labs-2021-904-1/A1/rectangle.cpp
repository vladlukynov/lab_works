#include "rectangle.hpp"

#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t& pos) :
  width_(width),
  height_(height),
  pos_(pos)
{
  if ((width < 0) || (height < 0))
  {
    throw std::invalid_argument("Thrown an exception: width or height less than 0...");
  }
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const point_t& newPosition)
{
  pos_ = newPosition;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::print(std::ostream& output) const
{
  output << "Rectangle" << "\n"
         << "Width: " << width_
         << ", height: " << height_ << "\n"
         << "Center: " << "x: " << pos_.x
         << ", y: " << pos_.y << "\n\n";
}
