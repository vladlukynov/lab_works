#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int a, b, c;
  std::cout << "Введите числа a, b, c" << std::endl;
  std::cin >> a >> b >> c;
  if ((a % 2 == 0) || (b % 2 == 0) || (c % 2 == 0))
  {
    if ((a % 2 != 0) || (b % 2 != 0) || (c % 2 != 0))
    {
      std::cout << "ДА";
    }
    else
    {
      std::cout << "НЕТ";
    }
  }
  else
  {
    std::cout << "НЕТ";
  }
  return 0;
}

