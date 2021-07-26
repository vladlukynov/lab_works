//Напишите программу, выполняющую ввод строк из файла и проверку соответствия каждой
//введенной строки правилу (в соответствии с указанным вариантом).

//Понятие вещественное число определено следующим образом:
//<вещественное число> ::= <мантисса> <порядок> |<знак> <мантисса> <порядок>
//<мантисса> ::= . <целое без знака>
//<порядок> ::= E <целое без знака> | E <знак> <целое без знака>
//<целое без знака> ::= <цифра> | <цифра> <целое без знака>
//<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 |7 | 8 | 9
//<знак> ::= + | -

#include <iostream>
#include <fstream>
#include <string>

bool isNumeric(std::string &str);
bool isMantissa(std::string &str);
bool isOrder(std::string &str);
bool isNumber(std::string &str);
bool isDigit(std::string &str);
void isSign(std::string &str);

int main()
{
  setlocale(LC_ALL, "Russian");
  std::string line;
  std::ifstream fileIn("input.txt");
  if (fileIn.is_open())
  {
    while (!fileIn.eof())
    {
      getline(fileIn, line);
      std::cout << line;
      if (isNumeric(line) == true)
      {
        std::cout << " - ДА!" << std::endl;
      }
      else
      {
        std::cout << " - НЕТ!" << std::endl;
      }
    }
  }
  else
  {
    std::cout << "Ошибка открытия файла...";
  }
  fileIn.close();
  return 0;
}

bool isNumeric(std::string &str)
{
  isSign(str);
  if (isMantissa(str) == true)
  {
    if (isOrder(str) == true)
    {
      if (str[0] == '\0')
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool isMantissa(std::string &str)
{
  if (str[0] == '.')
  {
    str.erase(0, 1);
    if (isNumber(str) == true)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool isOrder(std::string &str)
{
  if (str[0] == 'E')
  {
    str.erase(0, 1);
    isSign(str);
    if (isNumber(str) == true)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool isNumber(std::string &str)
{
  if (isDigit(str) == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isDigit(std::string &str)
{
  if ((str[0] >= '0') && (str[0] <= '9'))
  {
    str.erase(0, 1);
    isDigit(str);
    return true;
  }
  else
  {
    return false;
  }
}

void isSign(std::string &str)
{
  if ((str[0] == '+') || (str[0] == '-'))
  {
    str.erase(0, 1);
  }
}

