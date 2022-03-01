#include "functions.hpp"

void initEMatrix(std::vector <std::vector<double>> &matrix, int N)
{
  for (int i = 0; i < N; i++)
  {
    std::vector<double> temp;
    for (int j = 0; j < N; j++)
    {
      if (i == j)
      {
        temp.push_back(1);
      }
      else
      {
        temp.push_back(0);
      }
    }
    matrix.push_back(temp);
  }
}
