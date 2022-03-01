#include <iostream>
#include <cmath>

#include "functions.hpp"

int main()
{
  const int numPoints = 9;
  double argArray[numPoints];
  double resArray[numPoints];

  countIntegral(argArray, resArray);

  std::cout << "argArray\tresArray\n";
  for (int i = 0; i < numPoints; i++)
  {
    std::cout << argArray[i] << "\t\t" << resArray[i] << "\n";
  }

  double x0 = 3.125;
  double xk[8];
  double fLagrange[8];
  double fSpline[8];

  for (int k = 0; k < 8; k++)
  {
    xk[k] = x0 + 0.25 * k;
    fLagrange[k] = createLagrange(xk[k], numPoints, argArray, resArray);
    fSpline[k] = countSpline(8, argArray, resArray, xk[k]);
  }

  std::cout << "\nLagrange\n";
  for (int i = 0; i < 8; i++)
  {
    std::cout << "x = " << xk[i] << ": " << std::abs(resArray[i] - fLagrange[i]) << "\n";
  }

  std::cout << "\nSpline\n";
  for (int i = 0; i < 8; i++)
  {
    std::cout << "x = " << xk[i] << ": " << std::abs(resArray[i] - fSpline[i]) << "\n";
  }

  return 0;
}
