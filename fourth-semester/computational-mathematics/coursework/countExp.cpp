#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <cmath.h>

double expFunction(double x)
{
  return std::cos(x) / std::sin(x) + x / (1 - std::pow(x, 2));
}

double countExp()
{
  double A = 4.0;
  double B = 6.0;
  double TOL = 0.0001;
  int FLAG = 0;

  double result = zeroin(A, B, expFunction, TOL, &FLAG);
  std::cout << "Zeroin result, flag\n"
            << result << " " << FLAG << "\n";

  return result;
}
