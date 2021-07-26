//Напишите функцию, выполняющую действие в соответствии с вашим вариантом. Напишите
//функцию main, в которой примените вашу функцию для нескольких массивов:

//* Для массива, количество и значения элементов которого заданы при инициализации
//  (константы).

//* Для массива, размещённого в динамической памяти, количество элементов которого
//  должно быть введено, а значения элементов сгенерированы случайно.

//* Для нескольких массивов, размещённых в динамической памяти, значения которых
//  считаны из файла. Файл должен содержать несколько строк, первая строка из которых
//  содержит количество элементов массива, следующие - сами эти элементы.

//Массив целых чисел циклически сдвинуть вправо на указанное число элементов

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void functionArray(int *inArray, int step, int count);
void functionStaticArray(int *array, int step, int count);
void functionFileArray(int step);
void functionInput(int *input);
void functionArrayOutput(int *array, int count);

int main()
{
  setlocale(LC_ALL, "Russian");
  const int count = 10;
  int step;
  int staticArray[count] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Введите количество сдвигов элементов массивов: ";
  functionInput(&step);
  std::cout << std::endl;
  functionStaticArray(staticArray, step, count);
  int countArray;
  std::cout << "\n\nДинамический массив" << std::endl;
  std::cout << "Введите количество элементов массива: ";
  functionInput(&countArray);
  int *dynamicArray = new int[countArray];
  for (int i = 0; i < countArray; i++)
  {
    dynamicArray[i] = rand() % 100 + 1;
    std::cout << dynamicArray[i] << " ";
  }
  std::cout << std::endl;
  functionArray(dynamicArray, step, countArray);
  functionArrayOutput(dynamicArray, countArray);
  std::cout << "\n\n";
  std::cout << "Чтение массивов из файла" << std::endl;
  functionFileArray(step);
  delete[]dynamicArray;
  return 0;
}

void functionArray(int *inArray, int step, int count)
{
  int save;
  for (int i = 1; i <= step; i++)
  {
    save = inArray[count - 1];
    for (int j = count - 2; j >= 0; j--)
    {
      inArray[j + 1] = inArray[j];
    }
    inArray[0] = save;
  }
}

void functionStaticArray(int *array, int step, int count)
{
  std::cout << "Статический массив" << std::endl;
  functionArrayOutput(array, count);
  std::cout << std::endl;
  functionArray(array, step, count);
  functionArrayOutput(array, count);
}

void functionFileArray(int step)
{
  std::string line;
  std::ifstream fileIn("array.txt");
  if (fileIn.is_open())
  {
    while (!(fileIn.eof()))
    {
      getline(fileIn, line);
      int numberCount = 0;
      for (int i = 0; i < static_cast<int>(line.size()); i++)
      {
        if (line[i] == 32)
        {
          numberCount += 1;
        }
      }
      numberCount += 1;
      int countArray = 0;
      int *fileArray = new int[numberCount];
      fileArray[0] = 0;
      for (int i = 0; i < static_cast<int>(line.size()); i++)
      {
        if (line[i] != 32)
        {
          fileArray[countArray] = (fileArray[countArray] + static_cast<int>(line[i]) - 48) * 10;
        }
        else
        {
          fileArray[countArray] = fileArray[countArray] / 10;
          countArray += 1;
          fileArray[countArray] = 0;
        }
      }
      fileArray[numberCount - 1] = fileArray[numberCount - 1] / 10;
      functionArrayOutput(fileArray, numberCount);
      std::cout << std::endl;
      functionArray(fileArray, step, numberCount);
      functionArrayOutput(fileArray, numberCount);
      std::cout << "\n\n";
      delete[]fileArray;
    }
  }
  else
  {
    std::cout << "Ошибка открытия файла..." << std::endl;
  }
  fileIn.close();
}

void functionInput(int *input)
{
  while (!(std::cin >> *input))
  {
    std::cout << "Неверный ввод...\n\n";
    std::cout << "Повторите ввод: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

void functionArrayOutput(int *array, int count)
{
  for (int i = 0; i < count; i++)
  {
    std::cout << array[i] << " ";
  }
}

