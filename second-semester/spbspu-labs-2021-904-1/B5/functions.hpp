#ifndef B5_FUNCTIONS_HPP
#define B5_FUNCTIONS_HPP

#include <iosfwd>

#include "shape.hpp"

namespace details
{
  enum ShapeType
  {
    TRIANGLE,
    SQUARE,
    RECTANGLE
  };
  bool isTriangle(const Shape &shape);
  bool isSquare(const Shape &shape);
  bool isRectangle(const Shape &shape);
  bool isPentagon(const Shape &shape);
}

size_t countVertices(const Shapes &shapes);
size_t countShapes(const Shapes &shapes, const details::ShapeType &shapeType);
size_t getSquaredDistance(const Point &firstPoint, const Point &secondPoint);
void deletePentagons(Shapes &shapes);
std::vector<Point> getPointVector(const Shapes &shapes);

#endif
