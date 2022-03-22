#include "functions.hpp"

#include <cmath>

void function(double t, double *x, double *dx)
{
  dx[0] = -155 * x[0] - 750 * x[1] + std::sin(1 + t);
  dx[1] = x[0] + std::cos(1 - t) + t + 1;
}
