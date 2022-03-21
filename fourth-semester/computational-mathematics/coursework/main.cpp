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
  double l = 0.2231271 * calculateEquation(left, right, ABSERR);

  std::cout << "E = " << E << "\n"
            << "l = " << l << "\n";

  std::cout << "N = 10\n";
  calculateT(E, l, 10);

  return 0;
}
