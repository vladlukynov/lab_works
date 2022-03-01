#include "functions.hpp"

void subtractMatrices(const std::vector<std::vector<double>> &matrix1,
                      const std::vector<std::vector<double>> &matrix2,
                      std::vector<std::vector<double>> &result, int N)
{
  for (int i = 0; i < N; i++)
  {
    std::vector<double> temp;
    for (int j = 0; j < N; j++)
    {
      temp.push_back(matrix1[i][j] - matrix2[i][j]);
    }
    result.push_back(temp);
  }
}