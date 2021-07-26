#ifndef EMPLOYEE_CARD_H
#define EMPLOYEE_CARD_H

#include "my-string.h"

class EmployeeCard
{
public:
  EmployeeCard();
  EmployeeCard(EmployeeCard &other);
  void setData(MyString name, MyString INN, MyString position, MyString date, MyString year);
  EmployeeCard &operator=(EmployeeCard &other);
  MyString &getName();
  bool operator<(EmployeeCard &other);
  friend bool operator>(EmployeeCard &other1, EmployeeCard &other2);
  ~EmployeeCard();
  friend std::ostream &operator<<(std::ostream &output, EmployeeCard &object);
  friend std::istream &operator>>(std::istream &input, EmployeeCard &object);
private:
  MyString employeeName;
  MyString employeeINN;
  MyString employeePosition;
  MyString employeeDate;
  MyString employeeYear;
};

#endif
