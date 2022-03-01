#include "functions.hpp"

#include <iostream>

void printMatrix(const std::vector<std::vector<double>> &matrix, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}
