#include "functions.hpp"

#include <FORSYTHE.H>

double countSpline(int N, double* x, double* f, double U)
{
  SPLINE spline(N, x, f);

  return spline.Eval(U);
}
