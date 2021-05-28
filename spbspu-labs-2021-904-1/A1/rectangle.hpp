#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(double width, double height, const point_t& pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newPosition) override;
  void move(double dx, double dy) override;
  void print(std::ostream& output) const override;
private:
  double width_;
  double height_;
  point_t pos_;
};
#endif
