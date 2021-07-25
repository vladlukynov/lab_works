#include "data-struct.hpp"

#include <iostream>

#include "utilities.hpp"

const int MAX_ABS_KEY_VALUE = 5;
const char SEPARATOR = ',';

bool CompareDataStructs::operator()(const DataStruct &firstStruct, const DataStruct &secondStruct)
{
  if (firstStruct.key1 != secondStruct.key1)
  {
    return firstStruct.key1 < secondStruct.key1;
  }
  else if (firstStruct.key2 != secondStruct.key2)
  {
    return firstStruct.key2 < secondStruct.key2;
  }
  else
  {
    return firstStruct.str.size() < secondStruct.str.size();
  }
}

int readKey(std::istream &stream)
{
  int key;
  stream >> key;
  if (!stream || (std::abs(key) > MAX_ABS_KEY_VALUE))
  {
    stream.setstate(std::ios_base::failbit);
  }
  return key;
}

std::string readStr(std::istream &stream)
{
  std::string str;
  std::getline(stream, str);
  if (!stream)
  {
    stream.setstate(std::ios_base::failbit);
  }
  return str;
}

std::istream &operator>>(std::istream &stream, DataStruct &dataStruct)
{
  std::istream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  stream >> skipWS;
  const int key1 = readKey(stream);
  if (!stream || (stream.get() != SEPARATOR))
  {
    stream.setstate(std::ios_base::failbit);
    return stream;
  }
  stream >> skipWS;
  const int key2 = readKey(stream);
  if (!stream || (stream.get() != SEPARATOR))
  {
    stream.setstate(std::ios_base::failbit);
    return stream;
  }
  stream >> skipWS;
  const std::string str = readStr(stream);
  if (!stream)
  {
    stream.setstate(std::ios_base::failbit);
    return stream;
  }
  dataStruct.key1 = key1;
  dataStruct.key2 = key2;
  dataStruct.str = str;
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const DataStruct &dataStruct)
{
  std::ostream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  stream << dataStruct.key1 << SEPARATOR << dataStruct.key2 << SEPARATOR << dataStruct.str;
  return stream;
}
