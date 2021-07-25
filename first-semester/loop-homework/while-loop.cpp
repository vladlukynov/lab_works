#include <iostream>

int main()
{
  setlocale(LC_ALL, "Russian");
  double count = 0, sum = 0, max = 0, min = 0, minNumb = 0, maxNumb = 0, num = 0, countPlus = 0, sumPlus = 0;
  std::cout << "Введите число: ";
  std::cin >> num;
  while (num != 0)
  {
    count += 1; //Считаем количество чисел
    if (num > 0)
    {
      countPlus += 1; //Считаем количество положительных
      sumPlus += num; //Считаем сумму положительных
      if ((num < min) || (min == 0))
      {
        min = num; //Ищем минимальное положительное
        minNumb = count; //Номер минимального положительного
      }
    }
    sum += num; //сумма чисел
    if (max < num)
    {
      max = num; //Поиск максимального
      maxNumb = count; //Номер максимального
    }
    std::cout << "Введите число: ";
    std::cin >> num;
  }
  std::cout << "Сумма всех введённых чисел: " << sum << std::endl;
  std::cout << "Среднее арифметическое всех введённых чисел: " << (sum / count) << std::endl;
  std::cout << "Среднее арифметическое введённых положительных чисел: " << (sumPlus / countPlus) << std::endl;
  std::cout << "Максимальное значение: " << max << ". Его номер в списке: " << maxNumb << std::endl;
  std::cout << "Минимальное положительное значение: " << min << ". Его номер в списке: " << minNumb << std::endl;
  return 0;
}

