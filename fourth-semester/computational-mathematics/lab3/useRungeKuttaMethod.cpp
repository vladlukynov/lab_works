#include "functions.hpp"

#include <iostream>
#include <cmath>
#include <iomanip>

void useRungeKuttaMethod(double h, double hPrint_)
{
  double hPrint = hPrint_;

  const int N = 2;
  const double h_ = 1.0 / h;

  double tPrev = 0.0;
  double xPrev[N] = {5.0, -1.0};

  std::cout << std::setw(15) << "tout" << std::setw(15) << "x1" << std::setw(15) << "x2" << "\n";
  std::cout << std::setw(15) << tPrev << std::setw(15) << xPrev[0] << std::setw(15) << xPrev[1] << "\n";
  for (int i = 1; i <= h_; i++)
  {
    double fPrev[N];
    function(tPrev, xPrev, fPrev);
    double xInter[N] = {
      xPrev[0] + h / 6.0 * fPrev[0],
      xPrev[1] + h / 6.0 * fPrev[1]
    };

    double tInter = tPrev + h / 6.0;
    double fInter[N];
    function(tInter, xInter, fInter);

    double xNext[N] = {
      xPrev[0] + h * (-2 * fPrev[0] + 3 * fInter[0]),
      xPrev[1] + h * (-2 * fPrev[1] + 3 * fInter[1])
    };

    tPrev += h;

    if (std::abs(tPrev - hPrint) < 1.0E-5)
    {
      std::cout << std::setw(15) << tPrev << std::setw(15) << xNext[0] << std::setw(15) << xNext[1] << "\n";
      hPrint += hPrint_;
    }

    xPrev[0] = xNext[0];
    xPrev[1] = xNext[1];
  }
}
