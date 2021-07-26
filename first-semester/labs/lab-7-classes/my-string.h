#ifndef MYSTRING_H
#define MYSTRING_H

#include <iosfwd>

class MyString
{
public:
  MyString();
  MyString(const char *line);
  MyString(MyString &other);
  ~MyString();
  const char *getLine();
  void addSymbol(char symbol);
  int getLength();
  friend std::istream &operator>>(std::istream &input, MyString &string);
  friend std::ostream &operator<<(std::ostream &output, MyString &string);
  bool operator>(MyString &other);
  bool operator<(MyString &other);
  MyString &operator=(const char *line);
  MyString &operator=(const MyString &other);
  MyString operator+(MyString &other);
private:
  int length;
  char *line;
};
#endif
