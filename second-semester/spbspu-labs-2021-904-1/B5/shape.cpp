#include "shape.hpp"

#include <iostream>

#include "utilities.hpp"
#include "functions.hpp"

const char SEPARATOR = ' ';
const char OPEN_BRACKET = '(';
const char SEMICOLON = ';';
const char CLOSE_BRACKET = ')';

std::istream &operator>>(std::istream &stream, Shape &shape)
{
  std::istream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  StreamGuard streamGuard(stream);
  stream >> std::noskipws;
  int countVertices = 0;
  Shape tempShape;
  stream >> countVertices;
  if (!stream)
  {
    stream.setstate(std::ios::failbit);
    return stream;
  }
  for (int i = 0; i < countVertices; i++)
  {
    Point tempPoint{};
    stream >> skipWS;
    stream >> tempPoint;
    tempShape.push_back(tempPoint);
  }
  shape = std::move(tempShape);
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const Shape &shape)
{
  std::ostream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  stream << shape.size() << SEPARATOR;
  for (size_t i = 0; i < shape.size(); i++)
  {
    stream << shape[i] << SEPARATOR;
  }
  return stream;
}

std::istream &operator>>(std::istream &stream, Point &point)
{
  std::istream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  StreamGuard streamGuard(stream);
  if (stream.get() != OPEN_BRACKET)
  {
    stream.setstate(std::ios::failbit);
    return stream;
  }
  stream >> skipWS >> point.x >> skipWS;
  if (!stream || (stream.get() != SEMICOLON))
  {
    stream.setstate(std::ios::failbit);
    return stream;
  }
  stream >> skipWS >> point.y >> skipWS;
  if (!stream || (stream.get() != CLOSE_BRACKET))
  {
    stream.setstate(std::ios::failbit);
    return stream;
  }
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const Point &point)
{
  std::ostream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  stream << OPEN_BRACKET << point.x << SEMICOLON << point.y << CLOSE_BRACKET;
  return stream;
}

bool ShapeComparator::operator()(const Shape &firstShape, const Shape &secondShape)
{
  if (details::isRectangle(firstShape) && details::isRectangle(secondShape))
  {
    if (details::isSquare(firstShape) && !details::isSquare(secondShape))
    {
      return true;
    }
  }
  return firstShape.size() < secondShape.size();
}
