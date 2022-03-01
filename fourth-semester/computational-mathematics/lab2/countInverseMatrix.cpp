#include "functions.hpp"

#include <FORSYTHE.H>

void countInverseMatrix(const std::vector<std::vector<double>> &matrix,
                        const std::vector<std::vector<double>> &E,
                        std::vector<std::vector<double>> &result,
                        int N, double &condValue)
{
  DECOMP decomp(N, matrix);
  condValue = decomp.Cond();
  for (int i = 0; i < N; i++)
  {
    std::vector<double> temp(E[i]);
    decomp.Solve(temp);
    result.push_back(temp);
  }
}
