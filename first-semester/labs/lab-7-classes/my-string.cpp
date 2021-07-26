#include "my-string.h"

#include <iostream>
#include <cstring>

MyString::MyString()
{
  length = 0;
  line = nullptr;
}

MyString::MyString(const char *line)
{
  length = strlen(line);
  this->line = new char[length + 1];
  for (int i = 0; i < length; i++)
  {
    this->line[i] = line[i];
  }
  this->line[length] = '\0';
}

MyString::MyString(MyString &other)
{
  this->length = other.length;
  this->line = new char[length + 1];
  for (int i = 0; i < this->length; i++)
  {
    this->line[i] = other.line[i];
  }
  this->line[length] = '\0';
}

const char *MyString::getLine()
{
  return line;
}

void MyString::addSymbol(char symbol)
{
  MyString temp;
  temp = *this;
  length += 1;
  delete[] line;
  line = new char[length + 1];
  for (int i = 0; i < temp.length; i++)
  {
    line[i] = temp.line[i];
  }
  line[length - 1] = symbol;
  line[length] = '\0';
}

int MyString::getLength()
{
  return length;
}

MyString &MyString::operator=(const MyString &other)
{
  if (this->line != nullptr)
  {
    delete[] this->line;
  }
  this->length = other.length;
  this->line = new char[this->length + 1];
  for (int i = 0; i < this->length; i++)
  {
    this->line[i] = other.line[i];
  }
  this->line[this->length] = '\0';
  return *this;
}

MyString &MyString::operator=(const char *line)
{
  if (this->line != nullptr)
  {
    delete[] this->line;
  }
  length = strlen(line);
  this->line = new char[length + 1];
  for (int i = 0; i < length; i++)
  {
    this->line[i] = line[i];
  }
  this->line[length] = '\0';
  return *this;
}

MyString MyString::operator+(MyString &other)
{
  MyString temp;
  temp.length = this->length + other.length;
  temp.line = new char[temp.length + 1];
  int j = 0;
  for (int i = 0; i < this->length; i++, j++)
  {
    temp.line[i] = this->line[i];
  }
  for (int i = 0; i < other.length; i++, j++)
  {
    temp.line[j] = other.line[i];
  }
  temp.line[temp.length] = '\0';
  return temp;
}

bool MyString::operator<(MyString &other)
{
  for (int i = 6; i <= 9; i++)
  {
    if (line[i] < other.line[i])
    {
      return true;
    }
    if (line[i] > other.line[i])
    {
      break;
    }
  }
  for (int i = 3; i <= 4; i++)
  {
    if (line[i] < other.line[i])
    {
      return true;
    }
    if (line[i] > other.line[i])
    {
      break;
    }
  }
  for (int i = 0; i <= 1; i++)
  {
    if (line[i] < other.line[i])
    {
      return true;
    }
    if (line[i] > other.line[i])
    {
      break;
    }
  }
  return false;
}

bool MyString::operator>(MyString &other)
{
  for (int i = 6; i <= 9; i++)
  {
    if (line[i] > other.line[i])
    {
      return true;
    }
    if (line[i] < other.line[i])
    {
      break;
    }
  }
  for (int i = 3; i <= 4; i++)
  {
    if (line[i] > other.line[i])
    {
      return true;
    }
    if (line[i] < other.line[i])
    {
      break;
    }
  }
  for (int i = 0; i <= 1; i++)
  {
    if (line[i] > other.line[i])
    {
      return true;
    }
    if (line[i] < other.line[i])
    {
      break;
    }
  }
  return false;
}

MyString::~MyString()
{
  delete[] line;
}

std::istream &operator>>(std::istream &input, MyString &string)
{
  MyString temp;
  char symbol;
  while (input.peek() != EOF)
  {
    symbol = input.get();
    temp.addSymbol(symbol);
    if ((input.peek() == '\n') || (input.peek() == ' '))
    {
      break;
    }
  }
  string = temp;
  return input;
}

std::ostream &operator<<(std::ostream &output, MyString &string)
{
  for (int i = 0; i < string.length; i++)
  {
    output << string.line[i];
  }
  return output;
}
