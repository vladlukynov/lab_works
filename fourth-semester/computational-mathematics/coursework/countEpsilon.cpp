#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <cmath.h>

double integrateFunction(double x)
{
  return std::sqrt(3 - x) * std::cos(x);
}

double countEpsilon()
{
  double integralValue = 0.0;
  double A = 0.0;
  double B = M_PI / 2;
  double ABSERR = 0.00001;
  double RELERR = 0.00001;
  double ERREST = 0.0;
  int NOFUN = 0;
  double POSN = 0.0;
  int FLAG = 0;

  quanc8(integrateFunction, A, B, ABSERR, RELERR, &integralValue, &ERREST, &NOFUN, &POSN, &FLAG);

  std::cout << "QUANC8 result, flag\n"
            << integralValue << " " << FLAG << "\n";

  return  0.6436369 * integralValue;
}
