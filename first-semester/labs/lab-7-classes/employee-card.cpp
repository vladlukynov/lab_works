#include "employee-card.h"

#include <iostream>

EmployeeCard::EmployeeCard()
{

}

EmployeeCard::EmployeeCard(EmployeeCard &other)
{
  this->employeeName = other.employeeName;
  this->employeeINN = other.employeeINN;
  this->employeePosition = other.employeePosition;
  this->employeeDate = other.employeeDate;
  this->employeeYear = other.employeeYear;
}

void EmployeeCard::setData(MyString name, MyString INN, MyString position, MyString date, MyString year)
{
  employeeName = name;
  employeeINN = INN;
  employeePosition = position;
  employeeDate = date;
  employeeYear = year;
}

EmployeeCard::~EmployeeCard()
{

}

EmployeeCard &EmployeeCard::operator=(EmployeeCard &other)
{
  this->employeeName = other.employeeName;
  this->employeeINN = other.employeeINN;
  this->employeePosition = other.employeePosition;
  this->employeeDate = other.employeeDate;
  this->employeeYear = other.employeeYear;
  return *this;
}

MyString &EmployeeCard::getName()
{
  return employeeName;
}

bool EmployeeCard::operator<(EmployeeCard &other)
{
  if (employeeDate < other.employeeDate)
  {
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &output, EmployeeCard &object)
{
  output << object.employeeName;
  output.width(25 - object.employeeName.getLength());
  output << object.employeeINN;
  output.width(25 - object.employeeINN.getLength());
  output << object.employeePosition;
  output.width(25 - object.employeePosition.getLength());
  output << object.employeeDate;
  output.width(25 - object.employeeDate.getLength());
  output << object.employeeYear;
  return output;
}

std::istream &operator>>(std::istream &input, EmployeeCard &object)
{
  input >> object.employeeName >> object.employeeINN >> object.employeePosition >> object.employeeDate
        >> object.employeeYear;
  return input;
}

bool operator>(EmployeeCard &other1, EmployeeCard &other2)
{
  if (other1.employeeYear > other2.employeeYear)
  {
    return true;
  }
  return false;
}
