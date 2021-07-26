//Напишите функцию (в соответствии с указанным вариантом) для работы со встроенным
//массивом. Функция, должна иметь три параметра – адрес матрицы (целые числа), количество
//строк и количество столбцов и выполнять действия в соответствии с указанным вариантом.

//Напишите программу, выполняющую ввод и вывод матрицы и вызывающую эту функцию.

//Количество строк, содержащих только различные элементы.

#include <iostream>
#include <string>
#include <limits>

void functionStaticMartix(int **array, int row, int colomn);
void functionInputMatrix(int **array, int row, int colomn);
void functionDynamicMatrix(int **array, int size);
void functionInput(int *element);
void functionOutputDynamicMatrix(int **array, int size);

int main()
{
  const int row = 3;
  const int colomn = 5;
  setlocale(LC_ALL, "Russian");
  std::cout << "Встроенные массивы\n";
  int staticMatrix[row][colomn];
  int *colomnArray[row];
  for (int i = 0; i < row; i++)
  {
    colomnArray[i] = staticMatrix[i];
  }
  functionStaticMartix(colomnArray, row, colomn);
  int size;
  std::cout << "\nМассивы в динамической памяти\n";
  std::cout << "Введите размерность матрицы: ";
  functionInput(&size);
  int **dynamicMatrix = new int *[size];
  for (int i = 0; i < size; i++)
  {
    dynamicMatrix[i] = new int[size];
  }
  functionDynamicMatrix(dynamicMatrix, size);
  functionOutputDynamicMatrix(dynamicMatrix, size);
  return 0;
}

void functionStaticMartix(int **array, int row, int colomn)
{
  int count = 0;
  functionInputMatrix(array, row, colomn);
  for (int i = 0; i < row; i++)
  {
    bool check = true;
    for (int j = 0; j < colomn - 1; j++)
    {
      int element = array[i][j];
      for (int k = j + 1; k < colomn; k++)
      {
        if (element == array[i][k])
        {
          check = false;
          break;
        }
      }
    }
    if (check)
    {
      count += 1;
    }
  }
  std::cout << "Количество строк, содержащих только различные элементы: " << count << "\n";
}

void functionInputMatrix(int **array, int row, int colomn)
{
  std::cout << "Ввод матрицы\n";
  std::cout << "Строк: " << row << ", столбцов: " << colomn << "\n";
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < colomn; j++)
    {
      functionInput(&array[i][j]);
    }
  }
}

void functionDynamicMatrix(int **array, int size)
{
  int count = 0;
  while (count <= (size - count))
  {
    for (int j = count; j < (size - count); j++)
    {
      array[count][j] = count + 1;
    }
    for (int i = size - count - 1; i >= count; i--)
    {
      array[i][size - count - 1] = count + 1;
    }
    for (int j = size - count - 1; j >= count; j--)
    {
      array[size - count - 1][j] = count + 1;
    }
    for (int i = size - count - 1; i >= count; i--)
    {
      array[i][count] = count + 1;
    }
    count += 1;
  }
}

void functionInput(int *element)
{
  std::cin >> *element;
  while (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка ввода. Повторите попытку ввода: ";
    std::cin >> *element;
  }
}

void functionOutputDynamicMatrix(int **array, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      std::cout << array[i][j] << " ";
    }
    std::cout << "\n";
  }
}

