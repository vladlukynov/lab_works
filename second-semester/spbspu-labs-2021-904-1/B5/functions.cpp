#include "functions.hpp"

#include <algorithm>
#include <numeric>

const size_t TRIANGLE_VERTICES = 3;
const size_t RECTANGLE_VERTICES = 4;
const size_t PENTAGON_VERTICES = 5;

bool details::isTriangle(const Shape &shape)
{
  return shape.size() == TRIANGLE_VERTICES;
}

bool details::isSquare(const Shape &shape)
{
  return isRectangle(shape)
      && (getSquaredDistance(shape[0], shape[1]) == getSquaredDistance(shape[1], shape[2]));
}

bool details::isRectangle(const Shape &shape)
{
  return (shape.size() == RECTANGLE_VERTICES)
      && (getSquaredDistance(shape[0], shape[1]) == getSquaredDistance(shape[2], shape[3]))
      && (getSquaredDistance(shape[1], shape[2]) == getSquaredDistance(shape[0], shape[3]))
      && (getSquaredDistance(shape[0], shape[2]) == getSquaredDistance(shape[1], shape[3]));
}

bool details::isPentagon(const Shape &shape)
{
  return shape.size() == PENTAGON_VERTICES;
}

size_t countVertices(const Shapes &shapes)
{
  return std::accumulate(shapes.begin(), shapes.end(), 0,
      [](int sum, const Shape &shape)
      {
          sum += shape.size();
          return sum;
      });
}

size_t countShapes(const Shapes &shapes, const details::ShapeType &shapeType)
{
  if (shapeType == details::TRIANGLE)
  {
    return std::count_if(shapes.begin(), shapes.end(),
        [](const Shape &shape)
        {
          return details::isTriangle(shape);
        });
  }
  if (shapeType == details::SQUARE)
  {
    return std::count_if(shapes.begin(), shapes.end(),
        [](const Shape &shape)
        {
          return details::isSquare(shape);
        });
  }
  if (shapeType == details::RECTANGLE)
  {
    return std::count_if(shapes.begin(), shapes.end(),
        [](const Shape &shape)
        {
          return details::isRectangle(shape);
        });
  }
  return 0;
}

size_t getSquaredDistance(const Point &firstPoint, const Point &secondPoint)
{
  return (firstPoint.x - secondPoint.x) * (firstPoint.x - secondPoint.x) + (firstPoint.y - secondPoint.y) * (firstPoint.y - secondPoint.y);
}

void deletePentagons(Shapes &shapes)
{
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
      [](const Shape &shape)
      {
        return details::isPentagon(shape);
      }),
      shapes.end());
}

std::vector<Point> getPointVector(const Shapes &shapes)
{
  std::vector<Point> pointVector;
  pointVector.reserve(shapes.size());
  std::for_each(shapes.begin(), shapes.end(),
      [&pointVector](const Shape &shape)
      {
        pointVector.push_back(shape[0]);
      });
  return pointVector;
}
