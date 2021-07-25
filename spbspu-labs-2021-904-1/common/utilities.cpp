#include "utilities.hpp"

#include <iostream>

std::istream &skipWS(std::istream &stream)
{
  while (std::isblank(stream.peek()))
  {
    stream.get();
  }
  return stream;
}
