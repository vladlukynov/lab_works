#include "data-struct.hpp"

#include <iostream>

#include "utilities.hpp"

const int MIN_KEY_VALUE = -5;
const int MAX_KEY_VALUE = 5;
const char SEPARATOR = ',';

bool CompareDataStructs::operator()(const DataStruct &firstStruct, const DataStruct &secondStruct)
{
  if (firstStruct.key1 != secondStruct.key1)
  {
    return firstStruct.key1 < secondStruct.key1;
  }
  if (firstStruct.key2 != secondStruct.key2)
  {
    return firstStruct.key2 < secondStruct.key2;
  }
  return firstStruct.str.size() < secondStruct.str.size();
}

int readKey(std::istream &stream, int minKeyValue, int maxKeyValue)
{
  int key;
  stream >> key;
  if (!stream || (key < minKeyValue) || (key > maxKeyValue))
  {
    stream.setstate(std::ios::failbit);
  }
  return key;
}

std::istream &operator>>(std::istream &stream, DataStruct &dataStruct)
{
  std::istream::sentry sentry(stream);
  if (!sentry)
  {
    return stream;
  }
  StreamGuard streamGuard(stream);
  stream >> std::noskipws;
  const int key1 = readKey(stream, MIN_KEY_VALUE, MAX_KEY_VALUE);
  if (!stream || (stream.get() != SEPARATOR))
  {
    stream.setstate(std::ios::failbit);
    return stream;
  }
  stream >> skipWS;
  const int key2 = readKey(stream, MIN_KEY_VALUE, MAX_KEY_VALUE);
  if (!stream || (stream.get() != SEPARATOR))
  {
    stream.setstate(std::ios::failbit);
    return stream;
  }
  stream >> skipWS;
  std::string str;
  std::getline(stream, str);
  if (!stream || str.empty())
  {
    stream.setstate(std::ios::failbit);
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
