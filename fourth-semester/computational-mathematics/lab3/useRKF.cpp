#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <FORSYTHE.H>

void function(double t, double *x, double *dx)
{
  dx[0] = -155 * x[0] - 750 * x[1] + std::sin(1 + t);
  dx[1] = x[0] + std::cos(1 - t) + t + 1;
}

void useRKF()
{
  const int N = 2;
  double WORK[6 * N + 3];
  int FLAG = 1;

  double tBegin = 0.0;
  const double tEnd = 1.0;
  const double hint = 0.04;

  const double h = (tEnd - tBegin) / hint;

  double x[N] = {5.0, -1.0};
  double RE = 0.0001;
  double AE = 0.0001;

  double tout = tBegin;

  std::cout << std::setw(15) << "tout" << std::setw(15) << "y1" << std::setw(15) << "y2" << std::setw(15) << "FLAG"
            << std::endl;
  for (int i = 0; i <= h; i++)
  {
    RKF45(function, N, x, tBegin, tout, RE, AE, WORK, FLAG);
    std::cout << std::setw(15) << tout << std::setw(15) << x[0] << std::setw(15) << x[1] << std::setw(15) << FLAG
              << "\n";
    tout += hint;
  }
}
