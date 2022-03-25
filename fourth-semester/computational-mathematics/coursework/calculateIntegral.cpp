#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <cmath.h>

double integrateFunction(double x)
{
  return std::sqrt(3 - x) * std::cos(x);
}

double calculateIntegral(double A, double B, double ABSERR, double RELERR)
{
  double integralValue = 0.0;
  double ERREST = 0.0;
  int NOFUN = 0;
  double POSN = 0.0;
  int FLAG = 0;

  quanc8(integrateFunction, A, B, ABSERR, RELERR, &integralValue, &ERREST, &NOFUN, &POSN, &FLAG);

  std::cout << "Integral result = " << integralValue << "\n"
            << "FLAG = " << FLAG << "\n";

  return integralValue;
}
