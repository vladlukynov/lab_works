#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int side;
  std::cout << "Введите величину стороны треугольника: ";
  std::cin >> side;
  int count = 1; //количество *
  for (int firstExe = 1; firstExe <= side; firstExe++)
  {
    for (int secondExe = 1; secondExe <= count; secondExe++)
    {
      std::cout << "* ";
    }
    count++;
    std::cout << std::endl;
  }
  return 0;
}

