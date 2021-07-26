#include "functions.h"

#include <iostream>
#include <fstream>

void openFile()
{
  MyString path;
  std::cout << "Enter the path to the input file: ";
  std::cin >> path;
  std::ifstream fileIn(path.getLine());
  if (fileIn.is_open())
  {
    readFile(fileIn);
  }
  else
  {
    std::cout << "The file is not open...";
  }
  fileIn.close();
}

void readFile(std::ifstream &fileIn)
{
  int employeeCount = 0;
  char symbol;
  int countStr = countString(fileIn);
  Array<EmployeeCard> employee(countStr);
  Array<MyString> data(5);
  fileIn.clear();
  fileIn.seekg(0);
  while (!fileIn.eof())
  {
    int dataCount = 0;
    bool f = false;
    while (true)
    {
      fileIn >> symbol;
      data[dataCount].addSymbol(symbol);
      if ((fileIn.peek() == ' ') && (f == true))
      {
        dataCount += 1;
      }
      if ((fileIn.peek() == ' ') && (f == false))
      {
        data[dataCount].addSymbol(' ');
        f = true;
      }
      if ((fileIn.peek() == '\n') || (fileIn.peek() == EOF))
      {
        break;
      }
    }
    employee[employeeCount].setData(data[0], data[1], data[2], data[3], data[4]);
    employeeCount += 1;
    cleanData(data);
  }
  std::cout << "\nInput data\n\n";
  printData(employee, countStr);
  std::cout << std::endl;
  oldEmployee(employee, countStr);
  employee.sortData(countStr);
  std::cout << "\nOutput data in the output.txt file\n";
  outputFile(employee, countStr);
}

int countString(std::ifstream &fileIn)
{
  int count = 0;
  while (!fileIn.eof())
  {
    fileIn.get();
    if ((fileIn.peek() == '\n') || (fileIn.peek() == EOF))
    {
      count += 1;
    }
  }
  return count;
}

void printData(Array<EmployeeCard> &employee, int employeeCount)
{
  for (int i = 0; i < employeeCount; i++)
  {
    std::cout << employee[i] << std::endl;
  }
}

void cleanData(Array<MyString> &data)
{
  for (int i = 0; i < 5; i++)
  {
    data[i] = "";
  }
}

void oldEmployee(Array<EmployeeCard> &employee, int employeeCount)
{
  EmployeeCard temp = employee[0];
  for (int i = 1; i < employeeCount; i++)
  {
    if (employee[i] < temp)
    {
      temp = employee[i];
    }
  }
  std::cout << "Old employee: " << temp.getName() << std::endl;
}

void outputFile(Array<EmployeeCard> &employee, int employeeCount)
{
  std::ofstream fileOut("output.txt");
  fileOut << "Name";
  fileOut.width(23);
  fileOut << "INN";
  fileOut.width(29);
  fileOut << "Position";
  fileOut.width(24);
  fileOut << "Birthday";
  fileOut.width(31);
  fileOut << "Employment date" << "\n\n";
  for (int i = 0; i < employeeCount; i++)
  {
    fileOut << employee[i] << std::endl;
  }
  fileOut.close();
}
