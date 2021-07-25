#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int side;
  int countSpace = 1; //количество пробелов
  int count = 1; //количество *
  std::cout << "Введите величину стороны ромба: ";
  std::cin >> side;
  for (int firstExecutor = 1; firstExecutor <= side; firstExecutor++)
  {
    for (int secondExecutor = 1; secondExecutor <= (side - countSpace); secondExecutor++)
    {
      std::cout << " ";
    }

    for (int secondExecutor = 1; secondExecutor <= count; secondExecutor++)
    {
      std::cout << "*";
    }
    countSpace += 1;
    count += 2;
    std::cout << std::endl;
  }
  countSpace -= 2;
  count -= 4;
  for (int firstExecutor = 1; firstExecutor <= side - 1; firstExecutor++)
  {
    for (int secondExecutor = 1; secondExecutor <= (side - countSpace); secondExecutor++)
    {
      std::cout << " ";
    }
    for (int secondExecutor = 1; secondExecutor <= count; secondExecutor++)
    {
      std::cout << "*";
    }
    countSpace -= 1;
    count -= 2;
    std::cout << std::endl;
  }
  return 0;
}

