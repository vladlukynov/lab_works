#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

struct CompareDataStructs
{
  bool operator()(const DataStruct &firstStruct, const DataStruct &secondStruct);
};

int readKey(std::istream &stream);
std::string readStr(std::istream &stream);

std::istream &operator>>(std::istream &stream, DataStruct &dataStruct);
std::ostream &operator<<(std::ostream &stream, const DataStruct &dataStruct);

#endif
