#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int x1, y1, x2, y2;
  std::cout << "Введите координату x1: ";
  std::cin >> x1;
  std::cout << "Введите координату y1: ";
  std::cin >> y1;
  std::cout << "Введите координату x2: ";
  std::cin >> x2;
  std::cout << "Введите координату y2: ";
  std::cin >> y2;
  if (((x1 > 0) && (y1 > 0) && (x2 > 0) && (y2 > 0))
      || ((x1 < 0) && (y1 > 0) && (x2 < 0) && (y2 > 0))
      || ((x1 < 0) && (y1 < 0) && (x2 < 0) && (y2 < 0))
      || ((x1 > 0) && (y1 < 0) && (x2 > 0) && (y2 < 0)))
  {
    std::cout << "ДА";
  }
  else
  {
    std::cout << "НЕТ";
  }
  return 0;
}

