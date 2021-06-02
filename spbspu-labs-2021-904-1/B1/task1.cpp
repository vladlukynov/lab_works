#include "tasks.hpp"

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

#include "functions.hpp"

void task1(sort_t sortType)
{
  std::vector<int> vector1;
  int element = 0;
  while (std::cin >> element)
  {
    vector1.push_back(element);
  }
  if (!std::cin.eof())
  {
    throw std::runtime_error("Error input");
  }
  if (vector1.empty())
  {
    return;
  }
  std::vector<int> vector2 = vector1;
  std::list<int> list(vector1.begin(), vector1.end());
  sort<IndexAccess>(vector1, sortType);
  print(vector1, " ", std::cout);
  std::cout << "\n";
  sort<AtAccess>(vector2, sortType);
  print(vector2, " ", std::cout);
  std::cout << "\n";
  sort<AccessWithIterators>(list, sortType);
  print(list, " ", std::cout);
}
