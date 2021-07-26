//Определите количество строгих локальных максимумов в этой последовательности. Элемент
//последовательности называется локальным максимумом, если он строго больше
//предыдущего и последующего элемента последовательности. Первый и последний элемент
//последовательности не являются локальными максимумами.

#include <iostream>
#include <limits>

int main()
{
  setlocale(LC_ALL, "Russian");
  int number = 0; //текущий элемент
  int preNumber = 0; //предыдущий элемент
  int secondPreNumber = 0; //второй предыдущий элемент
  int count = 0; //номер элемента
  int countLocalMax = 0; //количество локальных максимумов
  while (true)
  {
    secondPreNumber = preNumber;
    preNumber = number;
    count += 1;
    std::cout << "Введите " << count << " элемент: ";
    std::cin >> number;
    while (std::cin.fail())
    {
      std::cout << std::endl << "Введено недопустимое значение..." << std::endl << "Повторите ввод" << "\n\n";
      std::cout << "Введите " << count << " элемент: ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> number;
    }
    if ((number != 0) && (count >= 3) && (preNumber > number) && (preNumber > secondPreNumber))
    {
      countLocalMax += 1;
    }
    if (number == 0)
    {
      break;
    }
  }
  count -= 1;
  if (count >= 3)
  {
    std::cout << "Строгих локальных максимумов в последовательности - " << countLocalMax;
  }
  else
  {
    if (count == 0)
    {
      std::cout << "Введена пустая последовательность...";
    }
    else
    {
      std::cout
        << "Введено мало элементов. Невозможно определить количество строгих локальных максимумов в последовательности...";
    }

  }
  return 0;
}

