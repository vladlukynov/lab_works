#include "functions.hpp"

#include <cmath>

double calculateMatrixNorm(const std::vector<std::vector<double>> &matrix, int N)
{
  double max = 0;
  for (int i = 0; i < N; i++)
  {
    double sum = 0;
    for (int j = 0; j < N; j++)
    {
      sum += std::abs(matrix[i][j]);
    }
    max = std::max(max, sum);
  }

  return max;
}
