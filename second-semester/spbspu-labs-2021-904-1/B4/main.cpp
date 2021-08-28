#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

#include "data-struct.hpp"

void task(std::istream &input, std::ostream &output);

int main()
{
  try
  {
    task(std::cin, std::cout);
  }
  catch (const std::runtime_error &error)
  {
    std::cerr << error.what() << "\n";
    return 2;
  }
  catch (const std::exception &error)
  {
    std::cerr << error.what() << "\n";
    return 2;
  }
  return 0;
}

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
