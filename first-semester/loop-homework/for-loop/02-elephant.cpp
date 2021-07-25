#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int line;
  int column;
  std::cout << "Введите координаты слона" << std::endl;
  std::cout << "Введите номер строки: ";
  std::cin >> line;
  std::cout << "Введите номер столбца: ";
  std::cin >> column;
  std::cout << "Координаты клеток, находящихся под ударом" << std::endl;
  for (int executor = 1; executor <= 8; executor++)
  {
    if (((line + executor) <= 8) && (((column + executor) <= 8)))
    {
      std::cout << "Строка: " << line + executor << ". Столбец: " << column + executor << "." << std::endl;
    }
    if (((line + executor) <= 8) && (((column - executor) >= 1)))
    {
      std::cout << "Строка: " << line + executor << ". Столбец: " << column - executor << "." << std::endl;
    }
    if (((line - executor) >= 1) && (((column + executor) <= 8)))
    {
      std::cout << "Строка: " << line - executor << ". Столбец: " << column + executor << "." << std::endl;
    }
    if (((line - executor) >= 1) && (((column - executor) >= 1)))
    {
      std::cout << "Строка: " << line - executor << ". Столбец: " << column - executor << "." << std::endl;
    }
  }
  return 0;
}

