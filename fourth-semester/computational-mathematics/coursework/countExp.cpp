#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <cmath.h>

double expFunction(double x)
{
  return std::cos(x) / std::sin(x) + x / (1 - std::pow(x, 2));
}

double calculateEquation(double A, double B, double ABSERR)
{
  int flag = 0;

  double result = zeroin(A, B, expFunction, ABSERR, &flag);
  std::cout << "Equation result = " << result << "\n"
            << "flag = " << flag << "\n";

  return result;
}
