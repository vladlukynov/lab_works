#include <iostream>
#include <vector>

#include "functions.hpp"

int main()
{
  const int N = 8;
  const double p[5] = {1.0, 0.1, 0.01, 0.0001, 0.000001};

  std::vector<std::vector<double>> matrix = {{0,  -6, -1, -6, -3, -4, -3, -4},
                                             {-6, 35, -1, -6, -5, -6, -3, -8},
                                             {-1, -1, 19, -6, -8, -2, 0,  -1},
                                             {-6, -6, -6, 36, -4, -3, -4, -7},
                                             {-3, -5, -8, -4, 25, 0,  -1, -4},
                                             {-4, -6, -2, -3, 0,  28, -8, -5},
                                             {-3, -3, 0,  -4, -1, -8, 21, -2},
                                             {-4, -8, -1, -7, -4, -5, -2, 31}};

  std::vector<std::vector<double>> E;
  initEMatrix(E, N);

  for (double p_: p)
  {
    double condValue = 0;
    double rate;

    std::vector<std::vector<double>> inverseMatrix;
    std::vector<std::vector<double>> mulMatrix;
    std::vector<std::vector<double>> R;

    std::cout << "p = " << p_ << "\n";
    matrix[0][0] = p_ + 27;

    countInverseMatrix(matrix, E, inverseMatrix, N, condValue);
    std::cout << "condValue = " << condValue << "\n";

    multiplyMatrices(inverseMatrix, matrix, mulMatrix, N);
    subtractMatrices(E, mulMatrix, R, N);

    rate = calculateRate(R, N);
    std::cout << "Rate: " << rate << "\n";
  }

  return 0;
}
