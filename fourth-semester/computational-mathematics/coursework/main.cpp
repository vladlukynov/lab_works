#include <iostream>

#include "functions.hpp"

int main()
{
  double EPS = countEpsilon();
  double l = 0.2231271 * countExp();

  std::cout << "Epsilon = " << EPS << "\n"
            << "l = " << l << "\n";

  return 0;
}
