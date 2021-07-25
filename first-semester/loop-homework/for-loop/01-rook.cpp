#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int column = 0;
  int line = 0;
  std::cout << "Введите координаты ладьи" << std::endl;
  std::cout << "Введите номер строки: ";
  std::cin >> line;
  std::cout << "Введите номер столбца: ";
  std::cin >> column;
  std::cout << "Координаты клеток, находящихся под ударом" << std::endl;
  for (int numbFor = 1; numbFor <= 8; numbFor++)
  {
    for (int secondNumbFor = 1; secondNumbFor <= 8; secondNumbFor++)
    {
      if ((numbFor != line) && (secondNumbFor != column))
      {
        std::cout << "Строка: " << numbFor << ". Столбец: " << secondNumbFor << "." << std::endl;
      }
    }
  }
  return 0;
}

