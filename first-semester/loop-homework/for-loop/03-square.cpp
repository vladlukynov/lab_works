#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int side;
  std::cout << "Введите величину стороны квадрата: ";
  std::cin >> side;
  for (int firstExecutor = 1; firstExecutor <= side; firstExecutor++)
  {
    for (int secondExecutor = 1; secondExecutor <= side; secondExecutor++)
    {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }
  return 0;
}

