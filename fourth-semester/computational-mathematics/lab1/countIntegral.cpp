#include "functions.hpp"

#include <cmath>
#include <FORSYTHE.H>

double f(double x)
{
  return std::cos(x) / x;
}

void countIntegral(double *argArray, double *resArray)
{
  const double A = 1.0;

  const double ABSERR = 1.0E-10;
  const double RELERR = 0.0;
  double ERREST = 0.0;

  const double x0 = 3.0;
  const double x = 5.0;
  const double h = 0.25;

  for (double i = x0; i <= x; i += h)
  {
    static int j = 0;

    double result = 0.0;
    int NOFUN = 0;
    double FLAG = 0.0;

    QUANC8(f, A, i, ABSERR, RELERR, result, ERREST, NOFUN, FLAG);
    argArray[j] = i;
    resArray[j] = result;
    j++;
  }
}
