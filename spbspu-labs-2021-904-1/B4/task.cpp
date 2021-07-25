#include "task.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "data-struct.hpp"

void task(std::istream &input, std::ostream &output)
{
  std::vector<DataStruct> structs((std::istream_iterator<DataStruct>(input)), std::istream_iterator<DataStruct>());
  if (!std::cin.eof())
  {
    throw std::runtime_error("Incorrect input");
  }
  std::sort(structs.begin(), structs.end(), CompareDataStructs());
  std::copy(structs.begin(), structs.end(), std::ostream_iterator<DataStruct>(output, "\n"));
}
