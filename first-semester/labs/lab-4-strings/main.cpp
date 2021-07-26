//Напишите две функции, выполняющие одинаковые действия (в соответствии с указанным вариантом):

//*  функцию, использующую только строки в стиле С
//*  функцию, использующую строки типа string

//В функциях разрешается использовать библиотечные функции из <cctype> и методы класса
//string, но запрещается пользоваться функциями из <cstring>.

//Строки в стиле С разместить в динамической памяти.
//Длину строки (строк) и сами символы строки (строк) вводить из файла. Если в задаче требуется
//формирование строки-результата, то вывести ее в файл.

//Определить, сколько различных букв латинского алфавита содержится в строке.

#include <iostream>
#include <fstream>
#include <string>

void functionC(const char *source, int length);
void functionString(const std::string &source);
bool fileCharInputCheck(std::string path);
int fileCountCheck(std::string path);
bool fileStringInputCheck(std::string path);
void openString();
void openChar();

int main()
{
  setlocale(LC_ALL, "Russian");
  std::cout << "Файл fileChar.txt должен состоять из 2-х строк.\n"
            << "Первая строка содержит одно число - количество символов в следующей строке.\n";
  std::cout << "Файл fileString.txt должен состоять из одной строки с любыми символами.\n\n";
  std::cout << "Строки cstyle\n";
  openChar();
  std::cout << "\nСтроки string\n";
  openString();
  return 0;
}

void openChar()
{
  std::string pathChar = "fileChar.txt";
  std::ifstream fileIn(pathChar);
  int length = 0;
  char chLength[20];
  if (fileIn.is_open())
  {
    if (fileCharInputCheck(pathChar))
    {
      fileIn.getline(chLength, 20);
      for (int i = 0; i < 20; i++)
      {
        if (chLength[i] == 0)
        {
          break;
        }
        else
        {
          length = (length + static_cast<int>(chLength[i]) - 48) * 10;
        }
      }
      length /= 10;
      length += 1;
      char *ch = new char[length];
      fileIn.getline(ch, length);
      functionC(ch, length);
    }
    else
    {
      std::cout << "Файл не соответствует условиям...\n";
    }
    fileIn.close();
  }
  else
  {
    std::cout << "Файл не открыт\n";
  }
}

void openString()
{
  std::string source;
  std::string stringPath = "fileString.txt";
  std::ifstream fileString(stringPath);
  if (fileString.is_open())
  {
    if (fileStringInputCheck(stringPath))
    {
      getline(fileString, source);
      std::cout << source;
      fileString.close();
      functionString(source);
    }
    else
    {
      std::cout << "Файл не соответствует условиям...\n";
    }
  }
  else
  {
    std::cout << "Файл не открыт\n";
  }
}


void functionC(const char *source, int length)
{
  std::string path = "fileChar.txt";
  char check;
  bool write = true;
  int result = 0;
  std::ofstream clean("check.txt");
  clean.close();
  for (int i = 0; i < length; i++)
  {
    std::cout << source[i];
    std::ifstream fileCheck("check.txt");
    while (!fileCheck.eof())
    {
      fileCheck >> check;
      if ((source[i] == check) || (source[i] == 32))
      {
        write = false;
        break;
      }
      write = true;
    }
    fileCheck.close();
    if (write)
    {
      result += 1;
      std::ofstream fileOut;
      fileOut.open("check.txt", std::ofstream::app);
      fileOut << source[i];
      fileOut.close();
    }
  }
  std::cout << "\nВстречено различных символов: " << (result - 1) << "\n";
}

void functionString(const std::string &source)
{
  int result = 0;
  bool write = true;
  std::string check;
  std::ofstream clean("check.txt");
  clean.close();
  for (int i = 0; i < static_cast<int>(source.size()); i++)
  {
    std::ifstream fileCheck("check.txt");
    while (!fileCheck.eof())
    {
      fileCheck >> check[0];
      if ((source[i] == check[0]) || (source[i] == 32))
      {
        write = false;
        break;
      }
      write = true;
    }
    fileCheck.close();
    if (write)
    {
      result += 1;
      std::ofstream fileOut;
      fileOut.open("check.txt", std::ofstream::app);
      fileOut << source[i];
      fileOut.close();
    }
  }
  std::cout << "\nВстречено различных символов: " << result << "\n";
}

bool fileCharInputCheck(std::string path)
{
  int countLine = 0;
  bool result = false;
  char element[20];
  std::ifstream file(path);
  if (fileCountCheck(path) == 2)
  {
    file.getline(element, 20);
    for (int i = 0; i < 20; i++)
    {
      if ((element[i] >= 48) and (element[i] <= 57))
      {
        result = true;
      }
      else
      {
        if (element[i] == 0)
        {
          result = true;
          break;
        }
        else
        {
          result = false;
          break;
        }
      }
    }
  }
  file.close();
  return result;
}

bool fileStringInputCheck(std::string path)
{
  bool result = false;
  if (fileCountCheck(path) == 1)
  {
    result = true;
  }
  return result;
}

int fileCountCheck(std::string path)
{
  int countLine = 0;
  std::string element;
  std::ifstream file(path);
  while (!(file.eof()))
  {
    getline(file, element);
    countLine += 1;
  }
  file.close();
  return countLine;
}

