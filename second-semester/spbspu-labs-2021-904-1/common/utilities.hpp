#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <istream>

std::istream &skipWS(std::istream &stream);

class StreamGuard
{
public:
  StreamGuard(std::istream &stream);
  ~StreamGuard();
private:
  std::istream &stream_;
  std::ios::fmtflags flags_;
};

#endif
