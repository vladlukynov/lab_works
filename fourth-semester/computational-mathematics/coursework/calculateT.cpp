#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <cmath.h>

void calculateT(double E, double l, int N)
{
  const double h = l / N;
  const int NDIM = N - 1;

  double *x = new double[N];
  x[0] = 0.0;
  for (int i = 1; i < N; i++)
  {
    x[i] = x[0] + i * h;
  }

  double T0 = 0.0;
  double TN = 1.0;

  double *A = new double[NDIM * NDIM];
  for (int i = 0; i < NDIM * NDIM; i++)
  {
    A[i] = 0;
  }

  double *B = new double[NDIM];
  /* initialize two first elements of matrix */
  A[0] = -2 * E - std::pow(h, 2) * x[1];  // i = 1
  A[1] = E + h * (x[1] / 2);
  B[0] = T0 * (h * (x[1] / 2) - E);
  /* --------------------------------------- */

  /* initialize two last elements of matrix */
  A[NDIM * (NDIM - 1) + (NDIM - 2)] = E - h * (x[NDIM] / 2);
  A[NDIM * (NDIM - 1) + (NDIM - 1)] = -2 * E - std::pow(h, 2) * x[NDIM];
  B[NDIM - 1] = TN * (-E - h * (x[NDIM] / 2));
  /* -------------------------------------- */

  /* initialize other elements of matrix */
  for (int i = 2; i < N - 1; i++)
  {
    A[NDIM * (i - 1) + (i - 2)] = E - h * (x[i] / 2);
    A[NDIM * (i - 1) + (i - 1)] = -2 * E - std::pow(h, 2) * x[i];
    A[NDIM * (i - 1) + i] = E + h * (x[i] / 2);

    B[i - 1] = 0;
  }
  /* ----------------------------------- */

  double cond = 0.0;
  int flag = 0;
  int *IPVT = new int[NDIM];
  decomp(NDIM, NDIM, A, &cond, IPVT, &flag);
  solve(NDIM, NDIM, A, B, IPVT);

  std::cout << "FLAG = " << flag << "\n"
            << "COND = " << cond << "\n";

  for (int i = 0; i < NDIM; i++)
  {
    std::cout << "T" << i + 1 << " = " << B[i] << "\n";
  }

  delete[] x;
  delete[] A;
  delete[] B;
  delete[] IPVT;
}
