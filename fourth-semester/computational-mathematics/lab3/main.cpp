#include <iostream>

#include "functions.hpp"

int main()
{
  const double hPrint = 0.04;
  const double h1 = 0.02;
  const double h2 = 0.01;

  std::cout << std::left;

  std::cout << "----------------------- RKF45 -----------------------\n";
  useRKF();

  std::cout << "----------- Runge-Kutta Method (h = " << h1 << ") -----------\n";
  useRungeKuttaMethod(h1, hPrint);

  std::cout << "----------- Runge-Kutta Method (h = " << h2 << ") -----------\n";
  useRungeKuttaMethod(h2, hPrint);

  return 0;
}
