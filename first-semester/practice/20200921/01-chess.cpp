#include <iostream>
int main()
{
  setlocale(LC_ALL, "Russian");
  int horse_1;
  int horse_2;
  int figure_1;
  int figure_2;
  std::cout << "Введите 1 координату коня: ";
  std::cin >> horse_1;
  std::cout << "Введите 2 координату коня: ";
  std::cin >> horse_2;
  std::cout << "Введите 1 координату фигуры: ";
  std::cin >> figure_1;
  std::cout << "Введите 2 координату фигуры: ";
  std::cin >> figure_2;
  if ((((horse_1 - 1) == figure_1) && ((horse_2 - 2) == figure_2))
      || (((horse_1 - 2) == figure_1) && ((horse_2 - 1) == figure_2))
      || (((horse_1 - 2) == figure_1) && ((horse_2 + 1) == figure_2))
      || (((horse_1 - 1) == figure_1) && ((horse_2 + 2) == figure_2))
      || (((horse_1 + 1) == figure_1) && ((horse_2 - 2) == figure_2))
      || (((horse_1 + 2) == figure_1) && ((horse_2 - 1) == figure_2))
      || (((horse_1 + 2) == figure_1) && ((horse_2 + 1) == figure_2))
      || (((horse_1 + 1) == figure_1) && ((horse_2 + 2) == figure_2)))
  {
    std::cout << "Истина!";
  }
  else
  {
    std::cout << "Ложь!";
  }
  return 0;
}

