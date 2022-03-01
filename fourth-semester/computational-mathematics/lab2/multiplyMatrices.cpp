#include "functions.hpp"

void multiplyMatrices(const std::vector<std::vector<double>> &matrix1,
                      const std::vector<std::vector<double>> &matrix2,
                      std::vector<std::vector<double>> &result, int N)
{
  for (int i = 0; i < N; i++)
  {
    std::vector<double> temp;
    for (int j = 0; j < N; j++)
    {
      double sum = 0;
      for (int k = 0; k < N; k++)
      {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      temp.push_back(sum);
    }
    result.push_back(temp);
  }
}
