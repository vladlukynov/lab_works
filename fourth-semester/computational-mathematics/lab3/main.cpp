#include <iostream>

#include "functions.hpp"

int main()
{
  std::cout << std::left;
  std::cout << "----------------------- RKF45 (h = 0.04) -----------------------\n";
  useRKF();

  return 0;
}
