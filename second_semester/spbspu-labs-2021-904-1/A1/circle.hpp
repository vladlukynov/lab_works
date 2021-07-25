#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>

#include "shape.hpp"

class Circle :public Shape
{
public:
  Circle(double radius, const point_t& pos);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t& newPosition) override;
  void move(double dx, double dy) override;
  void print(std::ostream& output) const override;
private:
  double radius_;
  point_t pos_;
};
#endif
