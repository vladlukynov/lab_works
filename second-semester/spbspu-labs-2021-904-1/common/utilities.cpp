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

StreamGuard::StreamGuard(std::istream &stream) :
  stream_(stream),
  flags_(stream.flags())
{}

StreamGuard::~StreamGuard()
{
  stream_.setf(flags_);
}
