#include <iostream>
#include <stdexcept>

#include "task.hpp"

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
  return 0;
}
