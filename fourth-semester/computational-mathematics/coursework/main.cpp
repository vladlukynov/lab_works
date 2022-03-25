#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

#include "functions.hpp"

int main()
{
  std::cout << std::fixed << std::setprecision(10);

  const double ABSERR = 0.00001;
  const double RELERR = 0.00001;
  const double A = 0.0;
  const double B = M_PI / 2;
  const double left = 4.0;
  const double right = 6.0;

  double E = 0.6436369 * calculateIntegral(A, B, ABSERR, RELERR);
  std::cout << "-------------------------------------------------\n";

  double l = 0.2231271 * calculateEquation(left, right, ABSERR);
  std::cout << "-------------------------------------------------\n";

  std::cout << "E = " << E << "\n"
            << "l = " << l << "\n"
            << "-------------------------------------------------\n";

  std::cout << "N = 10\n";
  calculateT(E, l, 10);

  std::cout << "N = 20\n";
  calculateT(E, l, 20);
  std::cout << "-------------------------------------------------\n";

  double E1 = 0.99 * E;
  std::cout << "E = 0.99 * E = " << E1 << "\n";

  std::cout << "N = 10\n";
  calculateT(E1, l, 10);

  std::cout << "N = 20\n";
  calculateT(E1, l, 20);
  std::cout << "-------------------------------------------------\n";

  double E2 = 1.01 * E;
  std::cout << "E = 1.01 * E = " << E2 << "\n";

  std::cout << "N = 10\n";
  calculateT(E2, l, 10);

  std::cout << "N = 20\n";
  calculateT(E2, l, 20);

  return 0;
}
