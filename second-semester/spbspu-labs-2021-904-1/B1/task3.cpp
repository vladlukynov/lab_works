#include "tasks.hpp"

#include <iostream>
#include <sstream>
#include <vector>

#include "functions.hpp"

void task3()
{
  int element = 0;
  std::vector<int> vector;
  while (std::cin >> element)
  {
    if (element == 0)
    {
      break;
    }
    vector.push_back(element);
  }
  if (element != 0)
  {
    throw std::runtime_error("Last element in not 0");
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::runtime_error("Error input");
  }
  if (vector.empty())
  {
    return;
  }
  switch (vector.back())
  {
    case 1:
    {
      auto i = vector.begin();
      while (i != vector.end())
      {
        if (*i % 2 == 0)
        {
          i = vector.erase(i);
        }
        else
        {
          i++;
        }
      }
      break;
    }
    case 2:
    {
      auto i = vector.begin();
      while (i != vector.end())
      {
        if (*i % 3 == 0)
        {
          i = vector.insert(i + 1, 3, 1) + 3;
        }
        else
        {
          i++;
        }
      }
      break;
    }
    default:
      break;
  }
  print(vector, " ", std::cout);
}
