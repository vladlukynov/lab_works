#include <iostream>

void inArray(int **array, int lineNumber, int columnNumber);
void outArray(int **array, int lineNumber, int columnNumber);
void deleteArray(int **array, int lineNumber, int columnNumber);

int main()
{
  int columnNumber, lineNumber;
  std::cin >> columnNumber;
  std::cin >> lineNumber;
  int **matrix = new int *[columnNumber];
  for (int i = 0; i < columnNumber; i++)
  {
    matrix[i] = new int[lineNumber];
  }
  inArray(matrix, lineNumber, columnNumber);
  outArray(matrix, lineNumber, columnNumber);
  deleteArray(matrix, lineNumber, columnNumber);
  return 0;
}

void inArray(int **array, int lineNumber, int columnNumber)
{
  for (int i = 0; i < lineNumber; i++)
  {
    for (int j = 0; j < columnNumber; j++)
    {
      std::cin >> array[i][j];
    }
  }
}

void outArray(int **array, int lineNumber, int columnNumber)
{
  for (int i = 0; i < lineNumber; i++)
  {
    for (int j = 0; j < columnNumber; j++)
    {
      std::cout << array[i][j] << " ";
      if (j == (columnNumber - 1))
      {
        std::cout << "\n";
      }
    }
  }
}

void deleteArray(int **array, int lineNumber, int columnNumber)
{
  for (int i = 0; i < columnNumber; i++)
  {
    delete[]array[i];
  }
  delete[]array;
}

