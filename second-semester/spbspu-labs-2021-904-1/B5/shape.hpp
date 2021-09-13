#ifndef B5_SHAPE_HPP
#define B5_SHAPE_HPP

#include <iosfwd>
#include <vector>

struct Point
{
  int x, y;
};

using Shape = std::vector<Point>;
using Shapes = std::vector<Shape>;

std::istream &operator>>(std::istream &stream, Shape &shape);
std::ostream &operator<<(std::ostream &stream, const Shape &shape);

std::istream &operator>>(std::istream &stream, Point &point);
std::ostream &operator<<(std::ostream &stream, const Point &point);

struct ShapeComparator
{
  bool operator()(const Shape &firstShape, const Shape &secondShape);
};

#endif
