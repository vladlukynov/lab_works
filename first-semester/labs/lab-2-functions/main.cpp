//Напишите функцию (в соответствии с указанным вариантом) для вычисления значения
//предложенной суммы в заданной точке (x) с указанной абсолютной погрешностью вычисления
//(absError) и максимальным числом слагаемых (numberMax).

//Напишите программу вывода таблицы вычисленных значений функции на указанном интервале и
//значений, полученных с использованием стандартных функций C++.

#include <iostream>
#include <iomanip>
#include <cmath>

double degree(double value, int count);  //функция возведения в степень
double value(double x, int numberMax);  //функция подсчёта суммы

int main()
{
  setlocale(LC_ALL, "Russian");
  double xLeft, xRight, step, absError, firstValue, secondValue;
  int numberMax;
  while (true)
  {
    std::cout << "Введите границы интервала:\t\t" << "Левая граница: ";
    if (!(std::cin >> xLeft)) //Ввод левой границы и проверка на корректность
    {
      std::cout << "Некорректный ввод...";
      break;
    }
    std::cout << std::setw(56) << "Правая граница: ";
    if (!(std::cin >> xRight)) //Ввод правой границы и проверка на корректность
    {
      std::cout << "Некорректный ввод...";
      break;
    }
    if (xLeft > xRight)
    {
      std::cout << "Левая граница больше правой...";
      break;
    }
    else
    {
      if ((xLeft <= 0) or (xRight >= 1))
      {
        std::cout << "x выходит за границы промежутка (0; 1)...";
        break;
      }
    }
    std::cout << "Введите шаг интервала: ";
    if (!(std::cin >> step)) //Ввод шага и проверка на корректность
    {
      std::cout << "Некорректный ввод...";
      break;
    }
    std::cout << "Введите желаемую точность вычисления: ";
    if (!(std::cin >> absError)) //Ввод точности и проверка на корректность
    {
      std::cout << "Некорректный ввод...";
      break;
    }
    std::cout << "Введите максимальное число слагаемых: ";
    if (!(std::cin >> numberMax)) //Ввод числа слагаемых и проверка на корректность
    {
      std::cout << "Некорректный ввод...";
      break;
    }
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << std::setw(15) << "Число x" << std::setw(40) << "Приближенное значение ln(x)" << std::endl;
    std::cout << "---------------------------------------------------------------------\n";
    for (double x = xLeft; x <= xRight; x += step)
    {
      std::cout << std::setw(15) << x;
      firstValue = log(x);
      secondValue = 2 * value(x, numberMax);
      if (std::abs(secondValue - firstValue) <= absError)
      {
        std::cout << std::setw(40) << secondValue << std::endl;
      }
      else
      {
        std::cout << std::setw(40) << "Точность не достигнута" << std::endl;
      }
    }
    break;
  }
  return 0;
}

double degree(double value, int count)  //функция возведения в степень
{
  double result = 1.0;
  for (int i = 1; i <= count; i++)
  {
    result *= value;
  }
  return result;
}

double value(double x, int numberMax)  //функция подсчёта суммы
{
  int validCount = 1;
  int count = -1;
  double sum = 0;
  double value = (x - 1) / (x + 1);
  while (true)
  {
    if (numberMax < validCount)
    {
      break;
    }
    else
    {
      sum += (1 / (static_cast<double>(count) + 2)) * degree(value, count + 2);
      count += 2;
      validCount++;
    }
  }
  return sum;
}

