#include "functions.hpp"

double createLagrange(double x, int N, const double *x_, const double *f)
{
  double lagrange = 0.0;
  for (int i = 0; i < N; i++)
  {
    double value1 = 1.0;
    double value2 = 1.0;
    for (int j = 0; j < N; j++)
    {
      if (i != j)
      {
        value1 *= (x - x_[j]);
        value2 *= (x_[i] - x_[j]);
      }
    }
    lagrange += (value1 / value2 * f[i]);
  }
  
  return lagrange;
}
