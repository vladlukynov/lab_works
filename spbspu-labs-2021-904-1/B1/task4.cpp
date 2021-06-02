#include "tasks.hpp"

#include <iostream>
#include <memory>
#include <vector>

#include "functions.hpp"

void task4(sort_t sortType, int size)
{
  if (size <= 0)
  {
    throw std::invalid_argument("Size must be more than 0");
  }
  std::vector<double> array(size);
  fillRandom(array.data(), size);
  print(array, " ", std::cout);
  std::cout << "\n";
  sort<IndexAccess>(array, sortType);
  print(array, " ", std::cout);
}
